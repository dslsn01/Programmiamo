/* file StackVsQueue.java */

import java.util.LinkedList;

public class StackVsQueue {
	public static void main(String [] args) {
		/* crea una pila di tre elementi */

		LinkedList<String> stack = new LinkedList<String>();

		// push() -> addFirst()

		stack.push("elefante");
		stack.push("giraffa");
		stack.push("tigre");

		System.out.println(stack);

		// pop() -> removeFirst()

		/* estrae dalla lista l'ultimo elemento aggiunto */

		String elem1 = stack.pop();

		System.out.println(elem1);
		System.out.println(stack);

		/* crea una coda di tre elementi */

		LinkedList<String> queue = new LinkedList<String>();

		queue.offer("cane");
		queue.offer("lupo");
		queue.offer("orso");

		System.out.println(queue);

		/* estrae dalla coda il primo elemento aggiunto */

		String elem2 = queue.poll();

		System.out.println(elem2);
		System.out.println(queue);
	}
}

