DELIMITER //  
Create procedure sucursales.EliminarProvincia(id int)
    begin
    start transaction;
		if id in (select provincia.IdProvin from provincia) then 
			delete from provincia where id = provincia.IdProvin;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.EliminarDireccion(id int)
    begin
    start transaction;
		if id in (select direccion.IdDireccion from direccion) then 
			delete from direccion where id = direccion.IdDireccion;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.EliminarPedido(id int)
    begin
    start transaction;
		if id in (select Pedido.IdPedido from Pedido) then 
			delete from Pedido where id = Pedido.IdPedido;
			commit;
        end if;   
	end;
    
DELIMITER //  
Create procedure sucursales.EliminarEmpleado(id int)
    begin
    start transaction;
		if id in (select Empleado.IdEmpleado from Empleado) then 
			delete from Empleado where id = Empleado.IdEmpleado;
			commit;
        end if;   
	end;    
  
DELIMITER //    
Create procedure sucursales.EliminarClienteMenu(id int)
	begin
    start transaction;
		if id in (select clientemenu.IdCliente from clientemenu) then 
			delete from clientemenu where id = clientemenu.IdCliente;
			commit;
        end if;   
	end;    
    
DELIMITER //  
Create procedure sucursales.EliminarClientePersona(id int)
    begin
    start transaction;
		if id in (select  clientepersona.IdCliente from clientepersona) then 
			delete from clientepersona where id = clientepersona.IdCliente;
			commit;
        end if;   
	end;    

DELIMITER //  
Create procedure sucursales.EliminarSucursal(id int)
    begin
    start transaction;
		if id in (select  Sucursal.IdSucursal from Sucursal) then 
			delete from Sucursal where id = Sucursal.IdSucursal;
			commit;
        end if;   
	end; 
    
DELIMITER //  
Create procedure sucursales.EliminarInventario(id int)
    begin
    start transaction;
		if id in (select  Inventario.IdInventario from Inventario) then 
			delete from Inventario where id = Inventario.IdInventario;
			commit;
        end if;   
	end;     
        
DELIMITER //  
Create procedure sucursales.EliminarProducto(id int)
    begin
    start transaction;
		if id in (select  Producto.IdProducto from Producto) then 
			delete from Producto where id = Producto.IdProducto;
			commit;
        end if;   
	end;       
    
DELIMITER //  
Create procedure sucursales.EliminarSolicitud(id int)
    begin
    start transaction;
		if id in (select  Solicitud.IdSolicitud from Solicitud) then 
			delete from Solicitud where id = Solicitud.IdSolicitud;
			commit;
        end if;   
	end;             
    
DELIMITER //  
Create procedure sucursales.EliminarHistorialVenta(id int)
    begin
    start transaction;
		if id in (select  HistorialVenta.IdHisotrialVenta from HistorialVenta) then 
			delete from HistorialVenta where id = HistorialVenta.IdHisotrialVenta;
			commit;
        end if;   
	end;    
    
 DELIMITER //  
Create procedure sucursales.EliminarFacturaPedido(id int)
    begin
    start transaction;
		if id in (select  facturapedido.IdFacturaPedido from facturapedido) then 
			delete from facturapedido where id = facturapedido.IdFacturaPedido;
			commit;
        end if;   
	end; 
    
DELIMITER //  
Create procedure sucursales.EliminarLineaFactPedido(id int)
    begin
    start transaction;
		if id in (select  lineafacturapedido.IdLineaFacturaPedido from lineafacturapedido) then 
			delete from lineafacturapedido where id = lineafacturapedido.IdLineaFacturaPedido;
			commit;
        end if;   
	end;     
    
 DELIMITER //  
Create procedure sucursales.EliminarFacturaCP(id int)
    begin
    start transaction;
		if id in (select  facturaclientepersona.IdFacturaCliente from facturaclientepersona) then 
			delete from facturaclientepersona where id = facturaclientepersona.IdFacturaCliente;
			commit;
        end if;   
	end;  
    
 DELIMITER //  
Create procedure sucursales.EliminarLineaFacturaCP(id int)
    begin
    start transaction;
		if id in (select  lineafacturacp.IdLineaFactura from lineafacturacp) then 
			delete from lineafacturacp where id = lineafacturacp.IdLineaFactura;
			commit;
        end if;   
	end;      
    
DELIMITER //  
Create procedure sucursales.EliminarTipoPago(id int)
    begin
    start transaction;
		if id in (select TipoPago.IdTipoPago from TipoPago) then 
			delete from TipoPago where id = TipoPago.IdTipoPago;
			commit;
        end if;   
	end;        

DELIMITER //  
Create procedure sucursales.EliminarTipoEmpleado(id int)
    begin
    start transaction;
		if id in (select tipoempleado.IdTipoEmpleado from tipoempleado) then 
			delete from tipoempleado where id = tipoempleado.IdTipoEmpleado;
			commit;
        end if;   
	end;      
    

     
       
    
    
DELIMITER //  
Create Procedure Sucursales.LimpiarTablas()
	begin 
		delete from clientepersona;
		delete from clientepersona;
		delete from detelleproducto;
		delete from direccion;
		delete from empleado;
		delete from facturaclientepersona;
		delete from  facturapedido;
		delete from ganancia;
		delete from historialventa;
		delete from inventario;
		delete from lineafacturacp;
		delete from lineafacturapedido;
		delete from pagoshacienda;
		delete from pedido;
		delete from producto;
		delete from productoxinventario;
		delete from provincia;
		delete from solicitud;
		delete from sucursal;
		delete from telefonocliente;
		delete from telefonoempleado;
		delete from telefonosucursal;
		delete from tipoempleado;
		delete from tipopago;
		delete from tipotelefono;
    end 