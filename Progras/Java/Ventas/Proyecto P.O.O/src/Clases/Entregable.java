/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.util.Date;

/**
 *
 * @author Chavas
 */
public  class Entregable {
    private String Identificador ;
    private boolean Estregado ;
    private String Descripcion ;
    private String Remitente ;
    private Date fechaR;
    private Date fechaE;
    
    
    public Entregable(String Identificador, boolean Estado, String Descripcion, String Remitente,Date fechaR) {
        this.Identificador = Identificador;
        this.Estregado = Estado;
        this.Descripcion = Descripcion;
        this.Remitente = Remitente;
        this.fechaR = fechaR;
    }   

    public String getIdentificador() {
        return Identificador;
    }

    public boolean isEstregado() {
        return Estregado;
    }

    public String getDescripcion() {
        return Descripcion;
    }

    public String getRemitente() {
        return Remitente;
    }

    public void setIdentificador(String Identificador) {
        this.Identificador = Identificador;
    }

    public void setEstregado(boolean Estado) {
        this.Estregado = Estado;
    }

    public void setDescripcion(String Descripcion) {
        this.Descripcion = Descripcion;
    }

    public void setRemitente(String Remitente) {
        this.Remitente = Remitente;
    }

    public Date getFechaR() {
        return fechaR;
    }

    public void setFechaR(Date fechaR) {
        this.fechaR = fechaR;
    }

    public Date getFechaE() {
        return fechaE;
    }

    public void setFechaE(Date fechaE) {
        this.fechaE = fechaE;
    }


    
    
}
