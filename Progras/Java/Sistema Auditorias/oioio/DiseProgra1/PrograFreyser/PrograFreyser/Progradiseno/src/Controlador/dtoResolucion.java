/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;
/**
 *
 * @author Usuario
 */
public class dtoResolucion {
    private String codigo;
    private int IDSolicitud;
    private String considerando;
    private boolean respuesta;
    public dtoResolucion() {
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }
    
    public int getIDSolicitud() {
        return IDSolicitud;
    }
    public void setIDSolicitud(int IDSolicitud) {
        System.out.println("hiwoe");
        this.IDSolicitud = IDSolicitud;
    }

    

    

    public String getConsiderando() {
        return considerando;
    }

    public void setConsiderando(String considerando) {
        this.considerando = considerando;
    }

    public boolean isRespuesta() {
        return respuesta;
    }

    public void setRespuesta(boolean respuesta) {
        this.respuesta = respuesta;
    }
    

}
