CREATE TABLE Usuario (
    Email VARCHAR(100) NOT NULL,
	Senha VARCHAR(50) NOT NULL,
    Nome VARCHAR(30),
    Sobrenome VARCHAR(50),
	Idade INT,
    Saldo FLOAT,
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
    
CREATE TRIGGER  UPDATE_NUMBER_PEOPLE_GROUP BEFORE INSERT ON usuario_grupo 
FOR EACH ROW 
	UPDATE grupo SET Quantidade_pessoas = Quantidade_pessoas + 1 
    WHERE grupo.identificador = NEW.Identificador;

CREATE TRIGGER SET_NUMBER_GROUP_ZERO BEFORE INSERT ON Grupo
FOR EACH ROW
	SET new.Quantidade_pessoas = 0;

