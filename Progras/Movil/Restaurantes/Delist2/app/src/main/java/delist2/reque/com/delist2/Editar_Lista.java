package delist2.reque.com.delist2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Editar_Lista extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_editar__lista);
        AbrirLista();
    }
    protected void AbrirLista() {
        Button abrir_lista = (Button)(findViewById(R.id.button2));
        abrir_lista.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(Editar_Lista.this,Listas_Privada.class));

            }
        });
    }

}
