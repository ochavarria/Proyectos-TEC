
DELIMITER //  
Create procedure sucursales.ActualizarProvincia(id int,Nombre_Provin varchar(20))
    begin
    start transaction;
		if id in (select provincia.IdProvin from provincia) then 
			update provincia set provincia.NombreProvincia = Nombre_Provin
					where id = provincia.IdProvin;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.ActualizarClienteMenu(id int,Nombre varchar(20))
    begin
    start transaction;
		if id in (select clientemenu.IdCliente from clientemenu) then 
			update clientemenu set clientemenu.Nombre = Nombre
					where id = clientemenu.IdCliente;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.ActualizarClientePersona(id int,Nombre varchar(20),Ape1 varchar(20),Ape2 varchar(20))
    begin
    start transaction;
		if id in (select clientepersona.IdCliente from clientepersona) then 
			if(Ape1 is null) then 
				set Ape1 = (select clientepersona.Apellido1 from clientepersona where id = clientepersona.IdCliente );
			end if;
            
			if(Ape2 is null) then 
				set Ape2 = (select clientepersona.Apellido2 from clientepersona where id = clientepersona.IdCliente );
			end if;
            
			update clientepersona set clientepersona.Nombre = Nombre, clientepersona.Apellido1 =Ape1, clientepersona.Apellido2=Ape2
					where id = clientepersona.IdCliente;
			commit;
        end if;   
	end;    
    
    
DELIMITER //  
Create procedure sucursales.ActualizarProvincia(id int,Nombre_Provin varchar(20))
    begin
    start transaction;
		if id in (select provincia.IdProvin from provincia) then 
			update provincia set provincia.NombreProvincia = Nombre_Provin
					where id = provincia.IdProvin;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.ActualizarDireccion(id int,Descrip varchar(20),CodPost int )
    begin
    start transaction;
		if id in (select direccion.IdDireccion from direccion) then 
			if(Descrip is null) then 
				set Descrip = (select direccion.Descripcion from direccion where id = direccion.IdDireccion );
			end if;
            
            if(CodPost is null) then 
				set CodPost = (select  direccion.CodPostal from direccion where id = direccion.IdDireccion) ;
			end if;
        
			update direccion set direccion.Descripcion= Descrip , direccion.CodPostal=CodPost
					where id = direccion.IdDireccion;
			commit;
        end if;   
	end;
    
    

DELIMITER //  
Create procedure sucursales.ActualizarEmpleados (id int, Nombre varchar (20),Apellido1 varchar (20),Apellido2 varchar (20))
	begin
     start transaction;
		if id in (select empleado.IdEmpleado from empleado) then 
			if(Nombre is null) then 
				set Nombre = (select Empleado.Nombre from empleado where id = empleado.IdEmpleado );
			end if;
            
            if(Apellido1 is null) then 
				set Apellido1 = (select  empleado.Apellido1 from empleado where id = empleado.IdEmpleado) ;
			end if;
            
            if(Apellido2 is null) then 
				set Apellido2 = (select  empleado.Apellido2 from empleado where id = empleado.IdEmpleado) ;
			end if;		
            
			update empleado set empleado.Nombre= Nombre , empleado.Apellido1=Apellido1, empleado.Apellido2=Apellido2
					where id = empleado.IdEmpleado;
			commit;
        end if;     
    end;
    
 DELIMITER //  
Create procedure sucursales.ActualizarSucursal(id int,Nombre varchar(20))
    begin
    start transaction;
		if id in (select sucursal.IdSucursal from sucursal) then 
			if(Nombre is null) then 
				set Nombre = (select sucursal.Nombre from sucursal where id = sucursal.IdSucursal );
			end if;
        
			update sucursal set sucursal.Nombre= Nombre 
					where id = sucursal.IdSucursal;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.ActualizarProductos (id int, Nombre varchar (20),Impuesto int,Precio int)
	begin
     start transaction;
		if id in (select producto.IdProducto from producto) then 
			if(Nombre is null) then 
				set Nombre = (select producto.Nombre from producto where id = producto.IdProducto );
			end if;
            
            if(Impuesto is null) then 
				set Impuesto = (select  producto.Impuesto from producto where id = producto.IdProducto) ;
			end if;
            
            if(Precio is null) then 
				set Precio = (select  producto.Precio from producto where id = producto.IdProducto) ;
			end if;		
            
			update producto set producto.Nombre= Nombre , producto.Impuesto=Impuesto, producto.Precio=Precio
					where id = producto.IdProducto;
			commit;
        end if;     
    end; 

DELIMITER //  
Create procedure sucursales.ActualizarDetallesProductos(id int, Titulo varchar (20),Descripcion varchar (20))
    begin
    start transaction;
		if id in (select detelleproducto.IdDetalleProducto from detelleproducto) then 
			if(Titulo is null) then 
				set Titulo = (select detelleproducto.Titulo from detelleproducto where id = detelleproducto.IdDetalleProducto );
			end if;
            
            if(Descripcion is null) then 
				set Descripcion = (select  detelleproducto.Descripcion from detelleproducto where id = detelleproducto.IdDetalleProducto) ;
			end if;
        
			update detelleproducto set detelleproducto.Titulo= Titulo , detelleproducto.Descripcion=Descripcion
					where id = detelleproducto.IdDetalleProducto;
			commit;
        end if;   
	end;

DELIMITER //  
Create procedure sucursales.ActualizarCantidadUnidadesProd(IdProd int, IdInvent int , CantP int)
    begin
    start transaction;
		if IdProd in (select productoxinventario.FK_Producto from productoxinventario) 
					and IdInvent in (select productoxinventario.FK_Inventario from productoxinventario ) then 
			
            if(CantP is null) then 
				set CantP = (select productoxinventario.ProductoUnidades from productoxinventario 
					where IdProd = productoxinventario.FK_Producto and IdInvent = productoxinventario.FK_Inventario );
			end if;
            
			update productoxinventario set productoxinventario.ProductoUnidades= CantP
					where IdProd = productoxinventario.FK_Producto and IdInvent = productoxinventario.FK_Inventario;
			commit;
        end if;   
	end;		
    
DELIMITER //  
Create procedure sucursales.ActualizarHistorialVenta(id int, Cantidad int , MontoTotal int ,FechaVenta date)
	begin
     start transaction;
		if id in (select historialventa.IdHisotrialVenta from historialventa) then 
			if(Cantidad is null) then 
				set Cantidad = (select historialventa.Cantidad from historialventa where id = historialventa.IdHisotrialVenta );
			end if;
            
            if(MontoTotal is null) then 
				set MontoTotal = (select  historialventa.MontoTotal from historialventa where id = historialventa.IdHisotrialVenta) ;
			end if;
            
            if(FechaVenta is null) then 
				set FechaVenta = (select  historialventa.FechaVenta from historialventa where id = historialventa.IdHisotrialVenta) ;
			end if;		
            
			update historialventa set historialventa.Cantidad= Cantidad , historialventa.MontoTotal=MontoTotal, 
							historialventa.FechaVenta=FechaVenta
					where id = historialventa.IdHisotrialVenta;
			commit;
        end if;     
    end; 
    
DELIMITER //  
Create procedure sucursales.ActualizarFacturaClientePer(id int,FechaVenta date, MontoTotal int )
	begin
     start transaction;
		if id in (select facturaclientepersona.IdFacturaCliente from facturaclientepersona) then 
            
            if(FechaVenta is null) then 
				set FechaVenta = (select  facturaclientepersona.FechaFactura from facturaclientepersona 
					where id = facturaclientepersona.IdFacturaCliente) ;
			end if;		
            
            if(MontoTotal is null) then 
				set MontoTotal = (select  facturaclientepersona.MontoTotal from facturaclientepersona 
					where id = facturaclientepersona.IdFacturaCliente) ;
			end if;
            
			update facturaclientepersona set facturaclientepersona.FechaFactura= FechaVenta , 
				facturaclientepersona.MontoTotal=MontoTotal
					where id = facturaclientepersona.IdFacturaCliente;
			commit;
        end if;     
    end; 

DELIMITER //  
Create procedure sucursales.ActualizarLineaFactuCP(id int, Cant int )
    begin
    start transaction;
		if id in (select lineafacturacp.IdLineaFactura from lineafacturacp) then 
			if(Cant is null) then 
				set Cant = (select lineafacturacp.Cantidad from lineafacturacp where id = lineafacturacp.IdLineaFactura );
			end if;
        
			update lineafacturacp set lineafacturacp.Cantidad= Cant 
					where id = lineafacturacp.IdLineaFactura;
			commit;
        end if;   
	end;
    
    
DELIMITER //  
Create procedure sucursales.ActualizarFacturaPedido(id int,FechaVenta date, MontoTotal int ,Estado varchar(20),FechaMorosidad date)
	begin
     start transaction;
		if id in (select facturapedido.IdFacturaPedido from facturapedido) then 
            
            if(FechaVenta is null) then 
				set FechaVenta = (select  facturapedido.FechaFactura from facturapedido 
					where id = facturapedido.IdFacturaPedido) ;
			end if;		
            
            if(MontoTotal is null) then 
				set MontoTotal = (select  facturapedido.MontoTotal from facturapedido 
					where id = facturapedido.IdFacturaPedido) ;
			end if;
            
            if(Estado is null) then 
				set Estado = (select  facturapedido.Estado from facturapedido 
					where id = facturapedido.IdFacturaPedido) ;
			end if; 
 
			if(FechaMorosidad is null) then 
				set FechaMorosidad = (select  facturapedido.FechaMorosidad from facturapedido 
					where id = facturapedido.IdFacturaPedido) ;
			end if;
 
			update facturapedido set facturapedido.FechaFactura= FechaVenta ,facturapedido.MontoTotal=MontoTotal, 
					facturapedido.Estado=Estado, facturapedido.FechaMorosidad= FechaMorosidad	
					where id = facturapedido.IdFacturaPedido;
			commit;
        end if;     
    end;    
    
DELIMITER //  
Create procedure sucursales.ActualizarLineaFactuPedido(id int, Cant int )
    begin
    start transaction;
		if id in (select lineafacturapedido.IdLineaFacturaPedido from lineafacturapedido) then 
			if(Cant is null) then 
				set Cant = (select lineafacturapedido.Cantidad from lineafacturapedido 
						where id = lineafacturapedido.IdLineaFacturaPedido );
			end if;
        
			update lineafacturapedido set lineafacturapedido.Cantidad= Cant 
					where id = lineafacturapedido.IdLineaFacturaPedido;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.ActualizarGanancias(id int,Fecha date, Monto int )
	begin
     start transaction;
		if id in (select ganancia.IdGranacia from ganancia) then 
            
            if(Fecha is null) then 
				set Fecha = (select  ganancia.FechaIng from ganancia 
					where id = ganancia.IdGranacia) ;
			end if;		
            
            if(Monto is null) then 
				set Monto = (select  ganancia.Monto from ganancia 
					where id = ganancia.IdGranacia) ;
			end if;
            
			update ganancia set ganancia.FechaIng= Fecha , ganancia.Monto=Monto
					where id = ganancia.IdGranacia;
			commit;
        end if;     
    end; 
    
DELIMITER //  
Create procedure sucursales.ActualizarPagosHacienda(id int, Cant int, Fecha date)
    begin
    start transaction;
		if id in (select pagoshacienda.IdPagosHacienda from pagoshacienda) then 
			if(Cant is null) then 
				set Cant = (select pagoshacienda.Monto from pagoshacienda where id = pagoshacienda.IdPagosHacienda );
			end if;
			
			if(Fecha is null) then 
				set Fecha = (select  pagoshacienda.FechaPago from pagoshacienda 
					where id = pagoshacienda.IdPagosHacienda) ;
			end if;		
        
			update pagoshacienda set pagoshacienda.Monto= Cant, pagoshacienda.FechaPago=Fecha
					where id = pagoshacienda.IdPagosHacienda;
			commit;
        end if;   
	end;

DELIMITER //  
Create procedure sucursales.ActualizarTipoPago(id int,Nombre varchar(20))
    begin
    start transaction;
		if id in (select tipopago.IdTipoPago from tipopago) then 
			update tipopago set tipopago.Nombre = Nombre
					where id = tipopago.IdTipoPago;
			commit;
        end if;   
	end;
    

DELIMITER //  
Create procedure sucursales.ActualizarPedidos(id int,Fecha date,  Eval varchar(20))
    begin
    start transaction;
		if id in (select pedido.IdPedido from pedido) then 
			if(Fecha is null) then 
				set Fecha = (select pedido.FechaEntrega from pedido where id = pedido.IdPedido );
			end if;
			
			if(Eval is null) then 
				set Eval = (select  pedido.Evaluacion from pedido 
					where id = pedido.IdPedido) ;
			end if;		
        
			update pedido set pedido.FechaEntrega = Fecha, pedido.Evaluacion =Eval
					where id = pedido.IdPedido;
			commit;
        end if;   
	end;   
    
DELIMITER //  
Create procedure sucursales.ActualizarTipoEmpleado(id int,Nombre varchar(20))
    begin
    start transaction;
		if id in (select tipoempleado.IdTipoEmpleado from tipoempleado) then 
			update tipoempleado set tipoempleado.NombreTipo = Nombre
					where id = tipoempleado.IdTipoEmpleado;
			commit;
        end if;   
	end;
    
