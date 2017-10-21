/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Datos;

import static Datos.Estado.Pendiente;

/**
 *
 * @author Usuario
 */
public class Solicitud {
    private int IDSoli;
    private String NombreSoli;
    private String PeriodoLectivo;
    private String CodigoCurso;
    private int Grupo;
    private int CarnetEstudiante;
    private String NombreEstudiante;
    private String CorreoEstudiante;
    private int telefonoEstudiante;
    private TipoI TipoI;
    private String Detalle;
    private Resolucion Resolucion;
    private Estado Estado;

    public Solicitud(int IDSoli, String NombreSoli, String PeriodoLectivo, String CodigoCurso, int Grupo, int CarnetEstudiante, String NombreEstudiante, String CorreoEstudiante, int telefonoEstudiante, TipoI TipoI, String Detalle) {
        this.IDSoli = IDSoli;
        this.NombreSoli = NombreSoli;
        this.PeriodoLectivo = PeriodoLectivo;
        this.CodigoCurso = CodigoCurso;
        this.Grupo = Grupo;
        this.CarnetEstudiante = CarnetEstudiante;
        this.NombreEstudiante = NombreEstudiante;
        this.CorreoEstudiante = CorreoEstudiante;
        this.telefonoEstudiante = telefonoEstudiante;
        this.TipoI = TipoI;
        this.Detalle = Detalle;
        this.Resolucion = null;
        this.Estado = Pendiente;
    }

    public int getIDSoli() {
        return IDSoli;
    }

    public void setIDSoli(int IDSoli) {
        this.IDSoli = IDSoli;
    }

    public String getNombreSoli() {
        return NombreSoli;
    }

    public void setNombreSoli(String NombreSoli) {
        this.NombreSoli = NombreSoli;
    }

    public String getPeriodoLectivo() {
        return PeriodoLectivo;
    }

    public void setPeriodoLectivo(String PeriodoLectivo) {
        this.PeriodoLectivo = PeriodoLectivo;
    }

    public String getCodigoCurso() {
        return CodigoCurso;
    }

    public void setCodigoCurso(String CodigoCurso) {
        this.CodigoCurso = CodigoCurso;
    }

    public int getGrupo() {
        return Grupo;
    }

    public void setGrupo(int Grupo) {
        this.Grupo = Grupo;
    }

    public int getCarnetEstudiante() {
        return CarnetEstudiante;
    }

    public void setCarnetEstudiante(int CarnetEstudiante) {
        this.CarnetEstudiante = CarnetEstudiante;
    }

    public String getNombreEstudiante() {
        return NombreEstudiante;
    }

    public void setNombreEstudiante(String NombreEstudiante) {
        this.NombreEstudiante = NombreEstudiante;
    }

    public String getCorreoEstudiante() {
        return CorreoEstudiante;
    }

    public void setCorreoEstudiante(String CorreoEstudiante) {
        this.CorreoEstudiante = CorreoEstudiante;
    }

    public int getTelefonoEstudiante() {
        return telefonoEstudiante;
    }

    public void setTelefonoEstudiante(int telefonoEstudiante) {
        this.telefonoEstudiante = telefonoEstudiante;
    }

    public TipoI getTipoI() {
        return TipoI;
    }

    public void setTipoI(TipoI TipoI) {
        this.TipoI = TipoI;
    }

    public String getDetalle() {
        return Detalle;
    }

    public void setDetalle(String Detalle) {
        this.Detalle = Detalle;
    }

    public Resolucion isResolucion() {
        return Resolucion;
    }

    public void setResolucion(Resolucion Resolucion) {
        this.Resolucion = Resolucion;
    }

    public Estado getEstado() {
        return Estado;
    }

    public void setEstado(Estado Estado) {
        this.Estado = Estado;
    }
    
    
}
