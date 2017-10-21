/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WEBSERVICE;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author Elias O
 */
public class Webservice {

    public Webservice() {
    }
    
    
    static  String obtenerIndicadoresEconomicosXML(java.lang.String tcIndicador, java.lang.String tcFechaInicio, java.lang.String tcFechaFinal, java.lang.String tcNombre, java.lang.String tnSubNiveles) {
        WEBSERVICE.WsIndicadoresEconomicos service = new WEBSERVICE.WsIndicadoresEconomicos();
        WEBSERVICE.WsIndicadoresEconomicosSoap port = service.getWsIndicadoresEconomicosSoap();
        return port.obtenerIndicadoresEconomicosXML(tcIndicador, tcFechaInicio, tcFechaFinal, tcNombre, tnSubNiveles);
    }

    public  static String getFechaActual(Date ahora) {
        SimpleDateFormat formateador = new SimpleDateFormat("dd/MM/yyyy");
        return formateador.format(ahora);
    }
    
    public static String ValorDolar(){
        Date now = new Date(System.currentTimeMillis());
        String s = getFechaActual(now); 
        String pitillo =(Webservice.obtenerIndicadoresEconomicosXML("318", s, s, "Carlillos", "N"));
        String pitillo2=pitillo.substring(196,202);
        return pitillo2;
    
    }
}
    
