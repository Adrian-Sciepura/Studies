.686
.model flat, c

public szukaj4_max

.code
szukaj4_max PROC

	push ebp
	mov ebp, esp
	push ebx

	sub esp, 4*32
	mov esi, 0

copyLoop:
	mov eax, DWORD PTR [ebp + esi + 8]
	mov [esp + esi], eax
	add esi, 4

	cmp esi, 4*4
	jne copyLoop

	mov esi, 0

outerLoop:
	mov edi, 0
innerLoop:
	mov eax, [esp + edi + 4]
	cmp [esp + edi], eax
	jge continue

	mov ebx, [esp + edi]
	mov [esp + edi], eax
	mov [esp + edi + 4], ebx

continue:
	add edi, 4
	cmp edi, 3*4
	jne innerLoop

	add esi, 4
	cmp esi, 3*4
	jne outerLoop

	mov eax, [esp]

	add esp, 4*32

	pop ebx
	pop ebp
	ret

szukaj4_max ENDP
END