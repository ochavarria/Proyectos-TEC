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
//tipo aéreo o de manila
//y si su contenido es documentación o algún 
//otro tipo de artículo. En ambos casos de debe indicar el peso en kg.
public class Sobre extends Entregable {
private String tipo; 
private String Contenido;
private int Peso; 


    
public Sobre(String tipo, String Contenido, int Peso,String Identificador, boolean Estado, String Descripcion,String Remitente,Date fecha)
    { 
        super( Identificador, Estado,  Descripcion, Remitente,fecha);
        this.tipo = tipo;
        this.Contenido = Contenido;
        this.Peso = Peso;
    }

    public String getTipo() {
        return tipo;
    }

    public String getContenido() {
        return Contenido;
    }

    @Override
    public String toString() {
        return "Sobre{" + "tipo=" + tipo + ", Contenido=" + Contenido + ", Peso=" + Peso + '}';
    }
    
}
