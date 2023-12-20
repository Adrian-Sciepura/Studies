.386
rozkazy SEGMENT use16
ASSUME CS:rozkazy

;============================================================
; procedura obs�ugi przerwania zegarowego
obsluga_zegara PROC
	push ax
	push bx
	push dx
	push es

	; wpisanie adresu pami�ci ekranu do rejestru ES - pami��
	; ekranu dla trybu tekstowego zaczyna si� od adresu B8000H,
	; jednak do rejestru ES wpisujemy warto�� B800H,
	; bo w trakcie obliczenia adresu procesor ka�dorazowo mno�y
	; zawarto�� rejestru ES przez 16
	mov ax, 0B800h							;adres pami�ci ekranu
	mov es, ax

	; zmienna 'licznik' zawiera adres bie��cy w pami�ci ekranu
	mov bx, cs:komorka

	; i kodu koloru: bia�y na czarnym tle (do nast�pnego bajtu)
	mov byte PTR es:[bx], '*'				; kod ASCII
	mov byte PTR es:[bx+1], 00000111B		; kolor


	inc cs:wiersz
	cmp cs:wiersz, 25
	jbe licz

	mov cs:wiersz, 2

	add cs:kolumna, 2
	cmp cs:kolumna, 160
	jne licz

	mov cs:kolumna, 0

licz:
	mov ax, 160								; dlugosc jednego wiersza
	mul cs:wiersz
	add ax, cs:kolumna

wysw_dalej:
	mov cs:komorka,ax

	pop es
	pop dx
	pop bx
	pop ax

	jmp dword PTR cs:wektor8

	komorka dw 320
	kolumna dw 0
	wiersz	dw 2
	wektor8 dd ?
obsluga_zegara ENDP

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

	; odczytanie zawarto�ci wektora nr 8 i zapisanie go
	; w zmiennej 'wektor8' (wektor nr 8 zajmuje w pami�ci 4 bajty
	; pocz�wszy od adresu fizycznego 8 * 4 = 32)
	mov eax,ds:[32]					; adres fizyczny 0*16 + 32 = 32
	mov cs:wektor8, eax 
 
	; wpisanie do wektora nr 8 adresu procedury 'obsluga_zegara'
	mov ax, SEG obsluga_zegara
	mov bx, OFFSET obsluga_zegara
	cli

	; zapisanie adresu procedury do wektora nr 8
	mov ds:[32], bx ; OFFSET 
	mov ds:[34], ax ; cz. segmentowa
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
	; odtworzenie oryginalnej zawarto�ci wektora nr 8
	mov eax, cs:wektor8
	cli
	mov ds:[32], eax
	sti

	mov al, 0
	mov ah, 4CH
	int 21H
rozkazy ENDS
nasz_stos SEGMENT stack
db 128 dup (?)
nasz_stos ENDS
END zacznij