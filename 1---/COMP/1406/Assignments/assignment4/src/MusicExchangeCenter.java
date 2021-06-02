import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.Comparator;
import java.util.Collections;

public class MusicExchangeCenter {
    private ArrayList<User> users;
    private HashMap<String,Float> royalties;
    private ArrayList<Song> downloadedSongs;

    public MusicExchangeCenter(){
        users = new ArrayList<>();
        royalties = new HashMap<>();
        downloadedSongs = new ArrayList<>();
    }

    public ArrayList<Song> getDownloadedSongs(){ return downloadedSongs; }

    public String toString(){
        return String.format("Music Exchange Center (%d users online, %d songs available)",onlineUsers().size(),allAvailableSongs().size());
    }

    ArrayList<User> onlineUsers(){
        ArrayList<User> oUsers = new ArrayList<User>();

        for(User u: users){
            if(u.isOnline()){
                oUsers.add(u);
            }
        }
        return oUsers;
    }

    ArrayList<Song> allAvailableSongs(){
        ArrayList<Song> dlSongs = new ArrayList<Song>();

        for(User u: onlineUsers()){
            for(Song s: u.getSongList()){
//                if(!(dlSongs.contains(s)))
                dlSongs.add(s);
            }
        }
        return dlSongs;
    }

    User userWithName(String s){
        for(User u: users){
            if(u.getUserName()==s){
                return u;
            }
        }
        return null;
    }

    void registerUser(User x){
        if(userWithName(x.getUserName())==null){
            users.add(x);
        }
    }

    ArrayList<Song> availableSongsByArtist(String artist){
        ArrayList<Song> songsBy = new ArrayList<Song>();
        for(Song s: allAvailableSongs()){
            if(s.getArtist().equals(artist)){
                songsBy.add(s);
            }
        }
        return songsBy;
    }

    Song getSong(String title, String ownerName){
        User u = userWithName(ownerName);
        if(u.isOnline()) {
            Song s = u.songWithTitle(title);
            if(s!=null){
                String artist = s.getArtist();
                if(royalties.containsKey(artist)){
                    float upRoyal = royalties.get(artist)+0.25f;
                    royalties.put(artist,upRoyal);
                } else{
                    royalties.put(artist,0.25f);
                }
                downloadedSongs.add(s);
                return s;
            }
        }
        return null;
    }

    void displayRoyalties(){
        System.out.println(String.format("%-8s%-10s","Amount","Artist"));
        System.out.println("-------------------");
        for(String artist: royalties.keySet()){
            System.out.println(String.format("$%-7.2f%-10s",royalties.get(artist),artist));
        }
    }

    TreeSet<Song> uniqueDownloads(){
        TreeSet<Song> uSongs = new TreeSet<>();
        for(Song s: downloadedSongs){
            uSongs.add(s);
        }
        return uSongs;
    }

    ArrayList<Pair<Integer,Song>> songsByPopularity(){
        ArrayList<Song> dSongs = downloadedSongs;
        ArrayList<Pair<Integer,Song>> popSongs = new ArrayList<>();
        int count;

        for(Song s: this.uniqueDownloads()) {
            count = 0;
            while(dSongs.remove(s)){
                count++;
            }
            popSongs.add(new Pair(count,s));
        }

        //Sorts list of pairs
        Collections.sort(popSongs, new Comparator<Pair<Integer, Song>>() {
            public int compare(Pair<Integer, Song> p1, Pair<Integer, Song> p2) {
                if(p1.getKey()>p2.getKey()){
                    return -1;
                } else if(p1.getKey()==p2.getKey()){
                    return 0;
                } else{
                    return 1;
                }
            }
        });
        return popSongs;
    }
}
