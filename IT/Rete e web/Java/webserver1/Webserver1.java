/*
file Webserver1.java
compilare con: javac -cp ".:${JETTY_HOME}/lib/*" Webserver1.java 
eseguire con:  java -cp ".:${JETTY_HOME}/lib/*:${JETTY_HOME}/lib/logging/*" Webserver1
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Webserver1 {
	public static void main(String [] args) {
		try {
			// avvia un server web sulla porta 8080 
			Server jetty = new Server(8080);

			ServletContextHandler handler = new ServletContextHandler();
			handler.setResourceBase(".");

			/* registra un servlet di default che serve le pagine html statiche */
			handler.addServlet(DefaultServlet.class, "/*");

			jetty.setHandler(handler);

			// avvia il server web
			jetty.start();
			jetty.join();
		}
		catch (InterruptedException e) {
			System.err.println(e);
		}
		catch (Exception e) {
			System.err.println(e);
		}
	}
}

