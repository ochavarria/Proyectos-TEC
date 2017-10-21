/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;


import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.Date;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Usuario
 */
public class dtoSolicitud {
    private Date fecha;
    private int IdSolicitante ;
    private String nombreSolitante;
    private String Periodo;
    private String CodigoCurso;
    private int grupo;
    private int carnet;
    private String nombre;
    private int telefono;
    private String correo;
    private String tipo;
    private String detalle;
    private ArrayList tabla;

    public dtoSolicitud() {
    }

    public ArrayList getTabla() {
        return tabla;
    }

    public void setTabla(ArrayList tabla) {
        this.tabla = tabla;
    }

    
    

    
    
    
    public String getDetalle() {
        return detalle;
    }

    public void setDetalle(String detalle) {
        this.detalle = detalle;
    }
    
    

    public dtoSolicitud(Date fecha, int IdSolicitante, String nombreSolitante, String Periodo, String CodigoCurso, int grupo, int carnet, String nombre, int telefono, String correo, String tipo) {
        this.fecha = fecha;
        this.IdSolicitante = IdSolicitante;
        this.nombreSolitante = nombreSolitante;
        this.Periodo = Periodo;
        this.CodigoCurso = CodigoCurso;
        this.grupo = grupo;
        this.carnet = carnet;
        this.nombre = nombre;
        this.telefono = telefono;
        this.correo = correo;
        this.tipo = tipo;
        this.tabla = null;
    }

    
    

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public int getIdSolicitante() {
        return IdSolicitante;
    }

    public void setIdSolicitante(int IdSolicitante) {
        this.IdSolicitante = IdSolicitante;
    }

    public String getNombreSolitante() {
        return nombreSolitante;
    }

    public void setNombreSolitante(String nombreSolitante) {
        this.nombreSolitante = nombreSolitante;
    }

    public String getPeriodo() {
        return Periodo;
    }

    public void setPeriodo(String Periodo) {
        this.Periodo = Periodo;
    }

    public String getCodigoCurso() {
        return CodigoCurso;
    }

    public void setCodigoCurso(String CodigoCurso) {
        this.CodigoCurso = CodigoCurso;
    }

    public int getGrupo() {
        return grupo;
    }

    public void setGrupo(int grupo) {
        this.grupo = grupo;
    }

    public int getCarnet() {
        return carnet;
    }

    public void setCarnet(int carnet) {
        this.carnet = carnet;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getTelefono() {
        return telefono;
    }

    public void setTelefono(int telefono) {
        this.telefono = telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }


    
    
    
    
    
    
}
