(defun ultimo (lista)
    (if (cdr lista)
      (ultimo (cdr lista))
      (car lista)
    )
)