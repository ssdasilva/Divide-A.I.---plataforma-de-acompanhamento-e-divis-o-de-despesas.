USE divide_ai;
INSERT INTO usuario(CPF,Idade,Pnome,Sobrenome,Saldo)
VALUES (10531266659,22,'Alexandre', 'Pereira Gomes', 0);
INSERT INTO usuario(CPF,Idade,Pnome,Sobrenome,Saldo)
VALUES (1548796543,35,'Naiara', 'Costa Fernandes', -20.50);
INSERT INTO usuario(CPF,Idade,Pnome,Sobrenome,Saldo)
VALUES (15233365623,50,'Germano', 'Fernandes da Silva', 500.50);
INSERT INTO usuario(CPF,Idade,Pnome,Sobrenome,Saldo)
VALUES (10651489765,18,'Kate', 'Junior costa', 50);

INSERT INTO grupo(Identificador,Nome,Quantidade_pessoas)
VALUES('564189416','Alunos engenharia UFMG',0);
INSERT INTO grupo(Identificador,Nome,Quantidade_pessoas)
VALUES('861574864','Familia',0);

INSERT INTO usuario_grupo(CPF,Identificador)
VALUES(1548796543,'564189416');
INSERT INTO usuario_grupo(CPF,Identificador)
VALUES(10651489765,'564189416');
INSERT INTO usuario_grupo(CPF,Identificador)
VALUES(1548796543,'861574864');
INSERT INTO usuario_grupo(CPF,Identificador)
VALUES(15233365623,'861574864');
INSERT INTO usuario_grupo(CPF,Identificador)
VALUES(10651489765,'861574864');

INSERT INTO divida(CPF_devedor,CPF_credor,Quantia,Tipo_moeda,Categoria)
VALUES(1548796543,15233365623,1000,'Dinheiro','Aluguel de casa');
INSERT INTO divida(CPF_devedor,CPF_credor,Quantia,Tipo_moeda,Categoria)
VALUES(10651489765,10531266659,350,'Dinheiro','Aluguel de carro');

