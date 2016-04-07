(defun n-esimo (lista n)
    (if (zerop n)
        (car lista)
        (n-esimo (rest lista) (1- n))
    )

)
