Create database DisenoP1; 

use DisenoP1;



CREATE TABLE Docentes
    (	
		idDocente varchar(30) Primary key,
		Nombre varchar(max) not null, 
		Correo varchar(max) not null,
		Telefono varchar(max) not null,
		TipoTelefono varchar(20) not null, 
		TipoCorreo varchar(20)
    ); 

Create Table Cursos
(
	Codigo varchar(150) primary key,
	Nombre varchar (150),
	Creditos varchar(150)
);

Create Table CursoAbiertos
( 
		periodo varchar(20),
		idCurso varchar(150) not null,
		Grupo varchar(20) not null,
		idDocente varchar(30) not null,
		Dias varchar(100) not null,
		Aula varchar(20) not null, 
		constraint Fk_idCurso foreign key (idCurso) references Cursos(codigo),
		foreign key (idDocente) references Docentes(idDocente),
		Primary key (Grupo,periodo,idCurso,idDocente)
);



Create table Solicitudes
(
	idSolicitud int primary key, 
	Fecha date, 
	NombreSolicitante varchar(20),
	idSolicitante int,
	PeriodoLect varchar(20),
	CodCurso varchar(20),
	Grupo int, 
	CarnetEst int,
	NombreEst varchar(50),
	CorreoEst varchar(50),
	TeleEst int, 
	TipoL varchar(50),
	Detalle varchar(100),
	Resolvido bit, 
	Estado varchar(50),
	--constraint Fk_idCursoSoli foreign key (CodCurso) references Cursos(idCurso)
);

Create Table Resoluciones
(
	idResolucion int primary key IDENTITY(1,1),
	Codigo varchar(max),
	Fecha date, 
	Coordinador	varchar(max),
	NombreAr varchar(max),
	NombreDirector varchar(max),
	idSolicitud int, 
	considerandos varchar(max)
	constraint Fk_idSolicitud foreign key (idSolicitud) references Solicitudes(idSolicitud),
	
);






