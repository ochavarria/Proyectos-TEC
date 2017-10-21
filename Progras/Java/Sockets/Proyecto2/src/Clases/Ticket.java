/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.io.Serializable;
import java.util.Date;



/**
 *
 * @author Chavas
 */
public class Ticket implements Serializable {
    Date Recepcion;
    String ID_Cliente;
    String Asunto;
    String Categoria;
    String ID_Empleado;
    Date Atencion;
    int TiempoAtencion;
    String Comentario;
    String Estado;

    public Ticket(String ID_Cliente, String Asunto, String Estado) {
        this.ID_Cliente = ID_Cliente;
        this.Asunto = Asunto;
        this.Estado = Estado;
    }

    public Ticket() {
 
    }

    public void setRecepcion(Date Recepcion) {
        this.Recepcion = Recepcion;
    }

    public void setID_Cliente(String ID_Cliente) {
        this.ID_Cliente = ID_Cliente;
    }

    public void setAsunto(String Asunto) {
        this.Asunto = Asunto;
    }

    public void setCategoria(String Categoria) {
        this.Categoria = Categoria;
    }

    public void setID_Empleado(String ID_Empleado) {
        this.ID_Empleado = ID_Empleado;
    }

    public void setAtencion(Date Atencion) {
        this.Atencion = Atencion;
    }

    public void setTiempoAtencion(int TiempoAtencion) {
        this.TiempoAtencion = TiempoAtencion;
    }

    public void setComentario(String Comentario) {
        this.Comentario = Comentario;
    }

    public void setEstado(String Estado) {
        this.Estado = Estado;
    }

    public Date getRecepcion() {
        return Recepcion;
    }

    public String getID_Cliente() {
        return ID_Cliente;
    }

    public String getAsunto() {
        return Asunto;
    }

    public String getCategoria() {
        return Categoria;
    }

    public String getID_Empleado() {
        return ID_Empleado;
    }

    public Date getAtencion() {
        return Atencion;
    }

    public int getTiempoAtencion() {
        return TiempoAtencion;
    }

    public String getComentario() {
        return Comentario;
    }

    public String getEstado() {
        return Estado;
    }

    @Override
    public String toString() {
        return "Ticket{" + "Recepcion=" + Recepcion + ", ID_Cliente=" + ID_Cliente + ", Asunto=" + Asunto + ", Categoria=" + Categoria + ", ID_Empleado=" + ID_Empleado + ", Atencion=" + Atencion + ", TiempoAtencion=" + TiempoAtencion + ", Comentario=" + Comentario + ", Estado=" + Estado + '}';
    }
    
    
}
