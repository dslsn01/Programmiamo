/* file LogoutServlet.java  */

import java.util.Date;
import java.io.IOException;
import java.text.SimpleDateFormat;
import javax.servlet.ServletException;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LogoutServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		// System.out.println("LogoutServlet");
		try {
			boolean _cookie = false;
			Cookie [] cookies = request.getCookies();
			if (cookies != null) {
				for (Cookie cookie : cookies) {
					if (cookie.getName().equals("username")) {
						_cookie = true;
						// System.out.println("Pongo il cookie a \"expired\".");
						// cookie.setValue("expired");
						cookie.setMaxAge(0);
						response.addCookie(cookie);
						break;
					}
				}
			}

			// System.out.println("_cookie: " + _cookie);

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
				// RequestDispatcher view = request.getRequestDispatcher("index.html");
				// view.forward(request, response);
				response.sendRedirect("/");
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
		//catch (ServletException e) {
		//	System.err.println(e);
		//}
	}
}

