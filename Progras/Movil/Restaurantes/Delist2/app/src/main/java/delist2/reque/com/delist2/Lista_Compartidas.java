package delist2.reque.com.delist2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Lista_Compartidas extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lista__compartidas);
        CrearLista();
        BorrarLista();
        EditarLista();
    }

    protected void CrearLista() {
        Button agregarlc = (Button)(findViewById(R.id.button8));
        agregarlc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Lista_Compartidas.this,Agregar_nueva_listaCompartida.class));

            }
        });
    }

    protected void BorrarLista() {
        Button borrarlc = (Button)(findViewById(R.id.button9));
        borrarlc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Lista_Compartidas.this,Borrar_Lista.class));

            }
        });
    }

    protected void EditarLista() {
        Button editarlc = (Button)(findViewById(R.id.button10));
        editarlc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Lista_Compartidas.this,Editar_Lista.class));

            }
        });
    }

}
