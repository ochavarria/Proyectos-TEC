
package Controlador;

import Datos.CursoAbierto;
import java.util.ArrayList;


public class GestorOferta extends GestorGeneral {
    private String ciclo;
    private ArrayList <CursoAbierto> oferta = new ArrayList();

    public GestorOferta() {
    }

    
    public GestorOferta(String ciclo) {
        this.ciclo = ciclo;
        
    }

    public String getCiclo() {
        return ciclo;
    }

    public void setCiclo(String ciclo) {
        this.ciclo = ciclo;
    }

    public ArrayList<CursoAbierto> getOferta() {
        return oferta;
    }

    public void setOferta(ArrayList<CursoAbierto> oferta) {
        this.oferta = oferta;
    }
    
    
    
    
}
