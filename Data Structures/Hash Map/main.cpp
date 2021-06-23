//*______ Joshua Snyder ______*//

#include <iostream>
#include <string.h>
#include <sstream>
#include <random>
#include <time.h>

#include "Hashmap.h"

std::string generateString() {
    int type = 0;
    char c;
    std::ostringstream oSS;

    for (int i = 0; i < 10; i++) {
        type = rand() % 2;

        if (type == 1) {
            c = (rand() % 26) + 97;
            oSS << c;
        }
        else {
            oSS << rand() % 10;
        }
    }

    return oSS.str();
}

int main(void) {
    HashMap<std::string> hm;

    srand(time(0));

    for (int i = 0; i < 256; i++) {
        hm.add(generateString());
    }

    hm.display();

    std::cout << hm.find(255) << std::endl;
}