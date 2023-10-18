; wczytywanie i wyœwietlanie tekstu wielkimi literami
; (inne znaki siê nie zmieniaj¹)
.686
.model flat
extern	_SetConsoleOutputCP@4	: PROC
extern	_ExitProcess@4			: PROC
extern	__write					: PROC	; (dwa znaki podkreœlenia)
extern	__read					: PROC	; (dwa znaki podkreœlenia)
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

	mov ecx,(OFFSET koniec_t) - (OFFSET tekst_pocz)	; liczba znaków tekstu
	push ecx
	push OFFSET tekst_pocz							; adres tekstu
	push 1											; nr urz¹dzenia (tu: ekran - nr 1)
	call __write									; wyœwietlenie tekstu pocz¹tkowego
	add esp, 12										; usuniecie parametrów ze stosu

													; czytanie wiersza z klawiatury
	push 80											; maksymalna liczba znaków
	push OFFSET magazyn
	push 0											; nr urz¹dzenia (tu: klawiatura - nr 0)
	call __read										; czytanie znaków z klawiatury
	add esp, 12										; usuniecie parametrów ze stosu
													; kody ASCII napisanego tekstu zosta³y wprowadzone
													; do obszaru 'magazyn'
													; funkcja read wpisuje do rejestru EAX liczbê
													; wprowadzonych znaków
	
	mov liczba_znakow, eax							; rejestr ECX pe³ni rolê licznika obiegów pêtli
	mov ecx, eax
	mov ebx, 0										; indeks pocz¹tkowy
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
	mov magazyn_unicode[eax], dx					; odes³anie znaku do pamiêci
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
	dec ecx											; sterowanie pêtl¹
	jnz ptl
													; wyœwietlenie przekszta³conego tekstu
	push 0
	push OFFSET naglowek
	push OFFSET magazyn_unicode
	push 0
	call _MessageBoxW@16
	
	add esp, 16										; usuniecie parametrów ze stosu
	push 0
	call _ExitProcess@4								; zakoñczenie programu
_main ENDP
END