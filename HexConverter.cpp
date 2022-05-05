#include <iostream>
#include <sstream>
#include <math.h>
#include <stack>
#include <cstring>

std::string upperString(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	
	return str;
}

char getHexChar(const int& num) {
	if (num < 10) {
		return '0' + num;
	}
	else {
		switch (num) {
			case 10:
				return 'A';
				break;
			case 11:
				return 'B';
				break;
			case 12:
				return 'C';
				break;
			case 13:
				return 'D';
				break;
			case 14:
				return 'E';
				break;
			case 15:
				return 'F';
				break;
		}
	}
}

std::string convertFromBinary(std::string binaryString) {
	int currCount = 0;
	int currSum = 0;
	std::ostringstream oSS;
	std::stack<char> charStack;
	
	oSS << "0x";
	
	for (int i = binaryString.length() - 1; i >= 0; i--) {
		if (binaryString[i] == '1') { currSum += pow(2, currCount); }
		currCount++;
		
		if (currCount == 4) {
			charStack.push(getHexChar(currSum));
			currCount = 0;
			currSum = 0;
		}
	}
	
	if (currSum != 0 && currCount < 4) { charStack.push(getHexChar(currSum)); }
	
	while (!charStack.empty()) {
		oSS << charStack.top();
		charStack.pop();
	}
	
	return oSS.str();
}

std::string convertFromDecimal(const int& num) {
	if (num == 0) {
		return "0";
	}
	
	int i = 0;
	int sum = pow(2, i);
	std::ostringstream oSS;
	
	// Find the MSB 
	while (sum < num) {
		i++;
		sum = pow(2, i);
	}	
	if (sum > num) {
		i--;
		sum = pow(2, i);
	}
	
	oSS << "1";
	
	// Find the remaining bits if needed 
	int tempSum = sum;
	i--;
	
	while (i >= 0) {
		tempSum = sum + pow(2, i);
		
		if (tempSum <= num) {
			oSS << "1";
			sum = tempSum;
		}
		else {
			oSS << "0";
		}
		
		i--;
	}
	
	return oSS.str();
}

int main(int argc, char* argv[]) {
	std::string base = upperString(argv[1]);
	
	if (base == "DECIMAL") {
		std::cout << convertFromBinary(convertFromDecimal(std::stoi(argv[2]))) << std::endl;
	}
	else if (base == "BINARY") {
		std::cout << convertFromBinary(argv[2]) << std::endl;
	}
	
	return 0;
}