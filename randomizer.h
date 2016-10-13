#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include "color.h"
#include <iostream>
#include <map>
#include <SDL.h>
#include <string>
#include <vector>

/** Pointer to SDL_Surface object */
#define Bitmap SDL_Surface*

/** Pointer to vector of colors */
#define Bucket std::vector<Color>*

/** Returns the Uint32 value of the pixel at the coordinates */
Uint32 GetPixel(Bitmap, int, int);

/** Replaces the pixel at the coordinates with the passed Uint32 value */
void PutPixel(Bitmap, Uint32, int, int);

void ReplaceColor(Bitmap, Uint32, Uint32);

struct BucketContainer {

	/** Vector of all colors in a bitmap */
	std::vector<Color> colors;

	/** Map to store total occurances of each color in the bitmap */
	std::map<Uint32, int> colorCount;

	/** Map to store which colors have already been bucketed */
	std::map<Uint32, bool> bucketedColors;

	/** Map of uint32 values and their randomized replacements */
	std::map<Uint32, Uint32> modColors;

	/** Vector of color buckets */
	std::vector<Bucket> buckets;

	/** Function to find all colors */
	void FindColors(Bitmap);

	/** Function to build a single bucket */
	Bucket BuildBucket(Bucket, Color, int);

	/** Function to build buckets for all colors */
	void BuildBuckets(int);

	/** Function to randomize all buckets */
	void RandomizeColors(int);

	/** Constructor */
	BucketContainer(Bitmap);

};

/** Main randomizer function */
Bitmap RandomizeBitmap(std::string filepath, int);

#endif