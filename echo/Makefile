CC = gcc
CFLAGS = -O2 -Wall -I .
LIB = -lpthread

all: echoclient echoserver
# csapp.c 와 csapp.h를 컴파일하여 csapp.o 목적파일 생성
csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c
# echoclient.c를 컴파일하고 csapp.o를 링크하여 echoclient 바이너리 파일 생성
echoclient: echoclient.c csapp.o
	$(CC) $(CFLAGS) -o echoclient echoclient.c csapp.o $(LIB)
# echoserveri.c를 컴파일하고 csapp.o를 링크하여 echoserver 바이너리 파일 생성
echoserver: echoserveri.c csapp.o
	$(CC) $(CFLAGS) -o echoserver echoserveri.c csapp.o $(LIB)
        
clean:
	rm -f *.o echoclient echoserver *~