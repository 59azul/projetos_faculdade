% voo(origem,destino,codigo,partida,(dia_chegada,horario_chegada),
% numero_de_escalas, companhia,[dias]).
voo(sao_paulo, mexico, a6, 1700, (mesmo, 2300), 0, gol, [segunda, terca, sabado]).
voo(sao_paulo, nova_york, a84, 1600 , (mesmo, 2200), 1, tam, [terca, quarta, sexta]).
voo(sao_paulo, lisboa, a32, 1400, (mesmo, 2030), 3, azul, [quarta, sexta, sababo]).
voo(sao_paulo, madrid, a68, 2030, (proximo, 0300), 1, tam, [sexta, sabado, domingo]).
voo(sao_paulo, londres, a54, 2100, (proximo, 0500), 1, gol, [segunda, sexta, domingo]).
voo(sao_paulo, paris, a48, 0000, (mesmo, 0630), 2, azul, [terca, quinta, sexta]).
voo(mexico, nova_york, b66, 1500, (mesmo, 1700), 0, tam, [quarta, quinta, sexta, sabado]).
voo(mexico, madrid, b65, 2000, (proximo, 0130), 0, azul, [segunda, quarta, quinta]).
voo(nova_york, londres, c64, 1300, (mesmo, 1700), 0, gol, [terca, quinta, sabado]).
voo(londres, lisboa, d56, 1200, (mesmo, 1400), 0, tam, [segunda, terca, sexta]).
voo(londres, paris, d65, 1500, (mesmo, 1630), 0, azul, [terca, quinta, sababdo]).
voo(londres, estocolmo, d84, 1230, (mesmo, 1500), 0, tam, [segunda, quarta, domingo]).
voo(madrid, paris, e49, 1400, (mesmo, 1530), 0, gol, [terca, quarta, quinta, sabado]).
voo(madrid, roma, e98, 1600, (mesmo, 1700), 0, tam, [quarta, sexta, sabado, domingo]).
voo(madrid, frankfurt, e82, 1700, (mesmo, 1830), 0, azul, [segunda, terca, sexta, domingo]).
voo(frankfurt, estocolmo, d65, 1500, (mesmo, 1630), 0, azul, [segunda, quarta, sexta]).
voo(frankfurt, roma, d15, 1200, (mesmo, 1400), 0, [terca, quinta, sexta, sabado, domingo]).

maior(X,Y,X) :- X>Y, !.
maior(_,Y,Y).

menor(X,Y,X) :- X<Y, !.
menor(_,Y,Y).

pertence_lista(X,[X|_]).
pertence_lista(X,[_|Cauda]) :- pertence_lista(X,Cauda).

voo_direto(Origem, Destino, Companhia, Dia, Horario) :-
	voo(Origem, Destino, _, Horario, (_, _), 0, Companhia, Lista),
        pertence_lista(Dia, Lista).

roteiro(Origem, Destino) :- voo(Origem, Destino, _, _, _, _, _, _).
roteiro(Origem, Destino) :- voo(Origem, Conexao, _, _, _, _, _, _),
		roteiro(Conexao,Destino).

duracao(HorarioSaida, HorarioChegada, DiaChegada, Total) :-
	DiaChegada = mesmo,
	Total is HorarioChegada-HorarioSaida,
	!.
duracao(HorarioSaida, HorarioChegada, DiaChegada, Total) :-
	DiaChegada = proximo,
	Aux is HorarioChegada+2400,
	Total is Aux-HorarioSaida.

menordalista(M,[M|[]]).
menordalista(M1,[Head|Tail]):- menordalista(M,Tail),
	menor(M,Head, M1).

%menorDuracao(Origem, Destino, DiaSaida, HorarioSaida, HorarioChegada, Companhia) :-
%	voo_direto(Origem, Destino, Companhia, DiaSaida, HorarioSaida).
	%setof(Horarios, ).
