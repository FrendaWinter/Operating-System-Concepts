import java.net.*;
import java.io.*;
import java.util.Random;

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
          /* write the Date to the socket */
          pout.println(getQuoteOfTheDay());
          /* close the socket and resume */
          /* listening for connections */
          client.close();
        }
    }
      catch (IOException ioe) {
      System.err.println(ioe);
    }
  }

  public static String getQuoteOfTheDay() {
    // Array of quotes
    String[] quotes = {
        "Do what you can, with what you have, where you are. – Theodore Roosevelt",
        "Success is not final, failure is not fatal: It is the courage to continue that counts. – Winston Churchill",
        "Believe you can and you're halfway there. – Theodore Roosevelt",
        "It always seems impossible until it’s done. – Nelson Mandela",
        "Happiness is not something ready-made. It comes from your own actions. – Dalai Lama"
    };
    Random random = new Random();
    int index = random.nextInt(quotes.length);
    return quotes[index];
  }
}