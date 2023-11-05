.686
.model flat

extern	__read			: PROC
extern _ExitProcess@4	: PROC

public _main


.data
buffer				db	12 dup (?)
multiplier			dd	10
converted_number	dd	0

.code
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

	push 0
	call _ExitProcess@4

_main ENDP
END