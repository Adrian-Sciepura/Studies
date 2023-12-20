.686
.model flat

public _srednia_harm


.data
jeden dd +1.0

.code
_srednia_harm PROC
	push ebp
	mov ebp, esp
	push ebx
	push ecx
	push esi

	mov esi, 0
	mov ebx, [ebp + 8]
	mov ecx, [ebp + 12]
	
	finit
	fild DWORD PTR [ebp + 12]
	fldz

ptl:
	fld jeden
	fld DWORD PTR [ebx + 4*esi]
	fdivp
	faddp
	inc esi
	loop ptl

	fdivp
	
	pop esi
	pop ecx
	pop ebx
	pop ebp
	ret

_srednia_harm ENDP
END