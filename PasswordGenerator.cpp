/*-----------------------------------------------------------
Generates a secure password with a user-specified length
* Supports 64-bit lengths

By: Joshua Snyder
-----------------------------------------------------------*/

#include <iostream>
#include <sstream>
#include <time.h>

std::string uppercaseString(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	
	return str;
}

void generatePassword(const uint64_t& length) {
	std::ostringstream oSS;
	
	for (int i = 0; i < length; i++) {
		oSS << (char)((rand() % 0x39) + 0x27);
	}
	
	std::cout << "Password: " << oSS.str() << std::endl;
}

void showHelp() {
	std::cout << "\"""test <password length>\"" << std::endl;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Invalid arguments specified. " << std::endl;
		showHelp();
	}
	else {
		std::string argument = uppercaseString(argv[1]);
		
		if (argument == "HELP") {
			showHelp();
		}
		else if (argument == "LENGTH") {
			if (argc > 2 && isdigit(*argv[2])) {
				srand(time(0));
				generatePassword(std::atoi(argv[2]));
			}
			else {
				std::cout << "Invalid length specified. " << std::endl;
				showHelp();
			}
		}
		else {
			std::cout << "Invalid arguments specified. " << std::endl;
			showHelp();
		}
	}

	return 0;
}