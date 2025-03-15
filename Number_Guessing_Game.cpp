#include <iostream>
#include <tuple>
#include "greeting.h"
#include "get_stuff.h"
#include "guess.h"

int main()
{
	greeting();
	while (true) {
		std::cout << "Enter an integer between 0 and 1000: ";
		int x{ getInt() };

		if (x > 0 && x < 1001) {
			break;
		}
	}

	auto [answer, numOfGuess] = guess();
	
	std::cout << "\nYour number is: " << answer << ". It took the machine: " << numOfGuess << " tries.\n";

	return 0;
}