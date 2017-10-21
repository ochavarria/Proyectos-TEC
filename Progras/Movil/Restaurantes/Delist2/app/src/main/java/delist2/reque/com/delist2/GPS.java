package delist2.reque.com.delist2;



import android.content.Context;
import android.content.pm.PackageManager;
import android.location.Address;
import android.location.Criteria;
import android.location.Geocoder;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

public class GPS extends AppCompatActivity implements LocationListener {



    private Switch MySwitch;
    private EditText editLatitud;
    private EditText editLongitud;
    private EditText editDireccion;
    private TextView txtGPS;
    public LocationManager handle;
    private String provider;
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gps);
        MySwitch  =  (Switch) findViewById(R.id.switchUbicacion);
        editLatitud = (EditText) findViewById(R.id.Latitud_texto);
        editLongitud = (EditText) findViewById(R.id.Longitud_texto);
        editDireccion = (EditText) findViewById(R.id.Direccion_texto);
        txtGPS = (TextView) findViewById(R.id.txtGPS);
        IniciarServicio();
        MySwitch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                setEstadoSwitch(isChecked);

            }
        });
    }

    void setEstadoSwitch (boolean x){
        if(x==true){
            IniciarServicio();
            muestraPosicionActual();
        }
        else{
            pararServicio();
        }
    }

    public void IniciarServicio() {
        Toast.makeText(this,"Busqueda activada",Toast.LENGTH_SHORT).show();
        handle = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
        Criteria c = new Criteria();
        c.setAccuracy(Criteria.ACCURACY_FINE);
        provider = handle.getBestProvider(c,true);
        txtGPS.setText("Provedor: "+provider);
        if ( ContextCompat.checkSelfPermission( this, android.Manifest.permission.ACCESS_COARSE_LOCATION ) != PackageManager.PERMISSION_GRANTED ) {
        }
        handle.requestLocationUpdates(provider,10000,1, (LocationListener) this);
    }

    public void muestraPosicionActual(){
        if ( ContextCompat.checkSelfPermission( this, android.Manifest.permission.ACCESS_COARSE_LOCATION ) != PackageManager.PERMISSION_GRANTED ) {
        }
        Location location = handle.getLastKnownLocation(provider);
        if(location==null){
            editLatitud.setText("Desconocida");
            editLongitud.setText("Desconocida");
            editDireccion.setText("Desconocida");
        }
        else{
            editLatitud.setText(String.valueOf(location.getLatitude()));
            editLongitud.setText(String.valueOf(location.getLongitude()));


        }
        setDireccion(location);

    }
    public void setDireccion(Location loc){
        if(loc != null){
            if(loc.getLatitude()!=0.0 && loc.getLongitude()!=0.0){
                try{
                    Geocoder geocoder = new Geocoder(this, Locale.getDefault());
                    List<Address> list = geocoder.getFromLocation(loc.getLatitude(),loc.getLongitude(),1);
                    if(!list.isEmpty()){
                        Address direccion = list.get(0);
                        editDireccion.setText(direccion.getAddressLine(0));

                    }
                }catch (IOException e){
                    editDireccion.setText(""+e);
                }
            }
        }

    }

    public void pararServicio(){
        if ( ContextCompat.checkSelfPermission( this, android.Manifest.permission.ACCESS_COARSE_LOCATION ) != PackageManager.PERMISSION_GRANTED ) {
        }
        handle.removeUpdates(this);
        editDireccion.setText(null);
        editLongitud.setText(null);
        editLatitud.setText(null);
        Toast.makeText(this,"Busqueda desactivada",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onLocationChanged(Location location) {
        if(location==null){
            editLatitud.setText("Desconocida");
            editLongitud.setText("Desconocida");
            editDireccion.setText("Desconocida");
        }
        else{
            editLatitud.setText(String.valueOf(location.getLatitude()));
            editLongitud.setText(String.valueOf(location.getLongitude()));


        }
        setDireccion(location);

    }

    @Override
    public void onStatusChanged(String s, int i, Bundle bundle) {

    }

    @Override
    public void onProviderEnabled(String s) {

    }

    @Override
    public void onProviderDisabled(String s) {

    }
}
