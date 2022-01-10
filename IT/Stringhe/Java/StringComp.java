/* file StringComp.java */

public class StringComp {
	public static void main(String [] args) {
		String s1 = new String("foo");
		String s2 = new String("foo");

		/* s1 e s2 sono uguali? */

		System.out.println("\"" + s1 + "\" == \"" + s2 + "\" ? " + (s1 == s2));
		System.out.println("\"" + s1 + "\".equals(\"" + s2 + "\") ? " + s1.equals(s2));

		String s3 = "bar";
		String s4 = "bar";

		/* s3 e s4 sono uguali? */

		System.out.println("\"" + s3 + "\" == \"" + s3 + "\" ? " + (s3 == s4));
		System.out.println("\"" + s3 + "\".equals(\"" + s4 + "\") ? " + s3.equals(s4));
	}
}

