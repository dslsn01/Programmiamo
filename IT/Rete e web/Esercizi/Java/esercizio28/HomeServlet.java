/* file HomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		try {
			HttpSession session = request.getSession(false);
			if (session == null) {
				RequestDispatcher view = request.getRequestDispatcher("index.html");
				view.forward(request, response);
			}
			else {
				String username = (String)session.getAttribute("username");
				response.setContentType("text/html");
				response.setStatus(HttpServletResponse.SC_OK);
				PrintWriter out = response.getWriter();

				String html = "<!DOCTYPE html>" +
							  "<html>" +
							   "<body style=\"text-align: center\">" +
							    "<div style=\"font-weight: bold;\">Benvenuto, " + username + "!</div>" +
							    "<a href=\"logout\">Esci</a>" +
							   "</body>" +
							  "</html>";

				out.write(html);
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
		catch (ServletException e) {
			System.err.println(e);
		}
	}
}

