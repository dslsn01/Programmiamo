/* file SummaryServlet.java */

import java.io.PrintWriter;
import java.io.IOException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletConfig;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SummaryServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String name = request.getParameter("nome");
			String surname = request.getParameter("cognome");
			String address = request.getParameter("indirizzo");
			String phone = request.getParameter("telefono");
			String email = request.getParameter("email");
			String credit_card = request.getParameter("email");

			String html = "<!DOCTYPE html>" +
						  "<html>" +
						   "<body style=\"text-align: center; \">" +
						    "<p>Nome: " + name + "</p>" +
						    "<p>Cognome: " + surname + "</p>" +
						    "<p>Indirizzo: " + address + "</p>" +
						    "<p>Telefono: " + phone + "</p>" +
						    "<p>Email: " + email + "</p>" +
						    "<p>Carta di credito: " + credit_card + "</p>" +
						   "</body>" +
						  "</html>";

			PrintWriter out = response.getWriter();
			out.write(html);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

