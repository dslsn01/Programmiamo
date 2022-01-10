/* file HomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String username = request.getParameter("username");
			String password = request.getParameter("password");

			if (username.equals(password)) {
				response.setContentType("text/html");
				response.setStatus(HttpServletResponse.SC_OK);

				PrintWriter out = response.getWriter();
				String html = "<!DOCTYPE html>" +
							  "<html>" +
							   "<body>" +
							    "<p style=\"font-weight: bold;\">Benvenuto, " + username + "!</p>" +
							   "</body>" +
							  "</html>";

				out.write(html);
			}
			else {
				response.sendError(401, "Username / password non corretti!");
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

