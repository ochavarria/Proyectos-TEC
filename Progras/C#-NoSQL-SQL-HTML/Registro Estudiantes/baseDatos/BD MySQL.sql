-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Categoria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Categoria` (
  `idCategoria` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL,
  PRIMARY KEY (`idCategoria`),
  UNIQUE INDEX `idCategoria_UNIQUE` (`idCategoria` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Curso`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Curso` (
  `idCurso` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL,
  `numeroCreditos` INT NULL,
  `Categoria_idCategoria` INT NOT NULL,
  PRIMARY KEY (`idCurso`),
  INDEX `fk_Curso_Categoria_idx` (`Categoria_idCategoria` ASC),
  UNIQUE INDEX `idCurso_UNIQUE` (`idCurso` ASC),
  CONSTRAINT `fk_Curso_Categoria`
    FOREIGN KEY (`Categoria_idCategoria`)
    REFERENCES `mydb`.`Categoria` (`idCategoria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Estudiante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Estudiante` (
  `idEstudiante` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `apellido` VARCHAR(45) NOT NULL,
  `correoElectronico` VARCHAR(45) NOT NULL,
  `contraseña` VARCHAR(55) NOT NULL,
  PRIMARY KEY (`idEstudiante`),
  UNIQUE INDEX `idEstudiante_UNIQUE` (`idEstudiante` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Profesor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Profesor` (
  `idProfesor` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `apellido` VARCHAR(45) NOT NULL,
  `correoElectronico` VARCHAR(45) NOT NULL,
  `contraseña` VARCHAR(55) NOT NULL,
  PRIMARY KEY (`idProfesor`),
  UNIQUE INDEX `idProfesor_UNIQUE` (`idProfesor` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Curso_X_Profesor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Curso_X_Profesor` (
  `Curso_idCurso` INT NOT NULL,
  `Profesor_idProfesor` INT NOT NULL,
  `grupo` INT NULL,
  `hora` TIME(6) NULL,
  PRIMARY KEY (`Curso_idCurso`, `Profesor_idProfesor`),
  INDEX `fk_Curso_has_Profesor_Profesor1_idx` (`Profesor_idProfesor` ASC),
  INDEX `fk_Curso_has_Profesor_Curso1_idx` (`Curso_idCurso` ASC),
  CONSTRAINT `fk_Curso_has_Profesor_Curso1`
    FOREIGN KEY (`Curso_idCurso`)
    REFERENCES `mydb`.`Curso` (`idCurso`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Curso_has_Profesor_Profesor1`
    FOREIGN KEY (`Profesor_idProfesor`)
    REFERENCES `mydb`.`Profesor` (`idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`C_X_P_X_Estudiante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`C_X_P_X_Estudiante` (
  `Curso_X_Profesor_Curso_idCurso` INT NOT NULL,
  `Curso_X_Profesor_Profesor_idProfesor` INT NOT NULL,
  `Estudiante_idEstudiante` INT NOT NULL,
  PRIMARY KEY (`Curso_X_Profesor_Curso_idCurso`, `Curso_X_Profesor_Profesor_idProfesor`, `Estudiante_idEstudiante`),
  INDEX `fk_Curso_X_Profesor_has_Estudiante_Estudiante1_idx` (`Estudiante_idEstudiante` ASC),
  INDEX `fk_Curso_X_Profesor_has_Estudiante_Curso_X_Profesor1_idx` (`Curso_X_Profesor_Curso_idCurso` ASC, `Curso_X_Profesor_Profesor_idProfesor` ASC),
  CONSTRAINT `fk_Curso_X_Profesor_has_Estudiante_Curso_X_Profesor1`
    FOREIGN KEY (`Curso_X_Profesor_Curso_idCurso` , `Curso_X_Profesor_Profesor_idProfesor`)
    REFERENCES `mydb`.`Curso_X_Profesor` (`Curso_idCurso` , `Profesor_idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Curso_X_Profesor_has_Estudiante_Estudiante1`
    FOREIGN KEY (`Estudiante_idEstudiante`)
    REFERENCES `mydb`.`Estudiante` (`idEstudiante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Duda_Reclamo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Duda_Reclamo` (
  `idDuda_Reclamo` INT NOT NULL AUTO_INCREMENT,
  `tipo` BIT(1) NOT NULL,
  `descripcion` VARCHAR(255) NULL,
  `Profesor_idProfesor` INT NOT NULL,
  `Estudiante_idEstudiante` INT NOT NULL,
  PRIMARY KEY (`idDuda_Reclamo`),
  INDEX `fk_Duda_Reclamo_Profesor1_idx` (`Profesor_idProfesor` ASC),
  INDEX `fk_Duda_Reclamo_Estudiante1_idx` (`Estudiante_idEstudiante` ASC),
  UNIQUE INDEX `idDuda_Reclamo_UNIQUE` (`idDuda_Reclamo` ASC),
  CONSTRAINT `fk_Duda_Reclamo_Profesor1`
    FOREIGN KEY (`Profesor_idProfesor`)
    REFERENCES `mydb`.`Profesor` (`idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Duda_Reclamo_Estudiante1`
    FOREIGN KEY (`Estudiante_idEstudiante`)
    REFERENCES `mydb`.`Estudiante` (`idEstudiante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Asignacion_Individual`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Asignacion_Individual` (
  `idAsignacion_Individual` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL,
  `descripcion` VARCHAR(255) NULL,
  `fecha` DATE NULL,
  `hora` TIME(6) NULL,
  `medio_entrega` VARCHAR(45) NULL,
  `Curso_X_Profesor_Curso_idCurso` INT NOT NULL,
  `Curso_X_Profesor_Profesor_idProfesor` INT NOT NULL,
  PRIMARY KEY (`idAsignacion_Individual`),
  INDEX `fk_Asignacion_Individual_Curso_X_Profesor1_idx` (`Curso_X_Profesor_Curso_idCurso` ASC, `Curso_X_Profesor_Profesor_idProfesor` ASC),
  UNIQUE INDEX `idAsignacion_Individual_UNIQUE` (`idAsignacion_Individual` ASC),
  CONSTRAINT `fk_Asignacion_Individual_Curso_X_Profesor1`
    FOREIGN KEY (`Curso_X_Profesor_Curso_idCurso` , `Curso_X_Profesor_Profesor_idProfesor`)
    REFERENCES `mydb`.`Curso_X_Profesor` (`Curso_idCurso` , `Profesor_idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Asignacion_Grupal`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Asignacion_Grupal` (
  `idAsignacion_Grupal` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL,
  `descripcion` VARCHAR(255) NULL,
  `fecha` DATE NULL,
  `hora` TIME(6) NULL,
  `medio_entrega` VARCHAR(45) NULL,
  `Curso_X_Profesor_Curso_idCurso` INT NOT NULL,
  `Curso_X_Profesor_Profesor_idProfesor` INT NOT NULL,
  PRIMARY KEY (`idAsignacion_Grupal`),
  INDEX `fk_Asignacion_Grupal_Curso_X_Profesor1_idx` (`Curso_X_Profesor_Curso_idCurso` ASC, `Curso_X_Profesor_Profesor_idProfesor` ASC),
  UNIQUE INDEX `idAsignacion_Grupal_UNIQUE` (`idAsignacion_Grupal` ASC),
  CONSTRAINT `fk_Asignacion_Grupal_Curso_X_Profesor1`
    FOREIGN KEY (`Curso_X_Profesor_Curso_idCurso` , `Curso_X_Profesor_Profesor_idProfesor`)
    REFERENCES `mydb`.`Curso_X_Profesor` (`Curso_idCurso` , `Profesor_idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`grupo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`grupo` (
  `idgrupo` INT NOT NULL AUTO_INCREMENT,
  `Asignacion_Grupal_idAsignacion_Grupal` INT NOT NULL,
  PRIMARY KEY (`idgrupo`),
  INDEX `fk_grupo_Asignacion_Grupal1_idx` (`Asignacion_Grupal_idAsignacion_Grupal` ASC),
  UNIQUE INDEX `idgrupo_UNIQUE` (`idgrupo` ASC),
  CONSTRAINT `fk_grupo_Asignacion_Grupal1`
    FOREIGN KEY (`Asignacion_Grupal_idAsignacion_Grupal`)
    REFERENCES `mydb`.`Asignacion_Grupal` (`idAsignacion_Grupal`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Estudiante_X_grupo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Estudiante_X_grupo` (
  `Estudiante_idEstudiante` INT NOT NULL,
  `grupo_idgrupo` INT NOT NULL,
  PRIMARY KEY (`Estudiante_idEstudiante`, `grupo_idgrupo`),
  INDEX `fk_Estudiante_has_grupo_grupo1_idx` (`grupo_idgrupo` ASC),
  INDEX `fk_Estudiante_has_grupo_Estudiante1_idx` (`Estudiante_idEstudiante` ASC),
  CONSTRAINT `fk_Estudiante_has_grupo_Estudiante1`
    FOREIGN KEY (`Estudiante_idEstudiante`)
    REFERENCES `mydb`.`Estudiante` (`idEstudiante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Estudiante_has_grupo_grupo1`
    FOREIGN KEY (`grupo_idgrupo`)
    REFERENCES `mydb`.`grupo` (`idgrupo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Calificacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Calificacion` (
  `idCalificacion` INT NOT NULL AUTO_INCREMENT,
  `Estudiante_idEstudiante` INT NOT NULL,
  `Asignacion_Individual_idAsignacion_Individual` INT NOT NULL,
  `nota` INT NULL,
  `porcentaje` DOUBLE NULL,
  PRIMARY KEY (`idCalificacion`),
  INDEX `fk_Calificacion_Estudiante1_idx` (`Estudiante_idEstudiante` ASC),
  INDEX `fk_Calificacion_Asignacion_Individual1_idx` (`Asignacion_Individual_idAsignacion_Individual` ASC),
  UNIQUE INDEX `idCalificacion_UNIQUE` (`idCalificacion` ASC),
  CONSTRAINT `fk_Calificacion_Estudiante1`
    FOREIGN KEY (`Estudiante_idEstudiante`)
    REFERENCES `mydb`.`Estudiante` (`idEstudiante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Calificacion_Asignacion_Individual1`
    FOREIGN KEY (`Asignacion_Individual_idAsignacion_Individual`)
    REFERENCES `mydb`.`Asignacion_Individual` (`idAsignacion_Individual`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Calificacion_Grupal`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Calificacion_Grupal` (
  `idCalificacion_Grupal` INT NOT NULL AUTO_INCREMENT,
  `grupo_idgrupo` INT NOT NULL,
  `Asignacion_Grupal_idAsignacion_Grupal` INT NOT NULL,
  `nota` INT NULL,
  `porcentaje` DOUBLE NULL,
  PRIMARY KEY (`idCalificacion_Grupal`),
  INDEX `fk_Calificacion_Grupal_grupo1_idx` (`grupo_idgrupo` ASC),
  INDEX `fk_Calificacion_Grupal_Asignacion_Grupal1_idx` (`Asignacion_Grupal_idAsignacion_Grupal` ASC),
  UNIQUE INDEX `idCalificacion_Grupal_UNIQUE` (`idCalificacion_Grupal` ASC),
  CONSTRAINT `fk_Calificacion_Grupal_grupo1`
    FOREIGN KEY (`grupo_idgrupo`)
    REFERENCES `mydb`.`grupo` (`idgrupo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Calificacion_Grupal_Asignacion_Grupal1`
    FOREIGN KEY (`Asignacion_Grupal_idAsignacion_Grupal`)
    REFERENCES `mydb`.`Asignacion_Grupal` (`idAsignacion_Grupal`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Calificacion_Curso`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Calificacion_Curso` (
  `idCalificacion_Curso` INT NOT NULL AUTO_INCREMENT,
  `nota_final` INT NULL,
  `finalizada` BIT(1) NULL,
  `Curso_idCurso` INT NOT NULL,
  `Estudiante_idEstudiante` INT NOT NULL,
  `Profesor_idProfesor` INT NOT NULL,
  PRIMARY KEY (`idCalificacion_Curso`),
  UNIQUE INDEX `idCalificacion_Curso_UNIQUE` (`idCalificacion_Curso` ASC),
  INDEX `fk_Calificacion_Curso_Curso1_idx` (`Curso_idCurso` ASC),
  INDEX `fk_Calificacion_Curso_Estudiante1_idx` (`Estudiante_idEstudiante` ASC),
  INDEX `fk_Calificacion_Curso_Profesor1_idx` (`Profesor_idProfesor` ASC),
  CONSTRAINT `fk_Calificacion_Curso_Curso1`
    FOREIGN KEY (`Curso_idCurso`)
    REFERENCES `mydb`.`Curso` (`idCurso`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Calificacion_Curso_Estudiante1`
    FOREIGN KEY (`Estudiante_idEstudiante`)
    REFERENCES `mydb`.`Estudiante` (`idEstudiante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Calificacion_Curso_Profesor1`
    FOREIGN KEY (`Profesor_idProfesor`)
    REFERENCES `mydb`.`Profesor` (`idProfesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
