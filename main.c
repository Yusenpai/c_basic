#include <stdio.h>
#include <stdint.h>

typedef union
{
	struct
	{
		uint8_t red : 8;   // 8 bits for red
		uint8_t green : 8; // 8 bits for green
		uint8_t blue : 8;  // 8 bits for blue
	};

	struct
	{
		uint8_t r0 : 1, r1 : 1, r2 : 1, r3 : 1, r4 : 1, r5 : 1, r6 : 1, r7 : 1;
		uint8_t g0 : 1, g1 : 1, g2 : 1, g3 : 1, g4 : 1, g5 : 1, g6 : 1, g7 : 1;
		uint8_t b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
	};

	uint32_t rgb : 24; // 24 bits for combined RGB value
} RGBColor;

int main()
{
	RGBColor color;

	// Set color channels individually
	color.red = 255;   // Red = 255 (0xFF)
	color.green = 127; // Green = 127 (0x7F)
	color.blue = 63;   // Blue = 63 (0x3F)

	// Display the combined 24-bit RGB value
	printf("Combined RGB value: 0x%06X\n", color.rgb);
	for (int i = 0; i < 24; i++)
	{
		printf("%d", color.rgb & (1 << (23 - i)) ? 1 : 0);
		if ((i + 1) % 8 == 0)
			printf(" ");
	}
	printf("\n");

	// Display individual color channel values
	printf("Red: %u, Green: %u, Blue: %u\n", color.red, color.green, color.blue);

	// Display individual bits of each channel
	printf("Red channel bits: %u%u%u%u%u%u%u%u\n",
		   color.r7, color.r6, color.r5, color.r4,
		   color.r3, color.r2, color.r1, color.r0);

	printf("Green channel bits: %u%u%u%u%u%u%u%u\n",
		   color.g7, color.g6, color.g5, color.g4,
		   color.g3, color.g2, color.g1, color.g0);

	printf("Blue channel bits: %u%u%u%u%u%u%u%u\n",
		   color.b7, color.b6, color.b5, color.b4,
		   color.b3, color.b2, color.b1, color.b0);

	return 0;
}