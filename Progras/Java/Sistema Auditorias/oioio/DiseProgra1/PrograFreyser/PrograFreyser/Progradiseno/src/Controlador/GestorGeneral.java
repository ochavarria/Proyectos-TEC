/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ersolano
 */
public abstract class GestorGeneral {
    
    protected List lista = new ArrayList();

    public GestorGeneral() {
        
    }
    public boolean agregar(Object obj){
        if (consultar(obj) == null){
            lista.add(obj);
            return true;
        }
        return false;
    }    
    
    public Object consultar(Object obj){
        int donde = lista.indexOf(obj);
        if (donde != -1)
            return lista.get(donde);
        else
            return null;
    }
    
    public boolean modificar(Object obj){
        int donde = lista.indexOf(obj);
        if (donde != -1){
            lista.set(donde, obj);
            return true;
        }
        else
            return false;        
    }
    
    public boolean eliminar(Object obj){
        return lista.remove(obj);
    }

    @Override
    public String toString() {
        return "{" + lista + "\n}";
    }
    
    public int total(){
       return lista.size();
   }

}
