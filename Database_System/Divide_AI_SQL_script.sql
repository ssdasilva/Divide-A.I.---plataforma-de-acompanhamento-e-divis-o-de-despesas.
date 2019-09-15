CREATE SCHEMA Divide_AI;
USE Divide_AI;

CREATE TABLE Usuario (
    CPF BIGINT NOT NULL,
    Idade TINYINT,
    Pnome VARCHAR(30),
    Sobrenome VARCHAR(50),
    Saldo FLOAT,
    PRIMARY KEY (CPF)
    );

CREATE TABLE Grupo(
	Identificador VARCHAR(50) NOT NULL,
    Nome VARCHAR(30),
    Quantidade_pessoas INT,
    PRIMARY KEY (Identificador)
);

CREATE TABLE Divida(
	CPF_devedor BIGINT NOT NULL,
    CPF_credor BIGINT NOT NULL,
    Quantia INT NOT NULL,
    Tipo_moeda VARCHAR(30),
    Categoria VARCHAR(30),
    PRIMARY KEY (CPF_devedor , CPF_credor),
    FOREIGN KEY (CPF_devedor)
		REFERENCES Usuario (CPF)
            ON DELETE CASCADE,
	FOREIGN KEY (CPF_credor)
		REFERENCES Usuario (CPF)
            ON DELETE CASCADE
);

CREATE TABLE Usuario_grupo(
	CPF BIGINT NOT NULL,
	Identificador VARCHAR(50) NOT NULL,
    PRIMARY KEY (CPF,Identificador),
    FOREIGN KEY (CPF)
		REFERENCES Usuario(CPF)
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

