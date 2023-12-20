.686
.XMM
.model flat

public _pm_jeden

.data
wartosci dd 1.0, 1.0, 1.0, 1.0 

.code
_pm_jeden PROC

	push ebp
	mov ebp, esp
	push ebx

	mov ebx, [ebp + 8]
	movups XMM0, XMMWORD PTR [ebx]
	addsubps XMM0, wartosci
	
	movups [ebx], XMM0

	pop ebx
	pop ebp
	ret

_pm_jeden ENDP
END