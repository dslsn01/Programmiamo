/* file Esercizio17 */

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;

public class Esercizio17 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler();
		handler.setResourceBase(".");

		handler.addServlet(WelcomeServlet.class, "/welcome");
		handler.addServlet(DefaultServlet.class, "/*");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

