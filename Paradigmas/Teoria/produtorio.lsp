(defun produtorio (function batata) a b
    (if (> b a)
    (* (funcall batata a) (produtorio batata (1+ a) b))
    (* a b)
    )
)
