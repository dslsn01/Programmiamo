/* file WelcomeServlet.java */

import java.io.IOException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class WelcomeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String p = request.getParameter("name");
			String username = !p.isEmpty() ? p : "ignoto";

			Cookie userCookie = new Cookie("username", username);
			userCookie.setMaxAge(60*60);
			response.addCookie(userCookie);

			response.sendRedirect(request.getContextPath() + "/");
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

