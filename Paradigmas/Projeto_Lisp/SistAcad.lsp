; (car (cdr (car bd))) <- lista de alunos em uma disciplina
; (cdr (cdr (car bd))) <- lista de professores vinculados a uma disciplina


(defun matricular (alunos disciplinas bd)
	(if (null bd)
		(if (null (car disciplinas))	; Se o bd estiver vazio, essa seção do código será executada
			bd
			(if (null (car alunos))
				bd
				(matricular alunos (cdr disciplinas) (cons (cons (car disciplinas) 	; Se o bd estiver vazio, um novo bd será construído 
				(cons (append (insere-grupo alunos bd)) nil) ) nil) ) 				; com os alunos e disciplinas inseridos
			)
		)
		
		(if (null (car disciplinas))	; Se o bd não estiver vazio, essa seção do código será executada
			bd
			(if (null (car alunos))
				bd
				(if (procura (car (car bd)) disciplinas)
					(cons (cons (car (car bd)) (cons (append (insere-grupo alunos (car (cdr (car bd))))) (append (cdr (cdr (car bd)))) ) ) 
						(matricular alunos (tira_lista (car (car bd)) disciplina) (cdr bd))
					)
					(cons (append (car bd)) (matricular alunos disciplinas (cdr bd)))
				)
			)
		)
	)
)

(defun insere-lista (elemento lista)
	(if (null lista)
		(cons elemento nil)
		(if (equal elemento (car lista))
			lista
			(cons (car lista) (insere-lista elemento (cdr lista)) )			
		)
	)
)

(defun insere-grupo (grupo bd)
	(if (null (car grupo))
		bd
		(insere-grupo (cdr grupo) (insere-lista (car grupo) bd))
	)
)

(defun tira-grupo (grupo bd)
	(if (null (car grupo))
		bd
		(tira-grupo (cdr grupo) (tira_lista (car grupo) bd))
	)
)

(defun procura (nome lista)
	(if (null lista)
		nil
		(if (equal nome (car lista))
			T
			(procura nome (cdr lista))
		)
	)
)

(defun tira_lista (nome lista)
	(if (null lista)
		nil
		(if (equal nome (car lista))
			(tira_lista nome (cdr lista))
			(cons (car lista) (tira_lista nome (cdr lista)))
		)
	)
)


(defun cancelar-matricula (alunos disciplinas bd)
	(if (null bd)
		bd
		(if (null (car disciplinas))
			bd
			(if (null (car alunos))
				nil
				(if (procura (car (car bd)) disciplinas)
					(cons (cons (car (car bd)) (cons (append (tira-grupo alunos (car (cdr (car bd))))) (append (cdr (cdr (car bd)))) ) ) 
								(cancelar-matricula alunos (tira_lista (car (car bd)) disciplinas) (cdr bd))
					)
					
					(cons (append (car bd)) (cancelar-matricula alunos disciplinas (cdr bd)))
				)
			)
		)
	)
)

(defun vincular (professores disciplinas bd)
	(if (null bd)
		(if (null (car disciplinas))
			bd
			(if (null (car professores))
				bd
				(vincular professores (cdr disciplinas) (cons (cons (car disciplinas) 
					(cons nil (append (insere-grupo professores bd)))) nil) 
				)
			)
		)
		
		(if (null (car disciplinas))
			bd
			(if (null (car professores))
				bd
				(if (procura (car (car bd)) disciplinas)
					(cons (cons (car (car bd)) (cons (append (car (cdr (car bd)))) 
						(append (insere-grupo professores (cdr (cdr (car bd))) ) )))
						(vincular professores (tira_lista (car (car bd)) disciplinas) (cdr bd))
					)
					
					(cons (append (car bd)) (vincular professores disciplinas (cdr bd)))
				)
			)
		)
	)
)

(defun remover-vinculo (professores disciplinas bd)
	(if (null bd)
		bd
		(if (null (car disciplinas))
			bd
			(if (null (car professores))
				nil
				(if (procura (car (car bd)) disciplinas)
					(cons (cons (car (car bd)) (cons (append (car (cdr (car bd)))) (append (tira-grupo professores (cdr (cdr (car bd))))) ) ) 
								(remover-vinculo professores (tira_lista (car (car bd)) disciplinas) (cdr bd))
					)
					
					(cons (append (car bd)) (remover-vinculo professores disciplinas (cdr bd)))
				)
			)
		)
	)
)

(defun alunos? (bd)
	(if (null bd)
		nil
		(insere-grupo (car (cdr (car bd))) (alunos? (cdr bd)))
	)
)

(defun professores? (bd)
	(if (null bd)
		nil
		(insere-grupo (cdr (cdr (car bd))) (professores? (cdr bd)))
	)
)

(defun disciplinas? (bd)
	(if (null bd)
		nil
		(cons (car (car bd)) (disciplinas? (cdr bd)))
	)
)

(defun matriculados? (disciplina bd)
	(if (null bd)
		nil
		(if (equal disciplina (car (car bd)) )
			(append (car (cdr (car bd))) )
			(matriculados? disciplina (cdr bd))
		)
	)
)

(defun vinculados? (disciplina bd)
	(if (null bd)
		nil
		(if (equal disciplina (car (car bd)) )
			(append (cdr (cdr (car bd))) )
			(vinculados? disciplina (cdr bd))
		)
	)
)

(defun cursa? (aluno db)
	(if (null bd)
		nil
		(if (procura aluno (car (cdr (car bd))) )
			(cons (car (car bd)) (cursa? aluno (cdr bd)))
			(cursa? aluno (cdr bd))
		)
	)
)

(defun ministra? (professor db)
	(if (null bd)
		nil
		(if (procura professor (cdr (cdr (car bd))) )
			(cons (car (car bd)) (ministra? professor (cdr bd)))
			(ministra? professor (cdr bd))
		)
	)
)
