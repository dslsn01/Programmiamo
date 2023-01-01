/* file BackEndRatioServlet.java */

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class BackEndRatioServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		try {
			String loan = request.getParameter("loan");
			String debts = request.getParameter("debts");
			String income = request.getParameter("income");
			String nMonths = request.getParameter("nMonths");

			if (!loan.isEmpty() && !income.isEmpty()) {
				try {
					double _loan = Double.parseDouble(loan);
					double _debts = !debts.isEmpty() ? Double.parseDouble(debts) : 0;
					int _nMonths = Integer.parseInt(nMonths);
					double _income = Double.parseDouble(income);

					if (_loan < 500 || _loan > 30000) {
						response.sendError(400, "L'importo del prestito richiesto dev'essere compreso tra 500 e 30000 euro!");
						return;
					}

					// tasso d'interesse annuo del 6,5%
					double taeg = (_loan / 100) * 6.5;

					double payment = ((_loan + taeg) / _nMonths);

					double beratio = ((payment + _debts) / _income) * 100;

					String html = "<!DOCTYPE html>" +
								  "<html>" +
								    "<body style=\"text-align: center\">" +
								     "<div style=\"font-style: italic;\">Riassunto</div><br/>" +
								     "<div>Prestito richiesto: " + loan + " euro</div>" +
								     "<div>Reddito mensile: " + income + " euro</div>" +
								     "<div>Totale debiti pregressi: " + debts + " euro mensili</div>" +
								     "<div>Numero rate desiderato: " + nMonths + " </div><br/>" +
								     "<div style=\"font-weight: bold\">Importo rata mensile: " + payment + " </div>" +
								     "<div>(Alla rata si applica un tasso di interesse annuo globale del 6.5% annuo)</div><br/>";

					if (beratio <= 36) {
						html += "<div style=\"color:green;\">Rapporto debiti / reddito uguale a " + beratio + "%. Possiamo concedere il prestito.</div>";
					}
					else {
						html += "<div style=\"color:red;\">Rapporto debiti / reddito eccessivo (" + beratio + "%). Impossibile concedere il prestito.</div>";
					}

					html += "</body></html>";

					response.setStatus(HttpServletResponse.SC_OK);
					PrintWriter out = response.getWriter();
					out.write(html);

				}
				catch (NumberFormatException e) {
					response.sendError(400, "Inserito un importo scorretto!");
				}
			}
			else {
				response.sendError(400, "Prestito e stipendio non possono essere nulli!");
			}
		}
		catch (IOException e) {
			System.err.println(e);
		}
	}
}

