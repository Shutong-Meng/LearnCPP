import socket
import sys

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect(('127.0.0.1', 5999))
while True:
   
    try:
        data = input("client: ")
        s.send(data.encode())
        buf = s.recv(1024).decode()
        if buf!='exit':
            print("server: " + buf)
    except:
        print("Dialogue Over")
        s.close()
        sys.exit(0)