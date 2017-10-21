Use DisenoP1
-- ================================================
-- Template generated from Template Explorer using:
-- Create Procedure (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the procedure.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE agregarSolicitud
	@idSolicitud int, 
	@Fecha date, 
	@NombreSolicitante varchar(20),
	@idSolicitante int,
	@PeriodoLect varchar(20),
	@CodCurso varchar(20),
	@Grupo int, 
	@CarnetEst int,
	@NombreEst varchar(50),
	@CorreoEst varchar(50),
	@TeleEst int, 
	@TipoL varchar(50),
	@Detalle varchar(100),
	@Resolvido bit, 
	@Estado varchar(50)
	

AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--if not exists (select cedula from MIEMBROS where cedula=@cedula )
	insert into Solicitudes(idSolicitud,Fecha,NombreSolicitante,idSolicitante,PeriodoLect,CodCurso,Grupo,CarnetEst,NombreEst,CorreoEst,TeleEst,TipoL,Detalle,Resolvido,Estado)
	values (@idSolicitud,@Fecha,@NombreSolicitante,@idSolicitante,@PeriodoLect,@CodCurso,@Grupo,@CarnetEst,@NombreEst,@CorreoEst,@TeleEst,@TipoL,@Detalle,@Resolvido,@Estado)
END
GO

select * from Solicitudes