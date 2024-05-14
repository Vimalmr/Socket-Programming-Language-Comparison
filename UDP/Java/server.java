import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Date;  // for precise timestamps

public class LatencyUdpServer {

  public static void main(String[] args) throws IOException {
    int port = 12345;
    byte[] data = new byte[1024];

    DatagramSocket socket = new DatagramSocket(port);
    DatagramPacket packet = new DatagramPacket(data, data.length);

    // Server doesn't measure latency as it doesn't send a response

    socket.receive(packet);

    String message = new String(packet.getData(), 0, packet.getLength());
    System.out.println("Received data: " + message);

    socket.close();
  }
}
