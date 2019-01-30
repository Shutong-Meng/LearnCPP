#coding=utf-8
import  socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('127.0.0.1',5999))
s.listen(1)
sock,addr = s.accept()
buf = sock.recv(1024).decode()
while True:
    if buf!='exit':
        print("client: " + buf)
    data =input("server: ")
    sock.send(data.encode())
    if data=='exit':
        break
    buf=sock.recv(1024).decode()