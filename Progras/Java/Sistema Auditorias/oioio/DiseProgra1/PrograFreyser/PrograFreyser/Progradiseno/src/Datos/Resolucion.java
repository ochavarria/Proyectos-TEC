/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Datos;

import java.util.ArrayList;

/**
 *
 * @author Usuario
 */
public class Resolucion {
    private Solicitud solicitud;
    private String Codigo;
    private String Coordinador;
    private String DirectorAR;
    private String DirectorIC;
    private String considerandos;

    public Resolucion(Solicitud solicitud, String Codigo, String Coordinador, String DirectorAR, String DirectorIC, String considerandos) {
        this.solicitud = solicitud;
        this.Codigo = Codigo;
        this.Coordinador = Coordinador;
        this.DirectorAR = DirectorAR;
        this.DirectorIC = DirectorIC;
        this.considerandos = considerandos;
    }

    public Solicitud getSolicitud() {
        return solicitud;
    }

    public void setSolicitud(Solicitud solicitud) {
        this.solicitud = solicitud;
    }

    public String getCodigo() {
        return Codigo;
    }

    public void setCodigo(String Codigo) {
        this.Codigo = Codigo;
    }

    public String getCoordinador() {
        return Coordinador;
    }

    public void setCoordinador(String Coordinador) {
        this.Coordinador = Coordinador;
    }

    public String getDirectorAR() {
        return DirectorAR;
    }

    public void setDirectorAR(String DirectorAR) {
        this.DirectorAR = DirectorAR;
    }

    public String getDirectorIC() {
        return DirectorIC;
    }

    public void setDirectorIC(String DirectorIC) {
        this.DirectorIC = DirectorIC;
    }

    public String getConsiderandos() {
        return considerandos;
    }

    public void setConsiderandos(String considerandos) {
        this.considerandos = considerandos;
    }
    
    
    
    
}
