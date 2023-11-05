.686
.model flat

extern	__read			: PROC
extern __write			: PROC
extern _ExitProcess@4	: PROC

public _main


.data
digits				db	12 dup (?)
buffer				db	12 dup (?)
multiplier			dd	10
converted_number	dd	0

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
	mul eax
	call printEAX

	push 0
	call _ExitProcess@4

_main ENDP
END