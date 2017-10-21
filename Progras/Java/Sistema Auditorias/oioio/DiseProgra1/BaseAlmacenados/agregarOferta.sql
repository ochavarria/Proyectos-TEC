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
CREATE PROCEDURE agregarOferta
	
	@Grupo int ,
	@Aula varchar(20) , 
	@Dias varchar(20) ,
	@idCurso varchar(20) ,
	@idDocente int ,
	@periodo varchar(50)
	
	
	

AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--if not exists (select cedula from MIEMBROS where cedula=@cedula )
	insert into CursoAbiertos(Grupo,Aula,Dias,idCurso,idDocente,periodo)
	values (@Grupo,@Aula,@Dias,@idCurso,@idDocente,@periodo)
END
GO

select * from [dbo].[CursoAbiertos]