
DELIMITER //
Create Procedure Sucursales.VerSucursales()
    begin 
		Select Nombre,Provincia.NombreProvincia, Direccion.CodPostal,Direccion.Descripcion, telefonosucursal.Numero
		from Sucursal inner join Direccion on Sucursal.FK_Direccion = Direccion.IdDireccion
        inner join Provincia on direccion.FK_Provincia = Provincia.IdProvin 
        inner join Telefonosucursal on Telefonosucursal.IdTelefonoSucur = Sucursal.IdSucursal ;
	end


DELIMITER //
Create Procedure  Sucursales.VerEmpleados()
	begin
	Select CONCAT_WS(" ",empleado.Nombre,empleado.Apellido1,empleado.Apellido2 )as Nombre, tipoempleado.NombreTipo, Direccion.CodPostal, sucursal.Nombre
		from empleado inner join tipoempleado on empleado.FK_TipoEmpleado = tipoempleado.IdTipoEmpleado 
		inner join direccion on empleado.FK_Direccion = direccion.IdDireccion 
		inner join sucursal on empleado.FK_Sucursal = sucursal.IdSucursal;
	end
    
DELIMITER //
Create Procedure  Sucursales.VerProductos()
		begin
        Select producto.Nombre,producto.Impuesto,producto.Precio,producto.FechaExp,empleado.Nombre,sucursal.Nombre as Sucursal
			from producto inner join empleado on empleado.IdEmpleado = producto.FK_Empleado 
			inner join productoxinventario on productoxinventario.FK_Producto = producto.IdProducto
			inner join inventario on inventario.IdInventario= productoxinventario.FK_Inventario
			inner join sucursal on inventario.FK_Sucursal= sucursal.IdSucursal; 
        end
        
DELIMITER //
Create Procedure  Sucursales.VerCantProductosxInventario()
			begin
            select producto.Nombre,productoxinventario.ProductoUnidades as CantidadUnidades,sucursal.Nombre,
				(DATE_SUB(FechaExp,INTERVAL 2 DAY))as FechaCreacion,producto.FechaExp
				from producto inner join empleado on empleado.IdEmpleado = producto.FK_Empleado 
				inner join productoxinventario on productoxinventario.FK_Producto = producto.IdProducto
				inner join inventario on inventario.IdInventario= productoxinventario.FK_Inventario
				inner join sucursal on inventario.FK_Sucursal= sucursal.IdSucursal; 
		
            end 
        
DELIMITER //
Create Procedure  Sucursales.VerProductosDetalles()
	begin 
    Select producto.Nombre, detelleproducto.Titulo, detelleproducto.Descripcion from producto
		inner join detelleproducto on detelleproducto.Fk_Producto=producto.IdProducto 
		order by producto.Nombre;
	end

DELIMITER //
Create Procedure  Sucursales.VerHistorialVentas()
	begin 
	select producto.Nombre,producto.Precio,historialventa.Cantidad,historialventa.MontoTotal,historialventa.FechaVenta
		from producto inner join historialventa on historialventa.FK_Producto = producto.IdProducto
		order by producto.Nombre;
    end
    
DELIMITER //
Create Procedure  Sucursales.VerFacturasClientes()
	begin
    select CONCAT_WS(" ",clientepersona.Nombre,clientepersona.Apellido1,clientepersona.Apellido2)as Cliente, 
				facturaclientepersona.MontoTotal,facturaclientepersona.FechaFactura,tipopago.Nombre as MetodoPago
                from clientepersona inner join facturaclientepersona on facturaclientepersona.FK_Cliente= clientepersona.IdCliente
                inner join tipopago on  facturaclientepersona.FK_TipoPago = tipopago.IdTipoPago ;
    end

DELIMITER //    
Create Procedure  Sucursales.VerDetallesFacturasClientes()
	begin 
    select CONCAT_WS(" ",clientepersona.Nombre,clientepersona.Apellido1,clientepersona.Apellido2)as Cliente,
				lineafacturacp.Cantidad,facturaclientepersona.IdFacturaCliente as NumeroFactura, producto.Nombre,producto.Precio
                from clientepersona inner join facturaclientepersona on facturaclientepersona.FK_Cliente= clientepersona.IdCliente
                inner join lineafacturacp on lineafacturacp.FK_FacturaCliente= facturaclientepersona.IdFacturaCliente 
                inner join producto on lineafacturacp.Fk_Producto= producto.IdProducto
                order by facturaclientepersona.IdFacturaCliente;
	end
    
DELIMITER //    
Create Procedure  Sucursales.VerGanancias()
	begin
    select ganancia.FechaIng,ganancia.Monto, sucursal.Nombre as NombreSucursal
		from ganancia inner join sucursal on ganancia.FK_Sucursal=sucursal.IdSucursal;
    end 
    
DELIMITER //    
Create Procedure  Sucursales.VerPagosHacienda()
	begin
    select pagoshacienda.Monto, sucursal.Nombre as NombreSucursal , pagoshacienda.FechaPago as FechaPago
		from pagoshacienda inner join sucursal on pagoshacienda.FK_Sucursal=sucursal.IdSucursal;
    end
    
DELIMITER //    
Create Procedure  Sucursales.VerPedidosCM()
	begin
    select clientemenu.Nombre, pedido.FechaEntrega, pedido.Evaluacion, solicitud.FechaSolicitud, empleado.Nombre as Evaluador
		from pedido inner join clientemenu on pedido.FK_ClienteMenu= clientemenu.IdCliente
        inner join empleado on pedido.FK_Empleado= empleado.IdEmpleado
        inner join solicitud on pedido.FK_Solicitud = solicitud.IdSolicitud;
    end 
    
DELIMITER //    
Create Procedure  Sucursales.VerPedidosSolicutud()
	begin
    select solicitud.IdSolicitud as NumeroSolicitud ,solicitud.FechaSolicitud, pedido.FechaEntrega,pedido.Evaluacion,empleado.Nombre as Evaluador
		from solicitud inner join pedido on pedido.FK_Solicitud= solicitud.IdSolicitud
		inner join empleado on empleado.IdEmpleado= pedido.FK_Empleado
		order by solicitud.IdSolicitud;
    end 
    
DELIMITER //    
Create Procedure  Sucursales.VerFacturasPedido()
	begin 
    select facturapedido.IdFacturaPedido as NumerodePedido,facturapedido.IdFacturaPedido as NumeroFactura,facturapedido.FechaFactura,
		facturapedido.MontoTotal,facturapedido.Estado,facturapedido.FechaMorosidad,tipopago.Nombre
        from facturapedido inner join pedido on facturapedido.FK_Pedido= pedido.IdPedido 
			inner join tipopago on tipopago.IdTipoPago = facturapedido.FK_TipoPago ;
    end

DELIMITER //    
Create Procedure  Sucursales.VerDetallesFacturaPedido()
	begin
    select facturapedido.IdFacturaPedido as NumeroFactura, lineafacturapedido.IdLineaFacturaPedido as Linea, lineafacturapedido.Cantidad , producto.Nombre,producto.Precio 
		from lineafacturapedido inner join producto on lineafacturapedido.Fk_Producto=producto.IdProducto
        inner join facturapedido on lineafacturapedido.FK_FacturaPedido = facturapedido.IdFacturaPedido
        order by facturapedido.IdFacturaPedido;
    end
    
DELIMITER //    
Create Procedure  Sucursales.VerClientesPer()
	begin 
    select CONCAT_WS(" ",clientepersona.Nombre,clientepersona.Apellido1,clientepersona.Apellido2) as NombreCliente,
		direccion.Descripcion, clientepersona.IdCliente as Identificador, sucursal.Nombre from clientepersona
			inner join direccion on clientepersona.FK_Direccion = direccion.IdDireccion 
            inner join sucursal on clientepersona.FK_Sucursal = sucursal.IdSucursal;
	end 
    
DELIMITER //    
Create Procedure  Sucursales.VerClientesMenu()
	begin
		select clientemenu.Nombre,direccion.Descripcion,sucursal.Nombre from clientemenu
			inner join direccion on clientemenu.FK_Direccion= direccion.IdDireccion 
            inner join sucursal on clientemenu.FK_Sucursal = sucursal.IdSucursal;
	end
		
DELIMITER //   
Create Procedure Sucursales.VerTipoPagos()
	begin
		select tipopago.IdTipoPago,tipopago.Nombre from tipopago;
	end
    
DELIMITER //   
Create Procedure Sucursales.VerTipoEmpleado()
	begin
		select tipoempleado.IdTipoEmpleado,tipoempleado.NombreTipo from tipoempleado;
	end    
    
 DELIMITER //   
Create Procedure Sucursales.VerDirecciones()
	begin
		select direccion.Descripcion,provincia.NombreProvincia,direccion.CodPostal from direccion 
			inner join provincia on direccion.FK_Provincia = provincia.IdProvin ;
	end  
    
 DELIMITER //   
Create Procedure Sucursales.VerProvicias()
	begin
		select provincia.NombreProvincia from provincia;
	end 