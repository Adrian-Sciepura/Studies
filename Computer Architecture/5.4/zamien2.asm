.686
.XMM
.model flat

public _zamien2

.code
_zamien2 PROC

	push ebp
	mov ebp, esp
	push ebx

	mov ebx, [ebp + 8]
	cvtpi2ps XMM0, QWORD PTR [ebx]
	
	mov ebx, [ebp + 12]
	movdqu [ebx], XMM0

	pop ebx
	pop ebp
	ret

_zamien2 ENDP
END