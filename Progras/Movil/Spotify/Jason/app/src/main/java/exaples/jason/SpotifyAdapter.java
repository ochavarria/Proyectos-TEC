package exaples.jason;

import android.content.Context;
import android.support.v4.view.LayoutInflaterFactory;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Gollo on 23/08/2016.
 */
public class SpotifyAdapter extends ArrayAdapter {

    List list = new ArrayList();

    public SpotifyAdapter(Context context, int resource) {
        super(context, resource);
    }

    @Override
    public void add(Object object) {
        super.add(object);
        list.add(object);
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public Object getItem(int position) {
        return list.get(position);

    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        View row;
        row = convertView;
        SpotifyHolder spotifyHolder;

        if(row==null)
        {
            LayoutInflater layoutInflater = (LayoutInflater) this.getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            row = layoutInflater.inflate(R.layout.row_layout,parent,false);
            spotifyHolder = new SpotifyHolder();
            spotifyHolder.tx_name= (TextView) row.findViewById(R.id.tx_Cancion);
            spotifyHolder.tx_album= (TextView) row.findViewById(R.id.tx_album);
            spotifyHolder.tx_artist= (TextView) row.findViewById(R.id.tx_artist);
            row.setTag(spotifyHolder);

        }
        else{
            spotifyHolder = (SpotifyHolder) row.getTag();
        }
        Spotify spotify = (Spotify) this.getItem(position);
        spotifyHolder.tx_name.setText(spotify.getCancion());
        spotifyHolder.tx_album.setText(spotify.getAlbum());
        spotifyHolder.tx_artist.setText(spotify.getArtist());


        return row;
    }
    static class SpotifyHolder{
        TextView tx_name, tx_album,tx_artist;
    }
}
