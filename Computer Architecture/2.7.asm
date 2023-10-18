; wczytywanie i wy�wietlanie tekstu wielkimi literami
; (inne znaki si� nie zmieniaj�)
.686
.model flat
extern	_SetConsoleOutputCP@4	: PROC
extern	_ExitProcess@4			: PROC
extern	__write					: PROC	; (dwa znaki podkre�lenia)
extern	__read					: PROC	; (dwa znaki podkre�lenia)
extern	_MessageBoxW@16			: PROC

public _main



.data
tekst_pocz		db 10, 'Prosz',169,' napisa',134,' jaki',152,' tekst '
				db 'i nacisna',134,' Enter', 10

koniec_t		db ?

magazyn			db 80 dup (?)

magazyn_unicode dw 80 dup (?)

nowa_linia		db 10

liczba_znakow	dd ?

naglowek		dw 'N','a','g','l','o','w','e','k',0


.code
_main PROC
	push 852
	call _SetConsoleOutputCP@4
	add esp, 4

	mov ecx,(OFFSET koniec_t) - (OFFSET tekst_pocz)	; liczba znak�w tekstu
	push ecx
	push OFFSET tekst_pocz							; adres tekstu
	push 1											; nr urz�dzenia (tu: ekran - nr 1)
	call __write									; wy�wietlenie tekstu pocz�tkowego
	add esp, 12										; usuniecie parametr�w ze stosu

													; czytanie wiersza z klawiatury
	push 80											; maksymalna liczba znak�w
	push OFFSET magazyn
	push 0											; nr urz�dzenia (tu: klawiatura - nr 0)
	call __read										; czytanie znak�w z klawiatury
	add esp, 12										; usuniecie parametr�w ze stosu
													; kody ASCII napisanego tekstu zosta�y wprowadzone
													; do obszaru 'magazyn'
													; funkcja read wpisuje do rejestru EAX liczb�
													; wprowadzonych znak�w
	
	mov liczba_znakow, eax							; rejestr ECX pe�ni rol� licznika obieg�w p�tli
	mov ecx, eax
	mov ebx, 0										; indeks pocz�tkowy
	mov eax, 0

ptl: 
	mov dl, magazyn[ebx]							; pobranie kolejnego znaku
	cmp dl, 'a'
	jb nieznany_znak								; skok, gdy znak nie wymaga zamiany
	
	cmp dl, 0A5H
	je duze_A
	cmp dl, 086H
	je duze_C
	cmp dl, 0A9H
	je duze_E
	cmp dl, 088H
	je duze_L
	cmp dl, 0E4H
	je duze_N
	cmp dl, 0A2H
	je duze_O
	cmp dl, 098H
	je duze_S
	cmp dl, 0ABH
	je duze_Z_1
	cmp dl, 0BEH
	je duze_Z_2

	cmp dl, 'z'										; skok, gdy znak nie wymaga zamiany
	ja nieznany_znak
	sub dl, 20H										; zamiana na wielkie litery
	mov magazyn_unicode[eax], dx					; odes�anie znaku do pami�ci
	jmp dalej


duze_A:
	mov magazyn_unicode[eax], 0104H
	jmp dalej

duze_C:
	mov magazyn_unicode[eax], 0106H
	jmp dalej

duze_E:
	mov magazyn_unicode[eax], 0118H
	jmp dalej

duze_L:
	mov magazyn_unicode[eax], 0141H
	jmp dalej

duze_N:
	mov magazyn_unicode[eax], 0143H
	jmp dalej

duze_O:
	mov magazyn_unicode[eax], 00D3H
	jmp dalej

duze_S:
	mov magazyn_unicode[eax], 015AH
	jmp dalej

duze_Z_1:
	mov magazyn_unicode[eax], 0179H
	jmp dalej

duze_Z_2:
	mov magazyn_unicode[eax], 017BH
	jmp dalej

nieznany_znak:
	mov magazyn_unicode[eax], dx

dalej: 
	inc ebx											; inkrementacja indeksu
	add eax,2
	dec ecx											; sterowanie p�tl�
	jnz ptl
													; wy�wietlenie przekszta�conego tekstu
	push 0
	push OFFSET naglowek
	push OFFSET magazyn_unicode
	push 0
	call _MessageBoxW@16
	
	add esp, 16										; usuniecie parametr�w ze stosu
	push 0
	call _ExitProcess@4								; zako�czenie programu
_main ENDP
END