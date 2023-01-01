/* file SimpleServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SimpleServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		try {
			response.setContentType("text/html");
			response.setStatus(HttpServletResponse.SC_OK);

			PrintWriter out = response.getWriter();

			String html = "<!DOCTYPE html>" + 
						  "<html>" +
						   "<head>" +
						    "<title>La mia pagina web</title>" +
						   "</head>" +
						   "<body>" +
						    "<p>Ciao, mondo!</p>" +
						   "</body>" +
						  "</html>";

			out.write(html);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

