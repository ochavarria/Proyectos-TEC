/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

/**
 *
 * @author Chavas
 */

import Frames.Pagar;
import Frames.Retiro;
 import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.util.*;


import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Cancelar extends JPanel implements ItemListener {
    private JLabel _label=new JLabel();
    private ArrayList<Entregable> Pendientes=new ArrayList<Entregable>();
    public static ArrayList<Entregable> Pagar =new ArrayList<Entregable>();   
    
    public Cancelar() 
    { 
        Pagar.clear();
        JCheckBox checkBox;
        JFrame _frame = new JFrame("Check box loop");
        _frame.setDefaultCloseOperation(WindowConstants.HIDE_ON_CLOSE);

        JPanel checkPanel = new JPanel();
        
        checkPanel.setLayout(new GridLayout(10,10));
        
        Cliente cliente= Retiro.cliente ;
        ArrayList<Entregable> entregables = Retiro.entregables;
       
        int x =0;
        int y =0;
        for (int i = 0; i < entregables.size(); i++) 
        {
            System.out.println(cliente.getNombre());
            System.out.println(entregables.get(i).getRemitente());

            if(cliente.getIdentificador()== null ? entregables.get(i).getRemitente() == null : cliente.getIdentificador().equals(entregables.get(i).getRemitente())
                    && !entregables.get(i).isEstregado())
            {
                checkBox = new JCheckBox(entregables.get(i).getIdentificador());
                checkBox.addItemListener(this);
                checkBox.setName("CheckBox" + i);
                checkBox.setLocation(x,y);
                checkPanel.add(checkBox);
                Pendientes.add(entregables.get(i));
                x=x+1;
                y=y;
            }

        }
            JButton Pagar=new JButton("Pagar");
            Pagar.setPreferredSize(new Dimension(40, 40));
            Pagar.addActionListener(new Action());
            checkPanel.add(Pagar);
             
        System.out.println(Pendientes.toString());   
        
        _frame.add(checkPanel);
        
        _frame.pack();
        _frame.setLocationByPlatform(true);
        _frame.setVisible(true);
        
   
    }


    public void itemStateChanged(ItemEvent e) {
        JCheckBox source = (JCheckBox) e.getItemSelectable();
        if (e.getStateChange() == ItemEvent.SELECTED) {
            for (int i = 0; i < Pendientes.size(); i++) 
            {
                if (Pendientes.get(i).getIdentificador() == null ? source.getText() == null : Pendientes.get(i).getIdentificador().equals(source.getText()))
                {
                    Pagar.add(Pendientes.get(i));
                    System.out.println(Pagar.toString());
                    
                }
            }
        }
        else
        {
            if (e.getStateChange() == ItemEvent.DESELECTED) {
                for (int i = 0; i < Pagar.size(); i++) 
                {
                    if (Pagar.get(i).getIdentificador() == null ? source.getText() == null : Pagar.get(i).getIdentificador().equals(source.getText()))
                    {
                        Pagar.remove(Pendientes.get(i));
                        System.out.println(Pagar.toString());
                        
                    }
                }
            }
        }

    }
class Action implements ActionListener{
    public void actionPerformed(ActionEvent e)
    {
        Pagar PagarV =new Pagar();
        PagarV.setDefaultCloseOperation(WindowConstants.HIDE_ON_CLOSE);
        PagarV.setVisible(true);
    }       
 }



    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Cancelar();          
            }
        });
    }
}
    
