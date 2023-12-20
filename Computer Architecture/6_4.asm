.386
rozkazy SEGMENT use16
ASSUME CS:rozkazy

wyswietl_AL PROC
	; wy�wietlanie zawarto�ci rejestru AL na ekranie wg adresu
	; podanego w ES:BX
	; stosowany jest bezpo�redni zapis do pami�ci ekranu 
	; przechowanie rejestr�w
	push ax
	push cx
	push dx
	mov cl, 10							; dzielnik
 
	mov ah, 0							; zerowanie starszej cz�ci dzielnej

	; dzielenie liczby w AX przez liczb� w CL, iloraz w AL,
	; reszta w AH (tu: dzielenie przez 10)
	div cl
	add ah, 30H							; zamiana na kod ASCII
	mov es:[bx+4], ah					; cyfra jedno�ci
	mov ah, 0
	div cl								; drugie dzielenie przez 10
	add ah, 30H							; zamiana na kod ASCII
	mov es:[bx+2], ah					; cyfra dziesi�tek
	add al, 30H							; zamiana na kod ASCII
	mov es:[bx+0], al					; cyfra setek

	; wpisanie kodu koloru (intensywny bia�y) do pami�ci ekranu
	mov al, 00001111B
	mov es:[bx+1],al
	mov es:[bx+3],al
	mov es:[bx+5],al

	pop dx
	pop cx
	pop ax
	ret
wyswietl_AL ENDP


;============================================================
; procedura obs�ugi przerwania klawiatury
obsluga_klawiatury PROC
	push ax
	push bx
	push es

	mov ax, 0B800h
	mov es, ax

	mov ax, 0
	in al, 60H
	call wyswietl_AL

	pop es
	pop bx
	pop ax

	jmp dword PTR cs:wektor9

	wektor9 dd ?
obsluga_klawiatury ENDP

;============================================================
; program g��wny - instalacja i deinstalacja procedury
; obs�ugi przerwa�
; ustalenie strony nr 0 dla trybu tekstowego
zacznij:
	mov al, 0
	mov ah, 5 
	int 10 
	mov ax, 0
	mov ds,ax

	; odczytanie zawarto�ci wektora nr 9 i zapisanie go
	; w zmiennej 'wektor9' (wektor nr 9 zajmuje w pami�ci 4 bajty
	; pocz�wszy od adresu fizycznego 9 * 4 = 36)
	mov eax,ds:[36]					; adres fizyczny 0*16 + 36 = 36
	mov cs:wektor9, eax 
 
	; wpisanie do wektora nr 8 adresu procedury 'obsluga_klawiatury'
	mov ax, SEG obsluga_klawiatury
	mov bx, OFFSET obsluga_klawiatury
	cli

	; zapisanie adresu procedury do wektora nr 9
	mov ds:[36], bx ; OFFSET 
	mov ds:[38], ax ; cz. segmentowa
	sti 

; oczekiwanie na naci�ni�cie klawisza 'x'
aktywne_oczekiwanie:
	mov ah,1
	int 16H 
	; funkcja INT 16H (AH=1) BIOSu ustawia ZF=1 je�li
	; naci�ni�to jaki� klawisz

	jz aktywne_oczekiwanie

	; odczytanie kodu ASCII naci�ni�tego klawisza (INT 16H, AH=0)
	; do rejestru AL
	mov ah, 0
	int 16H
	cmp al, 'x'
	jne aktywne_oczekiwanie ; skok, gdy inny znak

	; deinstalacja procedury obs�ugi przerwania zegarowego
	; odtworzenie oryginalnej zawarto�ci wektora nr 9
	mov eax, cs:wektor9
	cli
	mov ds:[36], eax
	sti

	mov al, 0
	mov ah, 4CH
	int 21H
rozkazy ENDS
nasz_stos SEGMENT stack
db 128 dup (?)
nasz_stos ENDS
END zacznij