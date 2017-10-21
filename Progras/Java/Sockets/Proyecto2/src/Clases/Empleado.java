/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import javax.swing.JOptionPane;

/**
 *
 * @author Chavas
 */
public class Empleado {
    private String ID;
    private String Contraseña;
    private String Nombre;
    private String Categoria;
    private String Estado;
    private int TicketsResueltos;



    
    private final String HOST = "localhost";
    private final int PUERTO= 5000;
    
    public Empleado(String ID, String Contraseña, String Nombre) {
        this.ID = ID;
        this.Contraseña = Contraseña;
        this.Nombre = Nombre;

    }

    public String getID() {
        return ID;
    }

    public String getContraseña() {
        return Contraseña;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getCategoria() {
        return Categoria;
    }

    public String getEstado() {
        return Estado;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public void setContraseña(String Contraseña) {
        this.Contraseña = Contraseña;
    }

    public void setNombre(String Nombre) {
        this.Nombre = Nombre;
    }

    public void setCategoria(String Categoria) {
        this.Categoria = Categoria;
    }

    public void setEstado(String Estado) {
        this.Estado=Estado;
    }

    public void addTicketsResueltos() {
        this.TicketsResueltos += 1;
    }

    public int getTicketsResueltos() {
        return TicketsResueltos;
    }
    
    
    
    public boolean Conectar_Empleado() {
        try{

            // Crea un socket para establecer comunicacion con el servidor...
            System.out.println("Conectando a " + HOST +":"+PUERTO);
            Socket cliente = new Socket(HOST, PUERTO);
            //Establece mecanismo de comunicacion con el servidor - Lectura..
            System.out.println("Estableciendo comunicacion de lectura con el server...");
            InputStream conexionEntrada = cliente.getInputStream();
            DataInputStream flujoLectura = new DataInputStream(conexionEntrada);

            //Establece mecanismo de comunicacion con el servidor - Escritura..
            System.out.println("Estableciendo comunicacion de escritura con el server...");

            ObjectOutputStream  flujoEscritura=new ObjectOutputStream(cliente.getOutputStream());//Escritura   
            //Enviar la informacion recibida al servidor...
            ArrayList Dato= new ArrayList();
            Dato.add("1");
            Dato.add("Conectar");

            flujoEscritura.writeObject(Dato);
            
            String Estado=flujoLectura.readUTF();
            setEstado(Estado);
            //procesa la respuesta del servidor..
            System.out.println("Procesando respuesta del server");
            System.out.println(Estado);
            // cierra la conexion...
            System.out.println("Cerrando conexion...");
            flujoLectura.close();
            flujoEscritura.close();
            cliente.close();
            System.out.println("Fin de la conexion con el server..");
            return true;
        }
        catch(java.net.ConnectException e){
            JOptionPane.showMessageDialog(null, "Servidor no disponible");
            return false;
        }
        catch(IOException e){
            System.out.println("Problemas con el servidor");
            return false;
        }
    }
    public void Desconectar_Empleado() {
        try{

            // Crea un socket para establecer comunicacion con el servidor...
            System.out.println("Conectando a " + HOST +":"+PUERTO);
            Socket cliente = new Socket(HOST, PUERTO);
            //Establece mecanismo de comunicacion con el servidor - Lectura..
            System.out.println("Estableciendo comunicacion de lectura con el server...");
            InputStream conexionEntrada = cliente.getInputStream();
            DataInputStream flujoLectura = new DataInputStream(conexionEntrada);

            //Establece mecanismo de comunicacion con el servidor - Escritura..
            System.out.println("Estableciendo comunicacion de escritura con el server...");
            ObjectOutputStream  flujoEscritura=new ObjectOutputStream(cliente.getOutputStream());//Escritura   
            //Enviar la informacion recibida al servidor...
            ArrayList Dato= new ArrayList();
            Dato.add("1");
            Dato.add("Desconectar");

            flujoEscritura.writeObject(Dato);
            
            String Estado=flujoLectura.readUTF();

            setEstado(Estado);
            //procesa la respuesta del servidor..
            System.out.println("Procesando respuesta del server");
            System.out.println(Estado);
            // cierra la conexion...
            System.out.println("Cerrando conexion...");
            flujoLectura.close();
            flujoEscritura.close();
            cliente.close();
            System.out.println("Fin de la conexion con el server..");
        }
        catch(java.net.ConnectException e){
            System.out.println("Servidor no disponible");
        }
        catch(IOException e){
            System.out.println("Problemas con el servidor");
        }
    }
}
