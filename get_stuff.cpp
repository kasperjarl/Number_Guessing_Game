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

bool hasUnextractedInput() {
	if (!std::cin.eof() && std::cin.peek() != '\n') {
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}


int getInt() {

	while (true) {
		int x{};
		std::cin >> x;

		if (hasUnextractedInput()) {
			std::cout << "Invalid input, try again.\n";
			continue;
		}

		if (clearFailedExtration()) {
			std::cout << "Invalid input, try again\n";
			continue;
		}

		ignoreLine();

		return x;
	}
}

char getAnswer() {
	
	char answer{};
	std::cin >> answer;
	while (true) {
		switch (answer)
		{
		case 'y':
			ignoreLine();
			return 'y';
		case 'h':
			ignoreLine();
			return 'h';
		case 'l':
			ignoreLine();
			return 'l';
		default:
			std::cout << "You must enter 'y' for yes, 'h' for higer or 'l' for lower: ";
			std::cin >> answer;
			continue;
		}

	}
}
