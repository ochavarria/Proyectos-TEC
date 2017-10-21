package delist2.reque.com.delist2;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.view.View;
import android.widget.TextView;

/**
 * Created by SANCHO on 12/09/2016.
 */
public class MiServicio extends Service implements LocationListener{

    private final Context ctx;
    double latitud;
    double longitud;
    Location location;
    boolean gpsActivo;
    TextView texto;
    LocationManager locationManager;

    public MiServicio() {
        super();
        this.ctx = this.getApplicationContext();
    }
    public MiServicio(Context c){
        super();
        this.ctx= c;
        getLocation();

    }

    public void setView(View v){
        texto = (TextView)v;
        texto.setText("Las coordenadas son: "+latitud+","+longitud);
    }

    public void getLocation(){
        try{
            locationManager = (LocationManager)this.ctx.getSystemService(LOCATION_SERVICE);
            gpsActivo = locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER);


        }catch (Exception e){}
        if(gpsActivo && ContextCompat.checkSelfPermission( this, android.Manifest.permission.ACCESS_FINE_LOCATION ) != PackageManager.PERMISSION_GRANTED &&
                ContextCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED){

            locationManager.requestLocationUpdates(locationManager.GPS_PROVIDER, 1000 * 60, 10, this);
            location = locationManager.getLastKnownLocation(locationManager.GPS_PROVIDER);
            latitud = location.getLatitude();
            longitud = location.getLongitude();


        }

    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onLocationChanged(Location location) {

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
