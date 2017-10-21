using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class SitioXListaCompartida
    {
        public int idListaCompartida { get; set; }
        public int idLugar { get; set; }


        public SitioXListaCompartida()
        {
 
        }
        public SitioXListaCompartida(int idListaCompartida ,int idLugar )
        {
             this.idListaCompartida=idListaCompartida;
             this.idLugar = idLugar;
        }
    }
}