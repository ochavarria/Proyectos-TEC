/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tareapatronescreacionales;

import java.util.Scanner;
import tareapatronescreacionales.Factory.Figura;
import tareapatronescreacionales.Factory.FiguraFactory;
import tareapatronescreacionales.Singleton.Ayuda;

/**
 *
 * @author ROLO
 */
public class TareaPatronesCreacionales {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int angul= 5;
        String Color = "azul";
        Figura fig = FiguraFactory.CrearFigura(6, angul, Color);
        if(fig!=null){
        System.out.println("Figura Creada "+fig.imprimirfigura());}
        else{System.out.println("Figura no existe");}
        
        Ayuda ayu =new Ayuda() ;
        ayu.MostarAyuda(1);
    }
    
}
