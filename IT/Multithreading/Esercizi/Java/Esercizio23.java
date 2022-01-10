/* file Esercizio23.java */

import java.io.IOException;
import java.io.File;
import java.awt.Color;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

class Mandelbrot implements Runnable {
	private final double minR = -1.5;
	private final double maxR = 1.5;
	private final double minI = -1.5;
	private final double maxI = 1.5;
	// [-1.5, 1.5]
	private final double rRange = maxR-minR;
	// [-1.5, 1.5]
	private final double iRange = maxI-minI;
	private final int CUTOFF = 256;
	private int start;
	private int end;
	private int [][] pixels;

	public Mandelbrot(int start, int end, int [][] pixels) {
		this.start = start;
		this.end = end;
		this.pixels = pixels;
	}

	@Override
	public void run() {
		int M = pixels[0].length;
		int N = M;
		for (int ix = start; ix < end; ix++) {
			for (int iy = 0; iy < N; iy++) {
				// parte reale
				double x0 = (ix*rRange/M) + minR;
				// parte immaginaria
				double y0 = (iy*iRange/N) + minI;

				double x = 0.0;
				double y = 0.0;

				int k = 0;
				while (k < CUTOFF && x*x + y*y < 4.0) {
					double newX = x*x - y*y + x0;
					y = 2*x*y + y0;
					x = newX;
					k++;
				}

				pixels[ix][iy] = k;
			}
		}
	}
}

public class Esercizio23 {
	private final int CUTOFF = 256;

	public static void main(String [] args) {
		final int M = 1024;
		final int N = M;
		final int CUTOFF = 256;

		int [][] pixels = new int[M][N];

		int nThreads = 8;

		int slice = M / nThreads;

		int start = 0;
		int end = slice;

		Thread [] threads = new Thread[nThreads];

		for (int i = 0; i < nThreads; i++) {
			threads[i] = new Thread(new Mandelbrot(start, end, pixels));
			start = end;
			end += slice;
		}

		for (Thread t : threads) {
			t.start();
		}

		try {
			for (Thread t : threads) {
				t.join();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		BufferedImage image = new BufferedImage(M, N, BufferedImage.TYPE_INT_RGB);

		for (int px = 0; px < M; px++) {
			for (int py = 0; py < N; py++) {
				int pixel = pixels[px][py];
				Color color = new Color(0, 0, 0);
				if (pixel < 256) {
					int c = (int) 255-(pixel*255 / 256);
					color = new Color(c, c, c);
				}

				image.setRGB(px, py, color.getRGB());
			}
		}

		try 
		{
			ImageIO.write(image, "PNG", new File("MandelbrotSet.png"));
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}

