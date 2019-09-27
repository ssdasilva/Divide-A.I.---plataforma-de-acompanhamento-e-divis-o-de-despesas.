INSERT INTO usuario(email,senha,nome,sobrenome,idade,saldo)
VALUES ('alexandre1235@hotmail.com','uogbek45','Alexandre','Pereira Gomes',22,0);
INSERT INTO usuario(email,senha,nome,sobrenome,idade,saldo)
VALUES ('Naiaracosta27@gmail.com','secreto1','Naiara', 'Costa Fernandes',35,-20.50);
INSERT INTO usuario(email,senha,nome,sobrenome,idade,saldo)
VALUES ('gfernandes1997@yahoo.com.br','125ud26-','Germano', 'Fernandes da Silva',50,500.50);
INSERT INTO usuario(email,senha,nome,sobrenome,idade,saldo)
VALUES ('katejun55@gmail.com','vidaloka1','Kate', 'Junior costa',18,50);

INSERT INTO grupo(Identificador,Nome,Quantidade_pessoas)
VALUES('564189416','Alunos engenharia UFMG',0);
INSERT INTO grupo(Identificador,Nome,Quantidade_pessoas)
VALUES('861574864','Familia',0);

INSERT INTO usuario_grupo(Email,Identificador)
VALUES('alexandre1235@hotmail.com','564189416');
INSERT INTO usuario_grupo(Email,Identificador)
VALUES('katejun55@gmail.com','564189416');
INSERT INTO usuario_grupo(Email,Identificador)
VALUES('Naiaracosta27@gmail.com','861574864');
INSERT INTO usuario_grupo(Email,Identificador)
VALUES('gfernandes1997@yahoo.com.br','861574864');
INSERT INTO usuario_grupo(Email,Identificador)
VALUES('katejun55@gmail.com','861574864');

INSERT INTO divida(Email_devedor,Email_credor,Quantia,Tipo_moeda,Categoria)
VALUES('alexandre1235@hotmail.com','Naiaracosta27@gmail.com',1000,'Dinheiro','Aluguel de casa');
INSERT INTO divida(Email_devedor,Email_credor,Quantia,Tipo_moeda,Categoria)
VALUES('katejun55@gmail.com','gfernandes1997@yahoo.com.br',350,'Dinheiro','Aluguel de carro');

