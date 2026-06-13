#include"sockets.h"



void menu()
{
    int sock = criar_socket(PORTA_SERVIDOR_TCP);
    char mensagem[TAM_MENSAGEM];
    
    for(;;)
    {
        socket_receber_mensagem(mensagem, sock);
        printf("\nTCP server: (%s)\n",mensagem);fflush(stdout);
    }
}

int main()
{
    int sock;
#ifdef WIN
    WORD wPackedValues;
    WSADATA  SocketInfo;
    int      nLastError,
	         nVersionMinor = 1,
	         nVersionMajor = 1;
    wPackedValues = (WORD)(((WORD)nVersionMinor)<< 8)|(WORD)nVersionMajor;
    nLastError = WSAStartup(wPackedValues, &SocketInfo);
#endif

    menu();

    return (0);
}
