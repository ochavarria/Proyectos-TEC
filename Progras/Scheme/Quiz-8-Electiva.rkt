; Quiz #8   Tecnologico de Costa Rica
; Oscar Chavarria C.
; Pablo Navarro
; 23/05/17 
; Se definio una variable "graf" con los caminos ya hechos, ya que la funcion (prof-todas ) no se pudo implementar,
;(calcular-todos-valores *valores* graf)
;(mejor-mochila *valores* graf)

(define *articulos*
  '((d 4)
    (e 3)
    (r 5)))

(define *valores*
  '((d 1000)
    (e 700)
    (r 1200)))

(define graf '( ((r r ) 1)  ((e e r) 0) ((e e e) 2)((e e d) 1)))




;; Se obtiene una solución cuando
;; se ha llegado al nodo destino
;;
(define (solución? fin ruta)
 (equal? fin (car ruta)))

;; Una función que retorna los vecinos inmediatos
;;
(define (vecinos ele grafo)
 (apply append
        (map (lambda(x)
               (cond ( (equal? ele (car x))
                       (cadr x))
                     ( else
                       '())))
             grafo)))

;; Elimina los elementos que cumplen
;; una función fun, esta función debe
;; producir valores #f o #t
;;
(define (remove-if fun? lista)
  (apply append
         (map (lambda(x) (cond ((fun? x) '())
                            (else
                                lista)))
              (list x))))

;; Una función que retorna los vecinos inmediatos
;;
(define (vecinos ele grafo)
  (let ( (resultado (assoc ele grafo)))
    (cond ( (equal? resultado #f)
            #f)
          ( else
            (cadr resultado)))))

;; Una función que crea nuevas trayectorias
;; Si no puede crear nuevas trayectorias devuelve #f
;;
(define (extender ruta grafo)
  (remove-if null?
             (map (lambda(x)
                    (cond ( (miembro? x ruta)
                            '())
                          ( else
                            (cons x ruta))))
                  (vecinos (car ruta) grafo))))
;; Determina si un elemento es miembro de una lista
;; ele : un símbolo
;; lista: una lista lineal
;;
(define (miembro? ele lista)
  (ormap (lambda(x)(equal? x ele))
         lista))

;; Encuentra TODAS ruta entre ini y fin en un grafo
;; Utilizndo Profundidad Primero
;;
(define (prof-todas ini fin grafo)
  (prof-todas-aux (list (list ini)) fin grafo '()))

(define (prof-todas-aux rutas fin grafo total)
  (cond ( (null? rutas)
          (map reverse total))
        ( (solución? fin (car rutas))
          (prof-todas-aux (cdr rutas)
                          fin
                          grafo
                          (cons (car rutas) total)))
        ( else
          (prof-todas-aux (append (extender (car rutas) grafo)
                                  (cdr rutas))
                          fin
                          grafo
                          total))))



;Saca el valor de la lista valores
(define (devolverVal ele lista)
  (cond ( (equal? ele (caar lista))
                  (cadr(car lista)))
        (else (devolverVal ele (cdr lista)))
        ))
; Funcion  que calcula el valor de todos sub caminos
(define (calcular-valor-sublista valores sublist  )
  (apply + (map (lambda(x) (devolverVal x valores)) sublist)))

; Funcion  que calcula el valor de todos los caminos
(define (calcular-todos-valores valores caminos )
  (map (lambda(x) ( cons (car x) (list(calcular-valor-sublista valores (car x) ))))
       caminos))

;Funcion principal devuelve la mejor combinacion del grafo
(define (mejor-mochila valores caminos)
  (let caminoscalc ((caminoscalc (calcular-todos-valores valores caminos))) (mejor-mochila_aux (cdr caminoscalc) (car caminoscalc))
    ))


(define (mejor-mochila_aux caminoscalc max )
    (cond ( (null? caminoscalc)
          max)
          ((< (cadr max) (cadr(car caminoscalc )))
           (mejor-mochila_aux (cdr caminoscalc) (car caminoscalc)))
          (else (mejor-mochila_aux (cdr caminoscalc) max ))
  
  ))