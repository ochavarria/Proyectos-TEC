/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Datos;

/**
 *
 * @author Usuario
 */
public class Docente {
    private int cedula;
    private String nombre;
    private String correo;
    private int telefono;
    private TipoTelefono TipoTelefono;
    private TipoCorreo TipoCorreo;

    public Docente(int cedula, String nombre, String correo, int telefono, TipoTelefono TipoTelefono, TipoCorreo TipoCorreo) {
        this.cedula = cedula;
        this.nombre = nombre;
        this.correo = correo;
        this.telefono = telefono;
        this.TipoTelefono = TipoTelefono;
        this.TipoCorreo = TipoCorreo;
    }

    public int getCedula() {
        return cedula;
    }

    public void setCedula(int cedula) {
        this.cedula = cedula;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public int getTelefono() {
        return telefono;
    }

    public void setTelefono(int telefono) {
        this.telefono = telefono;
    }

    public TipoTelefono getTipoTelefono() {
        return TipoTelefono;
    }

    public void setTipoTelefono(TipoTelefono TipoTelefono) {
        this.TipoTelefono = TipoTelefono;
    }

    public TipoCorreo getTipoCorreo() {
        return TipoCorreo;
    }

    public void setTipoCorreo(TipoCorreo TipoCorreo) {
        this.TipoCorreo = TipoCorreo;
    }

    @Override
    public String toString() {
        return "Docente{" + "cedula=" + cedula + ", nombre=" + nombre + ", correo=" + correo + ", telefono=" + telefono + ", TipoTelefono=" + TipoTelefono + ", TipoCorreo=" + TipoCorreo + '}';
    }
    
    
    
}
