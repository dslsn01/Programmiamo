/*
file esercizio23.cpp
Collocare il file di progetto esercizio23.pro nella directory corrente.
Compilare con: qmake-qt4 && make && make clean
*/

#include <thread>
#include <QImage>

using std::thread;

const int M = 1024;
const int N = M;
const double minR = -1.5;
const double maxR = 1.5;
const double minI = -1.5;
const double maxI = 1.5;
// [-1.5, 1.5]
const double rRange = maxR-minR;
// [-1.5, 1.5]
const double iRange = maxI-minI;
const int CUTOFF = 256;

void mandelbrot(int start, int end, int pixels[M][N]) {
	int N = sizeof(pixels[0])/sizeof(int);
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

int main() {
	int pixels[M][N];

	int nThreads = 8;

	int slice = M / nThreads;

	int start = 0;
	int end = slice;

	thread threads[nThreads];

	for (int i = 0; i < nThreads; i++) {
		threads[i] = thread(mandelbrot, start, end, pixels);
		start = end;
		end += slice;
	}

	for (auto& t : threads) {
		t.join();
	}

	QImage image(M, N, QImage::Format_RGB888);

	for (int px = 0; px < M; px++) {
		for (int py = 0; py < M; py++) {
			int pixel = pixels[px][py];
			int c = 0;
			if (pixel < CUTOFF) {
				c = (int) 255-(pixel*255 / CUTOFF);
			}

			image.setPixel(px, py, qRgb(c, c, c));
		}
	}

	image.save("MandelbrotSet.png");
}

