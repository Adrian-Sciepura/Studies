public suma_siedmiu_liczb

.code
suma_siedmiu_liczb PROC

	push rbp
	mov rbp, rsp

	mov rax, rcx
	add rax, rdx
	add rax, r8
	add rax, r9
	add rax, [rbp + 48]
	add rax, [rbp + 56]
	add rax, [rbp + 64]

	pop rbp
	ret

suma_siedmiu_liczb ENDP
END