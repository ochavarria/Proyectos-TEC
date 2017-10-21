
package WEBSERVICE;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Clase Java para anonymous complex type.
 * 
 * <p>El siguiente fragmento de esquema especifica el contenido que se espera que haya en esta clase.
 * 
 * <pre>
 * &lt;complexType>
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="tcIndicador" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="tcFechaInicio" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="tcFechaFinal" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="tcNombre" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="tnSubNiveles" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "", propOrder = {
    "tcIndicador",
    "tcFechaInicio",
    "tcFechaFinal",
    "tcNombre",
    "tnSubNiveles"
})
@XmlRootElement(name = "ObtenerIndicadoresEconomicosXML")
public class ObtenerIndicadoresEconomicosXML {

    protected String tcIndicador;
    protected String tcFechaInicio;
    protected String tcFechaFinal;
    protected String tcNombre;
    protected String tnSubNiveles;

    /**
     * Obtiene el valor de la propiedad tcIndicador.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTcIndicador() {
        return tcIndicador;
    }

    /**
     * Define el valor de la propiedad tcIndicador.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTcIndicador(String value) {
        this.tcIndicador = value;
    }

    /**
     * Obtiene el valor de la propiedad tcFechaInicio.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTcFechaInicio() {
        return tcFechaInicio;
    }

    /**
     * Define el valor de la propiedad tcFechaInicio.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTcFechaInicio(String value) {
        this.tcFechaInicio = value;
    }

    /**
     * Obtiene el valor de la propiedad tcFechaFinal.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTcFechaFinal() {
        return tcFechaFinal;
    }

    /**
     * Define el valor de la propiedad tcFechaFinal.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTcFechaFinal(String value) {
        this.tcFechaFinal = value;
    }

    /**
     * Obtiene el valor de la propiedad tcNombre.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTcNombre() {
        return tcNombre;
    }

    /**
     * Define el valor de la propiedad tcNombre.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTcNombre(String value) {
        this.tcNombre = value;
    }

    /**
     * Obtiene el valor de la propiedad tnSubNiveles.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTnSubNiveles() {
        return tnSubNiveles;
    }

    /**
     * Define el valor de la propiedad tnSubNiveles.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTnSubNiveles(String value) {
        this.tnSubNiveles = value;
    }

}
