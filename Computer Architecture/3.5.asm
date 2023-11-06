.686
.model flat

extern __read			: PROC
extern __write			: PROC
extern _ExitProcess@4	: PROC

public _main


.data
decode		db	'0123456789ABCDEF'
multiplier	dd	10
buffer		db	12 dup (?)

.code

printEAXasHEX PROC
	
	pusha
	sub esp, 10
	mov edi, esp

	mov ecx, 8
	mov esi, 1

convertToHexLoop:
	rol eax, 4

	mov ebx, eax
	and ebx, 0000000FH
	mov dl, decode[ebx]
	
	cmp dl, '0'
	jne nonZero
	mov dl, 20H

nonZero:
	mov [edi][esi], dl
	
	inc esi
	loop convertToHexLoop

	mov BYTE PTR [edi][0], 10
	mov BYTE PTR [edi][9], 10

	push 10
	push edi
	push 1
	call __write

	add esp, 22
	popa
	ret

printEAXasHEX ENDP



readToEAX PROC

	push ebx
	push ecx

	mov eax, 0
	mov ebx, OFFSET buffer

convertLoop:
	mov cl, [ebx]
	inc ebx
	cmp cl, 10
	je detectedENTER
	sub cl, 30H
	movzx ecx, cl

	mul DWORD PTR multiplier
	add eax, ecx
	jmp convertLoop

detectedENTER:
	pop ecx
	pop ebx
	ret

readToEAX ENDP



_main PROC

	push DWORD PTR 12
	push DWORD PTR OFFSET buffer
	push DWORD PTR 0
	call __read
	add esp, 12

	call readToEAX
	call printEAXasHEX


	push 0
	call _ExitProcess@4

_main ENDP
END