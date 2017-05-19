create table contas (num_conta varchar2(20), nome varchar2(20), saldo number(10,2));

create table movimentos (num number, num_conta varchar2(20), data date, valor number(10,2), tipo char);

alter table contas add constraint pk_contas primary key (num_conta);

alter table movimentos add constraint pk_movimentos primary key (num);

alter table movimentos add constraint fk_movimentos foreign key (num_conta) references contas;

alter table movimentos add constraint checa_tipo check (tipo in ('D', 'C'));

insert into contas values ('100010', 'José', 10000.00);

insert into contas values ('100020', 'Carlos', 20000.00);

insert into contas values ('100030', 'Paulo', 15000.00);

insert into movimentos values (1, '100010', to_date('15/01/17','dd/mm/yy'), 1000.00, 'C');

insert into movimentos values (2, '100020', to_date('12/02/17','dd/mm/yy'), 2000.00, 'C');

insert into movimentos values (3, '100010', to_date('05/03/17','dd/mm/yy'), 500.00, 'D');

insert into movimentos values (4, '100010', to_date('19/05/17','dd/mm/yy'), 200.00, 'D');

insert into movimentos values (5, '100030', to_date('19/05/17','dd/mm/yy'), 3000.00, 'C');

create or replace trigger trc_movimento
	after insert on movimentos
	for each row
	begin
		if :new.tipo = 'C' then
			update contas
				set saldo = saldo + :new.valor
				where num_conta = :new.num_conta;
		else 	-- :new.tipo 'D'
			update contas
				set saldo = saldo - :new.valor
				where num_conta = :new.num_conta;
		end if;
	end;
	/	

create or replace trigger trc_movimento_exclui
	after delete on movimentos
	for each row
	begin
		if :old.tipo = 'C' then
			update contas
				set saldo = saldo - :old.valor
				where num_conta = :old.num_conta;
		else 	-- :old.tipo 'D'
			update contas
				set saldo = saldo + :old.valor
				where num_conta = :old.num_conta;
		end if;
	end;
	/

create sequence nr_mov start with 6;

create or replace trigger gera_num_movimento
	before insert on movimentos
	for each row
	begin
		select nr_mov.nextval into :new.num from dual;
	end;
	/


insert into movimentos (num_conta, data, valor, tipo) values ('100030', to_date('01/06/17','dd/mm/yy'), 1000.00, 'C');

insert into movimentos values (100,'100030', to_date('01/06/17','dd/mm/yy'), 2000.00, 'C');