/* file HomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLEncoder;
import java.net.URLDecoder;
import java.text.SimpleDateFormat;
import java.util.Date;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		Cookie [] cookies = request.getCookies();

		String login = "";
		if (cookies != null) {
			for (Cookie cookie : cookies) {
				if (cookie.getName().equals("login")) {
					login = cookie.getValue();
					break;
				}
			}
		}

		String html = "";

		/* se il cookie manca, spedisce un nuovo cookie con la data di connessione */

		if (login.isEmpty()) {
			Date loginDate = new Date();
			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
			login = sdf.format(loginDate);

			// imposta un cookie valido per un'ora
			Cookie loginCookie = new Cookie("login", URLEncoder.encode(login, "UTF-8"));
			loginCookie.setMaxAge(60*60);
			response.addCookie(loginCookie);

			html = "Ti sei connesso il " + login;
		}
		else {
			/* se si trova il cookie, visualizza l'ultima connessione memorizzata */
			html = "Ultima connessione: " + URLDecoder.decode(login, "UTF-8");
		}

		response.setContentType("text/html");
		response.setStatus(HttpServletResponse.SC_OK);
		PrintWriter out = response.getWriter();
		out.write(html);
	}
}

