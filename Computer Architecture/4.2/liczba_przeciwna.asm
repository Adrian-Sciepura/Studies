.686
.model flat, c

public liczba_przeciwna

.code
liczba_przeciwna PROC

	push ebp
	mov ebp, esp
	push ebx

	mov ebx, [ebp + 8]
	not DWORD PTR [ebx]
	inc DWORD PTR [ebx]

	pop ebx
	pop ebp
	ret

liczba_przeciwna ENDP
END