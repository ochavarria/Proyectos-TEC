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
public class  FiguraFactory  {
    public final static int Figura1 = 0;
    public final static int Figura2 = 1;
    public final static int Figura3 = 2;
    public final static int Figura4 = 3;
    public final static int Figura5 = 4;
    public final static int Figura6 = 5;
    
    public static Figura CrearFigura(int Figura,int Angulo, String Color)
    {
        switch (Figura)
        {
            case(Figura1):
                return new Figura1(Angulo,Color);
            case(Figura2):
                return new Figura2(Angulo,Color);
            case(Figura3):
                return new Figura3(Angulo,Color);
            case(Figura4):
                return new Figura4(Angulo,Color);
            case(Figura5):
                return new Figura5(Angulo,Color);
            case(Figura6):
                return new Figura6(Angulo,Color);

                
        }
        return null;
    }
    
}
