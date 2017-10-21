(define mapa
  '( (0 1 2 3 4 5 6 7 8 9 10)
     (1 r - - - - - x x - -)
     (2 - - - - - - x x - -)
     (3 - - x x - - - - - -)
     (4 - - x x - - - - - -)
     (5 - - - - - - - - - f)))

;Funcion que saca el punto inicial y final 
(define (PuntosClave mat)
  (append (list(buscar 'r (cdr mat) '() 1)) (list(buscar 'f (cdr mat) '() 1))))
                     
;Reccore filas
(define (buscar ele mat rest nfil)
  (cond ( (null? mat )
           rest)
        (else
         (buscar ele (cdr mat) (append rest (buscaraux ele nfil 0 (car mat))) (+ 1 nfil )))))
                     
;Recorre Columnas
(define (buscaraux ele nfil ncol fila)
  (cond ( (null? fila)
           '())
        ( (equal? ele (car fila))
          (list nfil ncol))
          ( else
          (buscaraux ele  nfil (+ 1 ncol) (cdr fila )))))

;Funcion que saca los posibles vecinos
(define (vecinos lista mat )
  ( vecinosaux lista '() mat) )

(define (vecinosaux lista vecinos mat )
  ( cond ( (null? lista )
         vecinos)
         (else
          (vecinosaux (cdr lista) ( append  vecinos
                                           (list (buscarX mat (validarvecinos1 (generarvecinos (car lista )) (largo mat) (largo (car mat ))))))mat))))

;Generar Vecinos
(define (generarvecinos punC)
  (append  
           (list(list(+ (car punC) 1 ) (cadr punC))) ;Abjo
           (list(list(- (car punC) 1 ) (cadr punC))) ;Arriba 
           
           (list(list(car punC) (+ (cadr punC) 1 ))) ;derecha 
           (list(list(car punC) (- (cadr punC) 1 ))) ;izquierda
           
           (list(list(+ (car punC) 1 ) (+ (cadr punC) 1 ))) ;D.Abj Dere
           (list(list(+ (car punC) 1 ) (- (cadr punC) 1 ))) ;D.Abj Izq

           (list(list(- (car punC) 1 ) (+ (cadr punC) 1 ))) ;D.Arr Dere
           (list(list(- (car punC) 1 ) (- (cadr punC) 1 ))) ;D.Arr Izq
           ))

;Largo de una lista
(define (largo lista)
  (largo-aux lista 0))

(define (largo-aux lista resultado)
  (cond ( (null? lista)
          resultado)
        ( else
          (largo-aux (cdr lista)
                     (+ 1 resultado)))))

;busca los vecinos validos 1 
(define (validarvecinos1 lista lenfil lencol )
    (apply append
           (map (lambda(x) (cond ((equal? (car x ) 0 ) '())
                                 ((equal? (car x ) lenfil ) '())
                                 ((equal? (cadr x ) 0 ) '())
                                 ((equal? (cadr x ) lencol ) '())
                                 (else     (list x))))
                lista)))

;buscar vecinos validos 2 (que en la pos no sea una x) 
(define (buscarX mat vecinos)
 (apply append(map (lambda(x) (cond ( (equal? (buscarXaux 'x  mat x ) #t ) '())
                       (else
                        (list x))))
                vecinos)))
                     
;Reccore filas
(define (buscarXaux ele mat vecino )
  (cond ( (equal? (car vecino) (caar mat))
          (buscarXaux2 ele (car mat) vecino 0 ))
        (else
         (buscarXaux ele (cdr mat) vecino ))))

;Recorre columnas
(define (buscarXaux2 ele fila vecino cont )
  (cond ( (equal? cont (cadr vecino ))
          (verificar ele (car fila )))
        (else
         (buscarXaux2 ele (cdr fila) vecino (+ 1 cont )))))

; Verifica si hay una x en la posicion 
(define (verificar ele1 ele2 )
  (cond ( (equal? ele1 ele2) #t)
        (else
         #f)))

