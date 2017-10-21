
package WEBSERVICE;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the cr.fi.bccr.sdde.ws package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _DataSet_QNAME = new QName("http://ws.sdde.bccr.fi.cr", "DataSet");
    private final static QName _String_QNAME = new QName("http://ws.sdde.bccr.fi.cr", "string");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: cr.fi.bccr.sdde.ws
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link ObtenerIndicadoresEconomicosResponse }
     * 
     */
    public ObtenerIndicadoresEconomicosResponse createObtenerIndicadoresEconomicosResponse() {
        return new ObtenerIndicadoresEconomicosResponse();
    }

    /**
     * Create an instance of {@link ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult }
     * 
     */
    public ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult createObtenerIndicadoresEconomicosResponseObtenerIndicadoresEconomicosResult() {
        return new ObtenerIndicadoresEconomicosResponse.ObtenerIndicadoresEconomicosResult();
    }

    /**
     * Create an instance of {@link ObtenerIndicadoresEconomicosXMLResponse }
     * 
     */
    public ObtenerIndicadoresEconomicosXMLResponse createObtenerIndicadoresEconomicosXMLResponse() {
        return new ObtenerIndicadoresEconomicosXMLResponse();
    }

    /**
     * Create an instance of {@link DataSet }
     * 
     */
    public DataSet createDataSet() {
        return new DataSet();
    }

    /**
     * Create an instance of {@link ObtenerIndicadoresEconomicos }
     * 
     */
    public ObtenerIndicadoresEconomicos createObtenerIndicadoresEconomicos() {
        return new ObtenerIndicadoresEconomicos();
    }

    /**
     * Create an instance of {@link ObtenerIndicadoresEconomicosXML }
     * 
     */
    public ObtenerIndicadoresEconomicosXML createObtenerIndicadoresEconomicosXML() {
        return new ObtenerIndicadoresEconomicosXML();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link DataSet }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://ws.sdde.bccr.fi.cr", name = "DataSet")
    public JAXBElement<DataSet> createDataSet(DataSet value) {
        return new JAXBElement<DataSet>(_DataSet_QNAME, DataSet.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link String }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://ws.sdde.bccr.fi.cr", name = "string")
    public JAXBElement<String> createString(String value) {
        return new JAXBElement<String>(_String_QNAME, String.class, null, value);
    }

}
