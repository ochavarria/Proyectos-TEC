using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class ListaPrivada
    {
        public int idListaPrivada { get; set; }
        public int idUsuario { get; set; }

        public ListaPrivada()
        {
 
        }
        public ListaPrivada(int idListaPrivada, int idUsuario)
        {
            this.idListaPrivada = idListaPrivada;
            this.idUsuario = idUsuario;
        }
    }
}