#ifndef COLOR_H
#define COLOR_H
#define COLOR_KEY_HEX 0xFF00FF
#include <SDL.h>

struct RGB {
	double r;
	double g;
	double b;
};

struct HSV {
	double h;
	double s;
	double v;
};

struct Color {
	RGB rgb;
	HSV hsv;
	Uint32 uint32;
};

RGB Uint32toRGB(Uint32);

RGB HSVtoRGB(HSV);

HSV RGBtoHSV(RGB);

HSV Uint32toHSV(Uint32);

Uint32 RGBtoUint32(RGB);

Uint32 HSVtoUint32(HSV);

Color BuildColor(Uint32);

#endif
