/* file Esercizio30.java */

import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextPane;
import javax.swing.text.Style;
import javax.swing.text.StyleContext;
import javax.swing.text.StyledDocument;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.StyleConstants;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Stack;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio30 {
	private static class KPad extends JPanel implements ActionListener {
		private Calc calc;
		private String [] btns = { "7", "8", "9", "\u00F7", "CE", "C", "4", "5", "6", "\u2217", "(", ")", "1", "2", "3", "-", "x\u00b2", "\u221A", "0", ".", "%", "+", "=" };

		public KPad(JFrame parent) {
			super(new GridBagLayout());
			this.calc = (Calc) parent;
			int r = 0;
			int c = 0;
			for (String btn : btns) {
				JButton b = new JButton(btn);
				b.addActionListener(this);
				GridBagConstraints gbc = new GridBagConstraints();
				gbc.gridx = c;
				gbc.gridy = r;
				gbc.fill = GridBagConstraints.BOTH;
				if (!btn.equals("=")) c++;
				else {
					gbc.gridwidth = 2;
					c += 2;
				}
				add(b, gbc);

				if (c % 6 == 0) {
					c = 0;
					r++;
				}
			}
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String s = ((JButton) e.getSource()).getText();
			StyledDocument sd = calc.scr.getStyledDocument();
			if (s.equals("=")) {
				try {
					String expr = calc.scr.getText();
					List<String> rpn = calc.infixToRpn(expr);
					Double result = calc.evaluate(rpn);
					this.calc.scr.setText(String.valueOf(result));
				}
				catch (Exception ex) {
					calc.scr.setText("Espressione malformata");
				}
			}
			else if (s.equals("C")) {
				this.calc.scr.setText("");
			}
			else if (s.equals("CE")) {
				String onsc = calc.scr.getText();
				String lastN = "";
				Matcher m = Pattern.compile("[\\d]+(\\.[\\d]+)?").matcher(onsc);
				while (m.find()) lastN = m.group();
				int i = onsc.lastIndexOf(lastN);
				this.calc.scr.setText(onsc.substring(0, i));
			}
			else {
				// quadrato
				if (s.equals("x\u00b2")) s = "\u00b2";
				try {
					Style style = sd.getStyle(StyleContext.DEFAULT_STYLE);
					sd.insertString(sd.getLength(), s, style);
				}
				catch (Exception ex) {
					System.err.println(ex);
				}
			}
		}
	}

	private static class Calc extends JFrame {
		// mappa degli operatori con precedenza e associativà
		private static Map<String, int[]> ops = new HashMap<String, int[]>() {
			{
				put("+", new int[] {0, 0});
				put("-", new int[] {0, 0});
				put("/", new int[] {1, 0});
				put("*", new int[] {1, 0});
				put("^", new int[] {2, 1});
			}
		};

		public JTextPane scr;

		public Calc() {
			getContentPane().setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
			StyleContext ctx = new StyleContext();
			StyledDocument doc = new DefaultStyledDocument(ctx);
			Style style = ctx.getStyle(ctx.DEFAULT_STYLE);
			StyleConstants.setAlignment(style, StyleConstants.ALIGN_RIGHT);
			this.scr = new JTextPane(doc);
			add(scr);
			add(new KPad(this));
			pack();
			//setSize(new Dimension(300, 300));
			setSize(new Dimension(280, 225));
			setResizable(false);
			setTitle("Calcolatrice");
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setVisible(true);
		}

		public static List<String> infixToRpn(String expr) throws Exception {
			expr = expr.replace("\u00b2", "^2").replace("\u221A", "sqrt").replace("\u00F7", "/").replace("\u2217", "*");
			Matcher m = Pattern.compile("^[-+]?[\\d]+(\\.[\\d]+)?%?|[\\d]+(\\.[\\d]+)?%?|sqrt[\\d]+(\\.[\\d]+)?|[()*/+-\\^]").matcher(expr);
			List<String> tokens = new ArrayList<>();

			while (m.find()) {
				tokens.add(m.group());
			}

			List<String> rpn = new ArrayList<>();
			Stack<String> stackOps = new Stack<>();

			for (String token : tokens) {
				if (ops.containsKey(token)) {
					int [] prop = ops.get(token);
					int prec = prop[0];
					int ass = prop[1];

					while (!stackOps.empty() && ops.containsKey(stackOps.peek())) {
						int opPrec = ops.get(stackOps.peek())[0];
						if (prec < opPrec || (prec == opPrec && ass == 0)) {
							rpn.add(stackOps.pop());
						}
						break;
					}
					stackOps.push(token);
				}
				else if (token.equals("(")) {
					stackOps.push(token);
				}
				else if (token.equals(")")) {
					while (!stackOps.empty() && !stackOps.peek().equals("(")) {
						rpn.add(stackOps.pop());
					}
					stackOps.pop();
				}
				else { // numero o funzione
					// se si tratta di una funzione, la valuta e salva subito il risultato
					if (token.indexOf("sqrt") == 0) {
						Matcher f = Pattern.compile("[\\d]+(\\.[\\d]+)?").matcher(token);
						if (f.find()) {
							String s = f.group();
							Double d = Double.valueOf(s);
							Double res = Math.sqrt(d);
							token = String.valueOf(res);
						}
					}
					rpn.add(token);
				}
			}

			while (!stackOps.empty()) {
				rpn.add(stackOps.pop());
			}

			return rpn;
		}

		public static Double evaluate(List<String> rpn) throws Exception {
			Stack<String> stack = new Stack<>();
			for (String token : rpn) {
				if (!ops.containsKey(token)) {
					stack.push(token);
				}
				else {
					String s = stack.pop();
					Double o2 = 0.0;
					Double o1 = Double.valueOf(stack.pop());

					if (!s.endsWith("%")) o2 = Double.valueOf(s);
					else {
						// calcola la percentuale
						s = s.replace("%", "");
						o2 = o1/100*Double.valueOf(s);
					}

					Double result = 0.0;
					if (token.equals("+")) result = o1 + o2;
					else if (token.equals("-")) result = o1 - o2;
					else if (token.equals("*")) result = o1 * o2;
					else if (token.equals("/")) result = o1 / o2;
					else if (token.equals("^")) result = Math.pow(o1, o2);

					stack.push(String.valueOf(result));
				}
			}

			return Double.valueOf(stack.pop());
		}
	}

	public static void main(String [] args) {
		Calc calc = new Calc();
	}
}

