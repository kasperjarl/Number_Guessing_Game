#include <iostream>

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtration() {
	if (!std::cin) {
		if (std::cin.eof()) {
			std::cout << "terminating input stream";
			std::exit(0);
		}

		std::cin.clear();
		ignoreLine();
		
		return true;
	}
	return false;
}


int getInt() {

	while (true) {
		std::cout << "Enter an integer: ";
		int x{};
		std::cin >> x;

		/* 
		I also want to check if the user entered a float, and ask them to
		enter an integer instead...
		*/

		if (clearFailedExtration()) {
			std::cout << "Invalid input, try again\n";
			continue;
		}

		ignoreLine();

		return x;
	}
}