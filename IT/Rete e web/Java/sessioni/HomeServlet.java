/* file HomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		HttpSession session = request.getSession(true);
		Date login = (Date)session.getAttribute("login");

		String html = "";
		SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

		/* se la sessione non si trova, crea una nuova sessione dove memorizza l'ora corrente */

		if (login == null) {
			login = new Date();
			session.setAttribute("login", login);
			html = "Ti sei connesso il " + sdf.format(login);
		}
		else {
			/* se presente, visualizza l'ora dell'ultima connessione in sessione */
			html = "Ultima connessione: " + sdf.format(login);
		}

		response.setContentType("text/html");
		response.setStatus(HttpServletResponse.SC_OK);
		PrintWriter out = response.getWriter();
		out.write(html);
	}
}

