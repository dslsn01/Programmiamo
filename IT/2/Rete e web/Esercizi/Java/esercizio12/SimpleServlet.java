/* file SimpleServlet.java */

import java.io.IOException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletConfig;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SimpleServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		try {
			ServletConfig configuration = getServletConfig();
			String htmlPage = configuration.getInitParameter("htmlPage");
			RequestDispatcher view = request.getRequestDispatcher(htmlPage);
			view.forward(request, response);
		}
		catch (ServletException e) {
			System.err.println(e);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

