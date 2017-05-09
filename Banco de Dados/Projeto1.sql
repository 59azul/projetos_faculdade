create table cursos (nome varchar2(20), localidade varchar2(20), num number);

alter table cursos add constraint pk_cursos primary key (num);

create table alunos (num_curso number, ra number, nome varchar2(20), data_nasc date, cidade varchar2(20));

alter table alunos add constraint pk_alunos primary key (ra);

alter table alunos add constraint fk_alunos foreign key (num_curso) references cursos;

create table disciplinas (cod number, nome varchar2(20), cred number);

alter table disciplinas add constraint pk_disciplinas primary key (cod);

create table pre_req (cod_disc number, cod_pre_req number);

alter table pre_req add constraint fk_disc foreign key (cod_disc) references disciplinas;

alter table pre_req add constraint fk_pre_req foreign key (cod_pre_req) references disciplinas;

alter table pre_req add constraint pk_pre_req primary key (cod_disc, cod_pre_req);

create table grade (cod_disc number, num_curso number);

alter table grade add constraint fk_cursos foreign key (num_curso) references cursos;

alter table grade add constraint fk_disc_grade foreign key (cod_disc) references disciplinas;

alter table grade add constraint pk_grade primary key (cod_disc, num_curso);

create table alunos_graduacao (ra number, cd number);

create table alunos_pos_graduacao (ra number, orientador varchar2(20));

alter table alunos_graduacao add constraint fk_graduacao foreign key (ra) references alunos;

alter table alunos_pos_graduacao add constraint fk_pos_graduacao foreign key (ra) references alunos;

create table cursadas (ra number, cod_disc number, ano date, nota number, freq number, status varchar2(20));

alter table cursadas add constraint fk_alunos_cursadas foreign key (ra) references alunos;

alter table cursadas add constraint fk_disc_cursadas foreign key (cod_disc) references disciplinas;

alter table cursadas add constraint pk_cursadas primary key (ra, cod_disc, ano);

create table matricula (ra number, cod_disc number);

alter table matricula add constraint fk_alunos_matricula foreign key (ra) references alunos;

alter table matricula add constraint fk_disc_matricula foreign key (cod_disc) references disciplinas;

alter table matricula add constraint pk_matricula primary key (ra, cod_disc);

insert into cursos values ('Matemática', 'Campus 1', 1);

insert into cursos values ('Geografia', 'Campus 1', 2);

insert into cursos values ('Medicina', 'Campus 2', 3);

insert into alunos values (1, 1, 'Mateus', to_date('21/05/1996', 'dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 2, 'João', to_date('14/12/1995', 'dd/mm/yyyy'), 'São Paulo');

insert into alunos values (1, 3, 'Joaquim', to_date('28/01/1992', 'dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 4, 'Bruna', to_date('22/11/1994', 'dd/mm/yyyy'), 'Santos');

insert into alunos values (2, 5, 'Maria', to_date('17/07/1996', 'dd/mm/yyyy'), 'Campinas');

insert into alunos values (3, 6, 'Paulo', to_date('25/08/1996', 'dd/mm/yyyy'), 'São Paulo');

insert into alunos values (2, 7, 'Marcelo', to_date('15/10/1995', 'dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 8, 'Beatriz', to_date('23/02/1995','dd/mm/yyyy'), 'Campinas');

insert into alunos values (2, 9, 'Leonardo', to_date('19/07/1996','dd/mm/yyyy'), 'Rio de Janeiro');

insert into alunos values (1, 10, 'Alex', to_date('30/01/1996','dd/mm/yyyy'), 'Campinas');

insert into alunos values (3, 11, 'Carlos', to_date('31/03/1995','dd/mm/yyyy'), 'São Paulo');

insert into alunos values (3, 12, 'José', to_date('15/06/1996','dd/mm/yyyy'), 'Campinas');

insert into alunos values (2, 13, 'Carolina', to_date('26/04/1996','dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 14, 'Daniel', to_date('22/09/1995','dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 15, 'Luciana', to_date('31/12/1994','dd/mm/yyyy'), 'São Paulo');

insert into alunos values (2, 16, 'Lúcio', to_date('27/02/1996','dd/mm/yyyy'), 'Campinas');

insert into alunos values (1, 17, 'Letícia', to_date('10/05/1996','dd/mm/yyyy'), 'Campinas');

insert into alunos values (3, 18, '', to_date('06/06/1996','dd/mm/yyyy'), 'Santos');

insert into alunos values (, , '', to_date('','dd/mm/yyyy'), '');
