Create Procedure spDeleteTipoMovimientoSancion
@ID int
as 
	Begin 
		--Insertar Palabra clave--
		Delete TipoMovimientoSancion where ID=@ID
	end

Execute spInsertCarrera @ID= 1 