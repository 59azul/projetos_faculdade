% v�o(origem,destino,c�digo,partida,(dia_chegada,horario_chegada),
% n�mero_de_escalas, companhia,[dias]).
voo(sao_paulo, mexico, a6, 17:00, (mesmo, 23:00), 0, gol, [segunda, terca, sabado]).
voo(sao_paulo, nova_york, a84, 16:00 , (mesmo, 22:00), 1, tam, [terca, quarta, sexta]).
voo(sao_paulo, lisboa, a32, 14:00, (mesmo, 20:30), 3, azul, [quarta, sexta, sababo]).
voo(sao_paulo, madrid, a68, 20:30, (proximo, 03:00), 1, tam, [sexta, sabado, domingo]).
voo(sao_paulo, londres, a54, 21:00, (proximo, 05:00), 1, gol, [segunda, sexta, domingo]).
voo(sao_paulo, paris, a48, 00:00, (mesmo, 06:30), 2, azul, [terca, quinta, sexta]).
voo(mexico, nova_york, b66, 15:00, (mesmo, 17:00), 0, tam, [quarta, quinta, sexta, sabado]).
voo(mexico, madrid, b65, 20:00, (proximo, 01:30), 0, azul, [segunda, quarta, quinta]).
voo(nova_york, londres, c64, 13:00, (mesmo, 17:00), 0, gol, [terca, quinta, sabado]).
voo(londres, lisboa, d56, 12:00, (mesmo, 14:00), 0, tam, [segunda, terca, sexta]).
voo(londres, paris, d65, 15:00, (mesmo, 16:30), 0, azul, [terca, quinta, sababdo]).
voo(londres, estocolmo, d84, 12:30, (mesmo, 15:00), 0, tam, [segunda, quarta, domingo]).
voo(madrid, paris, e49, 14:00, (mesmo, 15:30), 0, gol, [terca, quarta, quinta, sabado]).
voo(madrid, roma, e98, 16:00, (mesmo, 17:00), 0, tam, [quarta, sexta, sabado, domingo]).
voo(madrid, frankfurt, e82, 17:00, (mesmo, 18:30), 0, azul, [segunda, terca, sexta, domingo]).
voo(frankfurt, estocolmo, d65, 15:00, (mesmo, 16:30), 0, azul, [segunda, quarta, sexta]).
voo(frankfurt, roma, d15, 12:00, (mesmo, 14:00), 0, [terca, quinta, sexta, sabado, domingo]).

maior(X,Y,X) :- X>Y, !.
maior(X,Y,Y).

menor(X,Y,X) :- X<Y, !.
menor(X,Y,Y).

pertence_lista(X,[X|Cauda]).
pertence_lista(X,[Cabeca|Cauda]) :- pertence_lista(X,Cauda).

voo_direto(Origem, Destino, Companhia, Dia, Horario) :-
	voo(Origem, Destino, _, Horario, (_, _), 0, Companhia, Lista),
        pertence_lista(Dia, Lista).

roteiro(Origem, Destino) :- voo(Origem, Destino, _, _, _, _, _, _).
roteiro(Origem, Destino) :- voo(Origem, Conexao, _, _, _, _, _, _),
		roteiro(Conexao,Destino).

%duracao(HorarioSaida, HorarioChegada, Total) :-
%	menor(HorarioSaida, HorarioChegada, HorarioSaida),


%menorDaLista(0, []).
%menorDaLista(X, [Head|Tail]) :-
%	menor(X, Head, Y),
%	menorDaLista(Y, Tail).

%menorDuracao(Origem, Destino, DiaSaida, HorarioSaida, HorarioChegada, Companhia) :-
%	voo_direto(Origem, Destino, Companhia, DiaSaida, HorarioSaida).
	%setof(Horarios, ).
