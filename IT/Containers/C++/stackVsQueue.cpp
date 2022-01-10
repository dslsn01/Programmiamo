/* file stackVsQueue.cpp */

#include <iostream>
#include <deque>

using std::string;
using std::cout;
using std::endl;
using std::deque;

int main() 
{
	/* crea una pila di tre elementi */

	deque<string> stack;

	stack.push_front("elefante");
	stack.push_front("giraffa");
	stack.push_front("tigre");

	deque<string>::iterator it;

	for (it = stack.begin(); it != stack.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	/* estrae dalla lista l'ultimo elemento aggiunto */

	string elem1 = stack.front();
	stack.pop_front();

	cout << elem1 << endl;

	for (it = stack.begin(); it != stack.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	/* crea una coda di tre elementi */

	deque<string> queue;

	queue.push_back("cane");
	queue.push_back("lupo");
	queue.push_back("orso");

	for (it = queue.begin(); it != queue.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	/* estrae dalla coda il primo elemento aggiunto */

	string elem2 = queue.front();
	queue.pop_front();

	cout << elem2 << endl;

	for (it = queue.begin(); it != queue.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;
}

