.686
.model flat

extern __read			: PROC
extern __write			: PROC
extern _ExitProcess@4	: PROC

public _main


.data
digits		db	12 dup (?)
buffer		db	12 dup (?)


.code

printEAX PROC
	pusha
	mov esi, 10
	mov ebx, 10
	
getDigitLoop:
	mov edx, 0
	div ebx

	add dl, 30H
	mov digits[esi], dl
	dec esi
	cmp eax, 0
	jne getDigitLoop

fill:
	cmp esi, 0
	jz display
	mov BYTE PTR digits[esi], 20H
	dec esi
	jmp fill

display:
	mov BYTE PTR digits[11], 0AH

	push DWORD PTR 12
	push DWORD PTR OFFSET digits
	push DWORD PTR 1
	call __write
	add esp, 12

	popa
	ret
printEAX ENDP



readHEXtoEAX PROC

	push ebx
	push ecx
	push edx
	push esi
	push edi
	push ebp

	sub esp, 12
	mov esi, esp

	push DWORD PTR 10
	push esi
	push DWORD PTR 0
	call __read
	add esp, 12

	mov eax, 0

convertLoop:
	mov dl, [esi]
	inc esi
	cmp dl, 10
	je done

	cmp dl, '0'
	jb convertLoop
	cmp dl, '9'
	ja keepChecking
	sub dl, '0'
	jmp addToResult

addToResult:
	shl eax, 4
	or al, dl
	jmp convertLoop

keepChecking:
	cmp dl, 'A'
	jb convertLoop
	cmp dl, 'F'
	ja keepChecking_2
	sub dl, 'A' - 10
	jmp addToResult

keepChecking_2:
	cmp dl, 'a'
	jb convertLoop
	cmp dl, 'f'
	ja convertLoop
	sub dl, 'a' - 10
	jmp addToResult

done:
	
	add esp, 12

	pop ebp
	pop edi
	pop esi
	pop edx
	pop ecx
	pop ebx
	ret

readHEXtoEAX ENDP



_main PROC

	call readHEXtoEAX
	call printEAX

	push 0
	call _ExitProcess@4

_main ENDP
END