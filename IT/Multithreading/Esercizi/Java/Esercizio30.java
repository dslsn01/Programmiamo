/* file Esercizio30.java */

import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Esercizio30 {
	private Semaphore agentSem = new Semaphore(1);
	private Lock mutex = new ReentrantLock();

	private Semaphore tobacco = new Semaphore(0);
	private Semaphore paper = new Semaphore(0);
	private Semaphore matches = new Semaphore(0);

	private boolean isTobacco = false;
	private boolean isPaper = false;
	private boolean isMatches = false;

	private Semaphore tobaccoSem = new Semaphore(0);
	private Semaphore paperSem = new Semaphore(0);
	private Semaphore matchesSem = new Semaphore(0);

	// sezione dei thread agenti

	// agente che distribuisce tabacco e carta
	class TobaccoPaperAgent implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					agentSem.acquire();
					System.out.println("L'agente mette tabacco e carta sul tavolo.");
					tobacco.release();
					paper.release();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// agente che distribuisce tabacco e fiammiferi
	class TobaccoMatchesAgent implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					agentSem.acquire();
					System.out.println("L'agente mette tabacco e fiammiferi sul tavolo.");
					tobacco.release();
					matches.release();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// agente che distribuisce carta e fiammiferi
	class PaperMatchesAgent implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					agentSem.acquire();
					System.out.println("L'agente mette carta e fiammiferi sul tavolo.");
					paper.release();
					matches.release();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	/* sezione dei thread pusher */

	// pusher che distribuisce il tabacco 
	class TobaccoPusher implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					tobacco.acquire();
					System.out.println("Spacciatore di tabacco all'opera.");
					mutex.lock();
					try {
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
					} finally {
						mutex.unlock();
					}
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// pusher che distribuisce la carta
	class PaperPusher implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					paper.acquire();
					System.out.println("Spacciatore di carta all'opera.");
					mutex.lock();
					try {
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
					} finally {
						mutex.unlock();
					}
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	// pusher che distribuisce i fiammiferi
	class MatchesPusher implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					matches.acquire();
					System.out.println("Spacciatore di fiammiferi all'opera.");
					mutex.lock();
					try {
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
					} finally {
						mutex.unlock();
					}
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	/* sezione dei thread fumatori */

	// fumatore che detiene il tabacco
	class TobaccoSmoker implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					tobaccoSem.acquire();
					int pause = ThreadLocalRandom.current().nextInt(5, 10+1);
					Thread.sleep(pause*1000);
					System.out.println("Il fumatore con il tabacco ha finito di prepararsi la sigaretta.");
					agentSem.release();
					System.out.println("Il fumatore con il tabacco sta fumando...");
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	class PaperSmoker implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					paperSem.acquire();
					int pause = ThreadLocalRandom.current().nextInt(5, 10+1);
					Thread.sleep(pause*1000);
					System.out.println("Il fumatore con la carta  ha finito di prepararsi la sigaretta.");
					agentSem.release();
					System.out.println("Il fumatore con la carta sta fumando...");
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	class MatchesSmoker implements Runnable {
		@Override
		public void run() {
			while (true) {
				try {
					matchesSem.acquire();
					int pause = ThreadLocalRandom.current().nextInt(5, 10+1);
					Thread.sleep(pause*1000);
					System.out.println("Il fumatore con i fiammiferi ha finito di prepararsi la sigaretta.");
					agentSem.release();
					System.out.println("Il fumatore con i fiammiferi sta fumando...");
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	/* il costruttore avvia l'applicazione */

	public Esercizio30() {
		Thread [] agents = new Thread[3];

		Thread agentA = new Thread(new TobaccoPaperAgent());
		Thread agentB = new Thread(new TobaccoMatchesAgent());
		Thread agentC = new Thread(new PaperMatchesAgent());

		agents[0] = agentA;
		agents[1] = agentB;
		agents[2] = agentC;

		Thread [] pushers = new Thread[3];

		Thread pusherA = new Thread(new TobaccoPusher());
		Thread pusherB = new Thread(new PaperPusher());
		Thread pusherC = new Thread(new MatchesPusher());

		pushers[0] = pusherA;
		pushers[1] = pusherB;
		pushers[2] = pusherC;

		Thread [] smokers = new Thread[3];

		Thread smokerA = new Thread(new TobaccoSmoker());
		Thread smokerB = new Thread(new PaperSmoker());
		Thread smokerC = new Thread(new MatchesSmoker());

		smokers[0] = smokerA;
		smokers[1] = smokerB;
		smokers[2] = smokerC;

		for (Thread agent : agents) {
			agent.start();
		}

		for (Thread pusher : pushers) {
			pusher.start();
		}

		for (Thread smoker : smokers) {
			smoker.start();
		}
	}

	public static void main(String [] args) {
		new Esercizio30();
	}
}

