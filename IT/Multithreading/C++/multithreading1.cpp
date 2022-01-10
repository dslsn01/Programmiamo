/*
file multithreading1.cpp
compilare con: g++ -std=c++11 multithreading1.cpp -lpthread
*/

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;
using std::chrono::seconds;
using std::this_thread::sleep_for;

int main()
{
	cout << "Thread main" << endl;

	// arresta il processo principale per 5 secondi
	sleep_for(seconds(5));

	cout << "Fine del thread main." << endl;
}

