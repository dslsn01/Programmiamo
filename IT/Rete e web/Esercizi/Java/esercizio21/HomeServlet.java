/* file HomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		String lang = "";
		Cookie [] cookies = request.getCookies();

		if (cookies != null) {
			for (Cookie cookie : cookies) {
				if (cookie.getName().equals("lang")) {
					lang = cookie.getValue();
				}
			}
		}

		try {
			// se manca il cookie, chiede di selezionare la lingua del sito
			if (lang.isEmpty()) {
				RequestDispatcher view = request.getRequestDispatcher("index.html");
				view.forward(request, response);
			}
			else {
				// ...altrimenti visualizza un messaggio di benvenuto nella lingua scelta
				response.setStatus(HttpServletResponse.SC_OK);

				String msg = lang.equals("it") ? "Benvenuto!" : "Welcome!";
				PrintWriter out = response.getWriter();
				String html = "<!DOCTYPE html>" +
							  "<html>" +
							   "<body style=\"text-align: center;\">" +
							    "<div style=\"font-weight: bold;\">" + msg + "</div>" +
							   "</body>" +
							  "</html>";

				out.write(html);
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
		catch (ServletException e) {
			System.err.println(e);
		}
	}
}

