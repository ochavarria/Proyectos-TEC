using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ServicioWebSoap.Clases
{
    public class Amigo
    {
        public int idAmigo1 { get; set; }
        public int idAmigo2 { get; set; }

        public Amigo()
        {

        }
        public Amigo(int idAmigo1, int idAmigo2)
        {
            this.idAmigo1 = idAmigo1;
            this.idAmigo2 = idAmigo2;
        }

    }
}