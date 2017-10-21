/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import com.itextpdf.text.BaseColor;
import com.itextpdf.text.Chunk;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Element;
import com.itextpdf.text.FontFactory;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;
import java.awt.Font;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gollo
 */
public class PDF implements FabricaArchivos{
    daoSolicitudes daosoli= new daoSolicitudes();
    daoResolucion daoResul= new daoResolucion();
    Configuracion confi;
    ArrayList datos;
    
    
    public PDF() throws IOException {
        this.datos = new ArrayList();
        this.confi = new Configuracion();
        
    }
    
    
    @Override
    public boolean  CrearDocumento(int valor)
    {    
        try{
            
            datos=daosoli.CargarDatos(valor);
             
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            String PeriodoL=(String) datos.get(4);
            String Profe;
            
            
            Document doc = new Document();

            PdfWriter.getInstance(doc, new FileOutputStream("Resolucion "+ CodR+".pdf"));
            doc.open();
            
            
            com.itextpdf.text.Font FdatoE = FontFactory.getFont(FontFactory.TIMES,14,Font.BOLD,BaseColor.BLACK);
            Chunk nombre = new Chunk(NombreE, FdatoE);
            Chunk carnet = new Chunk(CarnetE, FdatoE);
            Chunk codcurso = new Chunk(CodCursoE, FdatoE);
            Chunk grupo = new Chunk(GrupoE, FdatoE);
            Chunk periodo = new Chunk(PeriodoL, FdatoE);
            
            Profe = daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
            Chunk profe = new Chunk(Profe, FdatoE);
            
            //Insertar 
            Paragraph Titulo = new Paragraph("Resolucion de la Direccion de la Escuela de Ingenieria en Computacion Instituto Tecnologico de Costa Rica \n"
                    ,FontFactory.getFont(FontFactory.TIMES,16   ,Font.BOLD));
            Titulo.setAlignment(Element.ALIGN_CENTER);
            
            // Insertar el Codigo
            Paragraph Codigo = new Paragraph("RES-IC-"
                    ,FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD));
            com.itextpdf.text.Font Fcod = FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD,BaseColor.RED);
            Chunk greenText = new Chunk(CodR, Fcod);
            
            Codigo.add(greenText);
            Codigo.add("-2017"); 
            Codigo.add( Chunk.NEWLINE );
            Codigo.add( Chunk.NEWLINE );    
            Codigo.setAlignment(Element.ALIGN_CENTER);
            
            
            
            //Insertar el destinartario
            Paragraph Para = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            com.itextpdf.text.Font FAten = FontFactory.getFont(FontFactory.TIMES,12,Font.BOLD);
            
            Chunk Aten = new Chunk("Atencion:            ", FAten);
            Para.add(Aten);
            Para.add(DirE+", Director "+Chunk.NEWLINE +"                         "
                    + "Departamento de Admision y Registro");
            Para.add( Chunk.NEWLINE );
            Para.add( Chunk.NEWLINE );
            
            //Para.add(DirReg);
            Para.setAlignment(Element.ALIGN_CENTER);
            
            //Datos dinamicos
            Paragraph Cuerpo = new Paragraph("A las diez y siete horas de abril del año dos mil diecisiete, el suscrito Ing."
                    + "Mauricio Arroyo Herrera, Director de la Escuela de Ingenieria de Computacion en atencion al caso "
                    + "de modificacion de acta del estudiante "
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Cuerpo.add(nombre);
            Cuerpo.add(", carne ");
            Cuerpo.add(carnet);
            Cuerpo.add(", sobre el curso ");
            Cuerpo.add(codcurso);
            Cuerpo.add(", grupo ");
            Cuerpo.add(grupo);
            Cuerpo.add(", del segundo semestre del a;o dos mil diecisiete, resuelvo: ");
            Cuerpo.add( Chunk.NEWLINE );
            Cuerpo.add( Chunk.NEWLINE ); 
            
            Chunk Resul = new Chunk("Resultando Unico:", FdatoE);
            Paragraph Resultando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Resultando.add(Resul);
            Resultando.add( Chunk.NEWLINE );
            Resultando.add( Chunk.NEWLINE );
            
            Resultando.add("Por un error involuntario, no se tramito la inclusion del estudiante ");
            Resultando.add(nombre);
            Resultando.add(" con identificacion ");
            Resultando.add(carnet);
            Resultando.add(" en el curso ");
            Resultando.add(codcurso);
            Resultando.add(" grupo ");
            Resultando.add(grupo);
            Resultando.add(" impartido por el profesor ");
            Resultando.add(Profe);
            Resultando.add(" en el primer semestre del a;o 2017 y al final del semestre, el profesor no pudo "
                    + "registrar en el acta la calificacion obtenida por el estudiante ");
            Resultando.add( Chunk.NEWLINE ); 
            Resultando.add( Chunk.NEWLINE ); 
            
            
            com.itextpdf.text.Font FdatoC = FontFactory.getFont(FontFactory.TIMES,12);
            Chunk Consi = new Chunk("Considerando Unico:", FdatoE);
            Paragraph Considerando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Considerando.add(Consi);
            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            
            Chunk Considers = new Chunk(daoResul.ObtenerConsiderandos(Integer.parseInt(CodR)), FdatoC);
            Considerando.add(Considers);
                
           
            
            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            
            Chunk Resue = new Chunk("Resuelvo:", FdatoE);
            Paragraph Resuelvo = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));            
            
            Resuelvo.add(Resue);
            Resuelvo.add( Chunk.NEWLINE );            
            Resuelvo.add( Chunk.NEWLINE ); 
            Resuelvo.add("Autorizar la modificacion del acta del curso ");
            Resuelvo.add(codcurso);
            Resuelvo.add(",grupo ");
            Resuelvo.add(grupo);
            Resuelvo.add(" en el "+ periodo);
            Resuelvo.add(" del ano 2017 impartido por el profesor ");
            
            
            Resuelvo.add(profe);
            
            
            Resuelvo.add(" para incluir al estudiante ");
            Resuelvo.add(nombre);
            Resuelvo.add(", carne  ");
            Resuelvo.add(carnet);
            Resuelvo.add(", con una nota de aprovacion de noventa y cinco.");
            Resuelvo.add( Chunk.NEWLINE );            
            Resuelvo.add( Chunk.NEWLINE );
            
            Chunk Noti = new Chunk("Notifiquese:", FdatoE);
            Paragraph Notifiquese = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12)); 
            Notifiquese.add(Noti);
            Notifiquese.add( Chunk.NEWLINE );            
            Notifiquese.add( Chunk.NEWLINE ); 
            Notifiquese.add("                                                                                      ");
            Notifiquese.add(DirEC);
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Director Escuela Ingenieria en Computacion");
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Instituto Tecnologico de Costa Rica");
            
            doc.add(Titulo);
            doc.add(Codigo);
            doc.add(Para);
            doc.add(Cuerpo);
            doc.add(Resultando);
            doc.add(Considerando);
            doc.add(Resuelvo);
            doc.add(Notifiquese);
            doc.close();
            return true;
            
        }
        catch(DocumentException ex)
        {
            System.out.println("Error al crear el pdf");
        } catch (FileNotFoundException ex) {
            System.out.println("Error al crear el pdf");
        }catch(SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
        return false;
    }     
    
    @Override
    public boolean CrearDocumentoExclusion(int valor)
    {    
        try{
            
            datos=daosoli.CargarDatos(valor);
            
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            String PeriodoL=(String) datos.get(4);
            String Profe;
            
            
            Document doc = new Document();

            PdfWriter.getInstance(doc, new FileOutputStream("Resolucion "+ CodR+".pdf"));
            doc.open();
            
            
            com.itextpdf.text.Font FdatoE = FontFactory.getFont(FontFactory.TIMES,14,Font.BOLD,BaseColor.BLACK);
            Chunk nombre = new Chunk(NombreE, FdatoE);
            Chunk carnet = new Chunk(CarnetE, FdatoE);
            Chunk codcurso = new Chunk(CodCursoE, FdatoE);
            Chunk grupo = new Chunk(GrupoE, FdatoE);
            Chunk periodo = new Chunk(PeriodoL, FdatoE);
            
            Profe = daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
            Chunk profe = new Chunk(Profe, FdatoE);

            
            //Insertar 
            Paragraph Titulo = new Paragraph("Resolucion de la Direccion de la Escuela de Ingenieria en Computacion Instituto Tecnologico de Costa Rica \n"
                    ,FontFactory.getFont(FontFactory.TIMES,16   ,Font.BOLD));
            Titulo.setAlignment(Element.ALIGN_CENTER);
            
            // Insertar el Codigo
            Paragraph Codigo = new Paragraph("RES-IC-"
                    ,FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD));
            com.itextpdf.text.Font Fcod = FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD,BaseColor.RED);
            Chunk greenText = new Chunk(CodR, Fcod);
            
            Codigo.add(greenText);
            Codigo.add("-2017"); 
            Codigo.add( Chunk.NEWLINE );
            Codigo.add( Chunk.NEWLINE );    
            Codigo.setAlignment(Element.ALIGN_CENTER);
            
            
            
            //Insertar el destinartario
            Paragraph Para = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            com.itextpdf.text.Font FAten = FontFactory.getFont(FontFactory.TIMES,12,Font.BOLD);
            
            Chunk Aten = new Chunk("Atencion:            ", FAten);
            Para.add(Aten);
            Para.add(DirE+", Director "+Chunk.NEWLINE +"                         "
                    + "Departamento de Admision y Registro");
            Para.add( Chunk.NEWLINE );
            Para.add( Chunk.NEWLINE );
            
            //Para.add(DirReg);
            Para.setAlignment(Element.ALIGN_CENTER);
            
            //Datos dinamicos
            Paragraph Cuerpo = new Paragraph("A las diez y siete horas de abril del año dos mil diecisiete, el suscrito Ing."
                    + "Mauricio Arroyo Herrera, Director de la Escuela de Ingenieria de Computacion en atencion al caso "
                    + "de modificacion de acta del estudiante "
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Cuerpo.add(nombre);
            Cuerpo.add(", carne ");
            Cuerpo.add(carnet);
            Cuerpo.add(", sobre el curso ");
            Cuerpo.add(codcurso);
            Cuerpo.add(", grupo ");
            Cuerpo.add(grupo);
            Cuerpo.add(",asignado al profesor ");
            Cuerpo.add(Profe);
            
        
            Cuerpo.add(", ofertado en el segundo periodo del año 2017, resuelvo: ");
            Cuerpo.add( Chunk.NEWLINE );
            Cuerpo.add( Chunk.NEWLINE ); 
            
            Chunk Resul = new Chunk("Resultando Unico:", FdatoE);
            Paragraph Resultando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Resultando.add(Resul);
            Resultando.add( Chunk.NEWLINE );
            Resultando.add( Chunk.NEWLINE );
            
            Resultando.add("En el proceso de matricula del segundo periodo del año 2017, se oferto el curso ");
            Resultando.add(codcurso);
            Resultando.add(" grupo ");
            Resultando.add(grupo);
            Resultando.add(" que habia sido asignado al profesor ");
            Resultando.add(Profe);
            Resultando.add(" el cual debio cerrarse por no alcanzar el cupo minimo requerido.");
            Resultando.add( Chunk.NEWLINE ); 
            Resultando.add( Chunk.NEWLINE ); 
            
            
            com.itextpdf.text.Font FdatoC = FontFactory.getFont(FontFactory.TIMES,12,BaseColor.BLACK);
            Chunk Consi = new Chunk("Considerando Unico:", FdatoE);
            Paragraph Considerando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Considerando.add(Consi);
            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            Chunk Considers = new Chunk(daoResul.ObtenerConsiderandos(Integer.parseInt(CodR)), FdatoC);
            Considerando.add(Considers);


            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            
            Chunk Resue = new Chunk("Resuelvo:", FdatoE);
            Paragraph Resuelvo = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));            
            
            Resuelvo.add(Resue);
            Resuelvo.add( Chunk.NEWLINE );   
            Resuelvo.add("Esta direccion autorizada la modificacion del acta del curso sobre el curso");
            Resuelvo.add(codcurso);
            Resuelvo.add(",grupo ");
            Resuelvo.add(grupo);
            Resuelvo.add(" para gestionar la exclusion de la matricula de los estudiante "+ nombre + ", pues el curso fue cerrado por no alcanzar el cupo minimo.");

            Resuelvo.add( Chunk.NEWLINE );            
            Resuelvo.add( Chunk.NEWLINE );
            
            Chunk Noti = new Chunk("Notifiquese:", FdatoE);
            Paragraph Notifiquese = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12)); 
            Notifiquese.add(Noti);
            Notifiquese.add( Chunk.NEWLINE );            
            Notifiquese.add( Chunk.NEWLINE ); 
            Notifiquese.add("                                                                                      ");
            Notifiquese.add(DirEC);
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Director Escuela Ingenieria en Computacion");
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Instituto Tecnologico de Costa Rica");
            
            doc.add(Titulo);
            doc.add(Codigo);
            doc.add(Para);
            doc.add(Cuerpo);
            doc.add(Resultando);
            doc.add(Considerando);
            doc.add(Resuelvo);
            doc.add(Notifiquese);
            doc.close();
            return true;
            
        }
        catch(DocumentException ex)
        {
            System.out.println("Error al crear el pdf");
        } catch (FileNotFoundException ex) {
            Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
        }catch (SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
        return false;
    }         
    @Override
    public boolean CrearDocumentoInclusion(int valor)
    {    
        try{
            
            datos=daosoli.CargarDatos(valor);
            
            String NombreE=(String) datos.get(8);
            String CarnetE=(String) datos.get(7);
            String CodCursoE=(String) datos.get(5);
            String GrupoE=(String) datos.get(6);
            String CodS=(String) datos.get(0);
            String CodR=(String) datos.get(0);
            String DirE=String.valueOf(confi.nombreAR);
            String DirEC=String.valueOf(confi.nombreDC);
            String PeriodoL=(String) datos.get(4);
            String Profe;
            
            
            Document doc = new Document();

            PdfWriter.getInstance(doc, new FileOutputStream("Resolucion "+ CodR+".pdf"));
            doc.open();
            
            
            com.itextpdf.text.Font FdatoE = FontFactory.getFont(FontFactory.TIMES,14,Font.BOLD,BaseColor.BLACK);
            Chunk nombre = new Chunk(NombreE, FdatoE);
            Chunk carnet = new Chunk(CarnetE, FdatoE);
            Chunk codcurso = new Chunk(CodCursoE, FdatoE);
            Chunk grupo = new Chunk(GrupoE, FdatoE);
            Chunk periodo = new Chunk(PeriodoL, FdatoE);
            
            Profe = daoResul.ObtenerProfesor(Integer.valueOf(GrupoE),CodCursoE);
            Chunk profe = new Chunk(Profe, FdatoE);

            
            //Insertar 
            Paragraph Titulo = new Paragraph("Resolucion de la Direccion de la Escuela de Ingenieria en Computacion Instituto Tecnologico de Costa Rica \n"
                    ,FontFactory.getFont(FontFactory.TIMES,16   ,Font.BOLD));
            Titulo.setAlignment(Element.ALIGN_CENTER);
            
            // Insertar el Codigo
            Paragraph Codigo = new Paragraph("RES-IC-"
                    ,FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD));
            com.itextpdf.text.Font Fcod = FontFactory.getFont(FontFactory.TIMES,16,Font.BOLD,BaseColor.RED);
            Chunk greenText = new Chunk(CodR, Fcod);
            
            Codigo.add(greenText);
            Codigo.add("-2017"); 
            Codigo.add( Chunk.NEWLINE );
            Codigo.add( Chunk.NEWLINE );    
            Codigo.setAlignment(Element.ALIGN_CENTER);
            
            
            
            //Insertar el destinartario
            Paragraph Para = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            com.itextpdf.text.Font FAten = FontFactory.getFont(FontFactory.TIMES,12,Font.BOLD);
            
            Chunk Aten = new Chunk("Atencion:            ", FAten);
            Para.add(Aten);
            Para.add(DirE+", Director "+Chunk.NEWLINE +"                         "
                    + "Departamento de Admision y Registro");
            Para.add( Chunk.NEWLINE );
            Para.add( Chunk.NEWLINE );
            
            //Para.add(DirReg);
            Para.setAlignment(Element.ALIGN_CENTER);
            
            //Datos dinamicos
            Paragraph Cuerpo = new Paragraph("A las diez y siete horas de abril del año dos mil diecisiete, el suscrito Ing."
                    + "Mauricio Arroyo Herrera, Director de la Escuela de Ingenieria de Computacion en atencion al caso "
                    + "de modificacion de acta del estudiante "
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Cuerpo.add(nombre);
            Cuerpo.add(", carne ");
            Cuerpo.add(carnet);
            Cuerpo.add(", sobre el curso ");
            Cuerpo.add(codcurso);
            Cuerpo.add(", grupo ");
            Cuerpo.add(grupo);
            
            Cuerpo.add(", el primer semestre del año 2017, resuelvo: ");
            Cuerpo.add( Chunk.NEWLINE );
            Cuerpo.add( Chunk.NEWLINE ); 
            
            Chunk Resul = new Chunk("Resultando Unico:", FdatoE);
            Paragraph Resultando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Resultando.add(Resul);
            Resultando.add( Chunk.NEWLINE );
            Resultando.add( Chunk.NEWLINE );
            
            Resultando.add("En el proceso de matricula del segundo periodo del año 2017, se oferto el curso ");
            Resultando.add(nombre);
            Resultando.add(", carne ");
            Resultando.add(carnet);
            Resultando.add(" de forma equivocada no realizo la matricula del curso");
            Resultando.add(codcurso);
            Resultando.add(", pues el sistema le permitio matricular el curso complementario a este pero no el correquisito.");
            Resultando.add( Chunk.NEWLINE );
            Resultando.add("Se detecta la inconsistencia y se solicita el tramite de inclusion en el curso ");
            Resultando.add(codcurso);
            Resultando.add(" grupo ");
            Resultando.add(grupo);
            Resultando.add(" que es el mismo grupo del curso complementario matriculado, pero por un error administrativo, en el reporte de inclusiones tramitadas "
                    + "en este segundo semestre 2017 curso es aprobado en su totalidad por el estudiante con una nota de setenta (70) "
                    + "pero no puede ser reportado al no existir matriculado en el acta correspondiente.");
            Resultando.add( Chunk.NEWLINE ); 
            Resultando.add( Chunk.NEWLINE ); 
            
            
            com.itextpdf.text.Font FdatoC = FontFactory.getFont(FontFactory.TIMES,12,BaseColor.BLACK);
            Chunk Consi = new Chunk("Considerando Unico:", FdatoE);
            Paragraph Considerando = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));
            Considerando.add(Consi);
            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            Chunk Considers = new Chunk(daoResul.ObtenerConsiderandos(Integer.parseInt(CodR)), FdatoC);
            Considerando.add(Considers);


            Considerando.add( Chunk.NEWLINE ); 
            Considerando.add( Chunk.NEWLINE ); 
            
            
            Chunk Resue = new Chunk("Resuelvo:", FdatoE);
            Paragraph Resuelvo = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12));            
            
            Resuelvo.add(Resue);
            Resuelvo.add( Chunk.NEWLINE );   
            Resuelvo.add("Autorizar la inclusion en el curso ");
            Resuelvo.add(codcurso);
            Resuelvo.add(",grupo ");
            Resuelvo.add(grupo);
            Resuelvo.add(", impartido en el primer semestre del año 2017, al estudiante "+ nombre + ", carne "+carnet+
                    " y actualizar su nota de aprovacion a fin de que estado de la misma sea aprobado con una nota final de 70.");

            Resuelvo.add( Chunk.NEWLINE );            
            Resuelvo.add( Chunk.NEWLINE );
            
            Chunk Noti = new Chunk("Notifiquese:", FdatoE);
            Paragraph Notifiquese = new Paragraph(""
                    ,FontFactory.getFont(FontFactory.TIMES,12)); 
            Notifiquese.add(Noti);
            Notifiquese.add( Chunk.NEWLINE );            
            Notifiquese.add( Chunk.NEWLINE ); 
            Notifiquese.add("                                                                                      ");
            Notifiquese.add(DirEC);
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Director Escuela Ingenieria en Computacion");
            Notifiquese.add( Chunk.NEWLINE );
            Notifiquese.add("                                                                                      Instituto Tecnologico de Costa Rica");
            
            doc.add(Titulo);
            doc.add(Codigo);
            doc.add(Para);
            doc.add(Cuerpo);
            doc.add(Resultando);
            doc.add(Considerando);
            doc.add(Resuelvo);
            doc.add(Notifiquese);
            doc.close();
            return true;
            
        }
        catch(DocumentException ex)
        {
            System.out.println("Error al crear el pdf");
        } catch (FileNotFoundException ex) {
            Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
        }catch (SQLException ex) {
                Logger.getLogger(PDF.class.getName()).log(Level.SEVERE, null, ex);
            }
        return false;
    }
       
            
 } 
