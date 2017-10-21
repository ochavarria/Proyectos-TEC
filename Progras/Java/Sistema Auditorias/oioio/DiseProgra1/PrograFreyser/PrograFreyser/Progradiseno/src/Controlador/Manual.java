/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Datos.Solicitud;
import Datos.TipoI;

/**
 *
 * @author Usuario
 */
public class Manual extends Estrategia {

    public Manual() {
    }
    
    public Object agregar(dtoSolicitud dtoSoli){
        Solicitud soli = new Solicitud(dtoSoli.getIdSolicitante(),dtoSoli.getNombreSolitante(),dtoSoli.getPeriodo(),dtoSoli.getCodigoCurso(),dtoSoli.getGrupo(),dtoSoli.getCarnet(),dtoSoli.getNombre(),dtoSoli.getCorreo(),dtoSoli.getTelefono(),TipoI.valueOf(dtoSoli.getTipo()),dtoSoli.getDetalle());
        return soli;
    }
    
            
    
}
