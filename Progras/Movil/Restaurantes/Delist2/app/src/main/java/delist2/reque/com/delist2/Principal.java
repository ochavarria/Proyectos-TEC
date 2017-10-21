package delist2.reque.com.delist2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Principal extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_principal);
        registrarButton();
        buscarButton();
        ListaPersonal();
        ListaCompartida();
        agregarAmigos();

    }

    protected void registrarButton() {
        Button registrar = (Button)(findViewById(R.id.button_registrar));
        registrar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Principal.this,Registrar_Sitio.class));
                //startActivity(new Intent(Principal.this,GPS.class));

            }
        });
    }

    protected void buscarButton() {
        Button buscar = (Button)(findViewById(R.id.button_buscar));
        buscar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Principal.this,Buscar_Sitio.class));

            }
        });
    }

    protected void ListaPersonal() {
        Button lista_personal = (Button)(findViewById(R.id.button_lp));
        lista_personal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Principal.this,Listas_Privada.class));

            }
        });
    }

    protected void ListaCompartida() {
        Button lista_compartida = (Button)(findViewById(R.id.button_LC));
        lista_compartida.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Principal.this,Lista_Compartidas.class));

            }
        });
    }

    protected void agregarAmigos() {
        Button agregar_amigos = (Button)(findViewById(R.id.button_agregar));
        agregar_amigos.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Principal.this,Agregar_Amigos.class));

            }
        });
    }
}
