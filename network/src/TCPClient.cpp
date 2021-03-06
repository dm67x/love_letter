#include "TCPClient.h"

TCPClient::TCPClient()
{
	sock = -1;
    port = 8888;
	address = "";
}

// Creates socket
bool TCPClient::setup(string address , int port)
{
  	if(sock == -1)
	{
        sock = socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
		if (sock == -1)
		{
      			cout << "Could not create socket" << endl;
    		}
        }
  	if(inet_addr(address.c_str()) == -1)
  	{
    		struct hostent *he;
    		struct in_addr **addr_list;
    		if ( (he = gethostbyname( address.c_str() ) ) == NULL)
    		{
		      herror("gethostbyname");
      		      cout<<"Failed to resolve hostname\n";
		      return false;
    		}
	   	addr_list = (struct in_addr **) he->h_addr_list;
    		for(int i = 0; addr_list[i] != NULL; i++)
    		{
      		      server.sin_addr = *addr_list[i];
		      break;
    		}
  	}
  	else
  	{
    		server.sin_addr.s_addr = inet_addr( address.c_str() );
  	}
  	server.sin_family = AF_INET;
  	server.sin_port = htons( port );
  	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
  	{
    		perror("connect failed. Error");
    		return false;
  	}
  	return true;
}

bool TCPClient::Send(string data)
{
	if(sock != -1) 
	{
		if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
		{
			cout << "Send failed : " << data << endl;
			return false;
		}
	}
	else
		return false;
	return true;
}

string TCPClient::receive(int size)
{
  	char buffer[size];
	memset(&buffer[0], 0, sizeof(buffer));

  	string reply;
	if( recv(sock , buffer , size, 0) < 0)
  	{
	    	cout << "receive failed!" << endl;
        return NULL;
  	}
	buffer[size-1]='\0';
  	reply = buffer;
  	return reply;
}
/*
char TCPClient::receive_char()
{
    int size = 4096;
    char buffer[size];
    memset(&buffer[0], 0, sizeof(buffer));

    string reply;
    if( recv(sock , buffer , size, 0) < 0)
    {
            cout << "receive failed!" << endl;
        return NULL;
    }
    buffer[size-1]='\0';
    reply = buffer;
    return reply.at(0);
}
*/
string TCPClient::read()
{
  	char buffer[1] = {};
  	string reply;
  	while (buffer[0] != '\n') {
    		if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
    		{
      			cout << "receive failed!" << endl;
            return NULL;
    		}
		reply += buffer[0];
	}
	return reply;
}

void TCPClient::exit()
{
    close( sock );
}
