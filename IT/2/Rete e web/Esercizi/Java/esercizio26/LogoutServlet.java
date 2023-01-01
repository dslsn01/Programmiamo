/* file LogoutServlet.java */

import java.util.Date;
import java.io.IOException;
import java.text.SimpleDateFormat;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class LogoutServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		try {
			HttpSession session = request.getSession();
			session.invalidate();

			SimpleDateFormat fmt = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
			String html = "<!DOCTYPE html>" +
						  "<html>" +
						   "<body style=\"text-align: center\">" +
							"<div>Logout effettuato il " + fmt.format(new Date()) + ".</div>" +
						   "</body>" +
						  "</html>";

			response.setContentType("text/html");
			response.getWriter().write(html);

			return;
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

