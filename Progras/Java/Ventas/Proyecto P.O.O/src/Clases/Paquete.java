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
//Se consideran paquetes aquellos artículos que deben entregarse 
//a clientes en caja o bolsa,  se debe indicar si contienen algo electrónico, 
//si son frágiles o no y de igual forma deben registrar su peso en kg.
public class Paquete extends Entregable{
    private String envoltura;
    private boolean Electronico;
    private boolean fragil; 
    private int peso; 
    
 
    public Paquete(String envoltura, boolean Electronico, boolean fragil, int peso,String Identificador, boolean Estado, String Descripcion,String Remitente,Date fecha)
    { 
        super( Identificador, Estado,  Descripcion, Remitente,fecha);
        this.envoltura = envoltura;
        this.Electronico = Electronico;
        this.fragil = fragil;
        this.peso = peso;
    }

    public String getEnvoltura() {
        return envoltura;
    }

    public boolean isElectronico() {
        return Electronico;
    }

    public boolean isFragil() {
        return fragil;
    }

    public int getPeso() {
        return peso;
    }

    @Override
    public String toString() {
        return "Paquete{" + "envoltura=" + envoltura + ", Electronico=" + Electronico + ", fragil=" + fragil + ", peso=" + peso + '}';
    }
    
    
}
