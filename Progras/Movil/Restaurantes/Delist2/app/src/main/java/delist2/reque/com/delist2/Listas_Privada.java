package delist2.reque.com.delist2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Listas_Privada extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listas__privada);
        AgregarSitio();
        RemoverSitio();
        ListarSitios();
    }

    protected void AgregarSitio() {
        Button agregar = (Button)(findViewById(R.id.button11));
        agregar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Listas_Privada.this,Agregar_Sitio_Lista.class));

            }
        });
    }

    protected void RemoverSitio() {
        Button remover = (Button)(findViewById(R.id.button12));
        remover.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Listas_Privada.this,Borrar_Sitio.class));

            }
        });
    }

    protected void ListarSitios() {
        Button listar = (Button)(findViewById(R.id.button13));
        listar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Listas_Privada.this,Listar_Sitios.class));

            }
        });
    }

}
