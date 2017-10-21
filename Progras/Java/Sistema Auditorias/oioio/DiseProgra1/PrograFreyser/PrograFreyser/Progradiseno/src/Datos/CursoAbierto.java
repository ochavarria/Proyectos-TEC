/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Datos;


import java.sql.Time;

/**
 *
 * @author Usuario
 */
public class CursoAbierto {
    private int grupo;
    private String Aula;
    private Time Inicio;
    private Time Fin;
    private String Dias;
    private Curso curso;
    private Docente docente;

    public CursoAbierto(int grupo, String Aula, Time Inicio, Time Fin, String Dias, Curso curso, Docente docente) {
        this.grupo = grupo;
        this.Aula = Aula;
        this.Inicio = Inicio;
        this.Fin = Fin;
        this.Dias = Dias;
        this.curso = curso;
        this.docente = docente;
    }

    public int getGrupo() {
        return grupo;
    }

    public void setGrupo(int grupo) {
        this.grupo = grupo;
    }

    public String getAula() {
        return Aula;
    }

    public void setAula(String Aula) {
        this.Aula = Aula;
    }

    public Time getInicio() {
        return Inicio;
    }

    public void setInicio(Time Inicio) {
        this.Inicio = Inicio;
    }

    public Time getFin() {
        return Fin;
    }

    public void setFin(Time Fin) {
        this.Fin = Fin;
    }

    public String getDias() {
        return Dias;
    }

    public void setDias(String Dias) {
        this.Dias = Dias;
    }

    public Curso getCurso() {
        return curso;
    }

    public void setCurso(Curso curso) {
        this.curso = curso;
    }

    public Docente getDocente() {
        return docente;
    }

    public void setDocente(Docente docente) {
        this.docente = docente;
    }
    
}
