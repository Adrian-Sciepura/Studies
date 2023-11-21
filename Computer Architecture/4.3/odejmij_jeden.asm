.686
.model flat, c

public odejmij_jeden

.code
odejmij_jeden PROC

	push ebp
	mov ebp, esp
	push ebx
	
	mov ebx, [ebp + 8]
	mov ebx, [ebx]
	dec DWORD PTR [ebx]

	pop ebx
	pop ebp
	ret

odejmij_jeden ENDP
END