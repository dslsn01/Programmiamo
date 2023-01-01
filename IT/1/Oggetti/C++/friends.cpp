/*
file friends.cpp
compilare con: g++ friends.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

class Server {
	private:
		void restart();

	public:
		void login();

	/* la classe Sysadmin è "friend" di Server */

	friend class Sysadmin;
};

void Server::restart() {
	cout << "Riavvio del server..." << endl;
}

void Server::login() {
	cout << "L'utente si è autenticato sul sistema." << endl;
}

class Sysadmin {
	public:
		void doWork(Server&);
};

void Sysadmin::doWork(Server& server) {
	cout << "Manutenzione necessaria per il sistema operativo." << endl;
	server.restart();
}

class User {
	public:
		void doWork(Server&);
};

void User::doWork(Server& server) {
	server.login();
}

int main()
{
	Server server;

	User user;
	user.doWork(server);

	Sysadmin sysadmin;
	sysadmin.doWork(server);
}

