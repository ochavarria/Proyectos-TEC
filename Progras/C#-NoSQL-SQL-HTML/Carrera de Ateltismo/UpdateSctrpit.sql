Create Procedure spUpdateMovimientoSancion
@ID int,
@Fecha date,
@Monto int, 
@CxC int,
@TipoMovimientoSancion int

as 
	Begin 
		--Insertar Palabra clave--
		Update MovimientoSancion set Fecha=@Fecha,Monto=@Monto,CxC=@CxC,
		Tipo_Movimiento_Sancion=@TipoMovimientoSancion
		
		where ID=@ID 
	end

 