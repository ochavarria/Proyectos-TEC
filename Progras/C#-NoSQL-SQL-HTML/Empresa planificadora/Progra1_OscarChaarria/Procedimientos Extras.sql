SELECT producto.IdProducto FROM producto;
-- Punto 14
DELIMITER // 
Create procedure Sucursales.ProductosBajos()
	begin 
		DECLARE v_finished INTEGER DEFAULT 0;
        
        DECLARE ProductosNombre varchar(100) DEFAULT "";
        
        Declare ProductoFetch varchar(100) ;
        
        Declare Mes1 int; 
        Declare Mes2 int; 
        Declare Mes3 int; 
        
		DEClARE Productosids CURSOR FOR 
			SELECT producto.IdProducto FROM producto;
		
        DECLARE CONTINUE HANDLER 
			FOR NOT FOUND SET v_finished = 1;
		
        OPEN Productosids;
         
		get_Productos: LOOP
			FETCH Productosids INTO ProductoFetch;
			
            IF v_finished = 1 THEN 
				LEAVE get_Productos;
			END IF;
			
			set Mes1= (select (sum(historialventa.MontoTotal)) as Total from producto 
				inner join historialventa on historialventa.FK_Producto = producto.IdProducto
					where historialventa.FechaVenta between (DATE_SUB(curdate(), INTERVAL 1 MONTH)) and curdate() and 
                    ProductoFetch= producto.IdProducto
				group by producto.IdProducto );
			
			set Mes2=(select (sum(historialventa.MontoTotal)) as Total from producto 
				inner join historialventa on historialventa.FK_Producto = producto.IdProducto
					where historialventa.FechaVenta between (DATE_SUB(curdate(), INTERVAL 2 MONTH)) and (DATE_SUB(curdate(), INTERVAL 1 MONTH)) and
                    ProductoFetch= producto.IdProducto
				group by producto.IdProducto );
			
			set Mes3= (select (sum(historialventa.MontoTotal)) as Total from producto 
				inner join historialventa on historialventa.FK_Producto = producto.IdProducto
					where historialventa.FechaVenta between (DATE_SUB(curdate(), INTERVAL 3 MONTH)) and (DATE_SUB(curdate(), INTERVAL 2 MONTH)) and
					ProductoFetch= producto.IdProducto
                group by producto.IdProducto );

            If not((Mes3<Mes2)and(Mes2<Mes1)) then 
					SET ProductosNombre = CONCAT((select Producto.Nombre from producto where ProductoFetch = producto.IdProducto ),";",ProductosNombre);
				end if; 
            
			END LOOP get_Productos;
		close Productosids;
        
        select ProductosNombre;-- Lo devuelvo asi no se pueden crear temp tables. 
	end
-- Punto 14 

 DELIMITER //         
Create Procedure CrearFacturaCP(id int, Fecha date, Cliente int, ModoPago int)
    begin
    start transaction;
		insert into facturaclientepersona values (id,Fecha,0, Cliente,ModoPago );
        commit; 
	end;

    
DELIMITER //  
Create Procedure CrearLineaFactCP(id int, cantidad int,Produc int,FCP int )
    begin
    start transaction;
		insert into lineafacturacp values (id,cantidad,Produc,FCP );
        commit; 
	end;

DELIMITER //  
Create Procedure CalcularMontoFacturaCP (idfact int )
    begin
    declare MontoT int;
	declare MontoSinimp int; 
    declare ModoPago varchar(20);
    declare FechaFact date; 
    declare sucursal int;
    
    start transaction;
		set MontoT=(select(sum(lineafacturacp.Cantidad*((producto.Impuesto*producto.Precio/100)+producto.Precio)))
			from facturaclientepersona inner join lineafacturacp on lineafacturacp.FK_FacturaCliente=facturaclientepersona.IdFacturaCliente
				inner join producto on lineafacturacp.Fk_Producto = producto.IdProducto
            where facturaclientepersona.IdFacturaCliente=idfact group by facturaclientepersona.IdFacturaCliente);
		update facturaclientepersona set facturaclientepersona.MontoTotal = MontoT 
			where facturaclientepersona.IdFacturaCliente = idfact;	
        
        set modoPago=(select tipopago.Nombre from facturaclientepersona inner join tipopago on facturaclientepersona.FK_TipoPago= tipopago.IdTipoPago 
					where facturaclientepersona.IdFacturaCliente =idfact);
				
                if (modoPago="Tarjeta") then 
                
						set MontoSinimp=(select(sum(lineafacturacp.Cantidad*producto.Precio))
							from facturaclientepersona inner join lineafacturacp on lineafacturacp.FK_FacturaCliente =facturaclientepersona.IdFacturaCliente
								inner join producto on lineafacturacp.Fk_Producto = producto.IdProducto
							where facturaclientepersona.IdFacturaCliente =idfact group by facturaclientepersona.IdFacturaCliente );
						
						set FechaFact= (select facturaclientepersona.FechaFactura from facturaclientepersona where facturaclientepersona.IdFacturaCliente =idfact);
                        
                        set sucursal= (select sucursal.IdSucursal from facturaclientepersona inner join clientepersona on facturaclientepersona.FK_Cliente = clientepersona.IdCliente
                                        inner join sucursal on clientepersona.FK_Sucursal = sucursal.IdSucursal
                                        where facturaclientepersona.IdFacturaCliente =idfact group by facturaclientepersona.IdFacturaCliente );
                                        
                        
						insert into pagoshacienda (pagoshacienda.Monto,pagoshacienda.FechaPago,pagoshacienda.FK_Sucursal) 
							values ( (MontoSinimp*15/100),FechaFact,sucursal);
				end if;      
        commit; 
	end;
    
-- b 

 DELIMITER //         
Create Procedure CrearFacturaPedido(id int, Fecha date, Est varchar(20),FechaM date,ModoPago int,Pedido  int)
    begin
    start transaction;
		insert into facturapedido values (id,Fecha,0,Est,FechaM,ModoPago,Pedido );
        commit; 
	end;
    
DELIMITER //  
Create Procedure CrearLineaFactPedido(id int, cantidad int,Produc int,FPedido int )
    begin
    start transaction;
		insert into lineafacturapedido values (id,cantidad,Produc,FPedido );
        commit; 
	end;
    
 DELIMITER //  
Create Procedure CalcularMontoFacturaPedido (idfact int )
    begin
    declare MontoT int;
    declare MontoSinimp int; 
    declare ModoPago varchar(20);
    declare FechaFact date; 
    declare sucursal int;
    
    start transaction;
		set MontoT=(select(sum(lineafacturapedido.Cantidad*((producto.Impuesto*producto.Precio/100)+producto.Precio)))
			from facturapedido inner join lineafacturapedido on lineafacturapedido.FK_FacturaPedido =facturapedido.IdFacturaPedido
				inner join producto on lineafacturapedido.Fk_Producto = producto.IdProducto
            where facturapedido.IdFacturaPedido =idfact group by facturapedido.IdFacturaPedido );
            
		update facturapedido set facturapedido.MontoTotal = MontoT 
			where facturapedido.IdFacturaPedido = idfact;
		
        set modoPago=(select tipopago.Nombre from facturapedido inner join tipopago on facturapedido.FK_TipoPago= tipopago.IdTipoPago 
					where facturapedido.IdFacturaPedido =idfact);
				
                if (modoPago="Tarjeta") then 
                
						set MontoSinimp=(select(sum(lineafacturapedido.Cantidad*producto.Precio))
						from facturapedido inner join lineafacturapedido on lineafacturapedido.FK_FacturaPedido =facturapedido.IdFacturaPedido
							inner join producto on lineafacturapedido.Fk_Producto = producto.IdProducto
						where facturapedido.IdFacturaPedido =idfact group by facturapedido.IdFacturaPedido );
						
						set FechaFact= (select facturapedido.FechaFactura from facturapedido where facturapedido.IdFacturaPedido =idfact);
                        set sucursal= (select sucursal.IdSucursal from facturapedido inner join pedido on facturapedido.FK_Pedido = pedido.IdPedido
										inner join solicitud on solicitud.IdSolicitud = pedido.FK_Solicitud 
                                        inner join sucursal on solicitud.FK_Sucursal = sucursal.IdSucursal
                                        where facturapedido.IdFacturaPedido =idfact group by facturapedido.IdFacturaPedido );
                                        
                        
						insert into pagoshacienda (pagoshacienda.Monto,pagoshacienda.FechaPago,pagoshacienda.FK_Sucursal) 
							values ( (MontoSinimp*15/100),FechaFact,sucursal);
				end if;
						
        commit; 
	end;   
    
 DELIMITER //    
Create Procedure  Sucursales.VerPedidosCMEntreSemana(fechaini date)
	begin
    declare fechasemana date;
    set fechasemana= (DATE_ADD(fechaini,INTERVAL 7 DAY));
    
    select clientemenu.Nombre, pedido.FechaEntrega, pedido.Evaluacion, solicitud.FechaSolicitud, empleado.Nombre as Evaluador
		from pedido inner join clientemenu on pedido.FK_ClienteMenu= clientemenu.IdCliente
        inner join empleado on pedido.FK_Empleado= empleado.IdEmpleado
        inner join solicitud on pedido.FK_Solicitud = solicitud.IdSolicitud
			where pedido.FechaEntrega between fechaini and fechasemana; 
    end   

 DELIMITER //    
Create Procedure Sucursales.EnvioPedido(id int)
	begin
    declare Expirados int;
    start transaction;
		set Expirados = (select count(producto.IdProducto) from pedido inner join facturapedido on facturapedido.FK_Pedido = pedido.IdPedido
				inner join lineafacturapedido on lineafacturapedido.FK_FacturaPedido = facturapedido.IdFacturaPedido
				inner join producto on lineafacturapedido.Fk_Producto where producto.FechaExp<curdate() and pedido.IdPedido=id);
	
		if (Expirados > 0) then 
			update pedido set pedido.Evaluacion= "Rechazado";
			commit;
		end if;
        
	end;
			
DELIMITER //
Create Procedure  Sucursales.VerProductoEspecifico(id int )
		begin
        Select producto.Nombre,producto.Impuesto,producto.Precio,producto.FechaExp,empleado.Nombre,sucursal.Nombre as Sucursal
			from producto inner join empleado on empleado.IdEmpleado = producto.FK_Empleado 
			inner join productoxinventario on productoxinventario.FK_Producto = producto.IdProducto
			inner join inventario on inventario.IdInventario= productoxinventario.FK_Inventario
			inner join sucursal on inventario.FK_Sucursal= sucursal.IdSucursal where producto.IdProducto= id; 
        end            
			
 DELIMITER //    
Create Procedure Sucursales.VerPedidosEntregados()
	begin
		select pedido.FechaEntrega, pedido.Evaluacion,pedido.IdPedido as numeroPedido from pedido 
			where Pedido.Evaluacion="Aprovado" and pedido.FechaEntrega < DATE_ADD(curdate(),INTERVAL 1 DAY);
	end;
    
 DELIMITER //    
Create Procedure Sucursales.ConsultarFacturasVencidas()
	begin 
		declare FechaVencimiento date ;
        set FechaVencimiento= DATE_SUB(curdate(),INTERVAL 6 DAY);
		select facturapedido.IdFacturaPedido,facturapedido.FechaMorosidad,facturapedido.Estado from facturapedido
			where facturapedido.FechaMorosidad < FechaVencimiento and facturapedido.Estado= "Pendiente";
	end;
   
 DELIMITER //     
Create Procedure sucursales.ReporteProduccion(Sucursalid int, Fechaini date, fechafin date, productoid int)
	begin 
		if ( Sucursalid is not null and Fechaini is not null and fechafin is not null and productoid is not null)then
        
			select sum( productoxinventario.ProductoUnidades),producto.Nombre from sucursal 
			 inner join inventario on inventario.FK_Sucursal= sucursal.IdSucursal
			 inner join productoxinventario on productoxinventario.FK_Inventario=IdInventario
			 inner join producto on productoxinventario.FK_Producto=producto.IdProducto
			 where producto.FechaExp between fechaini and fechafin and sucursal.IdSucursal= Sucursalid
			 and producto.IdProducto=productoid;
		end if;
	end;


DELIMITER //     
Create Procedure sucursales.ReporteVentas (Sucursalid int, Fechaini date, fechafin date, productoid int)
	begin 
		if ( Sucursalid is not null and Fechaini is not null and fechafin is not null and productoid is not null)then
			select sum(historialventa.MontoTotal)as VentaTotal ,producto.Nombre,sucursal.Nombre from sucursal 
			 inner join inventario on inventario.FK_Sucursal= sucursal.IdSucursal
			 inner join productoxinventario on productoxinventario.FK_Inventario=IdInventario
			 inner join producto on productoxinventario.FK_Producto=producto.IdProducto
			 inner join historialventa on historialventa.FK_Producto=producto.IdProducto
			 where historialventa.FechaVenta between fechaini and fechafin and sucursal.IdSucursal= Sucursalid
				and producto.IdProducto=productoid
				group by sucursal.IdSucursal;
		end if;
	end;
    
    
DELIMITER //     
Create Procedure sucursales.ReporteGanaciasNeta (Sucursalid int, Fechaini date, fechafin date, productoid int)
	begin
		if ( Sucursalid is not null and Fechaini is not null and fechafin is not null and productoid is not null)then
			select sum( ganancia.Monto),sucursal.Nombre,sucursal.Nombre from sucursal 
			 inner join inventario on inventario.FK_Sucursal= sucursal.IdSucursal
			 inner join productoxinventario on productoxinventario.FK_Inventario=IdInventario
			 inner join producto on productoxinventario.FK_Producto=producto.IdProducto
			 inner join ganancia on ganancia.FK_Sucursal=sucursal.IdSucursal
			 where ganancia.FechaIng between fechaini and fechafin and sucursal.IdSucursal= Sucursalid
				and producto.IdProducto=productoid	
			 group by sucursal.IdSucursal;
		end if;
	end;
			
DELIMITER //     
Create Procedure sucursales.ReportePedidos(Sucursalid int, Fechaini date, fechafin date, productoid int)
	begin 
		if ( Sucursalid is not null and Fechaini is not null and fechafin is not null and productoid is not null)then
			select sum( facturapedido.MontoTotal)as VentaTotal,producto.Nombre,sucursal.Nombre from sucursal 
			inner join solicitud on solicitud.FK_Sucursal=sucursal.IdSucursal
			inner join pedido on pedido.FK_Solicitud=solicitud.IdSolicitud
			inner join facturapedido on facturapedido.FK_Pedido=pedido.IdPedido
			inner join lineafacturapedido on lineafacturapedido.FK_FacturaPedido=facturapedido.IdFacturaPedido
			inner join producto on lineafacturapedido.Fk_Producto=producto.IdProducto
			 where pedido.FechaEntrega between fechaini and fechafin and sucursal.IdSucursal= Sucursalid
			 and producto.IdProducto=productoid;
		end if;
	end; 
    
    