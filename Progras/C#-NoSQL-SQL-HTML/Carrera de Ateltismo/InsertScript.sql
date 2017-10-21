Create Procedure spInsertMovimientoSancion
@ID int,
@Fecha date,
@Monto int, 
@CxC int,
@TipoMovimientoSancion int

as 
	Begin 
		--Insertar Palabra clave--
		Insert into MovimientoSancion(ID ,Fecha,Monto, CxC,Tipo_Movimiento_Sancion)
		Values(@ID,@Fecha,@Monto,@CxC,@TipoMovimientoSancion) 
	end

Execute spInsertCarrera @ID= 1 