/* file SummaryServlet.java */

import java.io.PrintWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.HashMap;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class SummaryServlet extends HttpServlet {
	// listino prezzi
	private Map<String, Double> prices = new HashMap<String, Double>();

	@Override
	public void init() throws ServletException { 
		// prezzi degli smartphone
		prices.put("Samsung Galaxy", 500.0);
		prices.put("Apple iPhone", 800.0);
		prices.put("Huawei P", 200.0);
		prices.put("Sony Xperia", 250.0);

		// prezzi dei computer portatili
		prices.put("HP Pavilion", 1300.0);
		prices.put("Lenovo Thinkpad", 1200.0);
		prices.put("Fujitsu Lifebook", 1100.0);

		// prezzi dei televisori
		prices.put("Philips 22p", 150.0);
		prices.put("Philips 32p", 220.0);
		prices.put("Sony 32p", 380.0);
		prices.put("Samsung 49p", 600.0);
		prices.put("Sony 55p", 1200.0);
	}

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		String smartphone = request.getParameter("smartphone");
		String notebook = request.getParameter("notebook");
		String tv = request.getParameter("tv");

		String html = "<!DOCTYPE html>" +
					  "<html>" +
					    "<body style=\"text-align: center\">" +
					      "<h2>Riassunto acquisti (IVA inclusa):</h2>";

		double total = 0.0;

		try {
			if (!smartphone.isEmpty()) {
				double price = prices.get(smartphone);
				total += price;
				html += "<div>" + smartphone +" = " + price + " euro</div>";
			}

			if (!notebook.isEmpty()) {
				double price = prices.get(notebook);
				total += price;
				html += "<div>" + notebook + " = " + price + " euro</div>";
			}

			if (!tv.isEmpty()) {
				double price = prices.get(tv);
				total += price;
				html += "<div>" + tv + " = " + price + " euro</div>";
			}

			html += "<br/>";

			if (total != 0.0) {
				html += "<div style=\"font-weight: bold\">Totale spesa: " + total + " euro.</div>";
			}
			else {
				html = "<div style=\"font-weight: bold\">Non hai effettuato nessun acquisto.";
			}

			html += "</body></html>";

			response.setStatus(HttpServletResponse.SC_OK);
			PrintWriter out = response.getWriter();
			out.write(html);
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

