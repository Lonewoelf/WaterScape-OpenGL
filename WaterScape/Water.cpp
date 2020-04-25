#include <iostream>
#include "Water.h"

void Water::updateWaveMap()
{
	int x = 0, y = 0, n = 0;

	//Skip the edges to allow area sampling
	for (y = 1; y < MAX_Y - 1; y++) {
		for (x = 1; x < (MAX_X - 1); x++) {
			n = (WaveMap[CT][x - 1][y] +
				WaveMap[CT][x + 1][y] +
				WaveMap[CT][x][y - 1] +
				WaveMap[CT][x][y + 1]) / 2 -
				WaveMap[NW][x][y];

			n = n - (n / DAMP);

			std::cout << n;

			WaveMap[NW][x][y] = n;

		}
	}
}
