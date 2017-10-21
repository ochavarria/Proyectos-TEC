using ServicioWebSoap.Clases;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace ServicioWebSoap
{
    /// <summary>
    /// Summary description for ServicioUsuarios
    /// </summary>
    [WebService(Namespace = "http://sgoliver.net/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class ServicioUsuarios : System.Web.Services.WebService
    {
        [WebMethod]
        public ListaCompartida[] ListadoListas()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT idListaCompartida, idCreador, nombre FROM ListaCompartida";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<ListaCompartida> lista = new List<ListaCompartida>();

            while (reader.Read())
            {
                lista.Add(
                    new ListaCompartida(reader.GetInt32(0),
                                reader.GetInt32(1),
                                reader.GetString(2)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public Amigo[] ListadoAmigo()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT * FROM Amigos";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<Amigo> lista = new List<Amigo>();

            while (reader.Read())
            {
                lista.Add(
                    new Amigo(reader.GetInt32(0),
                                reader.GetInt32(1)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public AmigosListaCompartida[] ListarAmigosListaCompartida()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT * FROM AmigosListaCompartida ";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<AmigosListaCompartida> lista = new List<AmigosListaCompartida>();

            while (reader.Read())
            {
                lista.Add(
                    new AmigosListaCompartida(reader.GetInt32(0),
                                reader.GetInt32(1),
                                reader.GetInt32(2),
                                reader.GetInt32(3)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public ListaPrivada[] ListarListaPrivada()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT * FROM ListaPrivada ";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<ListaPrivada> lista = new List<ListaPrivada>();

            while (reader.Read())
            {
                lista.Add(
                    new ListaPrivada(reader.GetInt32(0),
                                reader.GetInt32(1)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public SitioXListaPrivada[] ListarSitioXListaPrivada()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT * FROM SitiosXListaPrivada ";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<SitioXListaPrivada> lista = new List<SitioXListaPrivada>();

            while (reader.Read())
            {
                lista.Add(
                    new SitioXListaPrivada(reader.GetInt32(0),
                                reader.GetInt32(1)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public int InsertarUsuario(int Id,string nombre)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");
           
            con.Open();

            string sql = "INSERT INTO Usuarios (idUsuario,Nombre) VALUES (@id,@nombre)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@id", System.Data.SqlDbType.Int).Value = Id;
            cmd.Parameters.Add("@nombre", System.Data.SqlDbType.NVarChar).Value = nombre;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }

        [WebMethod]

        public int InsertarAmigos(int id1, string id2)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO Amigos (idAmigo1,idAmigo2) VALUES (@id1,@id2)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@id1", System.Data.SqlDbType.Int).Value = id1;
            cmd.Parameters.Add("@id2", System.Data.SqlDbType.Int).Value = id2;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }

        [WebMethod]
        public int InsertarAmigosListaCompartida(int idListaCompartida, int id1, int id2)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO AmigosListaCompartida (idListaCompartida,idAmigo1,idAmigo2) VALUES (@idListaC,@id1,@id2)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@idListaC", System.Data.SqlDbType.Int).Value = idListaCompartida;
            cmd.Parameters.Add("@id1", System.Data.SqlDbType.Int).Value = id1;
            cmd.Parameters.Add("@id2", System.Data.SqlDbType.Int).Value = id2;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }

        [WebMethod]
        public int InsertarSitioXListaCompartida(int idListaC, int idLugar)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO SitiosXListaCompartida (idListaCompartida,idLugar) VALUES (@idC,@idL)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@idC", System.Data.SqlDbType.Int).Value = idListaC;
            cmd.Parameters.Add("@idL", System.Data.SqlDbType.Int).Value = idLugar;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }
            
        [WebMethod]
        public int InsertarSitioXListaPrivada(int IdP, int idL)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO SitiosXListaPrivada (idListaPrivada,idLugar) VALUES (@idP,@idL)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@idP", System.Data.SqlDbType.Int).Value = IdP;
            cmd.Parameters.Add("@idL", System.Data.SqlDbType.Int).Value = idL;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }





        [WebMethod]
        public Usuario[] ListadoUsuarios()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT * FROM Usuarios";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<Usuario> lista = new List<Usuario>();

            while (reader.Read())
            {
                lista.Add(
                    new Usuario(reader.GetInt32(0),
                                reader.GetString(1)));
            }

            con.Close();

            return lista.ToArray();
        }
        
        [WebMethod]
        public int InsertarLugar(string nombre, string Categoria, double Longitud, double Latitud, string Descripcion)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO Lugares (Nombre,Categoria,Longitud,Latitud,Descripcion) VALUES (@Nombre,@Categoria,@Longitud,@Latitud,@Descripcion)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@nombre", System.Data.SqlDbType.NVarChar).Value = nombre;
            cmd.Parameters.Add("@Categoria", System.Data.SqlDbType.NVarChar).Value = Categoria;
            cmd.Parameters.Add("@Longitud", System.Data.SqlDbType.Float).Value = Longitud;
            cmd.Parameters.Add("@Latitud", System.Data.SqlDbType.Float).Value = Latitud;
            cmd.Parameters.Add("@Descripcion", System.Data.SqlDbType.NVarChar).Value = Descripcion;



            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }

        [WebMethod]
        public Lugar[] ListadoLugares()
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "SELECT idLugar, Nombre,Categoria,Longitud,Latitud,Descripcion FROM Lugares";

            SqlCommand cmd = new SqlCommand(sql, con);

            SqlDataReader reader = cmd.ExecuteReader();

            List<Lugar> lista = new List<Lugar>();

            while (reader.Read())
            {
                lista.Add(
                    new Lugar(reader.GetInt32(0),
                                reader.GetString(1),
                                reader.GetString(2),
                                reader.GetDouble(3),
                                reader.GetDouble(4),
                                reader.GetString(5)));
            }

            con.Close();

            return lista.ToArray();
        }

        [WebMethod]
        public int InsertarListaCompartida(int Id,string nombre)
        {
            SqlConnection con =
                new SqlConnection(
                    @"Server=TOSHIBA; Database=Delist; User Id =sa;Password=123");

            con.Open();

            string sql = "INSERT INTO ListaCompartida (idCreador,nombre) VALUES (@id,@nombre)";

            SqlCommand cmd = new SqlCommand(sql, con);

            cmd.Parameters.Add("@id", System.Data.SqlDbType.Int).Value = Id;
            cmd.Parameters.Add("@nombre", System.Data.SqlDbType.NVarChar).Value = nombre;

            int res = cmd.ExecuteNonQuery();

            con.Close();

            return res;
        }



    }
}
