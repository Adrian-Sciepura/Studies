#!/bin/bash

CHOICE="0"
EXIT_CODE="0"

DIRECTORY=""
DIRECTORY_TEXT="Select directory"
ERROR_TEXT=""

showMenu() {
    CHOICE=$(zenity --list --title="C++ Project Generator" --column="Id." --column="Action" \
    --height=300 --width=500 \
    1 "$DIRECTORY_TEXT" \
    2 "Check statistics" \
    3 "Generate makefile" \
    4 "Compile" \
    5 "Run")

    EXIT_CODE=$?
}

selectDirectory() {
    DIRECTORY=$(zenity --file-selection --directory)
    DIRECTORY_TEXT="Current directory: $DIRECTORY"
}

checkStatistics() {
    if [ ! -n "$DIRECTORY" ]; then
        ERROR_MESSAGE+="ENTER VALID PROJECT DIRECTORY"
        return
    fi

    declare -A COUNTERS
    TYPES=("int" "float" "double" "char" "bool")
    CLASSES_IN_FILES=0
    STRUCTS_IN_FILES=0
    LINES_IN_FILES=0

    for TYPE in "${TYPES[@]}"; do
        COUNTERS[$TYPE]=0
    done

    for file in "$DIRECTORY"/*; do
        FILE_EXTENSION="${file##*.}"
        if [ -f "$file" ] && ([ "$FILE_EXTENSION" == "cpp" ] || [ "$FILE_EXTENSION" == "h" ]); then
            CLASSES_IN_FILES=$((CLASSES_IN_FILES + $(grep -c "class" "$file")))
            STRUCTS_IN_FILES=$((STRUCTS_IN_FILES + $(grep -c "struct" "$file")))
            LINES_IN_FILES=$((LINES_IN_FILES + $(grep -c ".*" "$file")))
            
            for TYPE in "${TYPES[@]}"; do
                COUNTERS[$TYPE]=$((COUNTERS[$TYPE] + $(grep -o "$TYPE" "$file" | wc -l)))
            done
        fi
    done

    RESULT="TYPES:\n"
    for TYPE in "${TYPES[@]}"; do
        RESULT+="$TYPE: ${COUNTERS[$TYPE]}\n"
    done

    RESULT+="\n\nCreated Types:\n"
    RESULT+="Classes: $CLASSES_IN_FILES\n"
    RESULT+="Structs: $STRUCTS_IN_FILES\n"

    RESULT+="\n\nNumber of lines: $LINES_IN_FILES"

    zenity --info --title "Statistics" --width=200 --text="$RESULT"
}

generateMakeFile() {
    if [ ! -n "$DIRECTORY" ]; then
        ERROR_MESSAGE+="ENTER VALID PROJECT DIRECTORY"
        return
    fi

    MAKE_FILE="${DIRECTORY}/Makefile"
    OBJ_FILES=""
    TEXT=""

    for FILE in "$DIRECTORY"/*.cpp; do
        FILE_PATH=$(realpath --relative-to="$DIRECTORY" "$FILE")
        FILE_NAME=$(basename "$FILE" .cpp)
        OBJ_FILES+="$FILE_NAME.o "
        FILE_HEADER="$FILE_NAME.o: $FILE_PATH" 

        if [ -f "${DIRECTORY}/${FILE_NAME}.h" ]; then
            FILE_HEADER+=" $FILE_NAME.h"
        fi

        TEXT+="$FILE_HEADER\n"
        TEXT+="\tg++ -c $FILE_PATH\n"
    done

    echo "output: $OBJ_FILES" > "$MAKE_FILE"
    echo -e "\tg++ $OBJ_FILES-o program\n\n" >> "$MAKE_FILE"
    echo -e "$TEXT\n" >> "$MAKE_FILE"
    echo -e "clean:\n\trm -f $OBJ_FILES" >> "$MAKE_FILE"
}

compile() {
    if [ ! -n "$DIRECTORY" ]; then
        ERROR_MESSAGE+="ENTER VALID PROJECT DIRECTORY"
        return
    fi

    if [ ! -f "${DIRECTORY}/Makefile" ]; then
        generateMakeFile
    fi

    cd "$DIRECTORY"
    TEMP=$(make)
    TEMP=$(make clean)
}

run() {
    if [ ! -n "$DIRECTORY" ]; then
        ERROR_MESSAGE+="ENTER VALID PROJECT DIRECTORY"
        return
    fi
    
    if [ ! -f "${DIRECTORY}/program" ]; then
        compile    
    fi

    cd "$DIRECTORY"
    exec "${DIRECTORY}/program"
}

while getopts d:smcrvh OPT; do
    case $OPT in
        d) DIRECTORY="$OPTARG";;
        s) checkStatistics;;
        m) generateMakeFile;;
        c) compile;;
        r) run;;
    esac

    EXIT_CODE=1
done



while [ $EXIT_CODE -eq 0 ]; do
    showMenu

    case $CHOICE in
    "1") selectDirectory;;
    "2") checkStatistics;;
    "3") generateMakeFile;;
    "4") compile;;
    "5") run;;
    esac

    if [ -n "$ERROR_TEXT" ]; then
        zenity --warning --title="An error occured" --text="$ERROR_TEXT" --width=200
        ERROR_TEXT=""
    fi

done