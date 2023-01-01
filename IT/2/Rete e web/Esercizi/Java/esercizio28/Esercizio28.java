/* file Esercizio28.java */

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;

public class Esercizio28 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler(ServletContextHandler.SESSIONS);
		handler.setResourceBase(".");

		ServletHolder home = handler.addServlet(HomeServlet.class, "");

		handler.addServlet(WelcomeServlet.class, "/welcome");
		handler.addServlet(LogoutServlet.class.getName(), "/logout");
		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

