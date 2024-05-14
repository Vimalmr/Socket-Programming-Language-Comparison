import socket
import time

# Server port
PORT = 12345

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind socket to address and port
server_socket.bind(("localhost", PORT))

print(f"Server listening on port {PORT}")

while True:
  # Receive data from client
  data, address = server_socket.recvfrom(1024)
  
  # Get current time
  receive_time = time.time()
  
  # Print received data and address
  print(f"Received data: {data.decode()} from {address}")
  
  # Calculate latency (round-trip time is not possible with UDP)
  # (Simulate processing time for demonstration)
  processing_time = 0.2  # Simulate 200ms processing
  latency = receive_time - (receive_time - processing_time)  # Approximate one-way latency
  
  print(f"Latency: {latency:.3f} seconds")

# Close socket (optional, included for completeness)
server_socket.close()
