
package WEBSERVICE;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAnyElement;
import javax.xml.bind.annotation.XmlElement;
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
 *         &lt;element name="ObtenerIndicadoresEconomicosResult" minOccurs="0">
 *           &lt;complexType>
 *             &lt;complexContent>
 *               &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *                 &lt;sequence>
 *                   &lt;any/>
 *                 &lt;/sequence>
 *               &lt;/restriction>
 *             &lt;/complexContent>
 *           &lt;/complexType>
 *         &lt;/element>
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
    "obtenerIndicadoresEconomicosResult"
})
@XmlRootElement(name = "ObtenerIndicadoresEconomicosResponse")
public class ObtenerIndicadoresEconomicosResponse {

    @XmlElement(name = "ObtenerIndicadoresEconomicosResult")
    protected ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult obtenerIndicadoresEconomicosResult;

    /**
     * Obtiene el valor de la propiedad obtenerIndicadoresEconomicosResult.
     * 
     * @return
     *     possible object is
     *     {@link ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult }
     *     
     */
    public ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult getObtenerIndicadoresEconomicosResult() {
        return obtenerIndicadoresEconomicosResult;
    }

    /**
     * Define el valor de la propiedad obtenerIndicadoresEconomicosResult.
     * 
     * @param value
     *     allowed object is
     *     {@link ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult }
     *     
     */
    public void setObtenerIndicadoresEconomicosResult(ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult value) {
        this.obtenerIndicadoresEconomicosResult = value;
    }


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
     *         &lt;any/>
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
        "any"
    })
    public static class ObtenerIndicadoresEconomicosResult {

        @XmlAnyElement(lax = true)
        protected Object any;

        /**
         * Obtiene el valor de la propiedad any.
         * 
         * @return
         *     possible object is
         *     {@link Object }
         *     
         */
        public Object getAny() {
            return any;
        }

        /**
         * Define el valor de la propiedad any.
         * 
         * @param value
         *     allowed object is
         *     {@link Object }
         *     
         */
        public void setAny(Object value) {
            this.any = value;
        }

    }

}
