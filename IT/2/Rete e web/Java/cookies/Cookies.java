/*
file Cookies.java
compilare con: javac -cp ".:${JETTY_HOME}/lib/*" *.java 
eseguire con:  java -cp ".:${JETTY_HOME}/lib/*:${JETTY_HOME}/lib/logging/*" Cookies
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Cookies {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler();
		handler.addServlet(HomeServlet.class, "");
		jetty.setHandler(handler);

		jetty.start();
		jetty.join();
	}
}

