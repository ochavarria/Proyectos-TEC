
--
-- Dumping routines for database 'mydb'
--
/* Rutina para agregar a cualquier estudiante a un curso, se utiliza en vez del insert. Crea la calificacion del curso para el estudiante tambien */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `agregar_estudiante_curso`(IN pIdEstudiante INT, IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

INSERT INTO `mydb`.`c_x_p_x_estudiante`
(`Curso_X_Profesor_Curso_idCurso`,
`Curso_X_Profesor_Profesor_idProfesor`,
`Estudiante_idEstudiante`)
VALUES
(pIdCurso,
pIdProfesor,
pIdEstudiante);


INSERT INTO `mydb`.`calificacion_curso`
(
`finalizada`,
`Curso_idCurso`,
`Estudiante_idEstudiante`,
`Profesor_idProfesor`)
VALUES
(0,
pIdCurso,
pIdEstudiante,
pIdProfesor);

END ;;
DELIMITER ;


/* Rutina para crear una asignacion, de misma forma crea una calificacion para todos los estudiantes del curso  */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `crear_asignacion_calificacion`(IN pNombre VARCHAR(45), IN pDescripcion VARCHAR(255), IN pFecha date, IN pHora time, IN pMedio VARCHAR(45), IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

DECLARE idActual INT;
DECLARE v_finished INTEGER DEFAULT 0;
DECLARE idAsignado INT;
DEClARE cursor_estudiantes CURSOR FOR 
 select idEstudiante from Estudiante inner join c_x_p_x_estudiante 
where c_x_p_x_estudiante.Curso_X_Profesor_Curso_idCurso = pIdCurso and 
c_x_p_x_estudiante.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor and
c_x_p_x_estudiante.Estudiante_idEstudiante = Estudiante.idEstudiante;
DECLARE CONTINUE HANDLER 
        FOR NOT FOUND SET v_finished = 1;
CALL `mydb`.`crear_asignacion_individual`(pNombre, pDescripcion, pFecha, pHora, pMedio, pIdCurso, pIdProfesor);
SET idAsignado = last_insert_id();

OPEN cursor_estudiantes;

crear_calificaciones: LOOP

FETCH cursor_estudiantes into idActual;

IF v_finished = 1 THEN 
 LEAVE crear_calificaciones;
 END IF;

INSERT INTO `mydb`.`calificacion`
(`Estudiante_idEstudiante`,
`Asignacion_Individual_idAsignacion_Individual`)
VALUES
( idActual,
idAsignado
);

END LOOP crear_calificaciones;
 
 CLOSE cursor_estudiantes;



END ;;
DELIMITER ;
/* rutina para crear asignaciones grupales */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `crear_asignacion_grupal`(IN pNombre VARCHAR(45), IN pDescripcion VARCHAR(255), IN pFecha date, IN pHora time, IN pMedio VARCHAR(45), IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

INSERT INTO `mydb`.`asignacion_grupal`
(`nombre`,
`descripcion`,
`fecha`,
`hora`,
`medio_entrega`,
`Curso_X_Profesor_Curso_idCurso`,
`Curso_X_Profesor_Profesor_idProfesor`)
VALUES
(pNombre,
pDescripcion,
pFecha,
pHora,
pMedio,
pIdCurso,
pIdProfesor);

END ;;
DELIMITER 

/* subrutina de crear asignacion con calificacion */ 
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `crear_asignacion_individual`(IN pNombre VARCHAR(45), IN pDescripcion VARCHAR(255), IN pFecha date, IN pHora time, IN pMedio VARCHAR(45), IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

INSERT INTO `mydb`.`asignacion_individual`
(`nombre`,
`descripcion`,
`fecha`,
`hora`,
`medio_entrega`,
`Curso_X_Profesor_Curso_idCurso`,
`Curso_X_Profesor_Profesor_idProfesor`)
VALUES
(pNombre,
pDescripcion,
pFecha,
pHora,
pMedio,
pIdCurso,
pIdProfesor);

END ;;
DELIMITER ;

/*rutina para crear un grupo con dos miembros, crea la calificacion grupal tambien */ 
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `crear_duo`(IN pIdAsignacion INT, IN pIdUno INT, IN pIdDos INT)
BEGIN

DECLARE idActual INT;
INSERT INTO `mydb`.`grupo`
(`Asignacion_Grupal_idAsignacion_Grupal`)
VALUES
(pIdAsignacion);

SET idActual = last_insert_id();

INSERT INTO `mydb`.`estudiante_x_grupo`
(`Estudiante_idEstudiante`,
`grupo_idgrupo`)
VALUES
(pIdUno,
idActual);

INSERT INTO `mydb`.`estudiante_x_grupo`
(`Estudiante_idEstudiante`,
`grupo_idgrupo`)
VALUES
(pIdDos,
idActual);

INSERT INTO `mydb`.`calificacion_grupal`
(`grupo_idgrupo`,
`Asignacion_Grupal_idAsignacion_Grupal`)
VALUES
(idActual,
pIdAsignacion);



END ;;
DELIMITER ;

/*rutina para crear un grupo con tres miembros, crea la calificacion grupal tambien */ 
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `crear_trio`(IN pIdAsignacion INT, IN pIdUno INT, IN pIdDos INT, pIdTres INT)
BEGIN

DECLARE idActual INT;
INSERT INTO `mydb`.`grupo`
(`Asignacion_Grupal_idAsignacion_Grupal`)
VALUES
(pIdAsignacion);

SET idActual = last_insert_id();

INSERT INTO `mydb`.`estudiante_x_grupo`
(`Estudiante_idEstudiante`,
`grupo_idgrupo`)
VALUES
(pIdUno,
idActual);

INSERT INTO `mydb`.`estudiante_x_grupo`
(`Estudiante_idEstudiante`,
`grupo_idgrupo`)
VALUES
(pIdDos,
idActual);

INSERT INTO `mydb`.`estudiante_x_grupo`
(`Estudiante_idEstudiante`,
`grupo_idgrupo`)
VALUES
(pIdTres,
idActual);

INSERT INTO `mydb`.`calificacion_grupal`
(`grupo_idgrupo`,
`Asignacion_Grupal_idAsignacion_Grupal`)
VALUES
(idActual,
pIdAsignacion);


END ;;
DELIMITER ;

/*consultar los cursos a los cuales esta asignado el estudiante*/ 
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `cursos_estudiante`(IN pIdEstudiante int)
BEGIN
SELECT idCurso, nombre from curso inner join c_x_p_x_estudiante where curso.idCurso = c_x_p_x_estudiante.Curso_X_Profesor_Curso_idCurso and c_x_p_x_estudiante.Estudiante_idEstudiante = pIdEstudiante;

END ;;
DELIMITER ;

/*consultar los cursos que da un profesor*/
/DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `cursos_profesor`(IN pIdProfesor int)
BEGIN
SELECT idCurso, nombre from curso inner join curso_x_profesor where curso.idCurso = curso_x_profesor.Curso_idCurso and curso_x_profesor.Profesor_idProfesor = pIdProfesor;

END ;;
DELIMITER ;

/*consulta para saber cuales estudiantes integran el grupo del curso que da el profesor*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `estudiantes_en_curso`(IN pIdProfesor INT, IN pIdCurso INT)
BEGIN

select idEstudiante, nombre, apellido from Estudiante inner join c_x_p_x_estudiante 
where c_x_p_x_estudiante.Curso_X_Profesor_Curso_idCurso = pIdCurso and 
c_x_p_x_estudiante.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor and
c_x_p_x_estudiante.Estudiante_idEstudiante = Estudiante.idEstudiante;

END ;;
DELIMITER ;

/*da valor a la nota global del curso*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_nota_curso`(IN pIdCalificacion INT, IN pNota INT)
BEGIN

UPDATE `mydb`.`calificacion_curso`
SET
`nota_final` = pNota,
`finalizada` = 1
WHERE `idCalificacion_Curso` = pIdCalificacion;



END ;;
DELIMITER ;

/*da valor a la nota de una asignacion grupal*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_nota_grupal`(IN pIdCalificacion INT, IN pNota INT)
BEGIN

UPDATE `mydb`.`calificacion_grupal`
SET
`nota` = pNota
WHERE `idCalificacion_Grupal` = pIdCalificacion;



END ;;
DELIMITER ;

/* da valor a una nota de una asignacion individual*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_nota_individual`(IN pIdCalificacion INT, IN pNota INT)
BEGIN

UPDATE `mydb`.`calificacion`
SET
`nota` = pNota
WHERE `idCalificacion` = pIdCalificacion;



END ;;
DELIMITER ;

/*da valor al porcentaje de la nota global que tiene una asignacion grupal*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_porcentaje_grupal`(IN pIdCalificacion INT, IN pPorcentaje DOUBLE)
BEGIN

UPDATE `mydb`.`calificacion_grupal`
SET
`porcentaje` = pPorcentaje
WHERE `idCalificacion_Grupal` = pIdCalificacion;



END ;;
DELIMITER ;

/*da valor al porcentaje de una nota de una asignacion individual a la nota global*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_porcentaje_individual`(IN pIdCalificacion INT, IN pPorcentaje DOUBLE)
BEGIN

UPDATE `mydb`.`calificacion`
SET
`porcentaje` = pPorcentaje
WHERE `idCalificacion` = pIdCalificacion;



END ;;
DELIMITER ;

/* ve todas las asignaciones de un curso*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_asignaciones_curso`(IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

SELECT Distinct idAsignacion_Individual, nombre, descripcion, fecha, asignacion_individual.hora, medio_entrega from asignacion_individual
inner join curso_x_profesor where 
asignacion_individual.Curso_X_Profesor_Curso_idCurso = pIdCurso 
and asignacion_individual.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor;
END ;;
DELIMITER ;

/* ve todas las asignaciones grupales de un curso*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_asignaciones_grupales`(IN pIdCurso INT, IN pIdProfesor INT)
BEGIN

SELECT Distinct idAsignacion_Grupal, nombre, descripcion, fecha, asignacion_individual.hora, medio_entrega from asignacion_individual
inner join curso_x_profesor where 
asignacion_individual.Curso_X_Profesor_Curso_idCurso = pIdCurso 
and asignacion_individual.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor;
END ;;
DELIMITER ;

/*Ve todas las calificaciones de cada asignacion individual de un estudiante para un curso */
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_calificaciones_curso`(IN pIdCurso INT, IN pIdProfesor INT, IN pIdEstudiante INT)
BEGIN

SELECT distinct a.idAsignacion_Individual, c.idCalificacion, a.nombre, a.descripcion, a.fecha, a.hora, a.medio_entrega, c.nota, c.porcentaje 
from asignacion_individual a
inner join curso_x_profesor cp on 
a.Curso_X_Profesor_Curso_idCurso = pIdCurso 
and a.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor
inner join calificacion c on
a.idAsignacion_Individual = c.Asignacion_Individual_idAsignacion_Individual
and c.Estudiante_idEstudiante = pIdEstudiante;
END ;;
DELIMITER ;
/* ve calificaciones grupales de un grupo designado*/ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_calificaciones_grupales`(IN pIdCurso INT, IN pIdProfesor INT, pIdGrupo INT)
BEGIN

SELECT distinct a.idAsignacion_Grupal, c.idCalificacion, a.nombre, a.descripcion, a.fecha, a.hora, a.medio_entrega, c.nota, c.porcentaje 
from asignacion_grupal a
inner join curso_x_profesor cp on 
a.Curso_X_Profesor_Curso_idCurso = pIdCurso 
and a.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor
inner join calificacion_grupal c on
a.idAsignacion_Grupal = c.Asignacion_Grupal_idAsignacion_Grupal
and c.grupo_idgrupo = pIdGrupo;

END ;;
DELIMITER ;

/*ve los miembros de un grupo para una asignacion grupal*/
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_estudiantes_grupo`(IN pIdGrupo INT)
BEGIN

SELECT distinct nombre, apellido from estudiante inner join estudiante_x_grupo 
where estudiante_x_grupo.grupo_idgrupo = pIdGrupo and
estudiante_x_grupo.Estudiante_idEstudiante = idEstudiante;

END ;;
DELIMITER ;

/* ve todas las dudas de un estudiante */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_historial_dudas`(IN pIdEstudiante INT)
BEGIN

SELECT duda_reclamo.idDuda_Reclamo, duda_reclamo.tipo, duda_reclamo.descripcion, profesor.nombre, profesor.apellido  from duda_reclamo
inner join profesor where duda_reclamo.Estudiante_idEstudiante = pIdEstudiante and duda_reclamo.Profesor_idProfesor = Profesor.idProfesor;

END ;;
DELIMITER ;

/*ve un historial de todas las notas globales de los cursos llevados*/ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_historial_notas`(IN pIdEstudiante INT)
BEGIN

SELECT distinct c.nombre, c.numeroCreditos, n.nota_final from calificacion_curso n 
inner join curso c on n.Estudiante_idEstudiante = pIdEstudiante and n.Curso_idCurso = c.idCurso;



END ;;
DELIMITER ;

DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ver_IDcalificaciones_curso`(IN pIdCurso INT, IN pIdProfesor INT, IN pIdEstudiante INT, IN pIdAsignacion INT)
BEGIN

SELECT distinct c.idCalificacion
from asignacion_individual a
inner join curso_x_profesor cp on 
a.Curso_X_Profesor_Curso_idCurso = pIdCurso 
and a.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor
inner join calificacion c on
a.idAsignacion_Individual = c.Asignacion_Individual_idAsignacion_Individual
and c.Estudiante_idEstudiante = pIdEstudiante where pIdAsignacion= a.idAsignacion_Individual;
END;;
DELIMITER ;

DELIMITER $$
CREATE DEFINER=`root`@`localhost` PROCEDURE `sumar_notas`(IN pIdEstudiante INT, IN pIdCurso INT, IN pIdProfesor INT)
BEGIN
DECLARE valor INT;
DECLARE total INT;
DECLARE pIdCalificacion INT;

select sum(calificacion.nota) into valor from calificacion inner join c_x_p_x_estudiante where calificacion.nota IS NOT NULL 
and calificacion.Estudiante_idEstudiante = pIdEstudiante
and c_x_p_x_estudiante.Curso_X_Profesor_Curso_idCurso = pIdCurso
and c_x_p_x_estudiante.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor
and c_x_p_x_estudiante.Estudiante_idEstudiante = pIdEstudiante;

select count(calificacion.nota) into total from calificacion inner join c_x_p_x_estudiante where calificacion.nota IS NOT NULL 
and calificacion.Estudiante_idEstudiante = pIdEstudiante
and c_x_p_x_estudiante.Curso_X_Profesor_Curso_idCurso = pIdCurso
and c_x_p_x_estudiante.Curso_X_Profesor_Profesor_idProfesor = pIdProfesor
and c_x_p_x_estudiante.Estudiante_idEstudiante = pIdEstudiante;

SET valor = valor/total;

select idCalificacion_Curso into pIdCalificacion from calificacion_curso  where Curso_idCurso = pIdCurso 
and Estudiante_idEstudiante = pIdEstudiante and Profesor_idProfesor = pIdProfesor;


CALL `mydb`.`update_nota_curso`(pIdCalificacion, valor);


END$$
DELIMITER ;
