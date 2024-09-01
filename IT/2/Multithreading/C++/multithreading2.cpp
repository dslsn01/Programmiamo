/* 
file multithreading2.cpp 
compilare con: g++ -std=c++11 multithreading2.cpp -lpthread
*/

#include <cstdio>
#include <thread>

using std::thread;

void func(int n) {
	printf("Ciao, sono il thread %d!\n", n);
}

int main()
{
	/* crea due thread che eseguono la funzione func() */

	thread t1(func, 1);
	thread t2(func, 2); 

	t1.join(); 
	t2.join(); 
}

