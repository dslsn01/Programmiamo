# file esercizio23.py

from multiprocessing import Process, Array
import ctypes
import numpy
from PIL import Image

n, m = 1024, 1024
minR = -1.5
maxR = 1.5
minI = -1.5
maxI = 1.5
rRange = maxR-minR
iRange = maxI-minI
CUTOFF = 256

def mandelbrot(start, end, pixels):
	height = m
	arr = numpy.frombuffer(pixels.get_obj())
	b = arr.reshape((n, m))

	counter = 0
	for ix in range(start, end):
		for iy in range(0, height):
			# parentesi "()" obbligatorie
			x0 = (ix*rRange / height) + minR;
			y0 = (iy*iRange / height) + minI;

			x = 0.0
			y = 0.0

			k = 0
			while (k < CUTOFF and x*x + y*y < 4.0):
				x_new = x*x - y*y + x0
				y = 2*x*y + y0
				x = x_new
				k += 1

			b[ix][iy] = k

if __name__ == "__main__":
	arr = Array(ctypes.c_double, n*m)
	nProc = 8

	_slice = m / nProc

	start = 0;
	end = _slice

	procs = []

	for i in range(nProc):
		p = Process(target=mandelbrot, args=(start, end, arr,))
		procs.append(p)

		start = end
		end += _slice

	for proc in procs:
		proc.start()

	for proc in procs:
		proc.join()

	pixels = numpy.frombuffer(arr.get_obj()).reshape((n, m))
	image = Image.new('RGB', (m, n))

	imgBuff = image.load()
	for px in range(m):
		for py in range(n):
			pixel = pixels[px][py]
			c = 0
			if pixel < CUTOFF:
				c = int(255-int(pixel*255 / CUTOFF))

			imgBuff[px, py] = (c, c, c)

	image.save("MandelbrotSet.png", "PNG")

