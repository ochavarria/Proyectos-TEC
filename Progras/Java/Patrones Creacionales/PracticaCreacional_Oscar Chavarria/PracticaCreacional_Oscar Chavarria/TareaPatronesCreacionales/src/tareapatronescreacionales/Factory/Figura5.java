/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tareapatronescreacionales.Factory;

/**
 *
 * @author ROLO
 */
public class Figura5 implements Figura {
    private int CantCuadro; 
    private int Aungulo;
    private String Color; 

    public Figura5(int Aungulo, String Color) {
        this.CantCuadro = 6;
        this.Aungulo = Aungulo;
        this.Color = Color;
    }

    @Override
    public String imprimirfigura() {
        return toString();
    }
    
    @Override
    public String toString() {
        return "5{" + "CantCuadro=" + CantCuadro + ", Aungulo=" + Aungulo + ", Color=" + Color + '}';
    }
   
    
    
}
