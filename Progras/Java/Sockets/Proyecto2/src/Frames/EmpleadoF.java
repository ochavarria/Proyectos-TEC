/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Frames;

import Clases.Cronometro;
import Clases.Ticket;

import Clases.Cronometro;
import static Clases.Cronometro.seg;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author Chavas
 */
public class EmpleadoF extends javax.swing.JFrame {
    private final String HOST = "localhost";
    private final int PUERTO= 5000;
    ArrayList<Ticket>DownloadTickets;
    ArrayList<Ticket>DownloadInfo;
    String Color="";
    String TicketElegido="";
    boolean cronometroActivo;
    
    /**
     * Creates new form Empleados
     */
    public EmpleadoF() {
        initComponents();
        LNUsuario.setText(Login.EmpleadoLogeado.getNombre());
       iniciarC();
       PararCronometro();

    }
    
    //Aqui se hace el cronometro
   Cronometro hilo1=new Cronometro();
   public void iniciarC(){
    hilo1.start();
    }
      public void iniciarCronometro() {
        hilo1.resume();
    }
      public void PararCronometro() {
        hilo1.suspend();
        seg=0;
    }
    
  
    //Esto es para parar el cronometro
 
    
    
    
    

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        GBColores = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        TAsunto = new javax.swing.JTextArea();
        jLabel2 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        LDownloadTickets = new javax.swing.JList();
        Usuario = new javax.swing.JLabel();
        LNUsuario = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        BLiberar_Ticket = new javax.swing.JButton();
        BActualizar_Ticket = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        BDesconectar = new javax.swing.JButton();
        CBVerde = new javax.swing.JCheckBox();
        Solicitar_Ticket = new javax.swing.JButton();
        BReservar_Ticket = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        CBRojo = new javax.swing.JCheckBox();
        CBAmarillo = new javax.swing.JCheckBox();
        BActualizar = new javax.swing.JButton();

        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));

        jPanel1.setBackground(new java.awt.Color(0, 0, 153));

        TAsunto.setColumns(20);
        TAsunto.setRows(5);
        jScrollPane2.setViewportView(TAsunto);

        jLabel2.setText("Resolver o justificar Ticket ");

        LDownloadTickets.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        LDownloadTickets.setToolTipText("");
        LDownloadTickets.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jScrollPane1.setViewportView(LDownloadTickets);

        Usuario.setText("Usuario");

        jLabel4.setText("Estado");

        jLabel5.setText("En linea ");

        BLiberar_Ticket.setBackground(new java.awt.Color(0, 0, 153));
        BLiberar_Ticket.setText("Liberar Ticket");
        BLiberar_Ticket.setEnabled(false);
        BLiberar_Ticket.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BLiberar_TicketActionPerformed(evt);
            }
        });

        BActualizar_Ticket.setBackground(new java.awt.Color(0, 0, 153));
        BActualizar_Ticket.setText("Actualizar Ticket");
        BActualizar_Ticket.setEnabled(false);
        BActualizar_Ticket.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BActualizar_TicketActionPerformed(evt);
            }
        });

        jButton1.setBackground(new java.awt.Color(0, 0, 153));
        jButton1.setText("Reporte Ticket");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        BDesconectar.setBackground(new java.awt.Color(0, 0, 153));
        BDesconectar.setText("Logout");
        BDesconectar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BDesconectarActionPerformed(evt);
            }
        });

        CBVerde.setBackground(new java.awt.Color(0, 0, 153));
        GBColores.add(CBVerde);
        CBVerde.setForeground(new java.awt.Color(51, 255, 0));
        CBVerde.setText("Verde");
        CBVerde.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CBVerdeActionPerformed(evt);
            }
        });

        Solicitar_Ticket.setBackground(new java.awt.Color(0, 0, 204));
        Solicitar_Ticket.setText("Solicitar Ticket");
        Solicitar_Ticket.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Solicitar_TicketActionPerformed(evt);
            }
        });

        BReservar_Ticket.setBackground(new java.awt.Color(0, 0, 153));
        BReservar_Ticket.setText("ReservarTicket");
        BReservar_Ticket.setEnabled(false);
        BReservar_Ticket.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BReservar_TicketActionPerformed(evt);
            }
        });

        jLabel1.setText("Tipo de ticket a trabajar");

        CBRojo.setBackground(new java.awt.Color(0, 0, 153));
        GBColores.add(CBRojo);
        CBRojo.setForeground(new java.awt.Color(255, 0, 51));
        CBRojo.setText("Rojo");
        CBRojo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CBRojoActionPerformed(evt);
            }
        });

        CBAmarillo.setBackground(new java.awt.Color(0, 0, 153));
        GBColores.add(CBAmarillo);
        CBAmarillo.setForeground(new java.awt.Color(255, 255, 0));
        CBAmarillo.setText("Amarrillo");
        CBAmarillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CBAmarilloActionPerformed(evt);
            }
        });

        BActualizar.setBackground(new java.awt.Color(0, 0, 153));
        BActualizar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Images/Refresh.png"))); // NOI18N
        BActualizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BActualizarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 469, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(jButton1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(BReservar_Ticket, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addGap(0, 32, Short.MAX_VALUE))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Solicitar_Ticket)
                            .addComponent(CBVerde)
                            .addComponent(CBAmarillo)
                            .addComponent(CBRojo, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2))
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Usuario)
                            .addComponent(jLabel4))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(LNUsuario, javax.swing.GroupLayout.PREFERRED_SIZE, 98, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(BActualizar, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(BLiberar_Ticket, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 286, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(BActualizar_Ticket))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(BDesconectar))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(BActualizar)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(Usuario, javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(LNUsuario, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4))
                .addGap(4, 4, 4)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(CBRojo)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(CBAmarillo)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(CBVerde)
                .addGap(18, 18, 18)
                .addComponent(Solicitar_Ticket)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(BReservar_Ticket)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButton1)
                .addGap(11, 11, 11)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 103, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(BLiberar_Ticket)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(BActualizar_Ticket)
                        .addGap(17, 17, 17))
                    .addComponent(BDesconectar, javax.swing.GroupLayout.Alignment.TRAILING)))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void CBRojoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CBRojoActionPerformed
    Color="Rojo";
    }//GEN-LAST:event_CBRojoActionPerformed

    private void BDesconectarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BDesconectarActionPerformed
    Login.EmpleadoLogeado.Desconectar_Empleado();
    Login LoginV = new Login();
    LoginV.setVisible(true);
    dispose();
    }//GEN-LAST:event_BDesconectarActionPerformed

    private void Solicitar_TicketActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Solicitar_TicketActionPerformed
       
        if (!"".equals(Color))
        {
            try {
                Socket cliente = new Socket(HOST, PUERTO);
                ObjectOutputStream flujoEscritura = new ObjectOutputStream(cliente.getOutputStream());//Escritura   
                ArrayList Dato = new ArrayList();
                Dato.add("2");
                Dato.add(Color);
                flujoEscritura.writeObject(Dato);
                ObjectInputStream flujoLectura = new ObjectInputStream(cliente.getInputStream());//Lectura
                DownloadTickets = (ArrayList<Ticket>) flujoLectura.readObject();
                if(!DownloadTickets.isEmpty())
                {    
                createJlist();
                BReservar_Ticket.setEnabled(true);
                }
                else
                {
                   JOptionPane.showMessageDialog(null,"No hay tickets para resolver ");
                   BReservar_Ticket.setEnabled(false);
                }
                flujoLectura.close();
                flujoEscritura.close();
                cliente.close();

            } catch (IOException | ClassNotFoundException ex) {
                Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else
        {
            JOptionPane.showMessageDialog(null,"Favor elegir el color de ticket a resolver", HOST, WIDTH);
        }

    }//GEN-LAST:event_Solicitar_TicketActionPerformed

    private void CBVerdeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CBVerdeActionPerformed
    Color="Verde";
    }//GEN-LAST:event_CBVerdeActionPerformed

    private void BReservar_TicketActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BReservar_TicketActionPerformed
        iniciarCronometro();
        
        int selFromList = LDownloadTickets.getSelectedIndex();           
        TicketElegido = (String) (LDownloadTickets.getModel().getElementAt(selFromList));
        
        Socket cliente;     
        try {        
            cliente = new Socket(HOST, PUERTO);
            ObjectOutputStream  flujoEscritura=new ObjectOutputStream(cliente.getOutputStream());//Escritura
            ArrayList Dato= new ArrayList();
            Dato.add("3");
            Dato.add(TicketElegido);
            Dato.add(Color);
            flujoEscritura.writeObject(Dato);

            flujoEscritura.close();
            cliente.close();
            
            BLiberar_Ticket.setEnabled(true);
            BActualizar_Ticket.setEnabled(true);
            BReservar_Ticket.setEnabled(false);
        } catch (IOException ex) {
            Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
        }
     
    }//GEN-LAST:event_BReservar_TicketActionPerformed

    private void BActualizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BActualizarActionPerformed
    
        try{
           
            Socket cliente = new Socket(HOST, PUERTO);
            ObjectOutputStream  flujoEscritura=new ObjectOutputStream(cliente.getOutputStream());//Escritura   
            ArrayList Dato= new ArrayList();
            Dato.add("2");
            Dato.add(Color);
            flujoEscritura.writeObject(Dato);
            ObjectInputStream flujoLectura=new ObjectInputStream(cliente.getInputStream());//Lectura
            DownloadTickets=(ArrayList<Ticket>)flujoLectura.readObject();          
            createJlist();

            flujoLectura.close();
            flujoEscritura.close();
            cliente.close();

            } catch (IOException ex) {
            Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_BActualizarActionPerformed

    private void BLiberar_TicketActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BLiberar_TicketActionPerformed
        Socket cliente; 
        PararCronometro();
        try {        
            
            cliente = new Socket(HOST, PUERTO);
            ObjectOutputStream  flujoEscritura=new ObjectOutputStream(cliente.getOutputStream());//Escritura
            ArrayList Dato= new ArrayList();
            Dato.add("4");
            Dato.add(TicketElegido);
            System.out.println(TicketElegido);
            Dato.add(Color);
            flujoEscritura.writeObject(Dato);

            flujoEscritura.close();
            cliente.close();
            BReservar_Ticket.setEnabled(true);
            BLiberar_Ticket.setEnabled(false);
            BActualizar_Ticket.setEnabled(false);
            cliente.close();
            
        } catch (IOException ex) {
            Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_BLiberar_TicketActionPerformed

    private void BActualizar_TicketActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BActualizar_TicketActionPerformed
        System.out.println(seg);
        
        if (!"".equals(TAsunto.getText())) {
            Socket cliente;
   
            try {
                cliente = new Socket(HOST, PUERTO);
                ObjectOutputStream flujoEscritura = new ObjectOutputStream(cliente.getOutputStream());//Escritura
                ArrayList Dato = new ArrayList();
                Dato.add("5");
                Dato.add(TicketElegido);
                
                Dato.add(Color);
                Dato.add(TAsunto.getText());
                Dato.add(seg);
                Dato.add(Login.EmpleadoLogeado.getNombre());
                flujoEscritura.writeObject(Dato);
                
                flujoEscritura.close();
                cliente.close();
                PararCronometro();
                BReservar_Ticket.setEnabled(true);
                BLiberar_Ticket.setEnabled(false);
                BActualizar_Ticket.setEnabled(false);
                Login.EmpleadoLogeado.addTicketsResueltos();
                
            } catch (IOException ex) {
                Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            JOptionPane.showMessageDialog(null, "Tienes que resolver el ticket");
        }
    }//GEN-LAST:event_BActualizar_TicketActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        JTextField login= new JTextField();
        JTextField fecha= new JTextField();
        Object[] fields={"Login",login,"Dia",fecha
            };
        
        int Respuesta=JOptionPane.showConfirmDialog(null, fields);
        if(Respuesta==0)
        {
            if (login.getText() == null ? Login.EmpleadoLogeado.getNombre() == null : login.getText().equals(Login.EmpleadoLogeado.getNombre()))
            {
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                String dateInString = fecha.getText();
                DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
                Calendar cal = Calendar.getInstance();
                String Hoy=dateFormat.format(cal.getTime());
                
                {
                    try 
                    {
                        Date date = formatter.parse(dateInString);
                        if (Hoy == null ? dateInString == null : Hoy.equals(dateInString))
                        {
                            Socket cliente = new Socket(HOST, PUERTO);
                            ObjectOutputStream flujoEscritura = new ObjectOutputStream(cliente.getOutputStream());//Escritura
                            ArrayList Dato = new ArrayList();
                            Dato.add("6");
                            Dato.add(Login.EmpleadoLogeado.getTicketsResueltos());
                            Dato.add(date);
                            Dato.add(Color);
                            flujoEscritura.writeObject(Dato);
                            ObjectInputStream flujoLectura = new ObjectInputStream(cliente.getInputStream());//Lectura
                            ArrayList DatoReporte = (ArrayList) flujoLectura.readObject();
                            JOptionPane.showMessageDialog(null, "Cantidad de Tickets dados " + DatoReporte.get(0) + "\n"
                                    + "Cantidad de Tickets Resueltos " + DatoReporte.get(1) + "\n"
                                    + "Porcentaje Resulto " + DatoReporte.get(2) + "\n");
                            System.out.print(DatoReporte.toString());
                            flujoEscritura.close();
                            flujoLectura.close();
                            cliente.close();
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "No hay datos para este dia");
                        }
                    }
                    catch (ParseException e) 
                    {
                         JOptionPane.showMessageDialog(null, "La fecha tiene que ser de formato dd/MM/yyyy"); 
                    } catch (IOException ex) {
                        Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (ClassNotFoundException ex) {
                        Logger.getLogger(EmpleadoF.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
            else
            {
                JOptionPane.showMessageDialog(null, "El ID tiene que ser es del usuario loggeado");   
            }
            
            
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void CBAmarilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CBAmarilloActionPerformed
    Color="Amarillo";
    }//GEN-LAST:event_CBAmarilloActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(EmpleadoF.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(EmpleadoF.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(EmpleadoF.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(EmpleadoF.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new EmpleadoF().setVisible(true);
            }
        });
    }
    public void createJlist() {
        DefaultListModel listModel = new DefaultListModel();    
        int i;
        for (i = 0; i < DownloadTickets.size(); i++) {
            if("Disponible".equals(DownloadTickets.get(i).getEstado()))
            {
                String Dato = "Fecha de Recepcion: ";
                Dato += DownloadTickets.get(i).getRecepcion() + "  ";
                Dato += "ID Cliente: " + DownloadTickets.get(i).getID_Cliente() + "  ";
                Dato += "Asunto: " + DownloadTickets.get(i).getAsunto() + "  ";
                Dato += "Categoria: " + DownloadTickets.get(i).getCategoria() + "  ";
                Dato += "Estado: " + DownloadTickets.get(i).getEstado()+ "  ";
                
                listModel.addElement(Dato);
            }
        }

        LDownloadTickets.setModel(listModel);

    }
      

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BActualizar;
    private javax.swing.JButton BActualizar_Ticket;
    private javax.swing.JButton BDesconectar;
    private javax.swing.JButton BLiberar_Ticket;
    private javax.swing.JButton BReservar_Ticket;
    private javax.swing.JCheckBox CBAmarillo;
    private javax.swing.JCheckBox CBRojo;
    private javax.swing.JCheckBox CBVerde;
    private javax.swing.ButtonGroup GBColores;
    private javax.swing.JList LDownloadTickets;
    private javax.swing.JLabel LNUsuario;
    private javax.swing.JButton Solicitar_Ticket;
    private javax.swing.JTextArea TAsunto;
    private javax.swing.JLabel Usuario;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    // End of variables declaration//GEN-END:variables
}
