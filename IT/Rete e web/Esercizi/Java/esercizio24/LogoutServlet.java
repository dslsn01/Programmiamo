/* file LogoutServlet.java  */

import java.util.Date;
import java.io.IOException;
import java.text.SimpleDateFormat;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class LogoutServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		try {
			boolean _cookie = false;
			Cookie [] cookies = request.getCookies();
			if (cookies != null) {
				for (Cookie cookie : cookies) {
					if (cookie.getName().equals("username")) {
						_cookie = true;
						cookie.setMaxAge(0);
						response.addCookie(cookie);
						break;
					}
				}
			}

			if (_cookie) {
				SimpleDateFormat fmt = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
				String html = "<!DOCTYPE html>" +
							  "<html>" +
							   "<body style=\"text-align: center\">" +
								"<div>Logout effettuato il " + fmt.format(new Date()) + ".</div>" +
							   "</body>" +
							  "</html>";

				response.setContentType("text/html");
				response.getWriter().write(html);
			}
			else {
				response.sendRedirect("/");
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

