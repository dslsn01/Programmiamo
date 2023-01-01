/* file Esercizio32.java */

import java.io.Console;
import java.util.List;
import java.util.ArrayList;

/* la classe Content rappresenta un contenuto generico: un libro, brano o video */
abstract class Content {
	private String title;
	private String year;

	public String getTitle() {
		return this.title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getYear() {
		return this.year;
	}

	public void setYear(String year) {
		this.year = year;
	}
}

class Book extends Content {
	private String author;

	public Book(String title, String author, String year) {
		this.setTitle(title);
		this.setAuthor(author);
		this.setYear(year);
	}

	public String getAuthor() {
		return this.author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	@Override
	public String toString() {
		return "\"" + this.getTitle() + "\" (" + this.getYear() + "), di " + this.author;
	}
}

class Song extends Content {
	private String author;
	private String singer;

	public Song(String title, String author, String singer, String year) {
		this.setTitle(title);
		this.setAuthor(author);
		this.setSinger(singer);
		this.setYear(year);
	}

	public String getAuthor() {
		return this.author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getSinger() {
		return this.singer;
	}

	public void setSinger(String singer) {
		this.singer = singer;
	}

	@Override
	public String toString() {
		return "\"" + this.getTitle() + "\" (" + this.getYear() + "), scritta da " + this.author + " e cantata da " + this.singer;
	}
}

class Film extends Content {
	private String director;
	private String screenwriter;

	public Film(String title, String director, String screenwriter, String year) {
		this.setTitle(title);
		this.setDirector(director);
		this.setScreenwriter(screenwriter);
		this.setYear(year);
	}

	public String getDirector() {
		return this.director;
	}

	public void setDirector(String director) {
		this.director = director;
	}

	public String getScreenwriter() {
		return this.screenwriter;
	}

	public void setScreenwriter(String screenwriter) {
		this.screenwriter = screenwriter;
	}

	@Override
	public String toString() {
		return "\"" + this.getTitle() + "\" (" + this.getYear() + "), diretto da " + this.director + " e sceneggiato da " + this.screenwriter;
	}
}

class Library {
	private List<Content> titles = new ArrayList<Content>();

	public Library() {
		this.titles.add(new Book("Ulisse", "James Joyce", "1922"));
		this.titles.add(new Book("On the road", "Jack Kerouac", "1951"));
		this.titles.add(new Book("Il nome della rosa", "Umberto Eco", "1980"));
		this.titles.add(new Film("Psycho", "Alfred Hitchcock", "Joseph Stefano", "1960"));
		this.titles.add(new Film("2001 Odissea nello spazio", "Stanley Kubrick", "Arthus C. Clarke", "1968"));
		this.titles.add(new Film("Shining", "Stanley Kubrick", "S. Kubrick & D. Johnson", "1980"));
	}

	public void loop() {
		System.out.println("+++++++ Benvenuto nella biblioteca multimediale +++++++\nPuoi lasciare o prendere in prestito libri, musica e video.");

		// stampa i libri disponibili
		printLib();

		Console console = System.console();
		while (true) {
			System.out.println("a. Prendi qualcosa in prestito\nb. Aggiungi un nuovo contenuto\nc. Esci" + System.lineSeparator());

			String opt = console.readLine();

			if ("a".equals(opt)) {
				System.out.println("Cosa vuoi in prestito?");
				String title = console.readLine("Titolo: ");

				boolean f = false;

				for (Content media : titles) {
					if (title.toLowerCase().equals(media.getTitle().toLowerCase())) {
						f = true;
						if (media instanceof Book) {
							System.out.println("Trovato il libro " + media + "." + System.lineSeparator());
						}

						if (media instanceof Song) {
							Song song = (Song) media;
							System.out.println("Trovata la canzone " + media + "." + System.lineSeparator());
						}

						if (media instanceof Film) {
							Film film = (Film)media;
							System.out.println("Trovato il film " + media + "." + System.lineSeparator());
						}
						break;
					}
				}

				if (!f) System.out.println("Titolo non trovato!\n");
			}
			/* salva un nuovo titolo (libro, canzone o film) nella mediateca */
			else if ("b".equals(opt)) {
				System.out.println("Cosa hai portato di nuovo?\n\na) Un libro\nb) Un brano audio\nc) Un film / video" + System.lineSeparator());
				String type = console.readLine();

				// controlla che l'opzione scelta sia 'a', 'b' o 'c'
				if (type.length() != 1 || ((int)type.charAt(0) < 97 || (int)type.charAt(0) > 99)) {
					System.out.println("Contenuto sconosciuto!\n");
					continue;
				}

				Content media = null;

				String title = console.readLine("Titolo: ");
				String year = console.readLine("Anno: ");

				/* salva un nuovo libro */
				if ("a".equals(type)) {
					String author = console.readLine("Autore: ");

					media = new Book(title, author, year);
					System.out.println(System.lineSeparator() + "Aggiunto il libro " + media + ".\n");
				}
				/* salva un nuovo brano audio */
				else if ("b".equals(type)) {
					String author = console.readLine("Autore: ");
					String singer = console.readLine("Cantante: ");

					media = new Song(title, author, singer, year);
					System.out.println(System.lineSeparator() + "Aggiunta la canzone " + media + ".\n");
				}
				/* salva un nuovo film */
				else if ("c".equals(type)) {
					String director = console.readLine("Regista: ");
					String screenwriter = console.readLine("Sceneggiatore: ");
					media = new Film(title, director, screenwriter, year);
					System.out.println(System.lineSeparator() + "Aggiunto il film " + media + ".\n");
				}

				titles.add(media);
				printLib();
			}
			else if ("c".equals(opt)) {
				System.out.println("Buon divertimento, speriamo di rivederti presto.");
				break;
			}
			else {
				System.out.println("Operazione sconosciuta!\n");
			}
		}
	}

	private void printLib() {
		System.out.println("Titoli disponibili: " + System.lineSeparator());
		int i = 1;
		for (Content c : titles) {
			System.out.println(i + ". " + c + ".");
			i++;
		}

		System.out.print(System.lineSeparator());
	}
}

public class Esercizio32 {
	public static void main(String [] args) {
		Library mediateca = new Library();

		// apre la biblioteca
		mediateca.loop();
	}
}

