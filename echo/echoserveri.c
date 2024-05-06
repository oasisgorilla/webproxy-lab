#include "csapp.h"

// echo 서버의 메인루틴(csapp 912.p)
void echo(int connfd);

int main(int argc, char **argv)
{
    int listenfd; // 서버 소켓을 나타내는 파일 디스크립터
    int connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    char client_hostname[MAXLINE], client_port[MAXLINE];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    listenfd = Open_listenfd(argv[1]); // 소켓 연결
    while (1) { // 무한루프(계속 연결)
        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); // 클라이언트 연결 수락
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0); // 클라이언트의 호스트 이름과 포트 번호를 얻는 함수
        printf("Connected to (%s, %s)\n", client_hostname, client_port); // 호스트 이름, 포트 번호 출력
        echo(connfd); // 연결 소켓을 통해 메세지를 echo로 보내면 echo에서 받은 메세지를 다시 클라이언트로 보냄
        Close(connfd); // 클라이언트와의 연결 종료
    }
    exit(0);
}