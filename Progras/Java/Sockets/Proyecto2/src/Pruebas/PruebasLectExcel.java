/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Pruebas;

import Clases.XLSXReaderWriter;
import java.util.ArrayList;

/**
 *
 * @author Chavas
 */
public class PruebasLectExcel {
        public static void main(String[] args) {
        XLSXReaderWriter Leer=new XLSXReaderWriter();
        ArrayList<ArrayList> Tickets=Leer.Read(null);
        int i;
        for(i=0;i<Tickets.size();i++)
        {
             System.out.print(Tickets.get(i));
        }
        
        //Leer.Write("E:\\Libro1.xlsx");
        }
    
}
