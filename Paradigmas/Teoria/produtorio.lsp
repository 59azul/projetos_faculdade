(defun produtorio (batata a b)
    (if (> a b)
    1
    (* (funcall batata a) (produtorio batata (1+ a) b))
    )
)
