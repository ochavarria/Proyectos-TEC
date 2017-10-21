package delist2.reque.com.delist2;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.FacebookSdk;
import com.facebook.login.LoginResult;
import com.facebook.login.widget.LoginButton;
import org.ksoap2.*;
import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapPrimitive;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;

import java.net.URL;


public class MainActivity extends AppCompatActivity {
    CallbackManager callbackManager;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        FacebookSdk.sdkInitialize(getApplicationContext());
        setContentView(R.layout.activity_main);
        final TextView result = (TextView)findViewById(R.id.resultado);
        callbackManager = CallbackManager.Factory.create();
        LoginButton loginButton = (LoginButton)findViewById(R.id.login_button);
        loginButton.registerCallback(callbackManager, new FacebookCallback <LoginResult>() {
            @Override
            public void onSuccess(LoginResult loginResult) {
               result.setText("User ID: "
                + loginResult.getAccessToken().getUserId()
                        + "\n" +
                        "Auth Token: "
                        + loginResult.getAccessToken().getApplicationId());
                        startActivity(new Intent(MainActivity.this,Principal.class));
                       //parseJSON();

            }

            @Override
            public void onCancel() {
                result.setText("Cancelado");

            }

            @Override
            public void onError(FacebookException error) {
                result.setText("Error");
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        callbackManager.onActivityResult(requestCode, resultCode, data);
    }
    //Tarea Asíncrona para llamar al WS de consulta en segundo plano
    private class TareaWSConsulta extends AsyncTask<String,Integer,Boolean> {
        final TextView resultado = (TextView)findViewById(R.id.resultado);

        private Cliente[] listaClientes;

        protected Boolean doInBackground(String... params) {

            boolean resul = true;

            final String NAMESPACE = "http://sgoliver.net/";
            final String URL="http://127.0.0.1:54143/ServicioUsuarios.asmx";
            final String METHOD_NAME = "ListadoUsuarios";
            final String SOAP_ACTION = "http://sgoliver.net/ListadoUsuarios";

            SoapObject request = new SoapObject(NAMESPACE, METHOD_NAME);

            SoapSerializationEnvelope envelope =
                    new SoapSerializationEnvelope(SoapEnvelope.VER11);
            envelope.dotNet = true;

            envelope.setOutputSoapObject(request);

            HttpTransportSE transporte = new HttpTransportSE(URL);

            try
            {
                transporte.call(SOAP_ACTION, envelope);

                SoapObject resSoap =(SoapObject)envelope.getResponse();

                listaClientes = new Cliente[resSoap.getPropertyCount()];

                for (int i = 0; i < listaClientes.length; i++)
                {
                    SoapObject ic = (SoapObject)resSoap.getProperty(i);

                    Cliente cli = new Cliente();
                    cli.id = Integer.parseInt(ic.getProperty(0).toString());
                    cli.nombre = ic.getProperty(1).toString();
                    listaClientes[i] = cli;
                }
            }
            catch (Exception e)
            {
                resul = false;
            }

            return resul;
        }

        protected void onPostExecute(Boolean result) {

            if (result)
            {
                //Rellenamos la lista con los nombres de los clientes
                final String[] datos = new String[listaClientes.length];
                String Prueba= "";
                for(int i=0; i<listaClientes.length; i++) {

                    Prueba += listaClientes[i].nombre;
                    datos[i] = listaClientes[i].nombre;
                }

                ArrayAdapter<String> adaptador =
                        new ArrayAdapter<String>(MainActivity.this,
                                android.R.layout.simple_list_item_1, datos);

                //lstClientes.setAdapter(adaptador);

                resultado.setText("Lo logre");
            }
            else
            {
                resultado.setText("Entre pero no funciono");
            }
        }
    }

    public void parseJSON()
    {
        {
            String NAMESPACE = "http://sgoliver.net/";
            String URL="http://10.0.2.2:54143/ServicioUsuarios.asmx";
            String METHOD_NAME = "NuevoUsuario";
            String SOAP_ACTION = "http://sgoliver.net/NuevoUsuario";

            SoapObject request = new SoapObject(NAMESPACE, METHOD_NAME);

            request.addProperty("nombre", "juan");
            request.addProperty("telefono", 12);

            SoapSerializationEnvelope envelope =
                    new SoapSerializationEnvelope(SoapEnvelope.VER11);

            envelope.dotNet = true;

            envelope.setOutputSoapObject(request);

            HttpTransportSE transporte = new HttpTransportSE(URL);

            try
            {
                transporte.call(SOAP_ACTION, envelope);

                SoapPrimitive resultado_xml =(SoapPrimitive)envelope.getResponse();
                String res = resultado_xml.toString();

                if(res.equals("1")) {
                    TextView rest = (TextView) findViewById(R.id.resultado);
                    rest.setText("Excelente");
                }
            }
            catch (Exception e)
            {
                TextView rest = (TextView) findViewById(R.id.resultado);
                rest.setText("Error");
            }

        }
    }



}

