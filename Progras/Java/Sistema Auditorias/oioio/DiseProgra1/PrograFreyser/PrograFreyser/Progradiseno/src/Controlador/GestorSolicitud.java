/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Datos.Solicitud;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Usuario
 */
public class GestorSolicitud extends GestorGeneral{
    private ArrayList<Solicitud> solicitudes = new ArrayList();
    private Manual manual = new Manual();
    private Automatico automatico = new Automatico();
    private daoSolicitudes daoSoli = new daoSolicitudes();
    
    public GestorSolicitud() {
        
    }
    
    public boolean agregar(dtoSolicitud soli) throws IOException{
        if(soli.getCorreo().isEmpty()){
            automatico.agregar(soli);
            return true;
        }
        else{
            
            solicitudes.add((Solicitud) manual.agregar(soli));
            try {
                
                if(daoSoli.AgregarSolicitud(soli))
                {return true;}
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(GestorSolicitud.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return false; 
    }
    public boolean CambiarEstado (String Estado,String Id) throws ClassNotFoundException
    {
        if (Estado.equals("aprobado")){
            try {
            return daoSoli.AprobarSolicitud (Id);
        } catch (IOException ex) {
            Logger.getLogger(GestorSolicitud.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
        }
        
        else {if (Estado.equals("rechazar")){
            try {
            return daoSoli.RechazarSolicitud (Id);
        } catch (IOException ex) {
            Logger.getLogger(GestorSolicitud.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
        }
        }
        return false;
        
           
    }
    
    
    public void SolicitudesPen(dtoSolicitud soli) throws SQLException
    {
        daoSoli.SolicitudesPendientes(soli);
    }
    
    public void SolicitudesAprobadas(dtoSolicitud soli) throws SQLException
    {
        daoSoli.SolicitudesAprobadas(soli);
    }
}
