import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;

public class Esercizio23 {
	public static void main(String [] args) throws Exception {
		Server jetty = new Server(8080);

		ServletContextHandler handler = new ServletContextHandler(ServletContextHandler.SESSIONS);

		ServletHolder home = handler.addServlet(HomeServlet.class.getName(), "");
		home.setInitParameter("resourceBase", ".");
		home.setInitParameter("pathInfoOnly","true");

		ServletHolder welcome = handler.addServlet(WelcomeServlet.class.getName(), "/welcome");
		welcome.setInitParameter("resourceBase", ".");
		welcome.setInitParameter("pathInfoOnly","true");

		ServletHolder logout = handler.addServlet(LogoutServlet.class.getName(), "/logout");
		logout.setInitParameter("resourceBase", ".");
		logout.setInitParameter("pathInfoOnly","true");

		DefaultServlet servlet = new DefaultServlet();
		ServletHolder holder = handler.addServlet(servlet.getClass().getName(), "/*");
		holder.setInitParameter("resourceBase", ".");
		holder.setInitParameter("pathInfoOnly","true");

		jetty.setHandler(handler);
		jetty.start();
		jetty.join();
	}
}

