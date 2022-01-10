# file esercizio30.py

# file esercizio29.py
from multiprocessing import Process, current_process, RLock, Semaphore, Value, Condition
from random import randint
from time import sleep

# processi agenti
# agente che distribuisce tabacco e carta

def tobaccoPaperAgent(agentSem, tobacco, paper):
	while True:
		agentSem.acquire()
		print("L'agente mette tabacco e carta sul tavolo.")
		tobacco.release()
		paper.release()

# agente che distribuisce tabacco e fiammiferi

def tobaccoMatchesAgent(agentSem, tobacco, matches):
	while True:
		agentSem.acquire()
		print("L'agente mette tabacco e fiammiferi sul tavolo.")
		tobacco.release()
		matches.release()

# agente che distribuisce carta e fiammiferi

def paperMatchesAgent(agentSem, paper, matches):
	while True:
		agentSem.acquire()
		print("L'agente mette carta e fiammiferi sul tavolo.")
		paper.release()
		matches.release()

# processi pusher
# pusher che distribuisce il tabacco

def tobaccoPusher(tobacco, lock, isTobacco, isPaper, isMatches, matchesSem, paperSem):
	while True:
		tobacco.acquire()
		print("Spacciatore di tabacco all'opera.")
		lock.acquire()
		if isPaper.value:
			isPaper.value = False
			matchesSem.release();
		elif isMatches.value:
			isMatches.value = False
			paperSem.release();
		else:
			isTobacco.value = True

		lock.release()

# pusher che distribuisce la carta

def paperPusher(paper, lock, isTobacco, isPaper, isMatches, tobaccoSem, matchesSem):
	while True:
		paper.acquire()
		print("Spacciatore di carta all'opera.")
		lock.acquire()
		# with self.__lock:
		if isTobacco.value:
			isTobacco.value = False
			matchesSem.release();
		elif isMatches.value: 
			isMatches.value = False
			tobaccoSem.release();
		else:
			isPaper.value = True

		lock.release()

# pusher che distribuisce i fiammiferi

def matchesPusher(matches, lock, isTobacco, isPaper, isMatches, tobaccoSem, paperSem):
	while True:
		matches.acquire()
		print("Spacciatore di fiammiferi all'opera.")
		lock.acquire()
		# with self.__lock:
		if isPaper.value:
			isPaper.value = False
			tobaccoSem.release();
		elif isTobacco.value: 
			isTobacco.value = False
			paperSem.release();
		else:
			isMatches.value = True

		lock.release()

# sezione dei processi fumatori
# fumatore che detiene il tabacco

def tobaccoSmoker(tobaccoSem, agentSem):
	while True:
		tobaccoSem.acquire()
		pause = randint(5, 10)
		sleep(pause);
		print("Il fumatore con il tabacco ha finito di prepararsi la sigaretta.")
		agentSem.release()
		print("Il fumatore con il tabacco sta fumando...")

# fumatore che detiene la carta per sigarette

def paperSmoker(paperSem, agentSem):
	while True:
		paperSem.acquire()
		pause = randint(5, 10)
		sleep(pause);
		print("Il fumatore con la carta  ha finito di prepararsi la sigaretta.")
		agentSem.release()
		print("Il fumatore con la carta sta fumando...")

# fumatore che detiene i fiammiferi

def matchesSmoker(matchesSem, agentSem):
	while True:
		matchesSem.acquire()
		pause = randint(5, 10)
		sleep(pause);
		print("Il fumatore con i fiammiferi ha finito di prepararsi la sigaretta.")
		agentSem.release()
		print("Il fumatore con i fiammiferi sta fumando...")

if __name__ == "__main__":
	agentSem = Semaphore(1)
	lock = RLock()

	tobacco = Semaphore(0)
	paper = Semaphore(0)
	matches = Semaphore(0)

	isTobacco = Value('b', False)
	isPaper = Value('b', False)
	isMatches = Value('b', False)

	tobaccoSem = Semaphore(0)
	paperSem = Semaphore(0)
	matchesSem = Semaphore(0)

	agents = []

	agentA = Process(target=tobaccoPaperAgent, args=(agentSem, tobacco, paper,))
	agentB = Process(target=tobaccoMatchesAgent, args=(agentSem, tobacco, matches,))
	agentC = Process(target=paperMatchesAgent, args=(agentSem, paper, matches,))

	agents.extend([agentA, agentB, agentC])

	pushers = []

	pusherA = Process(target=tobaccoPusher, args=(tobacco, lock, isTobacco, isPaper, isMatches, matchesSem, paperSem,))
	pusherB = Process(target=paperPusher, args=(paper, lock, isTobacco, isPaper, isMatches, tobaccoSem, matchesSem,))
	pusherC = Process(target=matchesPusher, args=(matches, lock, isTobacco, isPaper, isMatches, tobaccoSem, paperSem,))

	pushers.extend([pusherA, pusherB, pusherC])

	smokers = []

	smokerA = Process(target=tobaccoSmoker, args=(tobaccoSem, agentSem,))
	smokerB = Process(target=paperSmoker, args=(paperSem, agentSem,))
	smokerC = Process(target=matchesSmoker, args=(matchesSem, agentSem,))

	smokers.extend([smokerA, smokerB, smokerC])

	for agent in agents:
		agent.start()

	for pusher in pushers:
		pusher.start()

	for smoker in smokers:
		smoker.start()

	for agent in agents:
		agent.join()

	for pusher in pushers:
		pusher.join()

	for smoker in smokers:
		smoker.join()

