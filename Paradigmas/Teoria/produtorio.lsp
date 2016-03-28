(defun produtorio (batata a b)
    (if (> a b)
    1
    (* (funcall batata a) (produtorio batata (1+ a) b))
    )
)

(defun f (x y)
(+ (* (quadrado (+1 (* (quadrado x) y))) x)
(* (+1 (* (quadrado x) y)) y)))

(let ((temp (1+ (* (quadrado x) y))))
(+ (* (quadrado temp) x))
)
