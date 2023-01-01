/*
file Esercizio12.java
*/

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;

public class Esercizio12 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler();
		handler.setResourceBase(".");

		ServletHolder details = handler.addServlet(SimpleServlet.class, "/details");
		details.setInitParameter("htmlPage", "dettagli.html");

		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

