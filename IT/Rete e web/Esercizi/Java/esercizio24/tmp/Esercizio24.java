/* file Esercizio24.java */

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Esercizio24 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler();
		handler.setResourceBase(".");

		handler.addServlet(HomeServlet.class, "");
		handler.addServlet(WelcomeServlet.class, "/welcome");
		handler.addServlet(LogoutServlet.class, "/logout");
		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

