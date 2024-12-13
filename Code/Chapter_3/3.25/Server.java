
import java.net.*;
import java.io.*;

class EchoServer {

    public static void main(String[] args) {
        // Define the port number for the server to listen on
        final int PORT = 6013;

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Echo server started. Waiting for clients...");

            while (true) {
                // Accept a client connection
                try (Socket clientSocket = serverSocket.accept()) {
                    System.out.println("Client connected: " + clientSocket.getInetAddress());

                    // Get input and output streams
                    InputStream in = clientSocket.getInputStream();
                    OutputStream out = clientSocket.getOutputStream();

                    byte[] buffer = new byte[1024]; // Buffer to hold incoming data
                    int bytesRead;

                    // Read data from the client and echo it back
                    while ((bytesRead = in.read(buffer)) != -1) {
                        out.write(buffer, 0, bytesRead); // Echo the received data back to the client
                        out.flush();
                    }

                    System.out.println("Client disconnected.");
                } catch (IOException e) {
                    System.err.println("Error handling client: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println("Server error: " + e.getMessage());
        }
    }
}
