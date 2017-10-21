using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap
{
    public class Usuario
    {
        public int Id { get; set; }
        public string Nombre { get; set; }

        public Usuario()
        {
            this.Id = 0;
            this.Nombre = "";
        }

        public Usuario(int id, string nombre)
        {
            this.Id = id;
            this.Nombre = nombre;
        }
    }
}