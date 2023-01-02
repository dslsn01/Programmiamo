/* file TestPackage.java */

package mypackage;

class Foo {
	public void bar() {
		System.out.println("bar baz");
	}
}

public class TestPackage {
	public static void main(String [] args) {
		Foo foo1 = new Foo();
		foo1.bar();

		mypackage.utils.Foo foo2 = new mypackage.utils.Foo();
		foo2.bar();
	}
}
