#include <iostream>
#include <vector>

// stb image stuff move to other file
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

#define BYTE unsigned char

int main()
{
	// Image

	const int image_width = 256;
	const int image_height = 256;

	// Render

	vector<BYTE> data;

	for (int j = image_height - 1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i)
		{
			auto r = double(i) / (image_width - 1);
			auto g = double(j) / (image_height - 1);
			auto b = .25;

			BYTE ir = static_cast<BYTE>(255.999 * r);
			BYTE ig = static_cast<BYTE>(255.999 * g);
			BYTE ib = static_cast<BYTE>(255.999 * b);

			data.push_back(ir);
			data.push_back(ig);
			data.push_back(ib);
		}
	}
	stbi_write_jpg("image.jpg", image_width, image_height, 3, &data.data()[0], 80);
}