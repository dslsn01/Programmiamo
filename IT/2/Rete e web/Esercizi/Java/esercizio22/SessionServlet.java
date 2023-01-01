/* file SessionServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class SessionServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		HttpSession session = request.getSession(true);
		Integer counter = (Integer)session.getAttribute("counter");

		try {
			counter = counter == null ? 1 : counter.intValue() + 1;

			session.setAttribute("counter", counter);
			response.setStatus(HttpServletResponse.SC_OK);

			PrintWriter out = response.getWriter();
			String html = "<!DOCTYPE html>" +
						  "<html>" +
						   "<body>" +
						    "<div>Sei passato a trovarci " + counter + " volte!</div>" +
						   "</body>" +
						  "</html>";

			out.write(html);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

