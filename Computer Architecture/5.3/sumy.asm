.686
.XMM
.model flat

public _sumy

.code
_sumy PROC

	push ebp
	mov ebp, esp
	push ebx
	push ecx
	push edx

	mov ebx, [ebp + 8]	; tab_a
	mov ecx, [ebp + 12]	; tab_b
	mov edx, [ebp + 16]	; wynik

	movdqu XMM0, XMMWORD PTR [ebx]
	movdqu XMM1, XMMWORD PTR [ecx]
	paddsb XMM0, XMM1
	
	movdqa [edx], XMM0

	pop edx
	pop ecx
	pop ebx
	pop ebp
	ret

_sumy ENDP
END