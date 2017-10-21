/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

/**
 *
 * @author Chavas
 */
public class Counter {


    private Casillero Casilleros[]; 
    private ArrayList<Entregable> Entregables = new ArrayList<Entregable>();
    
    private ArrayList<Cliente> Clientes = new ArrayList<Cliente>();
    
    private final String nombre;
    private final String Ced;
    private final String Direccion; 

    
    public Counter(String nombre, String Ced, String Direccion,int CantCasilleros) {
                
        int id=999;
        Casilleros=new Casillero[CantCasilleros];
        
        for (int i = 0; i <CantCasilleros ; i++) {
            id=id+1;
            String strI = Integer.toString(id);
            
            Casilleros[i]=new Casillero(strI,"Libre"); 
        }  
        this.nombre = nombre;
        this.Ced = Ced;
        this.Direccion = Direccion;
    }
    
    public ArrayList<Entregable> getEntregables() {
        return Entregables;
    }

    public ArrayList<Cliente> getClientes() {
        return Clientes;
    }
    @Override
    public String toString() {
        return "Counter{"+"nombre=" + nombre + ", Ced=" + Ced + ", Direccion=" + Direccion + "Cantidad de Casilleros= "+Casilleros.length+'}';
    }
    
    public void  AgregarClientes( Cliente cliente ){
        AsignarCasillero(cliente);
        Clientes.add(cliente);
        System.out.println(cliente.toString());
    }
   
    public void AgregarEntregables( Entregable entregable ){
        Entregables.add(entregable);
    }
    
    public void AsignarCasillero(Cliente cliente){
        for (int i = 0; i <Casilleros.length ; i++) {
            System.out.println(Casilleros[i].toString());
            if ("Libre".equals(Casilleros[i].getEstado()))
            {
                cliente.setIdCasillero(Casilleros[i].getId());
                Casilleros[i].setEstado("Ocupado");
                break;
            }
             
        }  
    }
    public Cliente BusquedaCliente(String Identificador){
        Cliente ElCliente ;
        for (int i = 0; i < Clientes.size(); i++) {
            ElCliente = Clientes.get(i);
            System.out.println(ElCliente.getIdentificador());
            System.out.println(Identificador);
            if (ElCliente.getIdentificador() == null ? Identificador == null : ElCliente.getIdentificador().equals(Identificador))
            {
                return ElCliente;  
            }
        }
        return ElCliente=null;
   }
    public Casillero BusquedaCasillero(String Info)
    {
        Casillero casillero;
        int i;
        for ( i = 0; i <Casilleros.length ; i++) {
            System.out.println(Casilleros[i].toString());
            if (Info.equals(Casilleros[i].getId()))
            {
                casillero=Casilleros[i];
                return casillero;
            }
             
        } 
        return casillero=null;
    }
   public void EliminarCliente(String Identificador){
        for (int i = 0; i < Clientes.size(); i++) {
            if (Clientes.get(i).getIdentificador() == null ? Identificador == null : Clientes.get(i).getIdentificador().equals(Identificador))
            {
                Clientes.remove(i);
                
            }
        }
    }
   public String NCliente(int pos){
       String Nombre="";
       if (pos<Clientes.size()){
           Nombre=Clientes.get(pos).getIdentificador();
       }
       else
       {
           Nombre=null;
       }
       return Nombre;
   }
   public ArrayList<Entregable>BusquedaFechaR(Date fechaR)
   {
       ArrayList<Entregable> FechasR= new ArrayList<Entregable>();
       DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
       for (int i = 0; i < Entregables.size(); i++) {
           if (dateFormat.format(Entregables.get(i).getFechaR()) == null ? dateFormat.format(fechaR) == null : dateFormat.format(Entregables.get(i).getFechaR()).equals(dateFormat.format(fechaR)))
            {
                FechasR.add(Entregables.get(i));
            }
        }
    System.out.println(FechasR);
    return FechasR;
    }
    public ArrayList<Entregable>BusquedaFechaE(Date fechaE)
   {
       ArrayList<Entregable> FechasE= new ArrayList<Entregable>();
       DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

       for (int i = 0; i < Entregables.size(); i++) {
           if (null!=Entregables.get(i).getFechaE())
           {
               if (dateFormat.format(Entregables.get(i).getFechaE()) == null ? dateFormat.format(fechaE) == null : dateFormat.format(Entregables.get(i).getFechaE()).equals(dateFormat.format(fechaE)))
                {
                FechasE.add(Entregables.get(i));
                }
           }
       }
    System.out.println(FechasE);
    return FechasE;
    }
    
    public int Morosos(Cliente cliente)
    {
        int Pendientes=0;
         for (int i = 0; i < Entregables.size(); i++)
         {
             if (cliente.getIdentificador() == null ? Entregables.get(i).getRemitente() == null : cliente.getIdentificador().equals(Entregables.get(i).getRemitente()))
             {
                 if(!Entregables.get(i).isEstregado())
                 {
                    Pendientes+=1; 
                 }
             }
         }
         return Pendientes;
    }
    
}
   

    
    

