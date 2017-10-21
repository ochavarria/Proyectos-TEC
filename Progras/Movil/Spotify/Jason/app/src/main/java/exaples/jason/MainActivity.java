package exaples.jason;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class MainActivity extends AppCompatActivity {



    String json_string;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void getJSON(View view)
    {
        new BackgroundTask().execute();

    }
    class BackgroundTask extends AsyncTask<Void,Void,String>
    {
        String json_url;
        String JSON_STRING;
        @Override
        protected void onPreExecute() {

            json_url="https://api.spotify.com/v1/tracks/?ids=46GGxd8TVRt6FjUBfCavVT,3E14pb0zKtI9ugTGzWOOjU,7yq4Qj7cqayVTp3FF9CWbm,2Z8WuEywRWYTKe1NybPQEW,1wAXODAAL6hY64ZdhrnjBO,3xsrky7ED45oiA0rSN1RjM,1mqbTByfUxLPeqN1YEw08a,27SdWb2rFzO6GWiYDBTD9j,3zkWCteF82vJwv0hRLba76,1daWG6AYC20lWevL2r1Rm2,5MqPDDzP4fOjnHpVsBqcTh,6QLU1GKy2Zh2mOh2uoJ0TV,29U1azNyQN2vSqIquF9srD,35WhawODuOs0kaHxwmPA9D,06OYfrtoQwYk2Ju70MiBgS,4y3lhJ3PtvDuwFNX5zhFQ4,0aGSUNleFqs5HNEJcwqvXJ,6LLQY25x8tSelUTdpnL4tO,3V5qEaGZr52PrvHQ1n9JLI,7y2DeUcCrNhGjPUlHpSFsj";
        }

        @Override
        protected String doInBackground(Void... voids) {
            try {
                URL url = new URL(json_url);
                HttpURLConnection httpURLConnection = (HttpURLConnection)url.openConnection();
                httpURLConnection.connect();

                InputStream inputStream = httpURLConnection.getInputStream();
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));

                StringBuilder stringBuilder = new StringBuilder();
                while((JSON_STRING=bufferedReader.readLine())!=null)
                {
                    stringBuilder.append(JSON_STRING+"\n");

                }
                bufferedReader.close();
                inputStream.close();
                httpURLConnection.disconnect();
                return stringBuilder.toString().trim();


            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }

        @Override
        protected void onPostExecute(String result) {
            TextView textView = (TextView) findViewById(R.id.textview);
            textView.setText(result);
            json_string= result;
        }
    }
    public void parseJSON(View view)
    {

        if(json_string==null)
        {
            Toast.makeText(getApplicationContext(),"First get the Json",Toast.LENGTH_LONG).show();
        }
        else
        {
            Intent intent = new Intent(this,DisplayListView.class);
            intent.putExtra("json_data",json_string);
            startActivity(intent);
        }
    }
}
