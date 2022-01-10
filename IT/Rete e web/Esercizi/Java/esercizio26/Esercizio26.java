/* file Esercizio26.java */

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Esercizio26 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler(ServletContextHandler.SESSIONS);
		handler.setResourceBase(".");

		handler.addServlet(HomeServlet.class, "");
		handler.addServlet(WelcomeServlet.class, "/welcome");
		handler.addServlet(LogoutServlet.class.getName(), "/logout");
		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

