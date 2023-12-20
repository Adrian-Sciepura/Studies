.686
.model flat

public _nowy_exp

.data
jeden dd 1.0
tmp dd ?

.code
_nowy_exp PROC

	push ebp
	mov ebp, esp
	push ebx
	push ecx
	push edx
	push esi

	mov ecx, 19
	mov esi, 1
	mov eax, 1
	finit
	fld jeden
	fld jeden

ptl:
	mul esi
	fld DWORD PTR [ebp + 8]	
	fmulp
	fst ST(2)
	mov tmp, eax
	fild tmp
	fdivp
	faddp
	fxch
	inc esi
	loop ptl

	fstp ST(0)

	pop esi
	pop edx
	pop ecx
	pop ebx
	pop ebp
	ret

_nowy_exp ENDP
END