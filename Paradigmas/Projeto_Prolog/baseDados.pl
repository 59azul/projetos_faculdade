% vôo(origem,destino,código,partida,(dia_chegada,horario_chegada),
% número_de_escalas, companhia,[dias]).
voo(sao_paulo, mexico, a6, 17:00, (mesmo, 23:00), 0, gol, [segunda, terca, sabado]).
voo(sao_paulo, nova_york, a84, 16:00 , (mesmo, 22:00), 1, tam, [terca, quarta, sexta]).
voo(sao_paulo, lisboa, a32, 14:00, (mesmo, 20:30), 2, azul, [quarta, sexta, sababo]).
voo(sao_paulo, madrid, a68, 20:30, (proximo, 03:00), 3, tam, [sexta, sabado, domingo]).
voo(sao_paulo, londres, a54, 21:00, (proximo, 05:00), 4, gol, [segunda, sexta, domingo]).
voo(sao_paulo, paris, a48, 00:00, (mesmo, 06:30), 5, azul, [terca, quinta, sexta]).
voo(mexico, nova_york, b66, 15:00, (mesmo, 17:00), 0, tam, [quarta, quinta, sexta, sabado]).
voo(mexico, madrid, b65, 20:00, (proximo, 01:30), 1, azul, [segunda, quarta, quinta]).
voo(nova_york, londres, c64, 13:00, (mesmo, 17:00), 0, gol, [terca, quinta, sabado]).
voo(londres, lisboa, d56, 12:00, (mesmo, 14:00), 0, tam, [segunda, terca, sexta]).
voo(londres, paris, d65, 15:00, (mesmo, 16:30), 0, azul, [terca, quinta, sababdo]).
voo(londres, estocolmo, d84, 12:30, (mesmo, 15:00), 0, tam, [segunda, quarta, domingo]).
voo(madrid, paris, e49, 14:00, (mesmo, 15:30), 0, gol, [terca, quarta, quinta, sabado]).
voo(madrid, roma, e98, 16:00, (mesmo, 17:00), 0, tam, [quarta, sexta, sabado, domingo]).
voo(madrid, frankfurt, e82, 17:00, (mesmo, 18:30), 0, azul, [segunda, terca, sexta, domingo]).
voo(frankfurt, estocolmo, d65, 15:00, (mesmo, 16:30), 0, azul, [segunda, quarta, sexta]).
voo(frankfurt, roma, d15, 12:00, (mesmo, 14:00), 0, [terca, quinta, sexta, sabado, domingo]).

pertence_lista(X,[X|Cauda]).
pertence_lista(X,[Cabeca|Cauda]) :- pertence_lista(X,Cauda).

voo_direto(Origem, Destino, Companhia, Dia, Horario) :-
	voo(Origem, Destino, _, Horario, (_, _), 0, Companhia, Lista),
        pertence_lista(Dia, Lista).
