/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Vista.FSolicitud;
import java.io.IOException;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Usuario
 */
public class UISolicitud {
    private final dtoSolicitud dtoSoli = new dtoSolicitud();
    private final ControladorGeneral controladorGeneral;

    public UISolicitud() throws IOException {
        this.controladorGeneral = new ControladorGeneral();
    }
    
    public void AgregarSolicitud(FSolicitud ventana) throws IOException, SQLException{
        
            DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
            Date date = new Date();
            
            int id = Integer.parseInt(ventana.getjTextIDSolicitante().getText());
            String nombreSolitante = ventana.getjTextNombreSolicitante().getText();
            
            String Periodo = ventana.getjTextPeriodoLectivo().getText();
            String CodigoCurso = ventana.getjTextFieldCodCurso().getText();
            int grupo = Integer.parseInt(ventana.getjTextFieldNumGrupo().getText());
            int carnet = Integer.parseInt(ventana.getjTextFieldCarneEstu().getText());
            String nombre = ventana.getjTextFieldNombreEstu().getText();
            int telefono = Integer.parseInt(ventana.getjTextFieldTeleEstu().getText());
            String correo = ventana.getjTextFieldCorreoEstu().getText();
            String detalle = ventana.getjTextPaneDetalle().getText().toString();
            String tipo = String.valueOf(ventana.getjComboBoxTipoError().getSelectedItem().toString());
          
            if( nombreSolitante.isEmpty() || Periodo.isEmpty() || CodigoCurso.isEmpty() || nombre.isEmpty() || correo.isEmpty() || detalle.isEmpty() || tipo.isEmpty() ){
                    ventana.mostrarMensaje("Los campos no pueden estar vacios");
            }
            else{
                dtoSoli.setFecha(date);
                dtoSoli.setIdSolicitante(id);
                dtoSoli.setNombreSolitante(nombreSolitante);
                dtoSoli.setPeriodo(Periodo);
                dtoSoli.setCodigoCurso(CodigoCurso);
                dtoSoli.setGrupo(grupo);
                dtoSoli.setCarnet(carnet);
                dtoSoli.setNombre(nombre);
                dtoSoli.setTelefono(telefono);
                dtoSoli.setCorreo(correo);
                dtoSoli.setTipo(tipo);
                dtoSoli.setDetalle(detalle);
                boolean T = controladorGeneral.agregarSolicitud(dtoSoli);
                if (T == true){
                    Limpiar(ventana.getjTableSolicitudes());
                    for(int i=0;i<dtoSoli.getTabla().size();i++){
                        Object[] datos= new Object[5];
                        datos = (Object[]) dtoSoli.getTabla().get(i);
                        DefaultTableModel modelo=(DefaultTableModel) ventana.getjTableSolicitudes().getModel();
                        modelo.addRow(datos);
                        
                    }
                    ventana.mostrarMensaje("Se agrego correctamente");
                }
                else{
                    ventana.mostrarMensaje("No se pudo agregar");
                }
                
            }
    
    }
    
    public void Limpiar(JTable tabla){
        while(tabla.getRowCount()>0){
            ((DefaultTableModel) tabla.getModel()).removeRow(0);
        }
    }
    
    
    
    
}
