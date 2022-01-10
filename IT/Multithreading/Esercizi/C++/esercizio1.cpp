/*
file esercizio1.cpp
compilare con: g++ -std=c++11 esercizio1.cpp -lpthread
*/

#include <iostream>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::thread;
using std::chrono::seconds;

void func(int n)
{
	cout << "Inizio del thread " << n << "." << endl;
	std::this_thread::sleep_for(seconds(5));
	cout << "Fine del thread " << n << "." << endl;
}

int main()
{
	cout << "Thread main" << endl;

	thread t(func, 1);
	t.join();

	cout << "Fine del thread main." << endl;
}

