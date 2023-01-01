/*
file esercizio29.cpp
compilare con: g++ -std=c++11 esercizio29.cpp -lpthread
*/

#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::condition_variable;
using std::chrono::duration;
using std::chrono::seconds;
using std::deque;
using std::ref;
using std::move;

template<typename T>
class concurrent_queue {
	private:
		mutex _mutex;
		condition_variable _condition;
		deque<T> _queue;

	public:
		void push(T const&);
		T pop();
		int size();
};

template<typename T>
inline
void concurrent_queue<T>::push(T const& value) {
	{
		unique_lock<mutex> lock(_mutex);
		_queue.push_front(value);
	}
	_condition.notify_one();
}

template<typename T>
inline
T concurrent_queue<T>::pop() {
	unique_lock<mutex> lock(_mutex);
	_condition.wait(lock, [=]{ return !_queue.empty(); });
	T rc(move(_queue.back()));
	_queue.pop_back();
	return rc;
}

template<typename T>
inline
int concurrent_queue<T>::size() {
	return _queue.size();
}

void barber(concurrent_queue<int>& _queue, int i) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		int pc = _queue.pop();
		printf("Il barbiere thread %d sta tagliando i capelli al cliente thread %d.\n", i, pc);
		uniform_int_distribution<int> dist(10, 25);
		int pause = dist(gen);
		seconds duration(pause);
		std::this_thread::sleep_for(duration);

		printf("thread %d ha impiegato %d minuti per tagliare i capelli a thread %d. Avanti un altro!\n", i, pause, pc);
	}
}

void customer(concurrent_queue<int>& _queue, int i) {
	thread_local default_random_engine gen(random_device{}());

	printf("Il cliente thread %d entra nel negozio.\n", i);

	if (_queue.size() < 5) {
		_queue.push(i);
		printf("thread %d si siede e aspetta di farsi tagliare i capelli...\n", i);
	}
	else {
		printf("Il cliente thread %d non ha trovato posto per sedersi ed esce dal negozio...\n", i);
	}

	uniform_int_distribution<int> dist(1, 25);
	seconds duration(dist(gen));
	std::this_thread::sleep_for(duration);
}

int main()
{
	int i = 1;
	concurrent_queue<int> _queue;

	thread tbarber(barber, ref(_queue), i);

	thread processes[25];

	while (true) {
		i++;
		processes[i] = thread(customer, ref(_queue), i);
		thread_local default_random_engine gen(random_device{}());
		uniform_int_distribution<int> dist(5, 30);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
	}

	tbarber.join();

	for (auto& c : processes) {
		c.join();
	}
}

