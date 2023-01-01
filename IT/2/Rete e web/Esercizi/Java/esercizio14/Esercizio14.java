/* file Esercizio14.java */

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;

public class Esercizio14 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler();
		handler.setResourceBase(".");

		handler.addServlet(HomeServlet.class, "");

		ServletHolder details = handler.addServlet(RedirectServlet.class, "/redirect");
		details.setInitParameter("htmlPage", "redirect.html");

		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

