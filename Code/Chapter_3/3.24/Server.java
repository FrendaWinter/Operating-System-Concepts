import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DateServer
{
  public static void main(String[] args) {
    try {
      ServerSocket sock = new ServerSocket(6013);
      /* now listen for connections */
        while (true) {
          Socket client = sock.accept();
          PrintWriter pout = new
          PrintWriter(client.getOutputStream(), true);

          String randomHaikus = getHaiku();
          pout.println(randomHaikus);

          /* close the socket and resume */
          /* listening for connections */
          client.close();
        }
    }
      catch (IOException ioe) {
      System.err.println(ioe);
    }
  }

  public static String getHaiku() {
    // List of haikus
    List<String> haikus = new ArrayList<>();
    haikus.add("An old silent pond\nA frog jumps into the pond—\nSplash! Silence again.");
    haikus.add("Over the wintry\nForest, winds howl in rage\nWith no leaves to blow.");
    haikus.add("In the cicada's cry\nNo sign can foretell\nHow soon it must die.");
    haikus.add("Autumn moonlight—\nA worm digs silently\nInto the chestnut.");
    haikus.add("Winter seclusion—\nListening, that evening,\nTo the rain in the mountain.");
    haikus.add("Light of the moon\nMoves west, flowers' shadows\nCreep eastward.");
    haikus.add("Summer grasses:\nAll that remains of great soldiers'\nImperial dreams.");
    haikus.add("In the coolness\nOf the empty sixth-month sky…\nThe cuckoo's cry.");
    haikus.add("I write, erase, rewrite\nErase again, and then\nA poppy blooms.");
    haikus.add("From time to time\nThe clouds give rest\nTo the moon-beholders.");
    
    Random random = new Random();
    int index = random.nextInt(haikus.size());
    return haikus.get(index);
  }
}