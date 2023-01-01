/* file WelcomeServlet.java */

import java.io.IOException;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class WelcomeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String p = request.getParameter("name");
			String username = !p.isEmpty() ? p : "ignoto";

			Cookie userCookie = new Cookie("username", username);
			userCookie.setMaxAge(60*60); // cookie valido per un'ora
			response.addCookie(userCookie);

			response.sendRedirect(request.getContextPath() + "/");
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

