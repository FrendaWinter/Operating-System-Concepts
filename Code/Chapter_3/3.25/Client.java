
import java.net.*;
import java.io.*;

class EchoClient {

    public static void main(String[] args) {
        // Define server address and port
        final String SERVER_ADDRESS = "localhost";
        final int SERVER_PORT = 6013;

        try (Socket socket = new Socket(SERVER_ADDRESS, SERVER_PORT)) {
            System.out.println("Connected to the echo server.");

            // Get input and output streams for communication
            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();

            // Create a BufferedReader to read from the console
            BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));

            // Buffer to store server responses
            byte[] buffer = new byte[1024];
            int bytesRead;

            System.out.println("Type messages to send to the server (type 'exit' to quit):");

            while (true) {
                // Read a line from the console
                String message = consoleReader.readLine();

                // Exit if the user types "exit"
                if (message.equalsIgnoreCase("exit")) {
                    socket.close();
                    break;
                }

                // Send the message to the server
                out.write(message.getBytes());
                out.flush();

                // Read the server's response
                bytesRead = in.read(buffer);
                if (bytesRead == -1) {
                    System.out.println("Server disconnected.");
                    break;
                }

                // Display the echoed message
                String response = new String(buffer, 0, bytesRead);
                System.out.println("Server: " + response);
            }
        } catch (IOException e) {
            System.err.println("Client error: " + e.getMessage());
        }
    }
}
