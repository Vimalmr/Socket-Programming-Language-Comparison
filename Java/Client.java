import java.io.IOException;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
	long begin = System.currentTimeMillis();
        Socket clientSocket = new Socket("127.0.0.1", 12345);
        String message = "Hello, Server!";
        clientSocket.getOutputStream().write(message.getBytes());
        clientSocket.close();
        long end = System.currentTimeMillis();
        System.out.println("Time Taken : "+ (end-begin)+" ms");
    }
}
