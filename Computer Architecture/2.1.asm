.686
.model flat

extern	_ExitProcess@4	: PROC
extern	__write			: PROC ; (dwa znaki podkre�lenia)
public _main

.data
tekst	db 10, 'Nazywam si', 169,' . . . ' , 10
		db 'M', 162,'j pierwszy 32-bitowy program '
		db 'asemblerowy dzia', 136,'a ju', 190,' poprawnie!', 10

.code
_main PROC
	mov		ecx, 85					; liczba znak�w wy�wietlanego tekstu
	push	ecx						; liczba znak�w wy�wietlanego tekstu
	push	dword PTR OFFSET tytul_Unicode	; po�o�enie obszaru ze znakami
	push	dword PTR 1				; uchwyt urz�dzenia wyj�ciowego
	call	__write					; wy�wietlenie znak�w (dwa znaki podkre�lenia _ )
	add		esp, 12					; usuni�cie parametr�w ze stosu
	push	dword PTR 0				; kod powrotu programu 
	call	_ExitProcess@4 
_main ENDP
END
