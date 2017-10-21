( define ( natural lista)
   (natural-aux (cdr lista) (car lista) '() '()))

( define ( natural-aux lista elemento res res-parcial)
   (cond ( (null? lista)
           (reverse (cons (reverse (cons elemento res-parcial)) res)))
           ( (<= elemento (car lista))
           (natural-aux (cdr lista) (car lista) res (cons elemento res-parcial)))
           (else 
            (natural-aux (cdr lista) (car lista) (cons (reverse (cons elemento res-parcial)) res) '()))))
            

;Funcion mezclar  
(define (mezclar lista-uno lista-dos)
  (mezclar-aux lista-uno lista-dos '()))

(define (mezclar-aux lista-uno lista-dos res)
  (cond ( (null? lista-uno)
          (append res lista-dos))
        ( ( null? lista-dos)
          (append res lista-uno))
        ( (< (car lista-uno) (car lista-dos))
          (mezclar-aux (cdr lista-uno) lista-dos (append res (cons (car lista-uno) '()))))
        (else
         (mezclar-aux lista-uno (cdr lista-dos) (append res (cons (car lista-dos) '()))))))

;Funcion Merge-sort
(define (merge-sort lista)
  (let (( lista-natural (natural lista)))
    (merge-sort-aux (car lista-natural) (cdr lista-natural))))
   
(define (merge-sort-aux res lista-natural)
  (cond ( (null? lista-natural)
          res)
        (else
        (merge-sort-aux (mezclar res (car lista-natural)) (cdr lista-natural)))))