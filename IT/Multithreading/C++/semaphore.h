/* file semaphore.h */

#ifndef SEMAPHORE__H__
#define SEMAPHORE__H__
#define S_MAX 128

#include <chrono>
#include <mutex>
#include <condition_variable>

using std::mutex;
using std::unique_lock;
using std::condition_variable;
using std::chrono::duration;
using std::chrono::milliseconds;

template<unsigned int N = S_MAX>
class counting_semaphore {
	static_assert(N >= 0, "N < 0");
	static_assert(N <= S_MAX, "N > S_MAX");

	private:
		unsigned int count;
		mutex _mutex;
		condition_variable _condition;

	public:
		counting_semaphore(unsigned int signal=1);
		void acquire();
		bool try_acquire();
		void release();
};

template<unsigned int N>
counting_semaphore<N>::counting_semaphore(unsigned int signal) : count(signal) {}

template<unsigned int N>
void counting_semaphore<N>::acquire() {
	unique_lock<mutex> lock(_mutex);
	_condition.wait(lock, [&]() -> bool{ return count > 0; });
	--count;
}

template<unsigned int N>
bool counting_semaphore<N>::try_acquire() {
	unique_lock<mutex> lock(_mutex);
	if (!_condition.wait_for(lock, milliseconds(10), [&]() -> bool{ return count > 0; })) {
		return false;
	}

	--count;
	return true;
}

template<unsigned int N>
void counting_semaphore<N>::release() {
	unique_lock<mutex> lock(_mutex);
	++count;
	_condition.notify_one();
}

#endif

