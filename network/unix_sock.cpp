/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 * 
 * @Author: hhhhack
 * @Date: 2021-05-07 09:43:55
 * @LastEditTime: 2021-05-07 14:40:36
 * @LastEditors: hhhhack
 * @Description: 
 * @FilePath: /my_learn/network/unix_sock.cpp
 * 
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>
using namespace std;

#define MAX_LEN 1024

void server_ver_3(){
    int listen_fd, connect_fd;
    socklen_t sock_addr_l = sizeof(sockaddr), cli_len;
    pid_t s_pid;
    sockaddr ser_addr, client_addr;
    listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sa_family = AF_INET;
    sockaddr_in *ser_addr_in = (sockaddr_in *)&ser_addr;
    ser_addr_in->sin_port = htons(1234);
    // ser_addr_in->sin_addr.s_addr = htonl(INADDR_ANY);
    inet_aton("127.0.0.1", &ser_addr_in->sin_addr);
    bind(listen_fd, &ser_addr, sock_addr_l);
    listen(listen_fd, sock_addr_l);
    int ep_fd = epoll_create(1024);
    epoll_event *event;
    for (;;)
    {
        cli_len = sizeof(client_addr);
        connect_fd = accept4(listen_fd, &client_addr, &cli_len, SOCK_NONBLOCK);
        if (connect_fd > 0){
            if (event = malloc(sizeof(epoll_event)) == NULL ){
                cout << "malloc fail " << endl;
                continue;
            }
            
            bzero(event, sizeof(epoll_event));
            event->data.fd = connect_fd;
            event->events = EPOLLIN | EPOLLOUT;
            event->data.ptr = event;
            epoll_ctl(ep_fd, EPOLL_CTL_ADD, connect_fd, event);
        }else{
            if (errno == EAGAIN || errno == EWOULDBLOCK){
                cout << "no client connect " << endl;
                sleep(5);
            }else{
                cout << "accept faile error is " << strerror(errno) << endl; 
                break;
            }
        }
    }

    close(listen_fd);
    close(ep_fd);
}



/*
 * 非阻塞读
*/
void server_ver_2()
{
    int listen_fd, connect_fd;
    socklen_t sock_addr_l = sizeof(sockaddr), cli_len;
    pid_t s_pid;
    sockaddr ser_addr, client_addr;
    listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sa_family = AF_INET;
    sockaddr_in *ser_addr_in = (sockaddr_in *)&ser_addr;
    ser_addr_in->sin_port = htons(1234);
    // ser_addr_in->sin_addr.s_addr = htonl(INADDR_ANY);
    inet_aton("127.0.0.1", &ser_addr_in->sin_addr);
    bind(listen_fd, &ser_addr, sock_addr_l);
    listen(listen_fd, sock_addr_l);
    for (;;)
    {
        cli_len = sizeof(client_addr);
        connect_fd = accept4(listen_fd, &client_addr, &cli_len, SOCK_NONBLOCK);
        
        if (connect_fd > 0)
        {
            s_pid = fork();
            if (s_pid == 0)
            {
                //close(listen_fd);
                cout << "listen fd status is " << fcntl(listen_fd, F_GETFD, 0) << endl;
                int status = fcntl(connect_fd, F_GETFL, 0);
                status = status | O_NONBLOCK;
                if (fcntl(connect_fd, F_SETFL, status) < 0){
                    cout << "fcntl error " << strerror(errno) << endl;
                }
                status = fcntl(connect_fd, F_GETFL, 0);
                ssize_t len = 0;
                cout << "fork son process sucess" << endl;
                unsigned char buf[1024];
                for (;;)
                {
                    len = read(connect_fd, buf, 1023);
                    cout << "read len is " << len << endl;
                    if (len > 0)
                    {
                        if (strcmp((char *)buf, "stop") == 0)
                        {
                            break;
                        }
                        write(connect_fd, buf, len);
                        write(1, buf, len);
                    }else if (len == 0){
                        cout << "read end of file " << endl;
                        break;
                    }else {
                        cout << "read error ,errorno is " << errno << " " << strerror(errno)<< endl;
                        if (errno == EAGAIN || errno == EWOULDBLOCK){
                            sleep(10);
                            cout << "one circle "<< endl;
                        }
                    }
                }
                close(connect_fd);
                exit(0);
            }
            else if (s_pid > 0)
            {
                int status;
                waitpid(s_pid, &status, 0);
                cout << "wait son process finish" << endl;
            }
            else
            {
                throw "fork error";
            }
        }else {
            if (errno == EAGAIN || errno == EWOULDBLOCK){
                cout << "no client connect " << endl;
                sleep(5);
            }else{
                cout << "accept faile error is " << strerror(errno) << endl; 
                break;
            }
        }
    }
    close(listen_fd);
}

void server_ver_1()
{
    int listen_fd, connect_fd;
    socklen_t sock_addr_l = sizeof(sockaddr), cli_len;
    pid_t s_pid;
    sockaddr ser_addr, client_addr;
    listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sa_family = AF_INET;
    sockaddr_in *ser_addr_in = (sockaddr_in *)&ser_addr;
    ser_addr_in->sin_port = htons(1234);
    // ser_addr_in->sin_addr.s_addr = htonl(INADDR_ANY);
    inet_aton("127.0.0.1", &ser_addr_in->sin_addr);
    bind(listen_fd, &ser_addr, sock_addr_l);
    listen(listen_fd, sock_addr_l);
    for (;;)
    {
        cli_len = sizeof(client_addr);
        connect_fd = accept(listen_fd, &client_addr, &cli_len);
        if (connect_fd > 0)
        {
            s_pid = fork();
            if (s_pid == 0)
            {
                close(listen_fd);
                size_t len = 0;
                cout << "fork son process sucess" << endl;
                unsigned char buf[1024];
                for (;;)
                {
                    len = read(connect_fd, buf, 1023);
                    if (len > 0)
                    {
                        if (strcmp((char *)buf, "stop") == 0)
                        {
                            break;
                        }
                        write(connect_fd, buf, len);
                        write(1, buf, len);
                    }
                }
                close(connect_fd);
                exit(0);
            }
            else if (s_pid > 0)
            {
                int status;
                waitpid(s_pid, &status, 0);
                cout << "wait son process finish" << endl;
            }
            else
            {
                throw "fork error";
            }
        }
    }
}

void client()
{
    int client_fd;
    sockaddr client_addr;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t sk_len = sizeof(client_addr);
    client_addr.sa_family = AF_INET;
    sockaddr_in *client_in_addr = (sockaddr_in *)&client_addr;
    client_in_addr->sin_port = htons(1234);
    inet_aton("127.0.0.1", &client_in_addr->sin_addr);
    char buf[1024];
    size_t len;
    if (!connect(client_fd, &client_addr, sk_len))
    {
        for (;;)
        {
            cin >> buf;
            if (write(client_fd, buf, strlen(buf)) < 0)
            {
                break;
            }
            if (strcmp(buf, "stop") == 0)
            {
                break;
            }
            if ((len = read(client_fd, buf, 1024)) < 0)
            {
                break;
            }
            else
            {
                write(1, buf, len);
            }
        }
    }
    close(client_fd);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "input method" << endl;
        return 0;
    }
    if (strcmp(argv[1], "server") == 0)
    {
        server_ver_2();
    }
    else if (strcmp(argv[1], "client") == 0)
    {
        client();
    }
}