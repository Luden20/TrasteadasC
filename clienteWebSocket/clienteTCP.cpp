#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<iostream>
#include<string>
#define SERVER_IP "192.168.1.27"
#define PORT 80
int main()
{
	std::cout<<"Ejecutando..";
	int sock;
	struct sockaddr_in server_addr;
	const char* mensaje="Hola xd";
	char buffer[1024]={0};
	
	//Creamos el  socket usando el protocolo TCP
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		std::cout<<"Error";
		perror("Esta mamada fallo");
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	if(inet_pton(AF_INET,SERVER_IP,&server_addr.sin_addr)<0)
	{
		std::cout<<"no existe la conexion";
		perror("no existe esta conexion");
		return -1;
	}
	if(connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		perror("error al conexctar");
		close(sock);
		return -1;
	}
	std::cout<<"Nos estamos conectando...";
	send(sock,mensaje,strlen(mensaje),0);
	std::string input;
	while(input!="SALIR")
	{
		std::cout<<"\nIngrese algo...";
		std::cin >> input;
		send(sock,input.c_str(),input.size(),0);
	}
	std::cout<<"FIn";
	close(sock);
	return 0;
}
