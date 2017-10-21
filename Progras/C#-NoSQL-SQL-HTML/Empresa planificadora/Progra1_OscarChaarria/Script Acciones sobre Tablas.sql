Insert into Provincia values (1,"Limon");
Insert into Provincia values (2,"San Jose");
Insert into Provincia values (3,"Heredia");

-- Direccion de Sucursales
Insert into direccion values (1,"100mtrs Norte del Centro",702409,1);
Insert into direccion values (2,"200 mtrs Este del Centro",109230,2);
Insert into direccion values (3,"300 mtrs Sur de Belen",409234,3);

-- Direccion de Empleados
Insert into direccion values (4,"Barrio los cangrejos",109230,1);
Insert into direccion values (5,"Barrio Cieneguita",109230,1);

-- Direccion de Clientes
Insert into direccion values (6,"Barrio Corales",109230,1);
Insert into direccion values (7,"Barrio Santa",109230,1);



Insert into Sucursal values (1,"La Venta de lola",2);
Insert into Sucursal values (2,"La Venta de Juan",3);
Insert into Sucursal values (3,"La Venta de Pedro",1);	

Insert into Tipotelefono values(1,"Fijo");
Insert into Tipotelefono values(2,"Celuar");

Insert into telefonosucursal values (1,22222222,1,1);
Insert into telefonosucursal values (2,28352232,1,2);
Insert into telefonosucursal values (3,45643453,1,3);



Insert into Tipoempleado values(1,"Cajero");
Insert into Tipoempleado values(2,"Productores");

Insert into Empleado values (1,"Oscar","Chavarria","Campos",2,4,1);
Insert into Empleado values (2,"Alfredo","Chavarria","Campos",2,5,1);

Insert into Inventario values (1,1);

Insert into producto values (1,"Empanadas",2,700,'2017/01/25',1);
Insert into producto values (2,"Enchiladas",3,900,'2017/01/25',2);
Insert into producto values (3,"Sandwich",2,1000,'2017/01/25',1);

Insert into detelleproducto values (1,"Protenias","2mg",3);
Insert into detelleproducto values (4,"Grasas","2mg",3);

Insert into detelleproducto values (2,"Grasas","3mg",1);
Insert into detelleproducto values (3,"Azucar","1mg",2);

Insert into productoxinventario values (1,1,5);
Insert into productoxinventario values (1,2,6);
Insert into productoxinventario values (1,3,8);




Insert into sucursales.clientepersona values (1,"Fernando","Chevez","Alvares",1,6);
Insert into sucursales.clientepersona values (2,"Orlando","Chevez","Alvares",1,6);


Insert into sucursales.clientemenu values (1,"Puperia Palotes",1,7);
Insert into sucursales.clientemenu values (2,"Puperia Gaza",1,7);

insert into sucursales.tipopago values(1,"Efectivo");
insert into sucursales.tipopago values(2,"Tarjeta");


insert into sucursales.facturaclientepersona values(1,'2017/03/03',3000,1,1);

insert into sucursales.facturaclientepersona values(2,'2017/03/03',5800,1,2);


insert into sucursales.lineafacturacp values (1,3,3,1);

insert into sucursales.lineafacturacp values (2,2,2,2);
insert into sucursales.lineafacturacp values (3,4,3,2);


insert into sucursales.solicitud values (1,'2017/06/03',"Activo",1);

insert into sucursales.pedido values (1,'2017/01/03',"Aprovado",1,2,1);	
insert into sucursales.pedido values (2,'2017/07/03',"Rechazado",1,1,2);

insert into facturapedido values (1,'2017/07/03',4400,"Pendiente",'2017/10/03',2,1);

insert into lineafacturapedido values (1,3,3,1);
insert into lineafacturapedido values (2,2,1,1);

insert into ganancia values (1,'2017/10/03',15000,1);
insert into ganancia values (2,'2017/11/03',15800,1);

insert into pagoshacienda values (1,2000,'2017/10/03',1);
insert into pagoshacienda values (2,3000,'2017/10/04',1);

-- Read

-- VerClientesPer
-- VerClienteMenu


call sucursales.VerEmpleados();
call sucursales.VerProductos();
call sucursales.VerHistorialVentas();
call Sucursales.VerFacturasClientes();
Call Sucursales.VerDetallesFacturasClientes();
call sucursales.VerGanancias();
call sucursales.VerPagosHacienda();
call sucursales.VerPedidosCM();
call sucursales.VerDetallesFacturaPedido();
call sucursales.VerFacturasPedido();

-- Update 

call sucursales.ActualizarEmpleados(7,"Otto",null,null);
call sucursales.ActualizarProductos(2,null,6,800);
call sucursales.ActualizarDetallesProductos(2,null,"6mg");
call sucursales.ActualizarCantidadUnidadesProd(1,1,null);
call sucursales.ActualizarHistorialVenta(3,null,1600,'2017-05-03');
call sucursales.ActualizarFacturaClientePer(2,null,5000);
call sucursales.ActualizarLineaFactuCP(3,null);
call sucursales.ActualizarFacturaPedido(1,null,5000,"Cancelado",null);
call sucursales.ActualizarLineaFactuPedido(1,null);
call sucursales.ActualizarGanancias(1,'2017/03/10',null);
call sucursales.ActualizarPagosHacienda(2,null,'2017/10/08');






 


-- Punto 6 
call Sucursales.VerSucursales();
call sucursales.ActualizarSucursal(1,"Venta de Pepe");
call sucursales.EliminarSolicitud();

-- Punto 8
call sucursales.VerDirecciones();
call sucursales.VerProvicias();
call sucursales.EliminarProvincia(3);
call sucursales.EliminarDireccion(2);
call sucursales.ActualizarProvincia(4,"Cartago");
call sucursales.ActualizarDireccion(1,"hola",null);

-- Punto 9 
call sucursales.VerClientesPer();
call sucursales.VerClientesMenu();

call sucursales.ActualizarClienteMenu(1,"Chavelo");

call sucursales.ActualizarClientePersona(1,"Chavelox",null,null);

call sucursales.EliminarClienteMenu(2);
call sucursales.EliminarClientePersona(2);

-- Punto10 - 11 - 12
Insert into detelleproducto values (5,"Alergias","Veneno de serpiente",3);
call VerProductosDetalles();

call sucursales.VerCantProductosxInventario();
call sucursales.ActualizarCantidadUnidadesProd();

 

-- Punto 13
-- mes 1 25 a 25 
Insert into historialventa values (1,3,3000,'2017/01/20',3);
Insert into historialventa values (2,4,4000,'2017/01/20',3);
Insert into historialventa values (3,2,1800,'2017/01/20',2);

Insert into historialventa values (4,2,2700,'2017/01/20',2);
Insert into historialventa values (5,2,1400,'2017/01/20',1);
Insert into historialventa values (6,3,2100,'2017/01/20',1);


Insert into historialventa values (7,1,1000,'2016/12/20',3);
Insert into historialventa values (8,2,2000,'2016/12/20',3);
Insert into historialventa values (9,3,2700,'2016/12/20',2);
-- mes 2 

Insert into historialventa values (10,2,2700,'2016/11/29',2);
Insert into historialventa values (11,4,2800,'2016/11/29',1);
Insert into historialventa values (12,3,2100,'2016/11/29',1);

Insert into historialventa values (13,2,2700,'2016/10/29',2);
Insert into historialventa values (14,2,2000,'2016/10/29',3);
Insert into historialventa values (15,3,2100,'2016/10/29',1);


call sucursales.ProductosBajos();

-- Punto 14 
-- a
call sucursales.CrearFacturaCP(3,'2017-03-03',2,1);
call sucursales.CrearLineaFactCP(4,3,1,3);
call sucursales.CrearLineaFactCP(5,2,3,3);

call sucursales.CalcularMontoFacturaCP(3);

call sucursales.CalcularMontoFacturaCP(2);-- Genera Pago Hacienda

select * from sucursales.lineafacturacp;
call sucursales.VerFacturasClientes();

-- b 


call CrearFacturaPedido(2,'2017-07-03',"Cancelado",'2017-10-03',1,1);
call sucursales.CrearLineaFactPedido(3,2,2,2);

call CalcularMontoFacturaPedido(1); -- Genera Pago Hacienda

select * from sucursales.pedido;
select * from sucursales.lineafacturapedido;
call VerFacturasPedido();

-- Parte 15 
insert into sucursales.tipopago values(3,"Paypal");
call sucursales.VerTipoPagos();	
call sucursales.ActualizarTipoPago(3,"Otros");
call sucursales.EliminarTipoPago(3);

-- Parte 16 
insert into pagoshacienda (pagoshacienda.Monto,pagoshacienda.FechaPago,pagoshacienda.FK_Sucursal) values (2000,'2017/10/04',1);
call sucursales.VerPagosHacienda();

-- Parte 17 
call sucursales.VerPedidosCM();
call sucursales.ActualizarPedidos(1,'2017-01-28',null);
call sucursales.EliminarPedido(2);
call sucursales.VerPedidosCMEntreSemana(curdate());

-- Parte 18 

call sucursales.VerEmpleados();
call sucursales.ActualizarEmpleados(7,"Otto",null,null);
call sucursales.EliminarEmpleado(2);

call sucursales.VerTipoEmpleado();
Insert into Tipoempleado values(3,"Aguatero");
call sucursales.ActualizarTipoEmpleado(3,"Miselaneao");
call sucursales.EliminarTipoEmpleado(3);

-- Parte 19
call sucursales.VerProductos();
call sucursales.VerCantProductosxInventario();
call sucursales.ActualizarCantidadUnidadesProd(1,1,8);
call EliminarProducto(null);

-- Parte 20 
-- crud pedidos estan en parte 17
call sucursales.VerPedidosCM();

Insert into producto values (4,"Paleta",0,200,'2017/01/29',1);


insert into sucursales.pedido values (3,'2017/01/26',null,1,1,2);
insert into facturapedido values (3,'2017/01/26',400,"Pendiente",'2017/02/2',2,3);


insert into lineafacturapedido values (4,2,4,3);

Insert into producto values (5,"Paleta",0,200,'2017/01/20',1);
insert into lineafacturapedido values (5,1,5,3);

select producto.IdProducto;

call sucursales.EnvioPedido(3);

-- Parte 21 	

call sucursales.VerProductoEspecifico(2); 

-- Parte 22 y parte 20

call sucursales.VerPedidosEntregados();

-- Parte 23 
insert into facturapedido values (4,'2017/01/10',400,"Pendiente",'2017/01/13',2,1);
call sucursales.ConsultarFacturasVencidas();

-- Parte 24 
		
call sucursales.ReporteProduccion(1,'2017/01/10','2017/01/26',1);

-- Parte 25 
-- Ejecuar historiales punto 13


call sucursales.ReporteVentas(1,'2017/01/10','2017/01/26',2);

-- Parte26

insert into ganancia values (3,'2017/01/11',15000,1);
insert into ganancia values (4,'2017/01/12',15800,1);
         

call sucursales.ReporteGanaciasNeta (1,'2017/01/10','2017/01/26',2);      

-- Parte 27

insert into sucursales.pedido values (8,'2017-01-14',"Aprovado",1,2,1);	
call CrearFacturaPedido(7,'2017-01-14',"Pagado",'2017-01-17',1,8);
insert into lineafacturapedido values (10,2,3,7);-- da Valor 
insert into lineafacturapedido values (11,2,1,7);
call CalcularMontoFacturaPedido(7); 


insert into sucursales.pedido values (9,'2017-01-15',"Rechazado",1,1,2);
call CrearFacturaPedido(8,'2017-01-18',"Cancelado",'2017-01-21',1,9);
insert into lineafacturapedido values (12,1,2,8);-- No da Valor 
insert into lineafacturapedido values (13,2,2,8);
call CalcularMontoFacturaPedido(8); 

call sucursales.ReportePedidos(1,'2017/01/10','2017/01/26',1);    



