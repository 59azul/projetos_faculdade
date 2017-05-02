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

