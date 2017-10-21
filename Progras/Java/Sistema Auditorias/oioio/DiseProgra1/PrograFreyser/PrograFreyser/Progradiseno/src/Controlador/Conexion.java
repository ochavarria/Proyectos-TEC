
package Controlador;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class Conexion {
    public Connection conectar() throws ClassNotFoundException, SQLException{
        Connection con=null;
       try{
            Class.forName(("com.microsoft.sqlserver.jdbc.SQLServerDriver"));
            con = DriverManager.getConnection("jdbc:sqlserver://DESKTOP-2K3LH4A:1433;databaseName=DisenoP1","tivin","123");
        }catch(ClassNotFoundException | SQLException ex){
            System.out.println("Error"+ ex.getMessage());
        }
        return con;
    }
}
