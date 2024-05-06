#include "csapp.h"

// echo 클라이언트의 메인 루틴(csapp 911.p)
int main(int argc, char **argv)
{
    int clientfd; // 클라이언트 소켓 파일 디스크립터
    char *host;
    char *port;
    char buf[MAXLINE]; // 메시지를 읽거나 쓰기 위한 버퍼, 서버로부터 받은 응답이나 사용자가 입력한 메시지 임시저장
    rio_t rio; // 버퍼링된 입력 스트림

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1]; // 연결할 서버의 호스트 주소
    port = argv[2]; // 연결할 서버의 포트 번호

    clientfd = Open_clientfd(host, port); // 호스트와 포트에 대한 클라이언트 소켓을 열 때 생성
    Rio_readinitb(&rio, clientfd); // 버퍼링된 입력 스트림 초기화

    while (Fgets(buf, MAXLINE, stdin) != NULL) { // Fgets가 EOF 표준 입력을 만나면 종료
        Rio_writen(clientfd, buf, strlen(buf)); // 주어진 파일 디스크립터에 지정된 바이트 수를 쓰기 위해 호출됨
        Rio_readlineb(&rio, buf, MAXLINE); // 버퍼링된 입력 스트림에서 한 줄 읽어들임
        Fputs(buf, stdout); // 문자열을 파일에 출력
    }
    Close(clientfd); // readlineb에서 리턴코드 0을 받으면 이 사실을 감지하고, 자신의 식별자를 닫아주지만 명시적으로 닫아주기 위해 추가
    exit(0);
}