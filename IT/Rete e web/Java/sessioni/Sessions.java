/*
file Sessions.java
compilare con: javac -cp ".:${JETTY_HOME}/lib/*" *.java 
eseguire con:  java -cp ".:${JETTY_HOME}/lib/*:${JETTY_HOME}/lib/logging/*" Sessions
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Sessions {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		/* abilita la gestione delle sessioni */

		ServletContextHandler handler = new ServletContextHandler(ServletContextHandler.SESSIONS);

		handler.addServlet(HomeServlet.class, "");
		jetty.setHandler(handler);

		jetty.start();
		jetty.join();
	}
}

