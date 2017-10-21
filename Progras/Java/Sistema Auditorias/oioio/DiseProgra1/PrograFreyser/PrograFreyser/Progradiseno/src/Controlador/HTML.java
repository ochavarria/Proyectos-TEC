/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import com.itextpdf.text.Chunk;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gollo
 */
public class HTML implements FabricaArchivos {
    daoSolicitudes daosoli= new daoSolicitudes();
    daoResolucion daoResul= new daoResolucion();
    Configuracion confi;
    ArrayList datos;

    public HTML() throws IOException {
        this.datos = new ArrayList();
        this.confi = new Configuracion();
    }

    @Override
    public boolean CrearDocumento(int valor)
    {
            try {
                datos=daosoli.CargarDatos(valor);
            } catch (SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String PeriodoL=(String) datos.get(4);
            String FechaL=(String) datos.get(1);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            try {
                String Profe=daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
                String HTMLcode = "<div><h3><CENTER>"+"Resolucion de la Direccion de la Escuela de Ingenieria en Computacion <br></br>"
                    + "Instituto Tecnologico de Costa Rica"+"</CENTER></h3>"
                    + "<h3><CENTER>"+"RES-IC-"+CodR+"-2017"+"</CENTER></h3>"
                    + "<h3>"+"Atencion:"+"</h3>"
                    + "<p><CENTER>"+DirE+", Director <br></br>"
                    
                    + "Departamento de Admisión y Registro"
                    + "</CENTER></p>"
                    
                    +"<p>A las diez horas de enero del ano dos mil diecisiete, el suscrito <b>"+DirEC+"</b>, Director de la Escuela de Ingenieria de Computacion en atencion al caso de modificacion de acta del estudiante <b>"+NombreE+"</b>, carné <b>"+CarnetE+"</b>, sobre el curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b>, del segundo semestre del año dosmil quince, resuelvo:</p>"
                    + "<h3>"+"RESULTANDO UNICO:"+"</h3>"
                    
                    +"<p>Por un error involuntario, no se tramitó la inclusión del estudiante <b>"+NombreE+"</b> con identificación <b>"+CarnetE+"</b> en el curso <b>"+DirEC+"</b> , grupo <b>"+GrupoE+"</b> impartido por el profesor <b>"+Profe+"</b> en el <b>"+PeriodoL+"</b> y al final del semestre, el profesor no pudo registrar en el acta la calificación obtenida por el estudiante.</p>"
                    + "<h3>"+"CONSIDERANDO UNICO:"+"</h3>"
                    + "<p>"+ daoResul.ObtenerConsiderandos(Integer.parseInt(CodR))+"</p>"
                    + "<h3>"+"RESUELVO:"+"</h3>"
                    + "<p>Autorizar la modificación del acta del curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b> en el <b>"+PeriodoL+"</b> en la fecha <b>"+FechaL+"</b> del curso impartido por el profesor <b>"+Profe+"</b> para incluir al estudiante <b>"+NombreE+"</b>, carné <b>"+CarnetE+"</b> con una nota de aprobación de noventa y cinco (95).</p>"
                    + "<h3>"+"NOTIFÍQUESE"+"</h3>"
                    + "<p><CENTER>"+DirEC+"<br></br>"
                    + "Director Escuela Ingeniería en Computación<br></br>"
                    + "Instituto Tecnológico de Costa Rica"
                    + "</CENTER></p>"
                    + "</div>";
                File f = new File("Resolucion "+CodR+".html");
                try
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(f));
                    bw.write(HTMLcode);
                    bw.close();
                    return true;
                }
                catch(IOException e ) {
                    return false; 
                }
                
            } catch (SQLException ex) {
                Logger.getLogger(HTML.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }        
            
            
        }
    
    
    @Override
    public boolean CrearDocumentoExclusion(int valor)
    {
            try {
                datos=daosoli.CargarDatos(valor);
            } catch (SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String PeriodoL=(String) datos.get(4);
            String FechaL=(String) datos.get(1);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            try {
                String Profe=daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
                String HTMLcode = "<div><h3><CENTER>"+"Resolucion de la Direccion de la Escuela de Ingenieria en Computacion <br></br>"
                    + "Instituto Tecnologico de Costa Rica"+"</CENTER></h3>"
                    + "<h3><CENTER>"+"RES-IC-"+CodR+"-2017"+"</CENTER></h3>"
                    + "<h3>"+"Atencion:"+"</h3>"
                    + "<p><CENTER>"+DirE+", Director <br></br>"
                    
                    + "Departamento de Admisión y Registro"
                    + "</CENTER></p>"
                    +"<p>A las once horas del veinte de enero del <b>"+FechaL+"</b>, el suscrito <b>"+DirEC+"</b>, Director de la Escuela de Ingeniería en Computación, en atención al caso de modificación de acta de los estudiantes que se indican en el cuadro inferior, sobre el curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b>, asignado al  profesor <b>"+Profe+"</b>, ofertado en el periodo <b>"+PeriodoL+"</b>, resuelvo: </p>"
                    + "<h3>"+"RESULTANDO UNICO:"+"</h3>"
                    +"<p>En el proceso de matrícula del periodo de <b>"+PeriodoL+"</b> , se ofertó el curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b>, que había sido asignado al profesor <b>"+Profe+"</b>, el cual debió cerrarse por no alcanzar el cupo mínimo requerido.</p>"    
                    + "<h3>"+"CONSIDERANDO UNICO:"+"</h3>"
                    + "<p>"+ daoResul.ObtenerConsiderandos(Integer.parseInt(CodR))+"</p>"
                    + "<h3>"+"RESUELVO:"+"</h3>"
                    + "<p>Esta Dirección autoriza la modificación del acta del curso sobre el curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b> para gestionar la exclusión de la matrícula del estudiante <b>"+NombreE+"</b>, pues el curso fue cerrado por no alcanzar el cupo.</p>"
                    + "<h3>"+"NOTIFÍQUESE"+"</h3>"
                    + "<p><CENTER>"+DirEC+"<br></br>"
                    + "Director Escuela Ingeniería en Computación<br></br>"
                    + "Instituto Tecnológico de Costa Rica"
                    + "</CENTER></p>"
                    + "</div>";
                File f = new File("Resolucion "+CodR+".html");
                try
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(f));
                    bw.write(HTMLcode);
                    bw.close();
                    return true;
                }
                catch(IOException e ) {
                    return false; 
                }
                
            } catch (SQLException ex) {
                Logger.getLogger(HTML.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }        
            
            
        }
    
    @Override
    public boolean CrearDocumentoInclusion(int valor)
    {
            try {
                datos=daosoli.CargarDatos(valor);
            } catch (SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String PeriodoL=(String) datos.get(4);
            String FechaL=(String) datos.get(1);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            try {
                String Profe=daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
                String HTMLcode = "<div><h3><CENTER>"+"Resolucion de la Direccion de la Escuela de Ingenieria en Computacion <br></br>"
                    + "Instituto Tecnologico de Costa Rica"+"</CENTER></h3>"
                    + "<h3><CENTER>"+"RES-IC-"+CodR+"-2017"+"</CENTER></h3>"
                    + "<h3>"+"Atencion:"+"</h3>"
                    + "<p><CENTER>"+DirE+", Director <br></br>"
                    
                    + "Departamento de Admisión y Registro"
                    + "</CENTER></p>"
                    +"<p>A las once horas del veinte de enero del <b>"+FechaL+"</b>, el suscrito <b>"+DirEC+"</b>, Director de la Escuela de Ingeniería en Computación, en atención al caso de modificación de acta de los estudiantes que se indican en el cuadro inferior, sobre el curso <b>"+CodCursoE+"</b>, grupo <b>"+GrupoE+"</b>, asignado al  profesor <b>"+Profe+"</b>, ofertado en el periodo <b>"+PeriodoL+"</b>, resuelvo: </p>"
                    + "<h3>"+"RESULTANDO UNICO:"+"</h3>"
                    +"<p>En el proceso de matrícula  del periodo <b>"+PeriodoL+"</b>, el estudiante <b>"+NombreE+"</b>, carné <b>"+CarnetE+"</b> de forma equivocada no realizó la matrícula del curso <b>"+CodCursoE+"</b>,  pues el sistema le permitió matricular el curso complementario a éste pero no el correquisito.  Se detecta la inconsistencia y se solicita el trámite de inclusión en el curso <b>"+CodCursoE+"</b> grupo <b>"+GrupoE+"</b>,  que es el mismo grupo del curso complementario matriculado, pero por un error administrativo, en el reporte de inclusiones tramitadas en el semestre <b>"+PeriodoL+"</b>  se omite su solicitud.  El curso es aprobado en su totalidad por el estudiante con una nota de setenta (70) pero no puede ser reportado al no existir matriculado en el acta correspondiente. </p>"    
                    + "<h3>"+"CONSIDERANDO UNICO:"+"</h3>"
                    + "<p>"+ daoResul.ObtenerConsiderandos(Integer.parseInt(CodR))+"</p>"
                    + "<h3>"+"RESUELVO:"+"</h3>"
                    + "<p>Autorizar la inclusión en el curso <b>"+CodCursoE+"</b> grupo <b>"+GrupoE+"</b>,  impartido en el semestre <b>"+PeriodoL+"</b>,  al estudiante <b>"+NombreE+"</b>, carné <b>"+CarnetE+"</b>, y actualizar su nota de aprobación a fin de que estado de la misma sea aprobado con una nota final de setenta (70)</p>"
                    + "<h3>"+"NOTIFÍQUESE"+"</h3>"
                    + "<p><CENTER>"+DirEC+"<br></br>"
                    + "Director Escuela Ingeniería en Computación<br></br>"
                    + "Instituto Tecnológico de Costa Rica"
                    + "</CENTER></p>"
                    + "</div>";
                File f = new File("Resolucion "+CodR+".html");
                try
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(f));
                    bw.write(HTMLcode);
                    bw.close();
                    return true;
                }
                catch(IOException e ) {
                    return false; 
                }
                
            } catch (SQLException ex) {
                Logger.getLogger(HTML.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }        
            
            
        }
    
    
    
}
