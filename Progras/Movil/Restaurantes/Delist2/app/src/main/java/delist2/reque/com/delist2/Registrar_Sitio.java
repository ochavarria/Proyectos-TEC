package delist2.reque.com.delist2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Registrar_Sitio extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registrar__sitio);
        GPSButton();
    }
    protected void GPSButton() {
        Button registrarGPS = (Button)(findViewById(R.id.button5));
        registrarGPS.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Registrar_Sitio.this,GPS.class));
                //startActivity(new Intent(Principal.this,GPS.class));

            }
        });
    }
}
