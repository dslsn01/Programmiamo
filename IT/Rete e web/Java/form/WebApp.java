/*
file WebApp.java
compilare con: javac -cp ".:${JETTY_HOME}/lib/*" *.java 
eseguire con:  java -cp ".:${JETTY_HOME}/lib/*:${JETTY_HOME}/lib/logging/*" WebApp
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class WebApp {
	public static void main(String [] args) {
		try {
			Server jetty = new Server(8080);

			ServletContextHandler handler = new ServletContextHandler();
			handler.setResourceBase(".");

			handler.addServlet(HomeServlet.class, "/home");
			handler.addServlet(DefaultServlet.class, "/*");

			jetty.setHandler(handler);

			jetty.start();
			jetty.join();
		}
		catch (Exception e) {
			System.err.println(e);
		}
	}
}

