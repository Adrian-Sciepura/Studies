.686
.model flat

extern	_ExitProcess@4	: PROC
extern	__write			: PROC ; (dwa znaki podkreślenia)
public _main

.data
tekst	db 10, 'Nazywam si', 169,' . . . ' , 10
		db 'M', 162,'j pierwszy 32-bitowy program '
		db 'asemblerowy dzia', 136,'a ju', 190,' poprawnie!', 10

.code
_main PROC
	mov		ecx, 85					; liczba znaków wyświetlanego tekstu
	push	ecx						; liczba znaków wyświetlanego tekstu
	push	dword PTR OFFSET tytul_Unicode	; położenie obszaru ze znakami
	push	dword PTR 1				; uchwyt urządzenia wyjściowego
	call	__write					; wyświetlenie znaków (dwa znaki podkreślenia _ )
	add		esp, 12					; usunięcie parametrów ze stosu
	push	dword PTR 0				; kod powrotu programu 
	call	_ExitProcess@4 
_main ENDP
END
