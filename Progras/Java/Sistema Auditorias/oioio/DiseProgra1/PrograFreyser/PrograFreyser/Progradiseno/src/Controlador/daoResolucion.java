/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import static com.sun.org.apache.xalan.internal.lib.ExsltDatetime.date;
import static com.sun.org.apache.xalan.internal.lib.ExsltDatetime.date;
import java.io.IOException;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Usuario
 */
public class daoResolucion {
    
    Connection cn;
    Configuracion uno;

    public daoResolucion() {
        Conexion con= new Conexion();
        try {
            try {
                cn=con.conectar();
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(daoSolicitudes.class.getName()).log(Level.SEVERE, null, ex);
            }
        } catch (SQLException ex) {
            Logger.getLogger(daoSolicitudes.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public String ObtenerConsiderandos(int valor) throws SQLException{
        try{
            ArrayList Lista = new ArrayList();
            String sql="select considerandos from Resoluciones where idSolicitud ="+valor;
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
                    String x = rs.getString(1);
                    return x;
                }
       
            }
           
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        return null;
    }
    
    
    public String ObtenerProfesor(int valor,String cod) throws SQLException{
        try{
            ArrayList Lista = new ArrayList();
            String sql="select nombre from Docentes,CursoAbiertos where Docentes.idDocente=CursoAbiertos.idDocente and CursoAbiertos.Grupo = "+valor+" and CursoAbiertos.idCurso='"+cod+"'";
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
                    String x = rs.getString(1);
                    System.out.println(x);
                    return x;
                }
            }
           
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        return null;
    }
    
    
    public boolean AgregarSolicitud(dtoResolucion dtoReso) throws ClassNotFoundException, IOException 
    {
           uno = new Configuracion();
           try{
              
            String sql="agregarResolucion ?,?,?,?,?,?";
            PreparedStatement cmd= cn.prepareCall(sql);
            String Str = String.valueOf(dtoReso.getIDSolicitud());
            cmd.setString(1,Str);
            Calendar calendar = Calendar.getInstance();
            java.sql.Date ourJavaDateObject = new java.sql.Date(calendar.getTime().getTime());
            cmd.setDate(2,  ourJavaDateObject);
            System.out.println(ourJavaDateObject);
            cmd.setString(3,uno.nombreCC);
            cmd.setString(4,uno.nombreAR);
            cmd.setString(5,uno.nombreDC);
            cmd.setInt(6,dtoReso.getIDSolicitud());
            cmd.execute();
            return true;
        }catch(Exception ex){
            System.out.println(ex.getMessage());
             return false;
        }
           
       
        
    }
    
    public boolean AgregarConsiderando(dtoResolucion dtoReso) throws ClassNotFoundException, IOException 
    {
           uno = new Configuracion();
           try{               
            String sql="AgregarConsiderando ?,?";
            PreparedStatement cmd= cn.prepareCall(sql);
            cmd.setInt(1,dtoReso.getIDSolicitud());
            cmd.setString(2,dtoReso.getConsiderando());
            cmd.execute();
            return true;
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        return false;
    }
    
    
    
    
}
