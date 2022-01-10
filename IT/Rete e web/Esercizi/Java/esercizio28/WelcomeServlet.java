/* file WelcomeServlet.java */

import java.io.IOException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class WelcomeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String username = request.getParameter("username");
			String password = request.getParameter("password");

			if (username.equals(password)) {
				HttpSession session = request.getSession(true);
				session.setAttribute("username", username);
				response.sendRedirect(request.getContextPath() + "/");
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

