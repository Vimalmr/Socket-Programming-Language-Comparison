import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        long begin = System.currentTimeMillis();
        ServerSocket serverSocket = new ServerSocket(12345);
        System.out.println("Server listening...");
        long end = System.currentTimeMillis();
        Socket clientSocket = serverSocket.accept();
        System.out.println("Connection established.");
        byte[] data = new byte[1024];
        int bytesRead = clientSocket.getInputStream().read(data);
        String message = new String(data, 0, bytesRead);
        System.out.println("Received data: " + message);
        clientSocket.close();
        serverSocket.close();
        System.out.println("Time Taken : "+ (end-begin)+" ms");
    }
}
