/* file TestRegex.java */

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class TestRegex {
	public static void main(String [] args) {
		/* prepara un'espressione regolare, e la compila per essere riutilizzata */

		String regex = "^Ul[iy](?:ss|x)es?$";
		Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);

		String [] s = {"Ulisse", "ulysse", "Ulysses", "ULIXES"};

		for (String name : s) {
			Matcher matcher = pattern.matcher(name);
			if (matcher.matches()) {
				System.out.println("La regex \"" + regex + "\" coincide con il nome \"" + name + "\".");
			}
		}
	}
}

