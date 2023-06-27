CREATE TABLE Anunciante (
  id_anunciante INT PRIMARY KEY auto_increment,
  nome_anunciante varchar(50),
  cpf varchar(14) UNIQUE,
  email varchar(50) UNIQUE,
  senha_hash varchar(255),
  telefone varchar(15)
);

CREATE TABLE Endereco(
  cep_endereco varchar(9),
  bairro_endereco varchar(50),
  cidade_endereco varchar(50),
  estado_endereco varchar(2)
);

CREATE TABLE Categoria(
  id_categoria INT PRIMARY KEY auto_increment,
  nome_categoria varchar(50),
  descricao_categoria varchar(200)
);

CREATE TABLE Anuncio(
  id_anuncio INT PRIMARY KEY auto_increment,
  titulo varchar(80),
  descricao varchar(500),
  preco DECIMAL(10,2),
  data_hora_anuncio DATETIME,
  cep_anuncio varchar(9),
  bairro_anuncio varchar(50),
  cidade_anuncio varchar(50),
  estado_anuncio varchar(2),
  id_anunciante INT NOT NULL,
  id_categoria INT NOT NULL,
  FOREIGN KEY (id_anunciante) REFERENCES Anunciante(id_anunciante) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (id_categoria) REFERENCES Categoria(id_categoria) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Interesse(
  id_interesse INT PRIMARY KEY auto_increment,
  mensagem varchar(200),
  data_hora_interesse DATETIME,
  contato varchar(100),
  id_anuncio INT NOT NULL,
  FOREIGN KEY (id_anuncio) REFERENCES Anuncio(id_anuncio) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Foto(
  id_anuncio INT NOT NULL,  
  nome_arq_foto varchar(50),
  FOREIGN KEY (id_anuncio) REFERENCES Anuncio(id_anuncio) ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO Categoria (nome_categoria, descricao_categoria)
VALUES
  ('Veículo', 'Carros, motos, motos elétricas, vans, bicicletas, entre outros'),
  ('Eletroeletrônico', 'Celulares, computadores, televisores, geladeiras, microondas, entre outros'),
  ('Imóvel', 'Casas, chácaras, sítios, apartamentos, kitnet, flat, entre outros'),
  ('Móvel', 'Sofás, poltronas, mesas, cadeiras, raques, escrivaninhas, criados entre outros'),
  ('Vestuário', 'Peças de roupas, acessórios entre outros'),
  ('Outro', 'Outros produtos que não se encaixam nas categorias existentes');

INSERT INTO Endereco (cep_endereco, bairro_endereco, cidade_endereco, estado_endereco)
VALUES
  ('38408-100', 'Santa Monica', 'Uberlândia', 'mg'),
  ('01502-001', 'Liberdade', 'São Paulo', 'sp'),
  ('50090-000', 'São José', 'Recife', 'pe'),
  ('91170-200', 'Rubem Berta', 'Porto Alegre', 'rs'),
  ('97015-001', 'Bom Fim', 'Santa Maria', 'rs');

