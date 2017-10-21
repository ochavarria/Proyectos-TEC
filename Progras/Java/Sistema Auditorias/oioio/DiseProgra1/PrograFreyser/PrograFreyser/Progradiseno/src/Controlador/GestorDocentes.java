/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Datos.Docente;
import java.util.ArrayList;

/**
 *
 * @author Usuario
 */
public class GestorDocentes extends GestorGeneral{
    private ArrayList<Docente> docentes = new ArrayList();

    public GestorDocentes() {
    }
    

    public ArrayList<Docente> getDocentes() {
        return docentes;
    }

    public void setDocentes(ArrayList<Docente> docentes) {
        this.docentes = docentes;
    }
    
    
    
    
    
}
