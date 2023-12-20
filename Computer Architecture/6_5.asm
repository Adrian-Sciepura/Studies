.386
rozkazy SEGMENT use16
ASSUME cs:rozkazy

linia PROC
	push ax 
	push bx
	push dx
	push es

	mov ax, 0A000H				; adres pamiêci ekranu dla trybu 13H
	mov es, ax

	mov ax, 320
	mul cs:wiersz

	mov dx, 0
	mov dl, cs:kolor

	mov bx, ax
	add bx, cs:przyrost

	mov es:[bx], dl
	
	mov bx, ax
	add bx, 320
	sub bx, cs:przyrost

	mov es:[bx], dl



	mov ax, cs:przyrost
	div cs:trzy

	cmp ah, 0
	jz licz_przyrost
	inc cs:wiersz

licz_przyrost:

	inc cs:przyrost
	cmp cs:przyrost, 300
	jbe dalej

	inc cs:kolor
	mov cs:przyrost, 0
	mov cs:wiersz, 0

; zapisanie adresu bie¿¹cego piksela
dalej:
	pop es
	pop dx
	pop bx 
	pop ax

	jmp dword PTR cs:wektor8 

	kolor db 1					; bie¿¹cy numer koloru
	przyrost dw 0
	wiersz dw 0
	trzy db 3
	wektor8 dd ?
linia ENDP

; INT 10H, funkcja nr 0 ustawia tryb sterownika graficznego
zacznij:
	mov ah, 0
	mov al, 13H					; nr trybu
	int 10H
	mov bx, 0
	mov es, bx					; zerowanie rejestru ES
	mov eax, es:[32]			; odczytanie wektora nr 8
	mov cs:wektor8, eax			; zapamiêtanie wektora nr 8
	
	; adres procedury 'linia' w postaci segment:offset
	mov ax, SEG linia
	mov bx, OFFSET linia
	cli

	; zapisanie adresu procedury 'linia' do wektora nr 8
	mov es:[32], bx
	mov es:[32+2], ax 
	sti

czekaj:
	mov ah, 1					; sprawdzenie czy jest jakiœ znak
	int 16h						; w buforze klawiatury
	jz czekaj 

	mov ah, 0					; funkcja nr 0 ustawia tryb sterownika
	mov al, 3H					; nr trybu
	int 10H

	; odtworzenie oryginalnej zawartoœci wektora nr 8
	mov eax, cs:wektor8
	mov es:[32], eax 

	; zakoñczenie wykonywania programu
	mov ax, 4C00H 
	int 21H
rozkazy ENDS
stosik SEGMENT stack
db 256 dup (?)
stosik ENDS
END zacznij