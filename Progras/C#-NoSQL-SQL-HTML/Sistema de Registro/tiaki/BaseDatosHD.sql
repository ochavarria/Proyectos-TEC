Create database Tiaki; 

-- Tabla de Residenciales
Create table Residenciales(
	IdResidencial int primary key, 
	Nombre varchar(20),
    Direccion varchar(max)
);

insert into Residenciales values(1,'La Guaria','200 mts de la pulperia')
insert into Residenciales values(2,'Linda Vista','200 mts de la pulperia')
insert into Residenciales values(3,'Nuevo Horizonte','200 mts de la pulperia')

insert into Horarios values('a','Lunes','Viernes','5:00','14:00',8,1,450000,2000);
insert into Horarios values('b','Lunes','Viernes','14:00','23:00',8,1,470000,2000);
insert into Horarios values('c','Sabado','Domingo','5:00','14:00',8,1,430000,2000);
insert into Horarios values('d','Sabado','Domingo','14:00','23:00',8,1,456666,2000);
insert into Horarios values('e','Viernes','Domingo','23:00','5:00',6,0,577000,2000);
insert into Horarios values('f','Lunes','Viernes','23:00','5:00',6,0,5678904,20000);
insert into Horarios values('g','x','y','00:00','00:00',0,0,0,0);

select * from Residenciales
-- Tabla de horarios x vigilante
Create table Horarios(
	grupo char primary key,
	diaInicio varchar(50),
	diaFinal varchar(50),
	horaInicio time,
	horaFinal time,
	horasEstandar int,
	horasExtras int,
	salarioExtra money,
	salarioEstandar money
);

-- Tabla Vigilantes

Create table Vigilantes (
	IdVigilante int primary key, 
    Nombre varchar(50),
    Apellidos varchar(50),
    Estado varchar(20),
    Edad int,
    Telefono int,
    idHorario char,
	idResidencial int,
	Foreign key (idHorario) References Horarios(grupo),
	Foreign key (idResidencial) References Residenciales(IdResidencial)
);

-- Tabla de Vigilantes x Residencial

Create table VigixResi(
	Id int primary key,
	IdVigilante int , 
    IdResidencial int,
	Foreign key (IdVigilante) References Vigilantes(IdVigilante),
    Foreign key (IdResidencial) References Residenciales(IdResidencial)
);

Create table jefes(
	usuario varchar(50),
	contra varchar(50)
);

