using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class ListaCompartida
    {
        public int Id { get; set; }
        public int idCreador { get; set; }
        public String Nombre { get; set; }
        
    public ListaCompartida()
        {
            this.idCreador = 0;
            this.Nombre = "";
        }
    public ListaCompartida(int Id,int idCreador, string Nombre)
    {
        this.Id = Id;
        this.idCreador = idCreador;
        this.Nombre = Nombre;
    }
    }
}