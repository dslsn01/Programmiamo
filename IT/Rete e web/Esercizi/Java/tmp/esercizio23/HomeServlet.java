import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class HomeServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		try {
			HttpSession session = request.getSession(false);
			if (session == null) {
				RequestDispatcher view = request.getRequestDispatcher("login.html");
				view.forward(request, response);
			}
			else {
				String username = (String)session.getAttribute("username");
				if (username.equals("admin")) {
					RequestDispatcher view = request.getRequestDispatcher("admin-console.html");
					view.forward(request, response);
				}
				else {
					response.setContentType("text/html");
					response.setStatus(HttpServletResponse.SC_OK);

					PrintWriter out = response.getWriter();

					String html = "Benvenuto, " + username + "!";
					html += "<br/>";
					html += "<a href='logout'>Esci</a>";

					out.write(html);
				}
			}
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		catch (ServletException e) {
			e.printStackTrace();
		}
	}
}

