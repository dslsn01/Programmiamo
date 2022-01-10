/* file ThemeServlet.java */

import java.io.IOException;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class ThemeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String bgcol = request.getParameter("bgcol");
			Cookie bgCookie = new Cookie("bgcol", bgcol);
			bgCookie.setMaxAge(60*60);
			response.addCookie(bgCookie);

			response.sendRedirect(request.getContextPath() + "/");
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

