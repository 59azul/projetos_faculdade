um_dos_pais(paula, roberto).
um_dos_pais(tomas, roberto).
um_dos_pais(tomas, luisa).
um_dos_pais(roberto, ana).
um_dos_pais(roberto, patricia).
um_dos_pais(patricia, joao).

mulher(paula).
mulher(luisa).
mulher(ana).
mulher(patricia).
homem(tomas).
homem(roberto).
homem(joao).

um_dos_filhos(Y, X)  :- um_dos_pais(X, Y).

mae(X, Y)  :- 		% X é mãe de Y se
   um_dos_pais(X, Y),		% X é um_dos_pais de Y e
   mulher(X).			% X é mulher

um_dos_avos(X, Z)  :-	% X é um_dos_avos de Z se
   um_dos_pais(X, Y), 		% X é um_dos_pais de Y e
   um_dos_pais(Y, Z).		% Y é um_dos_pais de Z

irma(X, Y)  :-	% X é irmã de Y se
   um_dos_pais(Z, X),
   um_dos_pais(Z, Y), 	% X e Y tem um pai em comum e
   mulher(X),		% X é mulher e
   diferente(X, Y).	% X e Y são diferentes

diferente(X,Y):- X \= Y.

feliz(X) :-
    um_dos_pais(X, Y). % Alguém é feliz se tem um filho(a)

tem_dois_filhos(X) :-
    um_dos_pais(X, Y), % Se X tem um filho Y
    um_dos_pais(X, Z), % E X tem um filho Z
    diferente(Y, Z), % Z e Y são diferentes
    homem(Y), % Se Y for homem
    homem(Z). % E Z também for homem

tia(X, Y) :-
    um_dos_pais(Z, Y),
    irma(X, Z).

antepassado(X,Z) :-
    um_dos_pais(X,Z).
antepassado(X, Z) :-
    um_dos_pais(X,Y),
    antepassado(Y,Z).

descendente(X,Y) :-
    antepassado(Y,X).
