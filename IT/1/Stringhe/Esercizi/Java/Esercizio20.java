/* file Esercizio20.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio20 {
	public static void main(String [] args) {
		String si = "1 234 567.89";
		String us = null;
		String it = null;

		Pattern pattern = Pattern.compile("[\\s]");
		Matcher matcher = pattern.matcher(si);
		StringBuffer sb = new StringBuffer();

		while (matcher.find()) {
			matcher.appendReplacement(sb, ",");
		}

		matcher.appendTail(sb);
		us = sb.toString();

		pattern = Pattern.compile("[\\s\\.]");
		matcher = pattern.matcher(si);
		sb = new StringBuffer();

		while (matcher.find()) {
			String rep = " ".equals(matcher.group()) ? "." : ",";
			matcher.appendReplacement(sb, rep);
		}

		matcher.appendTail(sb);
		it = sb.toString();

		System.out.println("Stile SI: " + si);
		System.out.println("Stile US: " + us);
		System.out.println("Stile IT: " + it);
	}
}

