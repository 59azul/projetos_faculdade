set linesize 150;
set pagesize 60;

create table secao ( numsec number,  nome varchar2(20), cidade varchar2(20));

create table empregado ( numemp number, nome varchar2(20), numsec number, cargo varchar2(15), num_chefe number, salario number(8,2), comissao number(8,2) );

alter table empregado add primary key (numemp) ;

insert into empregado values (1, 'batata', 100, 'tuberculo', 1, 100.25, 10.50);

select * from empregado;