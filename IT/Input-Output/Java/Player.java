/* file Player.java */

import java.io.Serializable;

public class Player implements Serializable {
	private String name;
	private int score;

	public Player(String name) {
		this.setName(name);
		this.setScore(100);
	}

	public void addScore(int incr) {
		this.score += incr;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public int getScore() {
		return this.score;
	}

	public void setScore(int score) {
		this.score = score;
	}
}

