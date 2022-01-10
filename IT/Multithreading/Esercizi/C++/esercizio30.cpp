/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio30.cpp -lpthread
*/

#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#if __cplusplus > 201703L
#include <semaphore>
using std::counting_semaphore;
#else
#include "semaphore.h"
#endif
using semaphore = counting_semaphore<1>;

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::mutex;
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;

class SmokingRoom {
	private:
		semaphore agentSem;
		mutex _mutex;

		semaphore tobacco;
		semaphore paper;
		semaphore matches;

		bool isTobacco;
		bool isPaper;
		bool isMatches;

		semaphore tobaccoSem;
		semaphore paperSem;
		semaphore matchesSem;

	private:
		// thread agenti
		void tobaccoPaperAgent();
		void tobaccoMatchesAgent();
		void paperMatchesAgent();

		// thread pusher
		void tobaccoPusher();
		void paperPusher();
		void matchesPusher();

		// thread fumatori
		void tobaccoSmoker();
		void paperSmoker();
		void matchesSmoker();

	public:
		SmokingRoom();
		~SmokingRoom() = default;
};

void SmokingRoom::tobaccoPaperAgent() {
	while (true) {
		agentSem.acquire();
		printf("L'agente mette tabacco e carta sul tavolo.\n");
		tobacco.release();
		paper.release();
	}
}

void SmokingRoom::tobaccoMatchesAgent() {
	while (true) {
		agentSem.acquire();
		printf("L'agente mette tabacco e fiammiferi sul tavolo.\n");
		tobacco.release();
		matches.release();
	}
}

void SmokingRoom::paperMatchesAgent() {
	while (true) {
		agentSem.acquire();
		printf("L'agente mette carta e fiammiferi sul tavolo.\n");
		paper.release();
		matches.release();
	}
}

void SmokingRoom::tobaccoPusher() {
	while (true) {
		tobacco.acquire();
		printf("Spacciatore di tabacco all'opera.\n");
		_mutex.lock();

		if (isPaper) {
			isPaper = false;
			matchesSem.release();
		}
		else if (isMatches) {
			isMatches = false;
			paperSem.release();
		}
		else {
			isTobacco = true;
		}

		_mutex.unlock();
	}
}

void SmokingRoom::paperPusher() {
	while (true) {
		paper.acquire();
		printf("Spacciatore di carta all'opera.\n");
		_mutex.lock();

		if (isTobacco) {
			isTobacco = false;
			matchesSem.release();
		}
		else if (isMatches) {
			isMatches = false;
			tobaccoSem.release();
		}
		else {
			isPaper = true;
		}

		_mutex.unlock();
	}
}

void SmokingRoom::matchesPusher() {
	while (true) {
		matches.acquire();
		printf("Spacciatore di fiammiferi all'opera.\n");
		_mutex.lock();

		if (isPaper) {
			isPaper = false;
			tobaccoSem.release();
		}
		else if (isTobacco) {
			isTobacco = false;
			paperSem.release();
		}
		else {
			isMatches = true;
		}

		_mutex.unlock();
	}
}

void SmokingRoom::tobaccoSmoker() {
	thread_local default_random_engine gen(random_device{}());
	while (true) {
		tobaccoSem.acquire();
		uniform_int_distribution<int> dist(5, 10);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
		printf("Il fumatore con il tabacco ha finito di prepararsi la sigaretta.\n");
		agentSem.release();
		printf("Il fumatore con il tabacco sta fumando...\n");
	}
}

void SmokingRoom::paperSmoker() {
	thread_local default_random_engine gen(random_device{}());
	while (true) {
		paperSem.acquire();
		uniform_int_distribution<int> dist(5, 10);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
		printf("Il fumatore con la carta ha finito di prepararsi la sigaretta.\n");
		agentSem.release();
		printf("Il fumatore con la carta sta fumando...\n");
	}
}

void SmokingRoom::matchesSmoker() {
	thread_local default_random_engine gen(random_device{}());
	while (true) {
		matchesSem.acquire();
		uniform_int_distribution<int> dist(5, 10);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
		printf("Il fumatore con i fiammiferi ha finito di prepararsi la sigaretta.\n");
		agentSem.release();
		printf("Il fumatore con i fiammiferi sta fumando...\n");
	}
}

SmokingRoom::SmokingRoom() : agentSem(1), tobacco(0), paper(0), matches(0), isTobacco(false), isPaper(false), isMatches(false), tobaccoSem(0), paperSem(0), matchesSem(0) {
	thread agents[3];

	agents[0] = thread (&SmokingRoom::tobaccoPaperAgent, this);
	agents[1] = thread(&SmokingRoom::tobaccoMatchesAgent, this);
	agents[2] = thread(&SmokingRoom::paperMatchesAgent, this);

	thread pushers[3];

	pushers[0] = thread(&SmokingRoom::tobaccoPusher, this);
	pushers[1] = thread(&SmokingRoom::paperPusher, this);
	pushers[2] = thread(&SmokingRoom::matchesPusher, this);

	thread smokers[3];

	smokers[0] = thread(&SmokingRoom::tobaccoSmoker, this);
	smokers[1] = thread(&SmokingRoom::paperSmoker, this);
	smokers[2] = thread(&SmokingRoom::matchesSmoker, this);

	for (auto& agent : agents) {
		agent.join();
	}

	for (auto& pusher : pushers) {
		pusher.join();
	}

	for (auto& smoker : smokers) {
		smoker.join();
	}
}

int main()
{
	SmokingRoom sRoom;
}

