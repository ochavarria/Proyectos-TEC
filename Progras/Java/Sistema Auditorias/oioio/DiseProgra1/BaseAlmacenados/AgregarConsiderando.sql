USE [DisenoP1]
GO
/****** Object:  StoredProcedure [dbo].[AgregarConsiderando]    Script Date: 21/04/2017 1:32:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
Create PROCEDURE [dbo].[AgregarConsiderando]
	@idSolicitud int,
	@Considerando varchar(max)
	 	

AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--if not exists (select cedula from MIEMBROS where cedula=@cedula )

	
	UPDATE Resoluciones
	SET considerandos = considerandos+ CHAR(13) +@Considerando
	WHERE idSolicitud=@idSolicitud;

END