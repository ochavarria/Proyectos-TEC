/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Datos.Resolucion;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Usuario
 */
public class GestorResoluciones extends GestorGeneral{
    private ArrayList<Resolucion> resoluciones = new ArrayList();
    private final PDF GPDF;
    private final HTML GHTML;
    private daoResolucion daoResol = new daoResolucion();

    public GestorResoluciones() throws IOException {
        this.GHTML = new HTML();
        this.GPDF = new PDF();
 
    }

    public ArrayList<Resolucion> getResoluciones() {
        return resoluciones;
    }

    public void setResoluciones(ArrayList<Resolucion> resoluciones) {
        this.resoluciones = resoluciones;
    }
    
    public boolean GenerarArchivo(int TipoArchivo,String tipo,int valor)
    {
        
        if(TipoArchivo == 0){
            switch(tipo)
            {
                case "ExclusionActa":
                    GPDF.CrearDocumentoExclusion(valor);
                    return true;
                case "ErrorNota" : 
                    GPDF.CrearDocumento(valor);
                    return true;
                case "InclusionActa":
                    GPDF.CrearDocumentoInclusion(valor);
                    return true;
            }
            return false; 
        }
        else{
            switch(tipo)
            {
                case "ExclusionActa":
                    GHTML.CrearDocumentoExclusion(valor);
                    return true;
                case "ErrorNota" : 
                    GHTML.CrearDocumento(valor);
                    return true;
                case "InclusionActa":
                    GHTML.CrearDocumentoInclusion(valor);
                    return true;
            }
            return false; 
        }
        
    }
    
    public boolean agregar(dtoResolucion dtoReso) throws ClassNotFoundException{
        try {
            return daoResol.AgregarSolicitud(dtoReso);
        } catch (IOException ex) {
            Logger.getLogger(GestorResoluciones.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }
    
    public boolean AgregarConsiderandos (dtoResolucion dto) throws ClassNotFoundException
    {
        try {
            return daoResol.AgregarConsiderando(dto);
        } catch (IOException ex) {
            Logger.getLogger(GestorSolicitud.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
        
    }
    
    
}
