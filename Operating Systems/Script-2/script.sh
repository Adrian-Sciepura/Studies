#!/bin/bash

NAME=
CATALOG=
BIGGER_THAN=
SMALLER_THAN=
CONTENT=
CHOICE="0"

printMenu() {
	echo "1. Nazwa: $NAME"
	echo "2. Katalog: $CATALOG"
	echo "3. Większy niż: $BIGGER_THAN"
	echo "4. Mniejszy niż: $SMALLER_THAN"
	echo "5. Zawartość: $CONTENT"
	echo "6. Szukaj"
	echo "7. WYJŚCIE"
}

while [ "$CHOICE" -ne 7 ]; do
	printMenu
	read CHOICE
	
	case $CHOICE in
	"1") read NAME;;
	"2") read CATALOG;;
	"3") read BIGGER_THAN;;
	"4") read SMALLER_THAN;;
	"5") read CONTENT;;
	"6") 
	COMMAND=""
	
	if [ -n "$CATALOG" ]; then
		COMMAND="find $CATALOG "
	else
		COMMAND="find . "
	fi
	
	if [ -n "$NAME" ]; then
		COMMAND+="-name $NAME -type f "
	fi
		
	if [ -n "$BIGGER_THAN" ]; then
		COMMAND+="-size +${BIGGER_THAN}M "
	fi
		
	if [ -n "$SMALLER_THAN" ]; then
		COMMAND+="-size -${SMALLER_THAN}M " 
	fi
		
	if [ -n "$CONTENT" ]; then
		COMMAND+="-exec grep \"${CONTENT}\" {} +" 
	fi
	
	OUT=$(eval $COMMAND)
	if [ -n "$OUT" ]; then
		echo "ZNALEZIONO"
	else
		echo "NIE ZNALEZIONO"
	fi
	
	echo "Wciśnij ENTER aby kontynuować"
	read X
	;;
	esac
	clear
done
