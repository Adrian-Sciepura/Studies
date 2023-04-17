#!/bin/bash

NAME=
CATALOG=
BIGGER_THAN=
SMALLER_THAN=
CONTENT=
CHOICE="0"

printMenu() {
	CHOICE=$(zenity --list --title="Wyszukiwanie" --column="Nr." --column="Pole" --column="Wartosc" \
	--height=350 --width=300 \
	1 "Nazwa" "$NAME" \
	2 "Katalog" "$CATALOG" \
	3 "Wiekszy niz" "$BIGGER_THAN" \
	4 "Mniejszy niz" "$SMALLER_THAN" \
	5 "Zawartosc" "$CONTENT" \
	6 "Szukaj" "" \
	7 "Wyjscie" "")
	
	if [ -z "$CHOICE" ]; then
		CHOICE="0"
	fi
}

while [ "$CHOICE" -ne 7 ]; do
	printMenu
	
	case $CHOICE in
	"1") NAME=$(zenity --entry --text="Podaj nazwe pliku");;
	"2") CATALOG=$(zenity --entry --text="Podaj sciezke");;
	"3") BIGGER_THAN=$(zenity --entry --text="Podaj wartosc minimalna w MB");;
	"4") SMALLER_THAN=$(zenity --entry --text="Podaj wartosc maksymalna w MB");;
	"5") CONTENT=$(zenity --entry --text="Podaj szukana zawartosc");;
	"6") 
	COMMAND=""
	if [ -n "$NAME" ]; then
		if [ -n "$CATALOG" ]; then
			COMMAND="find $CATALOG -name $NAME -type f "
		else
			COMMAND="find . -name $NAME -type f "
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
	fi
	
	OUT=$(eval $COMMAND)
	if [ -n "$OUT" ]; then
		zenity --info --title "Wyszukiwanie" --text "ZNALEZIONO PLIK"
	else
		zenity --error --text "NIE ZNALEZIONO PLIKU"
	fi
	;;
	esac
done
