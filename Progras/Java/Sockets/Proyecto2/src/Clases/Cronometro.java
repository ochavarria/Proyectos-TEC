package Clases;

import javax.swing.JFrame;

public class Cronometro extends Thread{

Thread crono;

public static int seg;
/** Creates new form cronometro */
public void run (){
 try {
while (true){
    seg++;
    crono.sleep(1000); }
    }
catch (InterruptedException e) { System.out.println(e.getMessage()); }
}
}