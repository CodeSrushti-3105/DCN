import java.io.*;
import java.net.*;

public class UDPFileClient {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        InetAddress IPAddress = InetAddress.getByName("localhost"); // Change to server IP if needed
        byte[] sendBuffer = new byte[1024];

        // File to send (change filename as needed)
        File file = new File("file_to_send.mp4"); // or .txt, .mp3, .sh etc.
        FileInputStream fis = new FileInputStream(file);
        System.out.println("Sending file: " + file.getName());

        int bytesRead;
        while ((bytesRead = fis.read(sendBuffer)) != -1) {
            DatagramPacket sendPacket = new DatagramPacket(sendBuffer, bytesRead, IPAddress, 9876);
            socket.send(sendPacket);
        }

        // Send "END_OF_FILE" message to signal end
        byte[] endMessage = "END_OF_FILE".getBytes();
        DatagramPacket endPacket = new DatagramPacket(endMessage, endMessage.length, IPAddress, 9876);
        socket.send(endPacket);

        fis.close();
        socket.close();
        System.out.println("File sent successfully.");
    }
}
