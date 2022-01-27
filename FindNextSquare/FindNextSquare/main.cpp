#include <iostream>
#include <cmath>

long int findNextSquare(long int sq) {
	// Return the next square if sq if a perfect square, -1 otherwise
	float squareRt = sqrt(sq);

	if (std::roundf(squareRt) == squareRt) {
		printf("integer\n");
		return pow(squareRt + 1, 2);
	}
	else {
		printf("fraction\n");
		return -1;
	}
}

int main()
{
	findNextSquare(121); // Equals(144));
	findNextSquare(625); // Equals(676));
	findNextSquare(319225); // Equals(320356));
	//findNextSquare(15241383936); // Equals(15241630849));
	findNextSquare(155); // Equals(-1));
	return 0;
}