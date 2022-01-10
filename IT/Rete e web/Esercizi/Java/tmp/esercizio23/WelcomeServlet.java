import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

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
				response.sendError(401, "Username / password errati.");
			}
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

