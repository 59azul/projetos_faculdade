create table cursos (nome varchar2(20), localidade varchar2(20), num number);

alter table cursos add constraint pk_cursos primary key (num);

create table alunos (num_curso number, ra number, nome varchar2(20), data_nasc date, cidade varchar2(20));

alter table alunos add constraint pk_alunos primary key (ra);

alter table alunos add constraint fk_alunos foreign key (num_curso) references cursos;

create table disciplinas (cod number, nome varchar2(20), cred number);

alter table disciplinas add constraint pk_disciplinas primary key (cod);

create table pre_req (cod_disc number, cod_pre_req number);

alter table pre_req add constraint fk_disc (cod_disc) references disciplinas;

alter table pre_req add constraint fk_pre_req (cod_pre_req) references disciplinas;

create table grade (cod_disc number, num_curso number);
