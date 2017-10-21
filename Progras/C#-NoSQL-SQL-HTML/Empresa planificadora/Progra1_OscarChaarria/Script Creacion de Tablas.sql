Create DataBase Sucursales; 
Use Sucursales;
Create table Sucursales.Provincia(
	IdProvin int primary key, 
	NombreProvincia varchar(20)
);

Create table Sucursales.Direccion(
	IdDireccion int primary key,
    Descripcion varchar(50),
    CodPostal int, 
    FK_Provincia int, 
    Foreign key (FK_Provincia) References Sucursales.Provincia(IdProvin)
    ON DELETE CASCADE
);



Create table Sucursales.Sucursal(
	IdSucursal int primary key, 
    Nombre varchar(20),
    FK_Direccion int,
    Foreign key (FK_Direccion) references Sucursales.Direccion(IdDireccion)
    ON DELETE CASCADE
);

Create Table Sucursales.TipoTelefono(
	IdTipoTelefono int primary key, 
    NombreTipo varchar(20)
);

Create Table Sucursales.TelefonoSucursal(
	IdTelefonoSucur int primary key,
    Numero int, 
    FK_TipoTelefono int, 
    FK_Sucursal int,
	Foreign key (FK_TipoTelefono) references Sucursales.TipoTelefono(IdTipoTelefono) ON DELETE CASCADE,
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal) ON DELETE CASCADE
);

Create table Sucursales.Ganancia(
	IdGranacia int primary key, 
    FechaIng date, 
    Monto int, 
    FK_Sucursal int ,
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE
);

Create Table Sucursales.TipoEmpleado(
	IdTipoEmpleado int primary key, 
    NombreTipo varchar(20)
);

Create Table Sucursales.Empleado(
	IdEmpleado int primary key, 
    Nombre varchar(20),
    Apellido1 varchar(20),
    Apellido2 varchar(20),
    FK_TipoEmpleado int,
    FK_Direccion int,
    FK_Sucursal int,
    Foreign key (FK_TipoEmpleado) references Sucursales.TipoEmpleado(IdTipoEmpleado)ON DELETE CASCADE,
    Foreign key (FK_Direccion) references Sucursales.Direccion(IdDireccion)ON DELETE CASCADE,
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE
);

Create Table Sucursales.TelefonoEmpleado( 
	IdTelefonoEmpleado int primary key, 
    Numero int, 
    FK_Empleado int, 
    FK_TipoTelefono int, 
    Foreign key (FK_Empleado) references Sucursales.Empleado(IdEmpleado)ON DELETE CASCADE,
	Foreign key (FK_TipoTelefono) references Sucursales.TipoTelefono(IdTipoTelefono)ON DELETE CASCADE
);


Create Table Sucursales.ClientePersona(
	IdCliente int primary key,
    Nombre varchar(20),
    Apellido1 varchar(20),
    Apellido2 varchar(20),
    FK_Sucursal int, 
    FK_Direccion int, 
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE,
    Foreign key (FK_Direccion) references Sucursales.Direccion(IdDireccion)  ON DELETE CASCADE  
);

Create Table Sucursales.TelefonoCliente(
	IdTelefonoCliente int primary key,
    Numemero int, 
    FK_TipoTelefono int, 
    FK_Cliente int,
	Foreign key (FK_TipoTelefono) references Sucursales.TipoTelefono(IdTipoTelefono)ON DELETE CASCADE,
    Foreign key (FK_Cliente) references Sucursales.ClientePersona(IdCliente)ON DELETE CASCADE
);

Create Table Sucursales.Inventario(
	IdInventario int primary key,
    FK_Sucursal int, 
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE
);


Create Table Sucursales.Producto (
	IdProducto int primary key, 
    Nombre varchar(20),
    Impuesto int, 
    Precio int, 
    FechaExp date, 
    FK_Empleado int,
    Foreign key (FK_Empleado) references Sucursales.Empleado(IdEmpleado)ON DELETE CASCADE
);
Create Table Sucursales.DetelleProducto(
	IdDetalleProducto int primary key, 
    Titulo varchar(20),
    Descripcion varchar(50),
    Fk_Producto int, 
    Foreign key (Fk_Producto) references Sucursales.Producto(IdProducto)ON DELETE CASCADE
);

Create Table Sucursales.HistorialVenta(
	IdHisotrialVenta int primary key, 
    Cantidad int,
	MontoTotal int,
	FechaVenta date, 
    FK_Producto int,
    Foreign key (Fk_Producto) references Sucursales.Producto(IdProducto)ON DELETE CASCADE
);
Create Table Sucursales.ProductoXInventario(
	FK_Inventario int,
    FK_Producto int,
	ProductoUnidades int, 
    Primary key (FK_Inventario,FK_Producto),
    Foreign key (FK_Inventario) references Sucursales.Inventario(IdInventario)ON DELETE CASCADE,
    Foreign key (Fk_Producto) references Sucursales.Producto(IdProducto)ON DELETE CASCADE
);

Create Table Sucursales.PagosHacienda(
	IdPagosHacienda int AUTO_INCREMENT, 
    Monto int,
    FechaPago date, 
    FK_Sucursal int,
    primary key (IdPagosHacienda),
    Foreign key (FK_Sucu	rsal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE
);

Create table Sucursales.TipoPago(
	IdTipoPago int primary key, 
    Nombre varchar(20) 
);


Create Table Sucursales.FacturaClientePersona(
	IdFacturaCliente int primary key,
    FechaFactura date,
    MontoTotal int,
    FK_Cliente int,
    FK_TipoPago int,
    Foreign key (FK_Cliente) references Sucursales.ClientePersona(IdCliente)ON DELETE CASCADE,
    Foreign key (FK_TipoPago) references Sucursales.TipoPago(IdTipoPago)ON DELETE CASCADE
    
);

Create Table Sucursales.LineaFacturaCP(
	IdLineaFactura int primary key, 
    Cantidad int,
    Fk_Producto int, 
    FK_FacturaCliente int,
    Foreign key (Fk_Producto) references Sucursales.Producto(IdProducto)ON DELETE CASCADE,
    Foreign key (FK_FacturaCliente) references Sucursales.FacturaClientePersona(IdFacturaCliente)ON DELETE CASCADE
);

Create Table Sucursales.ClienteMenu(
	IdCliente int primary key,
    Nombre varchar(20),
    FK_Sucursal int, 
    FK_Direccion int, 
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE,
    Foreign key (FK_Direccion) references Sucursales.Direccion(IdDireccion)ON DELETE CASCADE 
);

Create Table Sucursales.Solicitud(
	IdSolicitud int primary key,
    FechaSolicitud date, 
    Estado varchar(20),
    FK_Sucursal int,
    Foreign key (FK_Sucursal) references Sucursales.Sucursal(IdSucursal)ON DELETE CASCADE
);

Create Table Sucursales.Pedido(
 IdPedido int primary key,
 FechaEntrega date,
 Evaluacion varchar(20),
 FK_Solicitud int,
 FK_ClienteMenu int,
 FK_Empleado int, 
 Foreign key (FK_Solicitud) references Sucursales.Solicitud(IdSolicitud)ON DELETE CASCADE,
 Foreign key (FK_ClienteMenu) references Sucursales.ClienteMenu(IdCliente)ON DELETE CASCADE,
 Foreign key (FK_Empleado) references Sucursales.Empleado(IdEmpleado)ON DELETE CASCADE
);


Create Table Sucursales.FacturaPedido(
	IdFacturaPedido int primary key,
    FechaFactura date,
    MontoTotal int,
    Estado varchar(20),
    FechaMorosidad date,
    FK_TipoPago int,
    FK_Pedido int,
    Foreign key (FK_Pedido) references Sucursales.Pedido(IdPedido)ON DELETE CASCADE,
    Foreign key (FK_TipoPago) references Sucursales.TipoPago(IdTipoPago)ON DELETE CASCADE
    
);

Create Table Sucursales.LineaFacturaPedido(
	IdLineaFacturaPedido int primary key, 
    Cantidad int,
    Fk_Producto int, 
    FK_FacturaPedido int,
    Foreign key (Fk_Producto) references Sucursales.Producto(IdProducto)ON DELETE CASCADE,
    Foreign key (FK_FacturaPedido) references Sucursales.FacturaPedido(IdFacturaPedido)ON DELETE CASCADE
);

