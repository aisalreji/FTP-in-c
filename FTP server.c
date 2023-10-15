//SERVER
#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>

#include<netinet/in.h>
#include<fcntl.h>
#include<sys/types.h>

main () 
{
  
struct sockaddr_in clientaddr, serveraddr;
  
int serversock, newserversock, clientsize, n, f, rc;
  
char filename[100], filedata[300];
  
 
 
fflush (stdin);
  
sock_desc = socket (AF_INET, SOCK_STREAM, 0);
  
 
bzero ((char *) &asever_addr, sizeof (server_addr));
  
 
server_addr.sin_family = AF_INET;
  
serve_raddr.sin_port = htons (2000);
  
server_addr.sin_addr.s_addr = inet_addr ("127.0.0.1");
  
 
bind (sock_desc, (struct sockaddr *) &serveraddr, sizeof (serveraddr));
  
 
listen (socket_desc, 5);
  
 
while (1)
    
    {
      
client_sock =
	accept (sock_desc, (struct sockaddr *) &clientaddr,
		sizeof (clientaddr));
      
n = read (client_sock, filename, 100);
      
filename[n] = 0;
      
printf ("\nThe requested file from the client is %s.\n", filename);
      
 
f = open (filename, O_RDWR);
      
n = read (f, filedata, 300);
      
 
printf ("\nThe contents of the file: \n\n");
      
printf ("%s", filedata);
      
write (client_sock, filedata, n);
    
}
  
close (sock_desc);
  
close (client_sock);

}




