CREATE TABLE Usuario (
    Email VARCHAR(100) NOT NULL,
	Senha VARCHAR(50) NOT NULL,
    Nome VARCHAR(30),
    Sobrenome VARCHAR(50),
	Idade INT,
    Saldo FLOAT,
    Simplificar BOOLEAN,
    PRIMARY KEY (Email)
    );

CREATE TABLE Grupo(
	Identificador VARCHAR(50) NOT NULL,
    Nome VARCHAR(30),
    Quantidade_pessoas INT,
    PRIMARY KEY (Identificador)
);

CREATE TABLE Divida(
        Email_devedor VARCHAR(100) NOT NULL,
    Email_credor VARCHAR(100) NOT NULL,
    Quantia INT NOT NULL,
    Tipo_moeda VARCHAR(30),
    Categoria VARCHAR(30),
    PRIMARY KEY (Email_devedor , Email_credor),
    FOREIGN KEY (Email_devedor)
		REFERENCES Usuario (Email)
            ON DELETE CASCADE,
	FOREIGN KEY (Email_credor)
		REFERENCES Usuario (Email)
            ON DELETE CASCADE
);

CREATE TABLE Despesa(
    Email VARCHAR(100) NOT NULL,
    Descricao VARCHAR(100) NOT NULL,
    Data VARCHAR(20) NOT NULL,
    Moeda VARCHAR(30),
    Categoria VARCHAR(30),
    Frequencia VARCHAR(30),
    Quantia INT NOT NULL,
    PRIMARY KEY (Email , Descricao),
    FOREIGN KEY (Email)
		REFERENCES Usuario (Email)
            ON DELETE CASCADE
);

CREATE TABLE Usuario_grupo(
	Email VARCHAR(100) NOT NULL,
	Identificador VARCHAR(50) NOT NULL,
    PRIMARY KEY (Email,Identificador),
    FOREIGN KEY (Email)
		REFERENCES Usuario(Email)
			ON DELETE CASCADE,
	FOREIGN KEY (Identificador)
		REFERENCES Grupo(Identificador)
			ON DELETE CASCADE
);
    
CREATE FUNCTION numeroPessoas_gatilho() RETURNS trigger AS $numeroPessoas_gatilho$
  BEGIN
		UPDATE grupo SET Quantidade_pessoas = Quantidade_pessoas + 1 
    	WHERE grupo.identificador = NEW.Identificador;
	RETURN NEW;
  END;
$numeroPessoas_gatilho$ LANGUAGE plpgsql;
  
CREATE TRIGGER numeroPessoas_gatilho BEFORE INSERT ON usuario_grupo
FOR EACH ROW EXECUTE PROCEDURE numeroPessoas_gatilho();


CREATE FUNCTION SET_NUMBER_GROUP_ZERO () RETURNS trigger AS $SET_NUMBER_GROUP_ZERO$
  BEGIN
	NEW.Quantidade_pessoas = 0;
	RETURN NEW;
  END;
$SET_NUMBER_GROUP_ZERO$ LANGUAGE plpgsql;
  
CREATE TRIGGER SET_NUMBER_GROUP_ZERO  BEFORE INSERT ON grupo
FOR EACH ROW EXECUTE PROCEDURE SET_NUMBER_GROUP_ZERO();
