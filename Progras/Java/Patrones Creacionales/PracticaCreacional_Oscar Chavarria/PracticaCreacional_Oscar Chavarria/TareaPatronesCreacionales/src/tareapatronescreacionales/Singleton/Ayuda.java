/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tareapatronescreacionales.Singleton;

/**
 *
 * @author ROLO
 */
public class Ayuda {
    private static Ayuda Instancia = null; 
    
    
    public Ayuda() {
        
    }
    
    private synchronized static void crearInstancia()
    {
        if(Instancia==null)
        {
            Instancia= new Ayuda ();
        }
    }
    
    public static Ayuda getInstacia()
    {
        if(Instancia==null){
            crearInstancia();}
            return Instancia;

    }
    public static void MostarAyuda(int pantalla)
    {   

                if(pantalla==1)
                    System.out.println("Ayuda1");
                if(pantalla==2)
                    System.out.println("Ayuda2");
                if(pantalla==3)
                    System.out.println("Ayuda3");
            

    }
    
}
