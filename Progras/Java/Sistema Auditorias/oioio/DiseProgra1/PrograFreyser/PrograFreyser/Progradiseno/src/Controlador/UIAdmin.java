/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Vista.FAdmin;
import java.awt.Dimension;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.JFreeChart;
import org.jfree.data.general.DefaultPieDataset;

/**
 *
 * @author Usuario
 */
public class UIAdmin {
    private final dtoResolucion dtoRes = new dtoResolucion();
    private final dtoSolicitud dtoSoli = new dtoSolicitud();
    Connection cn;
    
    private final ControladorGeneral controladorGeneral;
    
    public UIAdmin() throws IOException {
        this.controladorGeneral = new ControladorGeneral();
        Conexion con= new Conexion();
        try {
            try {
                cn=con.conectar();
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(daoSolicitudes.class.getName()).log(Level.SEVERE, null, ex);
            }
        } catch (SQLException ex) {
            Logger.getLogger(daoSolicitudes.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    public boolean GenerarArchivo(int TipoArchivo,String tipo,int valor)
    {
        
        return controladorGeneral.GenerarArchivo(TipoArchivo,tipo,valor);
    }
    public boolean CambiarEstado (String estado,String Id) throws ClassNotFoundException
    {
        return controladorGeneral.CambiarEstado(estado,Id);
           
    }
    
    public boolean AgregarConsiderandos(FAdmin ventana) throws ClassNotFoundException
    {
        dtoRes.setConsiderando(ventana.getjTextAreaConsiderando().getText());
        dtoRes.setIDSolicitud(Integer.parseInt(ventana.getIdSolicitudPendiente().getText()));
        return controladorGeneral.AgregarConsiderandos(dtoRes);
           
    }


    public void SolicitudesPendientes(FAdmin ventana) throws SQLException {
         
        controladorGeneral.SolicitudesPen(dtoSoli);
        
        Limpiar(ventana.getjTableSolicitudes());
        for(int i=0;i<dtoSoli.getTabla().size();i++){
            Object[] datos= new Object[5];
            datos = (Object[]) dtoSoli.getTabla().get(i);
            DefaultTableModel modelo=(DefaultTableModel) ventana.getjTableSolicitudes().getModel();
            modelo.addRow(datos);

        }            
    }
    public boolean CargarSolicitudes(String Path)
    {
        File file = new File(Path);
            String txt = ""; 
            try{
               Scanner inputStream = new Scanner(file); 
                inputStream.nextLine();
               
               while(inputStream.hasNext())
               {
                   txt=inputStream.nextLine();
                   txt = txt.replace("\"", "");
                   String Solicitud[] = txt.split(",");
                   for(int i=0; i<12;i++)
                   {
                        System.out.println(Solicitud[i]);
                        switch(i)
                        {
                                case 0: 
                                    System.out.println(Solicitud[i]);
                                    Solicitud[i]=Solicitud[i].replaceAll("AM CDT", "");
                                    Solicitud[i]=Solicitud[i].replaceAll("/", "-");
                                    SimpleDateFormat formatter3=new SimpleDateFormat("yyyy-MM-dd "); 
                                    
                                    java.util.Date dDate = formatter3.parse(Solicitud[i]);
                                    
                                    System.out.println(dDate);
                                    
                                    dtoSoli.setFecha(dDate);
                                    break;
                                case 1: 
                                    dtoSoli.setNombreSolitante(Solicitud[i]);
                                    break;
                                case 2:
                                    dtoSoli.setIdSolicitante(Integer.parseInt(Solicitud[i]));
                                    break;
                                case 3:
                                    dtoSoli.setPeriodo(Solicitud[i]);
                                    break;
                                case 4:
                                    dtoSoli.setNombre(Solicitud[i]);
                                    break;
                                case 5:
                                    dtoSoli.setCarnet(Integer.parseInt(Solicitud[i]));
                                    break;
                                case 6:
                                    dtoSoli.setCorreo(Solicitud[i]);
                                    break;
                                case 7:
                                    dtoSoli.setTelefono(Integer.parseInt(Solicitud[i]));
                                    break;
                                case 8:
                                    dtoSoli.setCodigoCurso(Solicitud[i]);
                                    break;
                                case 9:
                                    dtoSoli.setGrupo(Integer.parseInt(Solicitud[i]));
                                    break;
                                case 10:
                                    dtoSoli.setTipo(Solicitud[i]);
                                    break;
                                case 11:
                                    dtoSoli.setDetalle(Solicitud[i]);
                                    break;
                                    
                        }
                   }
                   controladorGeneral.agregarSolicitud(dtoSoli);
               }

               return true;
            }   
            catch (FileNotFoundException ex) {
                    Logger.getLogger(FAdmin.class.getName()).log(Level.SEVERE, null, ex);
                    return false;
            }catch (ParseException ex) {
                            Logger.getLogger(UIAdmin.class.getName()).log(Level.SEVERE, null, ex);
                        } catch (IOException ex) {
            Logger.getLogger(UIAdmin.class.getName()).log(Level.SEVERE, null, ex);
        }
            return false;
        
    }
    public boolean AgregarResolucion(FAdmin ventana){
        dtoRes.setIDSolicitud(Integer.parseInt(ventana.getjTextIDSolicitud2().getText()));
        return controladorGeneral.AgregarResolucion(dtoRes);
        
    }
    
    public void SolicitudesAprobadas(FAdmin ventana) throws SQLException {
        
        controladorGeneral.SolicitudesAprobadas(dtoSoli);
        
        Limpiar(ventana.getjTableSolicitudesAprobadas());
        for(int i=0;i<dtoSoli.getTabla().size();i++){
            Object[] datos= new Object[5];
            datos = (Object[]) dtoSoli.getTabla().get(i);
            DefaultTableModel modelo=(DefaultTableModel) ventana.getjTableSolicitudesAprobadas().getModel();
            modelo.addRow(datos);

        }            
    }
    public ArrayList ConsultarProfesores(){
        ArrayList datos = new ArrayList();       
        try{
            String sql="select top(3) Docentes.Nombre,Count(Docentes.Nombre) as suma from Solicitudes,Resoluciones,Docentes,CursoAbiertos,Cursos where Solicitudes.idSolicitud=Resoluciones.idSolicitud AND CursoAbiertos.idDocente=Docentes.idDocente and Solicitudes.Grupo=CursoAbiertos.Grupo and CursoAbiertos.idCurso =Solicitudes.CodCurso\n" +
                        "group by Docentes.Nombre\n" +
                        "order by suma";
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
                    ArrayList datos1 = new ArrayList();
                    for(int i=0;i<2;i++){
                        datos1.add(rs.getString(i+1));
                    }
                    datos.add(datos1);
                }
                return datos;
            }
        }catch(Exception ex){
            System.out.println(ex.getMessage());
            return datos;
        }
    }
    
    public ArrayList ConsultarCursos(){
        ArrayList datos = new ArrayList();       
        try{
            String sql="select top(5) Cursos.Nombre, Count(Cursos.Nombre) as suma From Cursos,Solicitudes,Resoluciones where Resoluciones.idSolicitud=Solicitudes.idSolicitud and Solicitudes.CodCurso= Cursos.Codigo\n" +
                        "group by Cursos.Nombre\n" +
                        "order by suma";
            
            try (CallableStatement cmd = cn.prepareCall(sql)) {
                ResultSet rs =cmd.executeQuery();
                while(rs.next()){
                    ArrayList datos1 = new ArrayList();
                    for(int i=0;i<2;i++){
                        datos1.add(rs.getString(i+1));
                    }
                    datos.add(datos1);
                }
                return datos;
            }
        }catch(Exception ex){
            System.out.println(ex.getMessage());
            return datos;
        }
    }
    
    public  void CrearGraficoCircular(FAdmin ventana,int TipoG) { 
        ArrayList datos= ConsultarProfesores();
        ArrayList datosC= ConsultarCursos();
        if(TipoG==0)
        {
            BufferedImage _image;//para la imagen en memoria
            JFreeChart grafico;// el grafico
            Dimension d = ventana.getPnGraphicoP().getSize();
            DefaultPieDataset dataset = new DefaultPieDataset();
            
            // Establecemos unas categorías de ejemplo
            for(int i=0; i<datos.size();i++){
                ArrayList datos1= (ArrayList) datos.get(i);
                dataset.setValue(datos1.get(0).toString(),Integer.parseInt((String) datos1.get(1)));
            }
            //dataset.setValue("Profesor2", 2);
            
            

            // Creamos la tabla
            grafico = ChartFactory.createPieChart(
                    "Top 3 Profesores",
                    dataset,
                    true,
                    true,
                    false);
            JLabel j = new JLabel();
            j.setBounds(0, 0, d.width, d.height);

            _image = grafico.createBufferedImage(d.width, d.height);
            ImageIcon imagenFondo = new ImageIcon(_image);
            j.setIcon(imagenFondo);
            j.repaint();

            ventana.getPnGraphicoP().add(j);
            ventana.getPnGraphicoP().setVisible(true);
            //ventana.getjPanel3().add(ventana.getPnGraphicoP().add(j));
            ventana.getjPanel3().add(ventana.getPnGraphicoP());
            ventana.getjPanel3().add(ventana.getPnGraphicoC());
            
            ventana.repaint();
        }
        else{
            
            BufferedImage _image;//para la imagen en memoria
            JFreeChart grafico;// el grafico
            Dimension d = ventana.getPnGraphicoC().getSize();
            DefaultPieDataset dataset = new DefaultPieDataset();

            // Establecemos unas categorías de ejemplo
            for(int i=0; i<datosC.size();i++){
                ArrayList datos1= (ArrayList) datosC.get(i);
                dataset.setValue(datos1.get(0).toString(),Integer.parseInt((String) datos1.get(1)));
            }
            
            // Creamos la tabla
            grafico = ChartFactory.createPieChart(
                    "Top 5 Cursos",
                    dataset,
                    true,
                    true,
                    false);
            JLabel j = new JLabel();
            j.setBounds(0, 0, d.width, d.height);

            _image = grafico.createBufferedImage(d.width, d.height);
            ImageIcon imagenFondo = new ImageIcon(_image);
            j.setIcon(imagenFondo);
            j.repaint();

            ventana.getPnGraphicoC().add(j);
            ventana.getPnGraphicoC().setVisible(true);

            ventana.getjPanel3().add(ventana.getPnGraphicoC());
            ventana.repaint();

        }
        
    } 
    
    
    
    
    
    public void Limpiar(JTable tabla){
        while(tabla.getRowCount()>0){
            ((DefaultTableModel) tabla.getModel()).removeRow(0);
        }
    }
    
}
