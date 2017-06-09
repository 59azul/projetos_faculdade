% voo(origem, destino, codigo, partida, (dia_chegada, horario_chegada),
% numero_de_escalas,  companhia, [dias]).
%Sao_Paulo
voo(sao_paulo, mexico, a01, 19:30, 23:30, 0, gol, [quarta]).
voo(sao_paulo, nova_york, a02, 17:15, 01:30, 0, tam, [segunda, terca, sabado]).
voo(sao_paulo, lisboa, a03, 21:30, 03:30, 0,  azul, [sexta, sabado]).
voo(sao_paulo, madrid, a04, 08:15, 12:30, 0,  azul, [quarta, sexta]).
voo(sao_paulo, londres, a05, 16:30, 23:30, 0, tam, [domingo, quinta, sexta, sabado]).
voo(sao_paulo, paris, a06, 21:45, 04:50, 0,  azul, [segunda, sabado]).

%Mexico
voo(mexico, nova_york, b01, 14:00, 19:30, 0, gol, [domingo, quarta, sexta]).
voo(mexico, paris, b02, 12:00, 23:30, 0, tam, [terca, sabado, domingo]).
voo(mexico, sao_paulo, b03, 21:30, 04:10, 0,  azul, [quarta, quinta]).

%Nova_York
voo(nova_york, londres, c01, 20:15, 00:30, 0,  azul, [domingo, segunda, terca, sexta, sabado]).
voo(nova_york, sao_paulo, c02, 21:45, 09:10, 0, tam, [segunda, quinta]).
voo(nova_york, mexico, c03, 10:30, 23:00, 0, gol, [domingo, sabado]).

%Londres
voo(londres, lisboa, d01, 05:10, 8:30, 0, gol, [quinta, sexta]).
voo(londres, paris, d02, 15:00, 17:50, 0, tam, [domingo, segunda, sexta, sabado]).
voo(londres, estocolmo, d03, 14:30, 16:00, 0, tam, [segunda, sexta]).
voo(londres, nova_york, d04, 19:20, 02:40, 0,  azul, [segunda, sexta, sabado]).
voo(londres, sao_paulo, d05, 10:30, 00:10, 0, gol, [segunda]).

%Lisboa
voo(lisboa, londres, e01, 08:30, 16:50, 0,  azul, [terca, quinta]).
voo(lisboa, sao_paulo, e02, 15:55, 01:20, 0, tam, [quinta, sabado]).

%Paris
voo(paris, londres, f01, 10:00, 16:30, 0, tam, [quarta, quinta]).
voo(paris, sao_paulo, f02, 00:30, 19:20, 0, tam, [domingo, segunda, sexta, sabado]).
voo(paris, madrid, f03, 23:30, 02:45, 0,  azul, [domingo, sexta]).

%Estocolmo
voo(estocolmo, londres, g01, 07:15, 13:50, 0, tam, [segunda, terca, quinta]).
voo(estocolmo, frankfurt, g02, 20:40, 03:30, 0, gol, [quinta, sabado]).

%Roma
voo(roma, madrid, h01, 18:30, 23:300, 0,  azul, [segunda, quarta]).
voo(roma, frankfurt, h02, 23:55, 06:50, 0, gol, [quinta, sabado]).

%Madrid
voo(madrid, paris, i01, 15:35, 18:30, 0,  azul, [quinta, sexta]).
voo(madrid, roma, i02, 15:00, 14:50, 0, tam, [segunda, sexta, sabado]).
voo(madrid, frankfurt, i03, 17:30, 23:10, 0, gol, [domingo, sexta, sabado]).
voo(madrid, sao_paulo, i04, 05:00, 20:30, 0,  azul, [quintan, sabado]).
voo(madrid, mexico, i05, 19:50, 02:40, 0, tam, [domingo, terca, quinta]).

%Frankfurt
voo(frankfurt, estocolmo, j01, 10:35, 16:30, 0, tam, [quinta, sexta, sabado]).
voo(frankfurt, roma, j02, 17:30, 23:10, 0,  azul, [segunda, sexta, sabado]).
voo(frankfurt, madrid, j03, 07:30, 13:25, 0, gol, [terca, sabado]).

maior(X, Y, X) :- X>Y,  !.
maior(_, Y, Y).

menor(X, Y, X) :- X<Y,  !.
menor(_, Y, Y).

acrescentarFim(X, [], [X]).
acrescentarFim(X, [Y|L1], [Y|L2]):- acrescentarFim(X, L1, L2).

pertence_lista(X, [X|_]).
pertence_lista(X, [_|Cauda]) :- pertence_lista(X, Cauda).

voo_direto(Origem,  Destino,  Companhia,  Dia,  Horario) :-
	voo(Origem,  Destino,  _,  Horario,  _,  0,  Companhia,  Lista),
	pertence_lista(Dia,  Lista).

roteiro(Origem,  Destino,  ListaCodigos) :-
	voo(Origem,  Destino,  Codigo,  _,  _,  _,  _,  _),
	acrescentarFim(Codigo, [], ListaCodigos).
roteiro(Origem,  Destino,  ListaCodigos) :-
	voo(Conexao,  Destino,  Codigo,  _,  _,  _,  _,  _),
	roteiro(Origem, Conexao,  Lista),
	acrescentarFim(Codigo, Lista, ListaCodigos).

filtra_voo_dia_semana(Origem,  Destino,  DiaSemana,  HorarioSaida,  HorarioChegada,  Companhia) :-
	voo(Origem,  Destino,  _,  HorarioSaida, HorarioChegada,  0,  Companhia,  Lista),
	pertence_lista(DiaSemana,  Lista).

duracao(Hora_i:Min_i,  Hora_f:Min_f,  Dura_h:Dura_m) :-
	Hora_f < Hora_i,
	Min_f < Min_i,
	Dura_h is Hora_f + 23 - Hora_i,
	Dura_m is Min_f + 60 - Min_i,
	!.
duracao(Hora_i:Min_i,  Hora_f:Min_f,  Dura_h:Dura_m) :-
	Hora_f < Hora_i,
	Dura_h is Hora_f + 24 - Hora_i,
	Dura_m is Min_f - Min_i,  !.
duracao(Hora_i:Min_i,  Hora_f:Min_f,  Dura_h:Dura_m) :-
	Min_f < Min_i,
	Dura_h is Hora_f - 1 - Hora_i,
	Dura_m is Min_f + 60 - Min_i,  !.
duracao(Hora_i:Min_i,  Hora_f:Min_f,  Dura_h:Dura_m) :-
	Dura_h is Hora_f - Hora_i,
	Dura_m is Min_f - Min_i.


menorDuracao(Origem,  Destino,  Dia,  HorarioSaida,  HorarioChegada,  Companhia,  ListaDuracoes) :-
	filtra_voo_dia_semana(Origem, Destino, Dia, HorarioSaida, HorarioChegada, Companhia),
	duracao(HorarioSaida, HorarioChegada,  Duracao).

roteiro(Origem, Destino, DiaSaida, HorarioSaida, Duracao) :-
	filtra_voo_dia_semana(Origem, Destino, Dia, HorarioSaida, HorarioChegada, Companhia),
	duracao(HorarioSaida, HorarioChegada,  Duracao).



listaDuracao(X, [], [X]).
listaDuracao(X, [Y|L1], [Y|L2]):-
	pertence_lista(X, [Y|L1]), !.
listaDuracao(X, [Y|L1], [Y|L2]):-
	listaDuracao(X, L1, L2).


menordalista(M, [M|[]]).
menordalista(M1, [Head|Tail]):- menordalista(M, Tail),
	menor(M, Head,  M1).
