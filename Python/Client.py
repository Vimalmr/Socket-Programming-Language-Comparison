import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))

message = 'Hello, Server!'
client_socket.sendall(message.encode())

client_socket.close()
