/* file LanguageServlet.java */

import java.io.IOException;
import jakarta.servlet.ServletException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class LangServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String lang = request.getParameter("lang");
			Cookie langCookie = new Cookie("lang", lang);
			langCookie.setMaxAge(60*60);
			response.addCookie(langCookie);

			response.sendRedirect(request.getContextPath() + "/");
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

