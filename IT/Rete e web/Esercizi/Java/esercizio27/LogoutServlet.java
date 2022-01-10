/* file LogoutServlet.java */

import java.io.IOException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
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

			RequestDispatcher view = request.getRequestDispatcher("/");
			view.forward(request, response);

			return;
		}
		catch (ServletException e) {
			System.err.println(e);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

