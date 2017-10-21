
use DisenoP1;

BULK
INSERT Docentes
FROM 'C:\Users\Usuario\Desktop\p.csv'
WITH
(
 FIRSTROW = 2,
    FIELDTERMINATOR = ';',  --CSV field delimiter
    ROWTERMINATOR = '\n',   --Use to shift the control to next row
    TABLOCK
)
GO


BULK
INSERT Cursos
FROM 'C:\Users\Usuario\Desktop\c.csv'
WITH
(
 FIRSTROW = 2,
    FIELDTERMINATOR = ';',  --CSV field delimiter
    ROWTERMINATOR = '\n',   --Use to shift the control to next row
    TABLOCK
)
GO

BULK
INSERT CursoAbiertos
FROM 'C:\Users\Usuario\Desktop\ca.csv'
WITH
(
 FIRSTROW = 2,
    FIELDTERMINATOR = ';',  --CSV field delimiter
    ROWTERMINATOR = '\n',   --Use to shift the control to next row
    TABLOCK
)
GO

