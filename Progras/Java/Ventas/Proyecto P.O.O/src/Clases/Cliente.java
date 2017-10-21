/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.util.ArrayList;

/**
 *
 * @author Chavas
 */
public class Cliente {
    private String Nombre;


    private String Apellido;
    private String Identificador;
    private String Correo;
    private String telefono;
    private String direccion;
    private String sexo;
    private String FechaN;
    private String IdCasillero;
    private String Nivel;
    private int CantPagos;

            
    public Cliente(String Nombre,String Apellido,String Identificador, String Correo, String telefono, String direccion, String sexo, String FechaN,String Nivel) {
        this.Nombre = Nombre;
        this.Apellido=Apellido;
        this.Identificador = Identificador;
        this.Correo = Correo;
        this.telefono = telefono;
        this.direccion = direccion;
        this.sexo = sexo;
        this.FechaN = FechaN;
        this.Nivel=Nivel;
    }

    @Override
    public String toString() {
        return "Cliente{" + "Nombre=" + Nombre + ", Identificador=" + Identificador + ", Correo=" + Correo + ", telefono=" + telefono + ", direccion=" + direccion + ", sexo=" + sexo + ", FechaN=" + FechaN + ", IdCasillero=" + IdCasillero + '}';
    }

    public void setIdCasillero(String IdCasillero) {
        this.IdCasillero = IdCasillero;
    }
    //Getters
    public String getNombre() {
        return Nombre;
    }

    public String getIdentificador() {
        return Identificador;
    }

    public String getCorreo() {
        return Correo;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getDireccion() {
        return direccion;
    }

    public String getSexo() {
        return sexo;
    }

    public String getFechaN() {
        return FechaN;
    }

    public String getIdCasillero() {
        return IdCasillero;
    }
    public String getApellido() {
        return Apellido;
    }
    //Setters

    public void setNombre(String Nombre) {
        this.Nombre = Nombre;
    }

    public void setIdentificador(String Identificador) {
        this.Identificador = Identificador;
    }

    public void setCorreo(String Correo) {
        this.Correo = Correo;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public void setFechaN(String FechaN) {
        this.FechaN = FechaN;
    }

    public String getNivel() {
        return Nivel;
    }

    public void setNivel(String Nivel) {
        this.Nivel = Nivel;
    }
    
    public int getCantPagos() {
        return CantPagos;
    }

    public void addPago()
    {
        this.CantPagos+=1;
    }
    public void Actualizarnivel()
    {
        if (10<CantPagos&& CantPagos<20)
        {
            setNivel("Plata");
        }
        else
        {
            if (CantPagos<20)
            {
                setNivel("Oro");
            }
        }
    }
}
