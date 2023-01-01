/* file LinkedVsArrayList.java */

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.ListIterator;

public class LinkedVsArrayList {
	public static void main(String [] args) {
		/* dichiara una lista linkata di interi */

		LinkedList<Integer> list = new LinkedList<Integer>();

		/* dichiara un ArrayList di interi */

		ArrayList<Integer> arrayList = new ArrayList<Integer>();

		for (int i = 0; i < 10000; i++) {
			list.add(i);
		}

		/* garantisce che l'ArrayList possa contenere diecimila elementi */

		arrayList.ensureCapacity(10000);

		for (int i = 0; i < 10000; i++) {
			arrayList.add(i);
		}

		long end = 0;
		long start = 0;

		/* tempo all'inizio dell'iterazione */

		start = System.currentTimeMillis();

		ListIterator<Integer> it = list.listIterator();
		
		while (it.hasNext()) {
			it.next();
			it.remove();
		}
			
		/* tempo alla fine dell'iterazione */
			
		end = System.currentTimeMillis();

		/* tempo complessivo per rimuovere tutti gli elementi della LinkedList con l'iteratore */

		System.out.println(end - start);

		start = System.currentTimeMillis();

		it = arrayList.listIterator();

		while (it.hasNext()) {
			it.next();
			it.remove();
		}

		end = System.currentTimeMillis();

		/* tempo complessivo per rimuovere tutti gli elementi dell'ArrayList con l'iteratore */

		System.out.println(end - start);
	}
}

