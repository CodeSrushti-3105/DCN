import java.io.*;
import java.net.*;

public class UDPFileServer {
    public static void main(String[] args)
    throws Exception {
        DatagramSocket socket = new DatagramSocket(9876);
        byte[] receiveBuffer = new byte[1024];
        
        FileOutputStream fos = new FileOutputStream("received_file");
        System.out.println("Server ready to receive file...");

        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveBuffer, receiveBuffer.length);
            socket.receive(receivePacket);

            int length = receivePacket.getLength();
            if (length == -1) break;

            // If it's the "end" message, break
            String message = new String(receivePacket.getData(), 0, length);
            if (message.equals("END_OF_FILE")) {
                System.out.println("File transfer complete.");
                break;
            }

            fos.write(receivePacket.getData(), 0, length);
        }

        fos.close();
        socket.close();
    }
}
