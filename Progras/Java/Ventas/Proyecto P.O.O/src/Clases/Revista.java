/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.util.Date;

/**
 *
 * @author Chavas
 */
//Por último a las revistas se les registra el nombre de la revista, 
//debe indicarse si se trata de un catálogo o no 
//y el tema (Negocios, Moda/Belleza, Tecnología, Salud/Medicina, Cocina u Otro). 
public class Revista extends Entregable {
    private String nombre;
    private boolean catalogo;
    private String Tema; 
    
    public Revista(String nombre, boolean catalogo, String Tema,String Identificador, boolean Estado, String Descripcion,String Remitente,Date fecha)
    { 
        super( Identificador, Estado,  Descripcion, Remitente, fecha);
        this.nombre = nombre;
        this.catalogo = catalogo;
        this.Tema = Tema;
    }

    @Override
    public String toString() {
        return "Revista{" + "nombre=" + nombre + ", catalogo=" + catalogo + ", Tema=" + Tema + '}';
    }

    public String getNombre() {
        return nombre;
    }

    public boolean isCatalogo() {
        return catalogo;
    }

    public String getTema() {
        return Tema;
    }
    
    
}
