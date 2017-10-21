;Esto es para hacer el código más legible
sys_exit        equ     1
sys_read        equ     3
sys_write       equ     4
sys_nanosleep   equ     162
stdin           equ     0
stdout          equ     1
stderr          equ     2


section .data           ; sección de datos (data)

 	square: db "█"
 	squaLen: equ $-square

 	space: db " "
 	spaceLen: equ $-space

 	borderLine: db "  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓", 0x0A
 	borderLineLen: equ $-borderLine

 	letters: db "   A ", "B ", "C ", "D ", "E ", "F ", "G ", "H", 0x0A
 	lettersLen: equ $-letters

 	numbers: db "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 "
 	numbersLen: equ $-numbers

    row1: db "x", "x", "x", "x", 0x0A
    len1: equ $-row1

    row2: db "x", "x", "x", "x", 0x0A
    len2: equ $-row2

    row3: db "x", "x", "x", "x", 0x0A
    len3: equ $-row3

    row4: db " ", " ", " ", " ", 0x0A
    len4: equ $-row4

    row5: db " ", " ", " ", " ", 0x0A
    len5: equ $-row5

    row6: db "o", "o", "o", "o", 0x0A
    len6: equ $-row6

    row7: db "o", "o", "o", "o", 0x0A
    len7: equ $-row7

    row8: db "o", "o", "o", "o", 0x0A
    len8: equ $-row8

    msg1 db "Digite la Primera Posición. Restricciones: Letras:(A-H), Numeros:(1-9)",10
	
	msg1len equ $-msg1
	
	msg2 db "Digite la Segunda Posición. Restricciones: Letras:(A-H), Numeros:(1-9)",10
	msg2len equ	$-msg2
	
	msg3 db "Entrada Correcta",10,10
	msg3len equ $-msg3
	
	msg4 db "Posición Erronea vuelva a intentarlo",10,10
	msg4len equ $-msg4
	
	msg5 db "Va Bien",10
	msg5len equ $-msg5

	msg6 db "Movimiento inválido",10,10
	msg6len equ $-msg6

	msg7 db "Error Traducir Posicion",10,10
	msg7len equ $-msg7

	msg8 db "Ficha inválida",10,10
	msg8len equ $-msg8

	msgJugador0: db "Turno jugador0",10,10
	msgJugador0len: equ $-msgJugador0

	msgJugador1: db "Turno jugador1",10,10
	msgJugador1len: equ $-msgJugador1

	msgPerdioJugador0: db "Jugador1 ha ganado!!",10, "Gracias por jugar!!",10,"Desarrollado por: Edwin Rees - Oscar Chavarría",10
	msgPerdioJugador0len: equ $-msgPerdioJugador0

	msgPerdioJugador1: db "Jugador0 ha ganado!!",10, "Gracias por jugar!!",10,"Desarrollado por: Edwin Rees - Oscar Chavarría",10
	msgPerdioJugador1len: equ $-msgPerdioJugador1


	MenuMsg db "0. Para rendirse",10,"1. Para movimiento simple",10,"2. Para comer a la izquierda",10,"3. Para comer a la derecha",10,"4. Para comer doble izq-der",10,"5. Para comer doble der-izq",10,"6. Para comer doble izq-izq",10,"7. Para comer doble der-der",10,"Elige la opcion deseada",10	
	MenuMsglen equ $-MenuMsg

	msgOpcionErronea db "La opción ingresada no es válida",10,10
	msgOpcionErronealen equ $-msgOpcionErronea

	msgEnDesarrollo db "Esa funcionalidad aún no esta disponible, se encuentra en desarrollo.",10,"¡Gracias por su comprensión!",10,10
	msgEnDesarrollolen equ $-msgEnDesarrollo

	
	Cont dd 0

	jugador dd 0

	fichasJugador0 dd 12

	fichasJugador1 dd 12



Section .bss

	Movimiento resb 5
	
	Movlen    equ 5

	Pos1	resb 4	; reserve 2 bytes
	Pos1len equ	 4
	
	Pos2	resb 4
	Pos2len equ	 4	

		
	Menu    resb 2 
	Menulen equ  2

	
	Validar resb 4



section .text
	
	global _start

_start:

	nop

	call imprimirTablero					; llama a imprimir el tablero
	mov ecx, [jugador]						; pregunta por el jugador que está jugando y respectivamente imprime el mismo
imprimirJugador0:
	cmp ecx, 0
	jne imprimirJugador1
	mov ecx, msgJugador0
	mov edx, msgJugador0len
	call DisplayText
	jmp inicio

imprimirJugador1:
	mov ecx, msgJugador1
	mov edx, msgJugador1len
	call DisplayText


inicio:
	mov ecx, [fichasJugador0]				; pregunta por las fichas restantes de cada jugador y si son 0 se acaba el juego
	cmp ecx, 0
	je perdioJugador0
	mov ecx, [fichasJugador1]
	cmp ecx, 0
	je perdioJugador1

	call PedirOpcion						; llama a pedir una de la opciones de movimiento del menú
	call PrimeraPos							; se solicita la posiciones de la fichas que quiere mover

	

Movimientos:

Jugador0:
	cmp dword[jugador], 0					; en ecx se ubica la opción del menú selecionada y respectivamente se va a esa funcionalidad
	jne Jugador1
	xor ecx, ecx
	mov ecx, [Menu]
	and ecx, 0xff							; se utiliza para quitar una "a" que siempre queda al frente cuando se lee
	cmp ecx, "0"
	je perdioJugador0
	cmp ecx, "1"
	je movimientoSimpleJug0
	cmp ecx, "2"
	je comerIzqJug0
	cmp ecx, "3"
	je comerDerJug0
	jmp mensajeEnDesarrollo



movimientoSimpleJug0:
	mov eax, [Pos1]							; Mueve a eax la posición deseada a mover
	and eax, 0xffff							; para quitar la "a" que siempre aparece al leer
	push eax
	call TraducirPosicion					; traduce la posición a la dirección en memoria y comprueba si ahí hay una "x"
	cmp byte[eax], "x"
	jne volverPedirOpcion
	pop eax									; hace un movimiento simple de la posición de partida hacia la izq y abajo y se compara con
	mov ebx, eax							; la posición de llegada para comprobar si el movimiento que se quiere hacer es válido
	and eax, 0x00ff
	inc eax
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, eax
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarCambioJug0
	xor ecx, ecx							; hace un movimiento simple de la posición de partida hacia la der y abajo y se compara con
	mov ecx, ebx							; la posición de llegada para comprobar si el movimiento que se quiere hacer es válido
	and ecx, 0x00ff
	dec ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarCambioJug0
	jmp volverPedirOpcion

realizarCambioJug0:
	mov eax, [Pos2]							; comprueba si la posición de llegada está vacía
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]							; realiza el movimiento, quita la ficha de la posición 1 y la pone en la posición 2
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "x"

	mov dword[jugador], 1					; asigna el turno al otro jugador
	jmp _start


comerIzqJug0:
	mov eax, [Pos1]							; lo que compara es posición 1 con "x" para ver si hay una ficha para mover
	and eax, 0xffff
	push eax
	call TraducirPosicion
	cmp byte[eax], "x"
	jne volverPedirOpcion
	pop eax									; verifica si en la posición abajo a la izq hay una "o" para comer
	mov ebx, eax
	xor ecx, ecx
	mov ecx, ebx
	and ecx, 0x00ff							; deja la letra sola, ejemplo convierte "B1" en "B"
	dec ecx
	mov edx, ebx
	and edx, 0xff00							; deja el num solo, ejemplo convierte "B1" en "1"
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	push edx
	mov eax, edx
	call TraducirPosicion
	cmp byte[eax], "o"
	jne volverPedirOpcion

	xor ecx, ecx							; si hay una ficha disponible para comer lo que hace es otro corrimiento para saber
	xor ebx, ebx							; si la posición de llegada, o sea la 2 es la misma para validar el movimiento
	pop ecx
	mov ebx, ecx
	and ecx, 0x00ff
	dec ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarComerIzqJug0
	jmp volverPedirOpcion

realizarComerIzqJug0:
	mov eax, [Pos2]							; se encarga de verificar si la posición de llegada está vacía
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]
	and eax, 0xffff
	push eax								; si la posición llega a estar vacía lo que hace es quitar la ficha de la posición 1
	call TraducirPosicion
	mov byte[eax], " "
	pop ecx									; se encarga de quitar la ficha del rival "comer"
	mov ebx, ecx
	and ecx, 0x00ff
	dec ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	mov eax, edx
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]							; asigna la ficha en la posición de llegada
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "x"

	xor ecx, ecx							; cuando "come" resta las fichas del jugador rival
	mov ecx, [fichasJugador1]
	dec ecx
	mov dword[fichasJugador1], ecx
	mov dword[jugador], 1
	jmp _start


comerDerJug0:
	mov eax, [Pos1]							; lo que compara es posición 1 con "x" para ver si hay una ficha para mover
	and eax, 0xffff
	push eax
	call TraducirPosicion
	cmp byte[eax], "x"
	jne volverPedirOpcion
	pop eax									; verifica si en la posición abajo a la der hay una "o" para comer
	mov ebx, eax
	xor ecx, ecx
	mov ecx, ebx
	and ecx, 0x00ff							; deja la letra sola, ejemplo convierte "B1" en "B"
	inc ecx
	mov edx, ebx
	and edx, 0xff00							; deja el num solo, ejemplo convierte "B1" en "1"
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	push edx
	mov eax, edx
	call TraducirPosicion
	cmp byte[eax], "o"
	jne volverPedirOpcion

	xor ecx, ecx							; si hay una ficha disponible para comer lo que hace es otro corrimiento para saber
	xor ebx, ebx							; si la posición de llegada, o sea la 2 es la misma para validar el movimiento
	pop ecx
	mov ebx, ecx
	and ecx, 0x00ff
	inc ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarComerDerJug0
	jmp volverPedirOpcion

realizarComerDerJug0:						; se encarga de verificar si la posición de llegada está vacía
	mov eax, [Pos2]
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]
	and eax, 0xffff
	push eax								; si la posición llega a estar vacía lo que hace es quitar la ficha de la posición 1
	call TraducirPosicion
	mov byte[eax], " "
	pop ecx									; se encarga de quitar la ficha del rival "comer"
	mov ebx, ecx
	and ecx, 0x00ff
	inc ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	inc edx
	shl edx, 8
	add edx, ecx
	mov eax, edx
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]							; asigna la ficha en la posición de llegada
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "x"

	xor ecx, ecx							; cuando "come" resta las fichas del jugador rival
	mov ecx, [fichasJugador1]
	dec ecx
	mov dword[fichasJugador1], ecx
	mov dword[jugador], 1
	jmp _start



Jugador1:
	xor ecx, ecx							; en ecx se ubica la opción del menú selecionada y respectivamente se va a esa funcionalidad
	mov ecx, [Menu]
	and ecx, 0xff							; se utiliza para quitar una "a" que siempre queda al frente cuando se lee
	cmp ecx, "0"
	je perdioJugador1
	cmp ecx, "1"
	je movimientoSimpleJug1
	cmp ecx, "2"
	je comerIzqJug1
	cmp ecx, "3"
	je comerDerJug1
	jmp mensajeEnDesarrollo



movimientoSimpleJug1:						; Mov dereccha sum Letra resta num
	mov eax, [Pos1]
	and eax, 0xffff
	push eax
	call TraducirPosicion
	cmp byte[eax], "o"
	jne volverPedirOpcion
	pop eax
	mov ebx, eax
	and eax, 0x00ff							; Letra 
	inc eax									; Suma letra 
	mov edx, ebx
	and edx, 0xff00							; Numero 
	shr edx, 8
	dec edx									; Dec num
	shl edx, 8
	add edx, eax							; Suma los 2 registros para volver a armar el mov ya con las sumas 
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx							; Ve si el mov es hacia la derecha
	je realizarCambioJug1
	xor ecx, ecx							; Mov Izq (Dec numero Dec letra)
	mov ecx, ebx
	and ecx, 0x00ff
	dec ecx									; Dec letra
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	dec edx									; Dec numero
	shl edx, 8
	add edx, ecx							; Suma los 2 registros para volver a armar el mov ya con las sumas 
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx							; compara el nuevo mov creado para ver si es el ingresado
	je realizarCambioJug1
	jmp volverPedirOpcion

realizarCambioJug1:
	mov eax, [Pos2]							; comprueba si la posición de llegada está vacía
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]							; realiza el movimiento, quita la ficha de la posición 1 y la pone en la posición 2
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "o"

	mov dword[jugador], 0
	jmp _start


comerIzqJug1:
	mov eax, [Pos1]							; lo que compara es posición 1 con "O" para ver si hay una ficha para mover
	and eax, 0xffff
	push eax
	call TraducirPosicion
	cmp byte[eax], "o"
	jne volverPedirOpcion
	pop eax									; verifica si en la posición arriba a la izq hay una "x" para comer
	mov ebx, eax
	xor ecx, ecx
	mov ecx, ebx
	and ecx, 0x00ff							; deja la letra sola, ejemplo convierte "B1" en "B"
	dec ecx
	mov edx, ebx
	and edx, 0xff00							; deja el num solo, ejemplo convierte "B1" en "1"
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	push edx
	mov eax, edx
	call TraducirPosicion
	cmp byte[eax], "x"
	jne volverPedirOpcion

	xor ecx, ecx							; si hay una ficha disponible para comer lo que hace es otro corrimiento para saber
	xor ebx, ebx							; si la posición de llegada, o sea la 2 es la misma para validar el movimiento
	pop ecx
	mov ebx, ecx
	and ecx, 0x00ff
	dec ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarComerIzqJug1
	jmp volverPedirOpcion

realizarComerIzqJug1:
	mov eax, [Pos2]							; se encarga de verificar si la posición de llegada está vacía
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]
	and eax, 0xffff
	push eax								; si la posición llega a estar vacía lo que hace es quitar la ficha de la posición 1
	call TraducirPosicion
	mov byte[eax], " "
	pop ecx									; se encarga de quitar la ficha del rival "comer"
	mov ebx, ecx
	and ecx, 0x00ff
	dec ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	mov eax, edx
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]							; asigna la ficha en la posición de llegada
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "o"

	xor ecx, ecx							; cuando "come" resta las fichas del jugador rival
	mov ecx, [fichasJugador0]
	dec ecx
	mov dword[fichasJugador0], ecx
	mov dword[jugador], 0
	jmp _start


comerDerJug1:
	mov eax, [Pos1]							; lo que compara es posición 1 con "o" para ver si hay una ficha para mover
	and eax, 0xffff
	push eax
	call TraducirPosicion
	cmp byte[eax], "o"
	jne volverPedirOpcion
	pop eax									; verifica si en la posición arriba a la der hay una "x" para comer
	mov ebx, eax
	xor ecx, ecx
	mov ecx, ebx
	and ecx, 0x00ff							; deja la letra sola, ejemplo convierte "B1" en "B"
	inc ecx
	mov edx, ebx
	and edx, 0xff00							; deja el num solo, ejemplo convierte "B1" en "1"
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	push edx
	mov eax, edx
	call TraducirPosicion
	cmp byte[eax], "x"
	jne volverPedirOpcion

	xor ecx, ecx							; si hay una ficha disponible para comer lo que hace es otro corrimiento para saber
	xor ebx, ebx							; si la posición de llegada, o sea la 2 es la misma para validar el movimiento
	pop ecx
	mov ebx, ecx
	and ecx, 0x00ff
	inc ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	mov ecx, [Pos2]
	and ecx, 0xffff
	cmp edx, ecx
	je realizarComerDerJug1
	jmp volverPedirOpcion

realizarComerDerJug1:						; se encarga de verificar si la posición de llegada está vacía
	mov eax, [Pos2]
	and eax, 0xffff
	call TraducirPosicion
	cmp byte[eax], " "
	jne volverPedirOpcion
	mov eax, [Pos1]
	and eax, 0xffff
	push eax								; si la posición llega a estar vacía lo que hace es quitar la ficha de la posición 1
	call TraducirPosicion
	mov byte[eax], " "
	pop ecx									; se encarga de quitar la ficha del rival "comer"
	mov ebx, ecx
	and ecx, 0x00ff
	inc ecx
	mov edx, ebx
	and edx, 0xff00
	shr edx, 8
	dec edx
	shl edx, 8
	add edx, ecx
	mov eax, edx
	call TraducirPosicion
	mov byte[eax], " "
	mov eax, [Pos2]							; asigna la ficha en la posición de llegada
	and eax, 0xffff
	call TraducirPosicion
	mov byte[eax], "o"

	xor ecx, ecx							; cuando "come" resta las fichas del jugador rival
	mov ecx, [fichasJugador0]
	dec ecx
	mov dword[fichasJugador0], ecx
	mov dword[jugador], 0
	jmp _start



mensajeEnDesarrollo:
	mov ecx, msgEnDesarrollo
	mov edx, msgEnDesarrollolen
	call DisplayText
	jmp _start

perdioJugador0:								; Cuando el jugador0 se queda sin fichas o se rinde desplega mensaje de gane del rival
	mov ecx, msgPerdioJugador0
	mov edx, msgPerdioJugador0len
	call DisplayText
	jmp salir

perdioJugador1:								; Cuando el jugador1 se queda sin fichas o se rinde desplega mensaje de gane del rival
	mov ecx, msgPerdioJugador1
	mov edx, msgPerdioJugador1len
	call DisplayText


salir:
	mov eax, sys_exit 		; llamada al sistema
	mov ebx, 0				; retorna 0
	int 80h


; ====================================================================
;  RUTINAS
; ====================================================================


; desplega algo en la salida estándar. debe "setearse" lo siguiente:
; ecx: el puntero al mensaje a desplegar
; edx: el largo del mensaje a desplegar
; modifica los registros eax y ebx
DisplayText:
    mov eax,sys_write       ; llamada al sistema
    mov ebx,stdout          ; desplegará en la salida estándar
    int 80H
    ret

lee_Posiciones:
	mov ebx, stdin 			; es la entrada estándar
	mov eax, sys_read 		; llamada al sistema para leer
	int 80h
	ret

limpiaReg:					; limpia todos los registros
	xor eax,eax
	xor ebx,ebx
	xor ecx,ecx
	xor	edx,edx
	ret

PrimeraPos:
	mov ecx,msg1			; Imprime el mensaje de digitar
	mov edx, msg1len
	call DisplayText
	
	mov ecx, Pos1
	mov edx, Pos1len		
	call lee_Posiciones		; Lee la primera letra del teclado
	mov eax, [Pos1]
	mov [Validar],eax		; Deja lo que leyo en validar 

	mov word[Cont], 0
	
	call limpiaReg
	jmp Validaciones
	
SegundaPos:
	mov ecx,msg2
	mov edx, msg2len
	call DisplayText		; imprime mensaje 

	mov ecx, Pos2
	mov edx, Pos2len
	call lee_Posiciones		; Lee la segunda Pos
	
	mov eax,[Pos2]
	mov [Validar],eax		; Deja lo que leyo en la variable validar
	
	xor ebx,ebx
	mov ebx,[Cont]
	add ebx,1				; Le suma uno para identificar que se va a validar la segunda pos
	mov [Cont],ebx			; Deja la suma en cont 
	
	call limpiaReg
	jmp Validaciones

Validaciones:
	
ValidarLetra:
	xor eax,eax
	mov eax, [Validar]
	and eax, 0x00ff			; Mult para quitar el num
		
ValidarAlta:				; Valida del A-D	
	cmp eax, "A"
	jb Erroneo
	cmp eax, "H"
	ja Erroneo
	jmp ValidarNum

		
ValidarNum:					; Valida el numero
	xor eax,eax
	mov eax, [Validar]
	and eax, 0xff00			; Mult para quitar la letra 
	
	cmp eax, 0x3100			; (Valor en ascii mas 2 ceros) los dos ceros quedan por la mult, No se como quitarlos  
	jb Erroneo
	cmp eax, 0x3900;
	ja Erroneo 
	jmp Bien

Erroneo:
	
	mov ecx, msg4
	mov edx, msg4len
	call DisplayText
	jmp PrimeraPos

Bien:
	mov ecx, msg3
	mov edx, msg3len
	call DisplayText
	xor ebx,ebx
	mov ebx,[Cont]			; Se mueve el cont para comparar 
	cmp ebx,1				; Compara para ver si la segunda pos se se valido
	jnz SegundaPos
	ret

volverPedirOpcion:			; desplaga mensaje de error y inicia de nuevo el proceso de pedir movimiento
	mov ecx, msg6
	mov edx, msg6len
	call DisplayText
	jmp _start

; Aqui se piden la opcion del menu, también se valida la entrada, y por último compara la entrada 
; Para ver a que opcion pertenece.
PedirOpcion:

	mov ecx, MenuMsg
	mov edx, MenuMsglen
	call DisplayText
	mov ecx, Menu 			; Variable donde va a quedar lo leido 
	mov edx, Menulen 		; Largo de la varible donde va a quedar lo leido
	call lee_Posiciones
	call ValidarMenu;
	ret

ValidarMenu:
	
	xor eax,eax
	mov eax, [Menu]
	and eax, 0xff			; Mult para quitar la letra 
	
	cmp eax, "0" 			; (Valor en ascii mas 2 ceros) los dos ceros quedan por la mult, No se como quitarlos  
	jb OpcionErronea
	cmp eax, "7";
	ja OpcionErronea 
	ret
	
OpcionErronea:
	mov ecx, msgOpcionErronea
	mov edx, msgOpcionErronealen
	call DisplayText
	jmp PedirOpcion


; Se encarga de traducir una cuadrícula en la dirección en memoria
; En el eax viene la cuadrícula que uno quiere traducir
; En el eax retorna la dirección exacta en memoria que se solicita
TraducirPosicion:

TraducirPosA1:
	cmp eax, "A1"			; compara la dirección que viene en eax
	jne TraducirPosA3		; si es diferente pasa a analizar si es igual a la siguiente direccion
	mov eax, row1			; si es igual asigna a eax el inicio de la primera fila porque hacemos referencia a 1 en este caso
	xor ebx, ebx			; limpia el registro ebx
	mov ebx, 0				; suma 0 porque en este caso hacemos referencia a la posición A que es la 0 en la fila
	add eax, ebx			; sumamos la fila con la posición y lo dejamos en eax
	ret

TraducirPosA3:				; La misma funcionalidad anterior con el resto de etiquetas y si lo ingresado en eax no corresponde
	cmp eax, "A3"			; a ninguna cuadrícula al final retorna un error y vuelva a iniciar el proceso
	jne TraducirPosA5
	mov eax, row3
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosA5:
	cmp eax, "A5"
	jne TraducirPosA7
	mov eax, row5
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosA7:
	cmp eax, "A7"
	jne TraducirPosB2
	mov eax, row7
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosB2:
	cmp eax, "B2"
	jne TraducirPosB4
	mov eax, row2
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosB4:
	cmp eax, "B4"
	jne TraducirPosB6
	mov eax, row4
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosB6:
	cmp eax, "B6"
	jne TraducirPosB8
	mov eax, row6
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosB8:
	cmp eax, "B8"
	jne TraducirPosC1
	mov eax, row8
	xor ebx, ebx
	mov ebx, 0
	add eax, ebx
	ret

TraducirPosC1:
	cmp eax, "C1"
	jne TraducirPosC3
	mov eax, row1
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosC3:
	cmp eax, "C3"
	jne TraducirPosC5
	mov eax, row3
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosC5:
	cmp eax, "C5"
	jne TraducirPosC7
	mov eax, row5
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosC7:
	cmp eax, "C7"
	jne TraducirPosD2
	mov eax, row7
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosD2:
	cmp eax, "D2"
	jne TraducirPosD4
	mov eax, row2
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosD4:
	cmp eax, "D4"
	jne TraducirPosD6
	mov eax, row4
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosD6:
	cmp eax, "D6"
	jne TraducirPosD8
	mov eax, row6
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosD8:
	cmp eax, "D8"
	jne TraducirPosE1
	mov eax, row8
	xor ebx, ebx
	mov ebx, 1
	add eax, ebx
	ret

TraducirPosE1:
	cmp eax, "E1"
	jne TraducirPosE3
	mov eax, row1
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosE3:
	cmp eax, "E3"
	jne TraducirPosE5
	mov eax, row3
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosE5:
	cmp eax, "E5"
	jne TraducirPosE7
	mov eax, row5
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosE7:
	cmp eax, "E7"
	jne TraducirPosF2
	mov eax, row7
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosF2:
	cmp eax, "F2"
	jne TraducirPosF4
	mov eax, row2
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosF4:
	cmp eax, "F4"
	jne TraducirPosF6
	mov eax, row4
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosF6:
	cmp eax, "F6"
	jne TraducirPosF8
	mov eax, row6
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosF8:
	cmp eax, "F8"
	jne TraducirPosG1
	mov eax, row8
	xor ebx, ebx
	mov ebx, 2
	add eax, ebx
	ret

TraducirPosG1:
	cmp eax, "G1"
	jne TraducirPosG3
	mov eax, row1
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosG3:
	cmp eax, "G3"
	jne TraducirPosG5
	mov eax, row3
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosG5:
	cmp eax, "G5"
	jne TraducirPosG7
	mov eax, row5
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosG7:
	cmp eax, "G7"
	jne TraducirPosH2
	mov eax, row7
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosH2:
	cmp eax, "H2"
	jne TraducirPosH4
	mov eax, row2
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosH4:
	cmp eax, "H4"
	jne TraducirPosH6
	mov eax, row4
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosH6:
	cmp eax, "H6"
	jne TraducirPosH8
	mov eax, row6
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosH8:
	cmp eax, "H8"
	jne TraducirPosError
	mov eax, row8
	xor ebx, ebx
	mov ebx, 3
	add eax, ebx
	ret

TraducirPosError:
	mov ecx, msg7
	mov edx, msg7len
	call DisplayText
	ret

; imprime en pantalla el tablero, con los bordes, letras y números para indicar posiciones
; no recibe argumentos y hace uso de otras rutinas
; deja los registros "sucios", hay que limpiarlos luego si se utilizan estas rutinas
imprimirTablero:
	mov ecx, letters 							; agrega a ecx la dirección del inicio de la hilera de letras
	mov edx, lettersLen 						; tamaño de la hilera
	call DisplayText
	mov ecx, borderLine 						; agrega a ecx la dirección del inicio del borde del tablero
	mov edx, borderLineLen 						; tamaño del borde
	call DisplayText
	call imprimirRow1							; llama a las rutinas que imprimen cada fila
	call imprimirRow2
	call imprimirRow3
	call imprimirRow4
	call imprimirRow5
	call imprimirRow6
	call imprimirRow7
	call imprimirRow8
	mov ecx, borderLine 						; agrega a ecx la dirección del inicio del borde del tablero
	mov edx, borderLineLen 						; tamaño del borde
	call DisplayText
	mov ecx, letters 							; agrega a ecx la dirección del inicio de la hilera de letras
	mov edx, lettersLen 						; tamaño de la hilera
	call DisplayText
	ret


; imprime en pantalla cada una de las filas para simular el tablero
; no recibe ningún argumento, solo toma los bytes definidos de las filas al inicio del programa
; deja los registros "sucios", hay que limpiarlos luego si se utilizan estas rutinas
imprimirRow1:
	mov edx, 0									; contador de bytes impresos de la fila 1
	push edx									; guarda el contador en la pila no perderlo
	mov ecx, numbers 							; agregar número de fila para ser impreso, en este caso el 1
	mov edx, 2									; imprimir 2 bytes, en este caso el número y un espacio
	call DisplayText 							; llamado a rutina que imprime
	imprimirRow1_1:
		mov ecx, square 						; imprime el cuadro antes del espacio de ficha
		mov edx, squaLen 						; tamaño del cuadro, 3 bytes en este caso
		Call DisplayText
		pop edx									; saca de la pila el contador
		cmp edx, 4								; compara el contador con 4, si es igual quiere decir que ya se imprimió toda la fila
		je terminarRow1							; salta a terminar la impresión de la fila
		mov ebx, row1							; mueve el puntero al inicio de la fila
		add ebx, edx							; suma el puntero más el contador para saber el byte imprimir
		mov ecx, ebx							; mueve ese puntero a ecx para imprimir
		inc edx									; incrementa el contador
		push edx								; guarda el contador en la pila
		mov edx, 1								; indica los byte a imprimir, en este caso 1 porque es el tamaño de las fichas de la fila
		call DisplayText
		mov ecx, square 						; imprime el cuadro entre las 2 fichas
		mov edx, squaLen 						; tamaño del cuadro, 3 bytes en este caso
		Call DisplayText
		mov ecx, square 						; imprime el cuadro después del espacio de la ficha
		mov edx, squaLen 						; tamaño del cuadro, 3 bytes en este caso
		call DisplayText
		jmp imprimirRow1_1
	terminarRow1:
		mov ebx, row1							; mueve el puntero al inicio de la fila
		add ebx, edx							; suma el puntero más el contador para saber el byte imprimir
		mov ecx, ebx							; mueve ese puntero a ecx para imprimir
		mov edx, 1								; indica los byte a imprimir, en este caso 1 porque es el tamaño del cambio de línea
		call DisplayText
		ret

imprimirRow2:									; La lógica de las siguientes filas (2, 3, 4, 5, 6, 7, 8) es la misma que la fila 1
	mov edx, 0									; solo variando el orden entre cada fila de los campos disponibles para simular el
	push edx									; tablero.
	mov ecx, numbers
	mov edx, 2
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow2_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow2
		mov ecx, square
		push edx
		mov edx, squaLen
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		mov ebx, row2
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		jmp imprimirRow2_1
	terminarRow2:
		mov ebx, row2
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow3:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 4
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow3_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow3
		mov ebx, row3
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		mov ecx, square
		mov edx, squaLen
		call DisplayText
		jmp imprimirRow3_1
	terminarRow3:
		mov ebx, row3
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow4:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 6
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow4_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow4
		mov ecx, square
		push edx
		mov edx, squaLen
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		mov ebx, row4
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		jmp imprimirRow4_1
	terminarRow4:
		mov ebx, row4
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow5:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 8
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow5_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow5
		mov ebx, row5
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		mov ecx, square
		mov edx, squaLen
		call DisplayText
		jmp imprimirRow5_1
	terminarRow5:
		mov ebx, row5
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow6:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 10
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow6_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow6
		mov ecx, square
		push edx
		mov edx, squaLen
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		mov ebx, row6
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		jmp imprimirRow6_1
	terminarRow6:
		mov ebx, row6
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow7:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 12
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow7_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow7
		mov ebx, row7
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		mov ecx, square
		mov edx, squaLen
		call DisplayText
		jmp imprimirRow7_1
	terminarRow7:
		mov ebx, row7
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret

imprimirRow8:
	mov edx, 0
	push edx
	mov ecx, numbers
	mov edx, 14
	add ecx, edx
	mov edx, 2
	call DisplayText
	imprimirRow8_1:
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		cmp edx, 4
		je terminarRow8
		mov ecx, square
		push edx
		mov edx, squaLen
		call DisplayText
		mov ecx, square
		mov edx, squaLen
		Call DisplayText
		pop edx
		mov ebx, row8
		add ebx, edx
		mov ecx, ebx
		inc edx
		push edx
		mov edx, 1
		call DisplayText
		jmp imprimirRow8_1
	terminarRow8:
		mov ebx, row8
		add ebx, edx
		mov ecx, ebx
		mov edx, 1
		call DisplayText
		ret