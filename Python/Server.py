import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(5)

print('Server listening...')
client_socket, address = server_socket.accept()
print('Connection established with:', address)

data = client_socket.recv(1024)
print('Received data:', data.decode())

client_socket.close()
server_socket.close()
