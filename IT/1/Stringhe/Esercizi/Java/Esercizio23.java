/* file Esercizio23.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Esercizio23 {
	public static void main(String [] args) {
		String s = "qui. quo. qua.";

		System.out.println(s);

		Pattern pattern = Pattern.compile("(^[\\w]|\\.\\s[\\w])");
		Matcher matcher = pattern.matcher(s);
		StringBuffer sb = new StringBuffer();

		while (matcher.find()) {
			matcher.appendReplacement(sb, matcher.group(1).toUpperCase());
		}

		matcher.appendTail(sb);

		s = sb.toString();
		System.out.println(s);
	}
}

