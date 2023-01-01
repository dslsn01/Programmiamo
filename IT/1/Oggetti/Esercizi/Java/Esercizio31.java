/* file Esercizio31.java */

import java.io.Console;
import java.util.List;
import java.util.ArrayList;

/* la classe Book rappresenta un libro */
class Book {
	private String title;
	private String author;
	private String year;

	public Book(String title, String author, String year) {
		this.setTitle(title);
		this.setAuthor(author);
		this.setYear(year);
	}

	public String getTitle() {
		return this.title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return this.author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getYear() {
		return this.year;
	}

	public void setYear(String year) {
		this.year = year;
	}

	@Override
	public String toString() {
		return "\"" + this.title + "\" (" + this.year + "), di " + this.author;
	}
}

class Library {
	private List<Book> titles = new ArrayList<Book>();

	public Library() {
		this.titles.add(new Book("Ulisse", "James Joyce", "1922"));
		this.titles.add(new Book("On the road", "Jack Kerouac", "1951"));
		this.titles.add(new Book("Il nome della rosa", "Umberto Eco", "1980"));
	}

	public void loop() {
		System.out.println("+++++++ Benvenuto in biblioteca +++++++");

		// stampa i libri disponibili
		printLib();

		Console console = System.console();
		while (true) {
			System.out.println("a. Prendi un libro in prestito\nb. Aggiungi un nuovo libro\nc. Esci" + System.lineSeparator());

			String opt = console.readLine();

			if ("a".equals(opt)) {
				System.out.println("Prendi un libro in prestito.");
				String title = console.readLine("Titolo: ");

				boolean f = false;

				for (Book book : titles) {
					if (title.toLowerCase().equals(book.getTitle().toLowerCase())) {
						System.out.println("Trovato il libro " + book + "." + System.lineSeparator());
						f = true;
						break;
					}
				}

				if (!f) System.out.println("Libro non trovato!\n");
			}
			/* salva un nuovo libro nella biblioteca */
			else if ("b".equals(opt)) {
				System.out.println("Aggiungi un nuovo libro.");

				String title = console.readLine("Titolo: ");
				String author = console.readLine("Autore: ");
				String year = console.readLine("Anno: ");

				Book book = new Book(title, author, year);
				titles.add(book);

				System.out.println(System.lineSeparator() + "Aggiunto il libro " + book + System.lineSeparator());
				printLib();
			}
			else if ("c".equals(opt)) {
				System.out.println("Buona lettura, speriamo di rivederti presto.");
				break;
			}
			else {
				System.out.println("Operazione sconosciuta!\n");
			}
		}
	}

	private void printLib() {
		System.out.println("Libri disponibili: " + System.lineSeparator());
		int i = 1;
		for (Book b : titles) {
			System.out.println(i + ". " + b + ".");
			i++;
		}

		System.out.print(System.lineSeparator());
	}
}

public class Esercizio31 {
	public static void main(String [] args) {
		Library library = new Library();

		// apre la biblioteca
		library.loop();
	}
}

