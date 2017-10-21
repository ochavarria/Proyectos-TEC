/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Clases;

import Frames.Administrador;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.plaf.metal.MetalBorders.Flush3DBorder;
import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 * @author Estudiantes
 */
public class Servidor extends Thread {
    ArrayList<Ticket>Inbox=new ArrayList<Ticket>();
    ArrayList<Ticket>ColaRoja=new ArrayList<Ticket>();
    ArrayList<Ticket>ColaAmarilla=new ArrayList<Ticket>();
    ArrayList<Ticket>ColaVerde=new ArrayList<Ticket>();
    ArrayList<Ticket>TicketsProcesados=new ArrayList<Ticket>();
    public volatile boolean running =true;
    private final int PUERTO= 5000;
    public boolean PeticionTiempo = false;
    String Nombre="";

    public ArrayList<Ticket> getTicketsProcesados() {
        return TicketsProcesados;
    }

    
     int Emp=0;
        int TT=0;

    public int getTT() {
        return TT;
    }
        
    public Servidor() {

  }
   public void run() {
        try {
            String monitoreo="";
            // se crea el servidor..
            monitoreo="Levantando servidor...\n";
            Administrador.Monitoreo(monitoreo);
            ServerSocket server = new ServerSocket(PUERTO);
            
            // se entra a un proceso infinto de atencion...
            while (running){
                monitoreo="";
                monitoreo+="Esperando conexion de un cliente...\n";
                // se espera la peticion del cliente
                Socket cliente = server.accept();
                monitoreo+="Cliente acceptado conexion ...\n";
                // se establece el canal de comunicacion-Escritura
                ObjectInputStream flujoLectura=new ObjectInputStream(cliente.getInputStream());//Lectura 

                ArrayList lectura = (ArrayList<Ticket>)flujoLectura.readObject();
                int Accion= Integer.parseInt((String)lectura.get(0));
               
                if (Accion==1)
                {
                    String Dato= (String)lectura.get(1);
                    
                    OutputStream conexionSalida = cliente.getOutputStream();
                    DataOutputStream flujoSalida = new DataOutputStream(conexionSalida);
                   
                    // se establece el canal de comunicacion-Escritura
                    String Estado="";
                    if ("Conectar".equals(Dato)) {Estado = Contectar_Empleado();
                    monitoreo+="Conectando usuario ...\n";} 
                    else {Estado = Desconectar_Empleado();
                    monitoreo+="Desconectado usuario...\n";}
                    // se define el procesamiento de la atencion...
                    // en este caso no se lee, solo se avisa al cliente
                    // que está conectado.
                   
                    flujoSalida.writeUTF(Estado);
                    flujoSalida.flush();
                    // se cierra la conexion con el cliente...
                    monitoreo+="Cerrando conexion ...\n";
                    flujoSalida.close();
                    flujoLectura.close();
                    cliente.close();
                    Administrador.Monitoreo(monitoreo);
                }
                else
                {
                    if(Accion==2)
                    {
                        String Dato= (String)lectura.get(1);
                        ArrayList<Ticket> Salida=Solicitar_Ticket(Dato);
                        ObjectOutputStream outStrm = new ObjectOutputStream(cliente.getOutputStream());//Escritura
                        
                        outStrm.writeObject(Salida);
                        outStrm.flush();
                        monitoreo+="Devolviendo la lista de tickets...\n";
                        monitoreo+="Cerrando conexion ...\n";
                        outStrm.close(); 
                        cliente.close();
                        Administrador.Monitoreo(monitoreo);
                        
                    }
                    
                    else
                        if (Accion==3)
                        {
                            String Dato = (String) lectura.get(1);
                            String Color= (String )lectura.get(2);
                            ArrayList<Ticket>Cola=Solicitar_Ticket(Color);
                            int i;
                            for (i = 0; i < Cola.size(); i++) {
                                String TicketData = "Fecha de Recepcion: ";
                                TicketData += Cola.get(i).getRecepcion() + "  ";
                                TicketData += "ID Cliente: " + Cola.get(i).getID_Cliente() + "  ";
                                TicketData += "Asunto: " + Cola.get(i).getAsunto() + "  ";
                                TicketData += "Categoria: " + Cola.get(i).getCategoria()+ "  ";
                                TicketData += "Estado: " + Cola.get(i).getEstado()+ "  ";
                                
                                if (TicketData == null ? Dato == null : TicketData.equals(Dato)) 
                                {
                                    Reservar_Ticket(Cola.get(i));
                                    break;
                                }
                            }
                            monitoreo+="Reservando ticket ...\n";
                            cliente.close();
                            monitoreo+="Cerrando conexion ...\n";
                            Administrador.Monitoreo(monitoreo);
                            
                        }
                        else
                        {
                            if (Accion==4)
                            {
                                String Dato = (String) lectura.get(1);
                                String Color = (String) lectura.get(2);
                                ArrayList<Ticket> Cola = Solicitar_Ticket(Color);
                              
                                int i;
                                for (i = 0; i < Cola.size(); i++) {
                                    String TicketData = "Fecha de Recepcion: ";
                                    TicketData += Cola.get(i).getRecepcion() + "  ";
                                    TicketData += "ID Cliente: " + Cola.get(i).getID_Cliente() + "  ";
                                    TicketData += "Asunto: " + Cola.get(i).getAsunto() + "  ";
                                    TicketData += "Categoria: " + Cola.get(i).getCategoria() + "  ";
                                    TicketData += "Estado: " + "Disponible"+ "  ";
                                 
                                    if (TicketData == null ? Dato == null : TicketData.equals(Dato)) 
                                    {
                                        Liberar_Ticket(Cola.get(i));
                                        break;
                                    }

                                }
                            monitoreo+="Liberando ticket ticket ...\n";
                            cliente.close();
                            monitoreo+="Cerrando conexion ...\n";
                            Administrador.Monitoreo(monitoreo);
                        
                            }
                            else
                            {
                                if (Accion==5)
                                {
                                    String Dato = (String) lectura.get(1);
                                    String Color = (String) lectura.get(2);
                                    String Asunto = (String) lectura.get(3);
                                    int Seg = (int) lectura.get(4);
                                    Nombre = (String) (lectura.get(5));
                                    ArrayList<Ticket> Cola = Solicitar_Ticket(Color);
                                    PeticionTiempo = true;
                                    int i;
                                    for (i = 0; i < Cola.size(); i++) {
                                        String TicketData = "Fecha de Recepcion: ";
                                        TicketData += Cola.get(i).getRecepcion() + "  ";
                                        TicketData += "ID Cliente: " + Cola.get(i).getID_Cliente() + "  ";
                                        TicketData += "Asunto: " + Cola.get(i).getAsunto() + "  ";
                                        
                                        TicketData += "Categoria: " + Cola.get(i).getCategoria() + "  ";
                                        TicketData += "Estado: " + "Disponible" + "  ";
                                        
                                   
                                        if (TicketData == null ? Dato == null : TicketData.equals(Dato)) {
                                            
                                            Actualizar_Ticket(Cola.get(i), Asunto,Seg,Nombre);
                                       
                                            TicketsProcesados.add(Cola.get(i));
                                            
                                            break;
                                        }                               
                                    }
                                    monitoreo+="Actualizado ticket ...\n";
                                    cliente.close();
                                    monitoreo+="Cerrando conexion ...\n";
                                    Administrador.Monitoreo(monitoreo);
                                
                                }
                               
                                    
                                else
                                {
                                    int TResueltos = (int) lectura.get(1);
                                    Date Day = (Date) lectura.get(2);
                                    String Color = (String) lectura.get(3);
                                    ArrayList<Ticket> Cola = Solicitar_Ticket(Color);
                                    int CantidadTotal=Cola.size();
                                    ArrayList Salida = Reporte_Ticket(TResueltos,Day,CantidadTotal);
                                    
                                    ObjectOutputStream outStrm = new ObjectOutputStream(cliente.getOutputStream());//Escritura
                                    outStrm.writeObject(Salida);
                                    outStrm.flush();
                                    monitoreo+="Creando el reporte ticket ...\n";
                                    cliente.close();
                                    monitoreo+="Cerrando conexion ...\n";
                                    Administrador.Monitoreo(monitoreo);
                                    
                                    outStrm.close();
                                    cliente.close();
                                    
                                    
                                
                                }
                            }
                        }
                
               }
                

            }  // while
        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Servidor.class.getName()).log(Level.SEVERE, null, ex);
        }catch(Exception excepcion){} 

    }
    
    public String Contectar_Empleado()
    {
        return "Conectado";             
    }

    public String Desconectar_Empleado()
    {
        return "Desconectado";             
    }

    public ArrayList Solicitar_Ticket(String Dato)
    {
        if ("Rojo".equals(Dato)){return ColaRoja;}
        else
        {
            if ("Amarillo".equals(Dato)){return ColaAmarilla;}
            else{return ColaVerde;} 
        }
    }
    public String NombreU (){
    
    return Nombre;
    }
    public void TiempoPorTiquet()
    {
        try {
            if (PeticionTiempo == true){
        for (int i = 0; i < ColaRoja.size(); i++) {
            
            if("Atendido".equals(ColaRoja.get(i).getEstado()))
            {
                TT +=ColaRoja.get(i).getTiempoAtencion();   
                Emp++;
            }
        }
        for (int i = 0; i < ColaVerde.size(); i++) {
            if("Atendido".equals(ColaVerde.get(i).getEstado()))
            {
                TT +=ColaVerde.get(i).getTiempoAtencion();    
                  Emp++;
            }
        }
        for (int i = 0; i < ColaAmarilla.size(); i++) {
            if("Atendido".equals(ColaAmarilla.get(i).getEstado()))
            {
                TT +=ColaAmarilla.get(i).getTiempoAtencion();  
                  Emp++;
            } 
        }
        for (int i = 0; i < TicketsProcesados.size(); i++) { 
            if("Atendido".equals(TicketsProcesados.get(i).getEstado()))
            {
                TT +=TicketsProcesados.get(i).getTiempoAtencion();  
                  Emp++;
            }
            
        }
        TT=TT/Emp;
        PeticionTiempo = false;
        }
        
        
        } catch(Exception excepcion){} 
        
    }
    public void Reservar_Ticket(Ticket tickt)
    {
        tickt.setEstado("En Atencion");
    }
    public void Actualizar_Ticket(Ticket tickt,String Asunto, int Seg, String nombre)
    {
        tickt.setAsunto(Asunto);
        tickt.setEstado("Atendido");
        tickt.setTiempoAtencion(Seg);
        tickt.setID_Empleado(nombre);
        
    }
    public void Liberar_Ticket(Ticket tickt)
    {   
        tickt.setEstado("Disponible");
    }
    public ArrayList Reporte_Ticket( int TResueltos, Date day ,int CantidadTotal)
    {
        ArrayList Reporte= new ArrayList ();
        
        double Total= (TResueltos*100)/CantidadTotal;
        Reporte.add(CantidadTotal);
        Reporte.add(TResueltos);
        Reporte.add(Total);
        
        return Reporte;
    }
    public void CargarXls()
    {
        
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
        "xlsx & xls Files", "xlsx", "xlsx");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showOpenDialog(null);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            XLSXReaderWriter Leer=new XLSXReaderWriter();
            ArrayList<ArrayList> DatosTickets = Leer.Read(chooser.getSelectedFile().getAbsolutePath());
            int i;
            if (null != DatosTickets) {
                for (i = 1; i < DatosTickets.size(); i++) {
                    int k;
                    Ticket ticket = new Ticket();
                    for (k = 0; k < DatosTickets.get(i).size(); k++) {
                        
                        if (k == 0) {
                            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm");
                            String dateInString = (String) DatosTickets.get(i).get(k);
                            try {
                                Date date;
                                date = formatter.parse(dateInString);

                                ticket.setRecepcion(date);


                            } catch (ParseException e) {
                                e.printStackTrace();
                            }
                        } else {
                            if (k == 1) {
                                String ID_Cliente = (String) DatosTickets.get(i).get(k);
                                ticket.setID_Cliente(ID_Cliente);

                            } else {
                                String Asunto = (String) DatosTickets.get(i).get(k);
                                ticket.setAsunto(Asunto);
                                ticket.setEstado("Disponible");
                            }
                        }

                    }
                    Inbox.add(ticket);
                    
                }
                String Dato="Se han Cargado nuevos tickets...\n";
                Administrador.Monitoreo(Dato);

            }
        }
    }

    public ArrayList<Ticket> getInbox() {
        return Inbox;
    }
    
    public void addColaRoja(Ticket Roja) {
        ColaRoja.add(Roja);

    }

    public void addColaAmarilla(Ticket Amarilla) {
        this.ColaAmarilla.add(Amarilla);

    }

    public void addColaVerde(Ticket Verde) {
        this.ColaVerde.add(Verde);

    }

    public void BajarServidor() {
        running = false;
    }

    public int getLargo_ColaRoja() {
        System.out.println(ColaRoja.size());
        return ColaRoja.size();
    }

    public int getLargo_ColaAmarilla() {
        System.out.println(ColaAmarilla.size());
        return ColaAmarilla.size();
    }
    public int getLargo_ColaVerde() {
        System.out.println(ColaVerde.size());
        return ColaVerde.size();
    }



}

