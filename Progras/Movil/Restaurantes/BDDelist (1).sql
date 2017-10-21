Create Database Delist
use Delist
Create Table Usuarios(
	idUsuario int primary key not null, 
	Nombre varchar(50))

Create Table Lugares(
	idLugar int identity (1,1)primary key,
	Nombre varchar(50),
	Categoria varchar(50),
	Longitud float, 
	Latitud float,
	Descripcion varchar(50)
	unique (Longitud,Latitud)
	)

Create Table ListaPrivada(
	idListaPrivada int identity (1,1)primary key,
	idUsuario int,
	 constraint FK_idUsuario foreign key (idUsuario) references Usuarios(idUsuario) 
	)

Create Table SitiosXListaPrivada(
	idListaPrivada int,
	idLugar int,
	primary key (idListaPrivada,idLugar),
	constraint FK_idListaPrivada foreign key (idListaPrivada) references ListaPrivada(idListaPrivada),
	constraint FK_idSitio foreign key (idLugar) references Lugares(idLugar)
)

Create Table Amigos(
	idAmigo1 int,
	idAmigo2 int,
	primary key(idAmigo1,idAmigo2),
	constraint FK_idUsuario1 foreign key (idAmigo1) references Usuarios(idUsuario),
	constraint FK_idUsuario2 foreign key (idAmigo2) references Usuarios(idUsuario)
)


Create Table ListaCompartida(
  idListaCompartida int identity(1,1) primary key,
  idCreador int,
  nombre varchar(50),
  constraint FK_idCreador foreign key (idCreador) references Usuarios(idUsuario),
);

Create Table AmigosListaCompartida(
	id int identity primary key,
	idListaCompartida int,
	idAmigo1 int,
	idAmigo2 int,
	constraint FK_idListaCompartidas foreign key (idListaCompartida) references ListaCompartida(idListaCompartida),
	constraint FK_idLCAmigo1 foreign key (idAmigo1,idAmigo2) references Amigos(idAmigo1,idAmigo2),
);

Create Table SitiosXListaCompartida(
	idListaCompartida int,
	idLugar int,
	primary key (idListaCompartida,idLugar),
	constraint FK_idListaCompartida foreign key (idListaCompartida) references ListaCompartida(idListaCompartida),
	constraint FK_idSitios foreign key (idLugar) references Lugares(idLugar)
)

