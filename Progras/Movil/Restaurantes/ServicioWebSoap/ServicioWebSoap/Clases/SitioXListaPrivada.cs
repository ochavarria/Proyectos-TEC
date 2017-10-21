using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class SitioXListaPrivada
    {
        public int idListaPrivada{ get; set; }
        public int idLugar { get; set; }

        public SitioXListaPrivada()
        {
 
        }
        public SitioXListaPrivada(int idListaPrivada,int idLugar )
        {
            this.idListaPrivada=idListaPrivada;
            this.idLugar = idLugar;
        }

    }
}