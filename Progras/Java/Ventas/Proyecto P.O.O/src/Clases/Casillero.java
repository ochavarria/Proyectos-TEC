/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Clases;

/**
 *
 * @author Chavas
 */
public class Casillero {
    private String Id;
    private String Estado;

    public Casillero(String Id, String Estado) {
        this.Id = Id;
        this.Estado = Estado;
    }

    public String getId() {
        return Id;
    }

    public String getEstado() {
        return Estado;
    }

    public void setId(String Id) {
        this.Id = Id;
    }

    public void setEstado(String Estado) {
        this.Estado = Estado;
    }

    @Override
    public String toString() {
        return "Casillero{" + "Id=" + Id + ", Estado=" + Estado + '}';
    }

}
