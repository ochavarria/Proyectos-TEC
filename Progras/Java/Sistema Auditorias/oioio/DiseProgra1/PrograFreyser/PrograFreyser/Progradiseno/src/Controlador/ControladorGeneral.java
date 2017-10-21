/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import java.io.IOException;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Usuario
 */
public class ControladorGeneral {
    private PlanEstudio planEstudio = new PlanEstudio();
    private GestorOferta oferta = new GestorOferta() ;
    private GestorResoluciones resoluciones; 
    private GestorDocentes docentes = new GestorDocentes();
    private GestorSolicitud solicitudes = new GestorSolicitud() ;
    
    
    
    public ControladorGeneral() throws IOException {
        this.resoluciones = new GestorResoluciones();
        
    }
    
    public boolean agregarSolicitud(dtoSolicitud sol) throws IOException{
        return solicitudes.agregar(sol);
    }
    
    public boolean AgregarResolucion(dtoResolucion dtoReso){
        try {
            return resoluciones.agregar(dtoReso);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ControladorGeneral.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }
    
    public boolean GenerarArchivo(int TipoArchivo,String tipo,int valor)
    {
        
        return resoluciones.GenerarArchivo(TipoArchivo,tipo,valor);
    }
    
    public boolean CambiarEstado (String Estado,String Id) throws ClassNotFoundException
    {
        return solicitudes.CambiarEstado(Estado,Id);
    }
    
    public boolean AgregarConsiderandos (dtoResolucion dtoResol) throws ClassNotFoundException
    {
        return resoluciones.AgregarConsiderandos(dtoResol);
    }
    
    
    public void SolicitudesPen(dtoSolicitud dtosol) throws SQLException
    {
        solicitudes.SolicitudesPen(dtosol);
    }
    
    public void SolicitudesAprobadas(dtoSolicitud dtosol) throws SQLException
    {
        solicitudes.SolicitudesAprobadas(dtosol);
    }
}
