using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap
{
    public class Lugar
    {
        public int Id { get; set; }
        public string Nombre { get; set; }
        public string Categoria { get; set; }
        public double Longitud { get; set; }
        public double Latitud { get; set; }
        public string Descripcion { get; set; }

        public Lugar()
        {
            this.Id = 0;
            this.Nombre = "";
        }

        public Lugar(int Id,string nombre,string Categoria,double Longitud,double Latitud,string Descripcion)
        {
            this.Id = Id;
            this.Nombre = nombre;
            this.Categoria = Categoria;
            this.Longitud=Longitud;
            this.Latitud=Latitud;
            this.Descripcion=Descripcion;
        }
    
    }
}