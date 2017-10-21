/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

/**
 *
 * @author Gollo
 */
public interface FabricaArchivos {
    public  boolean  CrearDocumento(int valor);
    public  boolean  CrearDocumentoExclusion(int valor);
    public  boolean  CrearDocumentoInclusion(int valor);   
}
