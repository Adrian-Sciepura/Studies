.686
.model flat
extern __write			: PROC
extern _ExitProcess@4	: PROC

public _main


.data
digits	db	12 dup (?)


.code
printEAX PROC
	pusha
	mov esi, 10
	mov ebx, 10
	
getDigitLoop:
	mov edx, 0
	div ebx

	add dl, 30H
	mov digits[esi], dl
	dec esi
	cmp eax, 0
	jne getDigitLoop

fill:
	cmp esi, 0
	jz display
	mov BYTE PTR digits[esi], 20H
	dec esi
	jmp fill

display:
	mov BYTE PTR digits[11], 0AH

	push DWORD PTR 12
	push DWORD PTR OFFSET digits
	push DWORD PTR 1
	call __write
	add esp, 12

	popa
	ret
printEAX ENDP

_main PROC

	mov eax, 1
	mov ebx, 0
	mov esi, 50

numbers:
	add eax, ebx
	inc ebx
	call printEAX
	dec esi
	jnz numbers


	push 0
	call _ExitProcess@4

_main ENDP
END