package exaples.jason;

/**
 * Created by Gollo on 23/08/2016.
 */
public class Spotify {
    private String cancion, album ,artist;

    public Spotify(String cancion, String album, String artist) {
        this.cancion = cancion;
        this.album = album;
        this.artist = artist;
    }

    public String getCancion() {
        return cancion;
    }

    public void setCancion(String cancion) {
        this.cancion = cancion;
    }

    public String getAlbum() {
        return album;
    }

    public void setAlbum(String album) {
        this.album = album;
    }

    public String getArtist() {
        return artist;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }
}
