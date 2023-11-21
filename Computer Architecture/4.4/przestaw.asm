.686
.model flat, c

public przestaw
.code
przestaw PROC
	push ebp 
	mov ebp,esp
	push ebx
	mov ebx, [ebp+8]
	mov ecx, [ebp+12]
	dec ecx

ptl: 
	mov eax, [ebx]
	cmp eax, [ebx+4]
	jle gotowe

	mov edx, [ebx+4]
	mov [ebx], edx
	mov [ebx+4], eax
gotowe:
	add ebx, 4
	loop ptl
	pop ebx
	pop ebp
	ret
przestaw ENDP
 END