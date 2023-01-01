/*
file Webserver2.java
compilare con: javac -cp ".:${JETTY_HOME}/lib/*" *.java 
eseguire con:  java -cp ".:${JETTY_HOME}/lib/*:${JETTY_HOME}/lib/logging/*" Webserver2
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Webserver2 {
	public static void main(String [] args) {
		try {
			// avvia un server web sulla porta 8080 
			Server jetty = new Server(8080);

			ServletContextHandler handler = new ServletContextHandler();

			/* registra un servlet personalizzato che genera una pagina dinamica di benvenuto */
			handler.addServlet(SimpleServlet.class, "/*");

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

