/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import java.io.IOException;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Gollo
 */
public class daoSolicitudes {
    Connection cn;
    Configuracion uno;
    
    

    public daoSolicitudes()  {
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
    
    
    public boolean AgregarSolicitud(dtoSolicitud dtoSoli) throws ClassNotFoundException, IOException 
    {
           uno = new Configuracion();
           try{
               
            String sql="agregarSolicitud ?,?,?,?,?,?,?,?,?,?,?,?,?,?,?";
            PreparedStatement cmd= cn.prepareCall(sql);
            cmd.setInt(1,uno.ultimaResolucion);
            uno.cargarDatos(uno.ultimaResolucion+1);
            java.sql.Date sqlDate = new java.sql.Date(dtoSoli.getFecha().getTime());
            cmd.setDate(2,  sqlDate);
            cmd.setString(3,dtoSoli.getNombreSolitante());
            cmd.setInt(4,dtoSoli.getIdSolicitante());
            cmd.setString(5,dtoSoli.getPeriodo());
            cmd.setString(6,dtoSoli.getCodigoCurso());
            cmd.setInt(7,dtoSoli.getGrupo());
            cmd.setInt(8,dtoSoli.getCarnet());
            cmd.setString(9,dtoSoli.getNombre());  
            cmd.setString(10,dtoSoli.getCorreo()); 
            cmd.setInt(11,dtoSoli.getTelefono());
            cmd.setString(12,dtoSoli.getTipo()); 
            cmd.setString(13,dtoSoli.getDetalle().toString());
            cmd.setInt(14, 0);
            cmd.setString(15, "pendiente");
            cmd.execute();
            SolicitudesPendientes(dtoSoli);
            
            return true;
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
           
        return false;
        
        
    }
    
    public void SolicitudesPendientes(dtoSolicitud modelo) throws SQLException{
        try{
            ArrayList Lista = new ArrayList();
            String sql="select idSolicitud,idSolicitante,CarnetEst,TipoL,Detalle from Solicitudes where Estado= 'pendiente'";
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
            
                    Object[] datos= new Object[5];
                    for(int i=0;i<5;i++){
                        datos[i]=rs.getString(i+1);
                       
                    }
                    Lista.add(datos);
                   
                }
            modelo.setTabla(Lista);
            }
           
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    
    public void SolicitudesAprobadas(dtoSolicitud modelo) throws SQLException{
        try{
            ArrayList Lista = new ArrayList();
            String sql="select idSolicitud,idSolicitante,CarnetEst,TipoL,Detalle from Solicitudes where Estado= 'tramitada'";
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
            
                    Object[] datos= new Object[5];
                    for(int i=0;i<5;i++){
                        datos[i]=rs.getString(i+1);
                       
                    }
                    Lista.add(datos);
                   
                }
            modelo.setTabla(Lista);
            }
           
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    
    public ArrayList CargarDatos(int valor) throws SQLException{
        try{
            ArrayList Lista = new ArrayList();
            String sql="select * from Solicitudes where idSolicitud="+valor;
            
                    
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
            
                    for(int i=0;i<15;i++){
                        Lista.add(rs.getString(i+1));
                       
                       
                    }
                    
                    
                }
               return Lista;
            }
           
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        return null;
    }
    
    
    public boolean AprobarSolicitud(String id) throws ClassNotFoundException, IOException 
    {
           uno = new Configuracion();
           try{
            int ide = Integer.parseInt(id);
            String sql="AprobarSolicitud ?";
            PreparedStatement cmd= cn.prepareCall(sql);
            cmd.setInt(1,ide);
            cmd.execute();
            return true;
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
           
        return false;
    }
    
    
    public boolean RechazarSolicitud(String id) throws ClassNotFoundException, IOException 
    {
           uno = new Configuracion();
           try{
            int ide = Integer.parseInt(id);
            String sql="RechazarSolicitud ?";
            PreparedStatement cmd= cn.prepareCall(sql);
            cmd.setInt(1,ide);
            cmd.execute();
            return true;
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
           
        return false;
    }
    
    
    
  
    
    

}
