USE [DisenoP1]
GO
/****** Object:  StoredProcedure [dbo].[agregarResolucion]    Script Date: 21/04/2017 1:26:38 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
Create PROCEDURE [dbo].[agregarResolucion]
	@Codigo varchar(max), 
	@Fecha date, 
	@Coordinador varchar(max),
	@NombreAr varchar(max),
	@NombreDirector varchar(max),
	@idSolicitud int
	
	
	

AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--if not exists (select cedula from MIEMBROS where cedula=@cedula )
	insert into Resoluciones(Codigo,Fecha,Coordinador,NombreAr,NombreDirector,idSolicitud,Considerandos)
	values (@Codigo,@Fecha,@Coordinador,@NombreAr,@NombreDirector,@idSolicitud,'')
END
