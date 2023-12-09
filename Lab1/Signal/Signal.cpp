#include <iostream>
#include <conio.h>
#include <windows.h>
#include <csignal>

void signalHandler(int signal)
{
    std::cout << "signal received " << std::endl;

    exit(signal);
}

int main()
{
    signal(SIGINT, signalHandler);

    std::cout << "Waiting for a signal..." << std::endl;

    while (true)
    {
    }

    return 0;
}