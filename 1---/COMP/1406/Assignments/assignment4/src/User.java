import java.util.ArrayList;

public class User {
  private String     userName;
  private boolean    online;
  private ArrayList<Song>  songList;
  
  public User()  { this(""); }
  
  public User(String u)  {
    userName = u;
    songList = new ArrayList<>();
    online = false;
  }
  
  public String getUserName() { return userName; }
  public ArrayList<Song> getSongList() { return songList; }
  public boolean isOnline() { return online; }
  
  public String toString()  {
    String s = "" + userName + ": "+songList.size()+" songs (";
    if (!online) s += "not ";
    return s + "online)";
  }

  void addSong(Song s){
    songList.add(s);
    s.setOwner(this);
  }

 Integer totalSongTime(){
    int totalTime = 0;
    for(Song s: songList){
      totalTime+= s.getDuration();
    }
    return totalTime;
 }

 ArrayList<String> requestCompleteSonglist(MusicExchangeCenter m){
      ArrayList<String> compSongList = new ArrayList<>();
      compSongList.add(String.format("%-32s%-18s%-10s%-20s","TITLE","ARTIST","TIME","OWNER"));
      compSongList.add("");

      int count = 0;
      for(Song s: m.allAvailableSongs()){
          count++;
          compSongList.add(String.format("%02d. %-28s%-18s%-10s%-20s",count,s.getTitle(),s.getArtist(),String.format("%d:%02d",s.getMinutes(),s.getSeconds()),s.getOwner().getUserName()));
      }
      return compSongList;
 }

 ArrayList<String> requestSonglistByArtist(MusicExchangeCenter m, String artist){
      ArrayList<String> songsBy = new ArrayList<>();
     songsBy.add(String.format("%-32s%-18s%-10s%-20s","TITLE","ARTIST","TIME","OWNER"));
     songsBy.add("");

      int count = 0;
      for(Song s: m.availableSongsByArtist(artist)){
          count++;
          songsBy.add((String.format("%02d. %-28s%-186s%-10s%-20s",count,s.getTitle(),s.getArtist(),String.format("%d:%02d",s.getMinutes(),s.getSeconds()),s.getOwner().getUserName())));
      }
      return songsBy;
 }

 Song songWithTitle(String title){
    for(Song s: songList){
        if(s.getTitle()==title){
            return s;
        }
    }
    return null;
 }

 void downloadSong(MusicExchangeCenter m, String title, String ownerName){
      Song s = m.getSong(title,ownerName);
      if(s!=null) {
          songList.add(s);
      }
 }

 void register(MusicExchangeCenter m){ m.registerUser(this); }
 void logon(){ online = true; }
 void logoff(){ online = false; }
}
