import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;  // for precise timestamps

public class LatencyUdpClient {

  public static void main(String[] args) throws IOException {
    InetAddress serverAddress = InetAddress.getByName("localhost");
    int port = 12345;
    byte[] data = "Hello, Server!".getBytes();

    // Record start time before sending data
    Date startTime = new Date();

    DatagramSocket socket = new DatagramSocket();
    DatagramPacket packet = new DatagramPacket(data, data.length, serverAddress, port);

    socket.send(packet);

    // No response received in UDP, so latency measurement ends here
    Date endTime = new Date();

    long latency = endTime.getTime() - startTime.getTime(); // time in milliseconds

    System.out.println("Latency (sending only): " + latency + " ms");

    socket.close();
  }
}
