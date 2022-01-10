/* file Esercizio14.java */

import java.util.List;
import java.util.Arrays;
import java.util.stream.Stream;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Esercizio14 {
	public static void main(String [] args) {
		List<String> li = Arrays.asList("Nel", "bel", "mezzo", "del", "cammin", "di", "nostra", "vita");

		String s = li.stream().map(Object::toString).collect(Collectors.joining(" "));

		System.out.println(li);
		System.out.printf("\"%s\"\n", s);
	}
}

