/* file SimpleServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.text.SimpleDateFormat;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SimpleServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) {
		try {
			response.setContentType("text/html");
			response.setStatus(HttpServletResponse.SC_OK);

			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
			String [] parts = sdf.format(new Date()).split(" ");

			PrintWriter out = response.getWriter();
			String html = "Ti sei connesso il " + parts[0] + " ore " + parts[1] + ".";

			out.write(html);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

