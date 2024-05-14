import socket
import time

# Server address and port
SERVER_ADDRESS = ("localhost", 12345)

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Message to send
message = "Hello, Server!".encode()

# Send message to server
send_time = time.time()
client_socket.sendto(message, SERVER_ADDRESS)

print(f"Sent message: {message.decode()}")

# (Optional) Receive data from server (not applicable for one-way communication)
# data, address = client_socket.recvfrom(1024)
# print(f"Received data: {data.decode()} from {address}")

# Close socket (optional, included for completeness)
client_socket.close()

# Calculate one-way latency (measured on client-side)
elapsed_time = time.time() - send_time
print(f"One-way latency: {elapsed_time:.3f} seconds")
