.686
.model flat

extern	_ExitProcess@4	: PROC
extern	_MessageBoxW@16	: PROC

public _main

.data
msg_text	dw 'T','o',' ','j','e','s','t',' '
			dw 'p','i','e','s',' ',0D83DH,0DC15H,' ','a',' '
			dw 't','o',' ','j','e','s','t',' ','k','o','t',' ',0D83DH,0DC08H,0

msg_head	dw 'Z','w','i','e','r','z','e','t','a',0

.code
_main PROC
	push 0
	push OFFSET msg_head
	push OFFSET msg_text
	push 0
	call _MessageBoxW@16

	push 0
	call _ExitProcess@4
_main ENDP
END