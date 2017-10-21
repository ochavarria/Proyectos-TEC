package exaples.jason;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class DisplayListView extends AppCompatActivity {
    String json_string;
    JSONObject jsonObject;
    JSONArray jsonArray;
    SpotifyAdapter spotifyAdapter;

    ListView listView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.display_listview_layout);
        listView = (ListView)findViewById(R.id.listview);
        spotifyAdapter = new SpotifyAdapter(this,R.layout.row_layout);
        listView.setAdapter(spotifyAdapter);

        json_string = getIntent().getExtras().getString("json_data");

        try
        {
            jsonObject = new JSONObject(json_string);
            jsonArray = jsonObject.getJSONArray("tracks");

            int count = 0;
            String name, artists,album;
            while(count<jsonArray   .length()){
                JSONObject JO= jsonArray.getJSONObject(count);
                name=JO.getString("name");
                artists= getArtist(JO.getString("artists"));

                album= getAlbum(JO.getString("album"));
                Spotify spotify = new Spotify(name,album,artists);
                spotifyAdapter.add(spotify);

                count++;
            }


        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
    public String getArtist(String Artist)
    {
        json_string = Artist;
        try
        {
            JSONArray jArray = new JSONArray(Artist);
            String artist= jArray.getJSONObject(0).getString("name");
            return artist;
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return null;
    }

    public String getAlbum(String Album)
    {
        json_string = Album;
        try
        {
            jsonObject = new JSONObject(json_string);
            String album= jsonObject.getString("name");
            return album;


        } catch (JSONException e) {
            e.printStackTrace();
        }
        return null;

    }
}
