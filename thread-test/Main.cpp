#include "thread.h"
#include <iostream>

void print(int a, int b)
{
	std::cout << "1\n";
}

int main()
{
	thread mythread(print, 5, 8);
	std::cout << "2" << std::endl;
}