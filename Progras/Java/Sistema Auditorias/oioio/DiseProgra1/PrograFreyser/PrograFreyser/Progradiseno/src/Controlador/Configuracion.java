/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Properties;

/**
 *
 * @author freys
 */
public class Configuracion {
    public int ultimaResolucion;
    public String nombreAR;
    public String nombreDC;
    public String nombreCC;
    
    public Configuracion() throws FileNotFoundException, IOException {
        
        Properties prop = new Properties();
        InputStream input = new FileInputStream("datosImportantes");
        prop.load(input);
        ultimaResolucion= Integer.valueOf(prop.getProperty("UltimaResolucion"));
        nombreAR=prop.getProperty("nombreAR");
        nombreDC=prop.getProperty("nombreDC");
        nombreCC=prop.getProperty("nombreCC");
    }
    
    public void cargarDatos(int valor){
        Properties prop = new Properties();
	OutputStream output = null;

	try {
		output = new FileOutputStream("datosImportantes");
		prop.setProperty("nombreAR", "Master Geovanni Rojas Rodriguez");
		prop.setProperty("nombreDC", "Ing. Mauricio Arroyo Herrera ");
		prop.setProperty("nombreCC", "Ing. Ericka Solano Fernandez");
                prop.setProperty("UltimaResolucion",String.valueOf(valor));
		prop.store(output, null);

	} catch (IOException io) {
	} finally {
		if (output != null) {
			try {
				output.close();
			} catch (IOException e) {
			}
		}

	}
    }
    
}
