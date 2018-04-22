#ifndef CLIENT_H
#define CLIENT_H

#include "../src/TCPClient.h"

class Client
{

public:
    void sig_exit(int s);
    int main();

private:
    TCPClient * tcp;
};

#endif
