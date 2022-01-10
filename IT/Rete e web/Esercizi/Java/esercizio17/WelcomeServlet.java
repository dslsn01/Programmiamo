/* file WelcomeServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class WelcomeServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String p = request.getParameter("name");
			String name = !p.isEmpty() ? p : "ignoto";

			response.setContentType("text/html");
			response.setStatus(HttpServletResponse.SC_OK);

			String html = "<!DOCTYPE html>" +
						  "<html>" +
						   "<body style=\"text-align: center\">" +
						    "<div style=\"font-weight: bold;\">Benvenuto, " + name + "!</div>" + 
						   "</body>" +
						  "</html>";

			PrintWriter out = response.getWriter();
			out.write(html);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

