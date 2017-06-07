% voo(origem,destino,codigo,partida,(dia_chegada,horario_chegada),
% numero_de_escalas, companhia,[dias]).
voo(sao_paulo, mexico, a6, 17, 00, 23, 00, 0, gol, [segunda, terca, sabado]).
voo(sao_paulo, mexico, a7, 17, 00, 22, 30, 0, tam, [segunda, quarta, sexta]).
voo(sao_paulo, mexico, a8, 19, 20, 00, 30, 0, azul, [terca, quinta, domingo]).
voo(sao_paulo, nova_york, a84, 16, 00 , 22, 00, 0, tam, [terca, quarta, sexta]).
voo(sao_paulo, lisboa, a32, 14, 00, 20, 30, 0, azul, [quarta, sexta, sababo]).
voo(sao_paulo, madrid, a68, 20, 30, 03, 00, 0, tam, [sexta, sabado, domingo]).
voo(sao_paulo, londres, a54, 21, 00, 05, 00, 0, gol, [segunda, sexta, domingo]).
voo(sao_paulo, paris, a48, 00, 00, 06, 30, 0, azul, [terca, quinta, sexta]).
voo(mexico, nova_york, b66, 15, 00, 17, 00, 0, tam, [quarta, quinta, sexta, sabado]).
voo(mexico, madrid, b65, 20, 00, 01, 30, 0, azul, [segunda, quarta, quinta]).
voo(nova_york, londres, c64, 13, 00, 17,00, 0, gol, [terca, quinta, sabado]).
voo(londres, lisboa, d56, 12, 00, 14, 00, 0, tam, [segunda, terca, sexta]).
voo(londres, paris, d65, 15, 00, 16, 30, 0, azul, [terca, quinta, sababdo]).
voo(londres, estocolmo, d84, 12, 30, 15, 00, 0, tam, [segunda, quarta, domingo]).
voo(madrid, paris, e49, 14, 00, 15, 30, 0, gol, [terca, quarta, quinta, sabado]).
voo(madrid, roma, e98, 16, 00, 17, 00, 0, tam, [quarta, sexta, sabado, domingo]).
voo(madrid, frankfurt, e82, 17, 00, 18, 30, 0, azul, [segunda, terca, sexta, domingo]).
voo(frankfurt, estocolmo, d65, 15, 00, 16, 30, 0, azul, [segunda, quarta, sexta]).
voo(frankfurt, roma, d15, 12, 00, 14, 00, 0, [terca, quinta, sexta, sabado, domingo]).

maior(X,Y,X) :- X>Y, !.
maior(_,Y,Y).

menor(X,Y,X) :- X<Y, !.
menor(_,Y,Y).

pertence_lista(X,[X|_]).
pertence_lista(X,[_|Cauda]) :- pertence_lista(X,Cauda).

voo_direto(Origem, Destino, Companhia, Dia, Horario_h, Horario_min) :-	% funcao verifica se existe algum voo entre
	% as cidades origem e destino em que o numero de escalas é 0
	voo(Origem, Destino, _, Horario_h, Horario_min, _, _, 0, Companhia, Lista),
        pertence_lista(Dia, Lista).

roteiro(Origem, Destino, Codigo) :- voo(Origem, Destino, Codigo, _, _, _, _, _, _).
roteiro(Origem, Destino, Codigo) :- voo(Origem, Conexao, Codigo, _, _, _, _, _, _),
		roteiro(Conexao,Destino, Codigo).

filtra_voo_dia_semana(Origem, Destino, DiaSemana, HorarioSaida_h,	% funcao verifica se existe algum voo direto
		      % entre as cidades origem e destino e mostra os horarios de saida e chegada, o dia da semana e a companhia
HorarioSaida_min, HorarioChegada_h, HorarioChegada_min, Companhia) :- voo(Origem, Destino, _, HorarioSaida_h,
HorarioSaida_min, HorarioChegada_h, HorarioChegada_min, 0, Companhia, Lista), pertence_lista(DiaSemana, Lista).

duracao(Hora_i, Min_i, Hora_f, Min_f, Dura_h, Dura_m) :-	Hora_f < Hora_i,
																													Min_f < Min_i,

																													Dura_h is Hora_f + 23 - Hora_i,
																													Dura_m is Min_f + 60 - Min_i,
																													!.
duracao(Hora_i, Min_i, Hora_f, Min_f, Dura_h, Dura_m) :-	Hora_f < Hora_i,
																													
																													Dura_h is Hora_f + 24 - Hora_i,
																													Dura_m is Min_f - Min_i, !.
duracao(Hora_i, Min_i, Hora_f, Min_f, Dura_h, Dura_m) :-	Min_f < Min_i,

																													Dura_h is Hora_f - 1 - Hora_i,
																													Dura_m is Min_f + 60 - Min_i, !.
duracao(Hora_i, Min_i, Hora_f, Min_f, Dura_h, Dura_m) :-	Dura_h is Hora_f - Hora_i,
																													Dura_m is Min_f - Min_i.


menorDuracao(Origem, Destino, Dia, HorarioSaida_h, HorarioSaida_min, HorarioChegada_h, HorarioChegada_min, Companhia) :-
				filtra_voo_dia_semana(Origem, Destino, Dia, HorarioSaida_h, HorarioSaida_min,
						      HorarioChegada_h, HorarioChegada_min, Companhia).

menordalista(M,[M|[]]).
menordalista(M1,[Head|Tail]):- menordalista(M,Tail),
	menor(M,Head, M1).
