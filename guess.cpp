#include <iostream>
#include "get_stuff.h"


std::tuple<int,int> guess() {
	int numOfGuesses{ 1 };
	int high{ 1000 };
	int low{ 0 };
	

	while (true) {
		int median{ (high + low) / 2 };

		std::cout << "Press 'y' for yes, 'h' for higher, 'l' for lower\n";
		std::cout << "Is your number: " << median << "?: ";
		
		// get user input: yes, higher or lower?
		char answer{getAnswer()};

		switch (answer)
		{
		case 'y':
			return { median, numOfGuesses };
		case 'h':
			low = median + 1;
			numOfGuesses++;
			continue;
		case 'l':
			high = median - 1;
			numOfGuesses++;
			continue;
		default:
			std::cout << "not understood\n";
			continue;
		}

	}

	
}