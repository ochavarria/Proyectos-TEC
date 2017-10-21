using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class AmigosListaCompartida
    {
        public int id { get; set; }
        public int idListaCompartida { get; set; }
        public int idAmigo1 { get; set; }
        public int idAmigo2 { get; set; }

        public AmigosListaCompartida()
        {


        }
        public AmigosListaCompartida(int id, int idListaCompartida, int idAmigo1, int idAmigo2)
        {
            this.id = id;
            this.idListaCompartida = idListaCompartida;
            this.idAmigo1 = idAmigo1;
            this.idAmigo2 = idAmigo2;

        }
        
    }
}