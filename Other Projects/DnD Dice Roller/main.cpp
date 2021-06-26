//*______ Joshua Snyder ______*//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <time.h>

/*
    ====== DnD Dice Roller v0.1 ======

    #AUTHOR 
        Joshua Snyder

    #USAGE 
        This is a simple terminal based application that can be used to roll dice. This application
        mostly geared towards Dungeons and Dragons, but any dice can be rolled however many times you wish for 
        whatever reason. 
*/

int roll(const int& ROLL_COUNT, const int& MAX) {
    int result = 0;
    int total = 0;

    std::cout << std::endl;
    std::cout << "~~~~~ Results (" << ROLL_COUNT << "d" << MAX << ") ~~~~~" << std::endl;

    for (int i = 0; i < ROLL_COUNT; i++) {
        result = (rand() % MAX) + 1;
        
        std::cout << " * Rolled: " << result << std::endl;

        total += result;
    }
    
    std::cout << std::endl;

    std::cout << "TOTAL: " << total << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    // Confirm completion 
    if (ROLL_COUNT > 1) {
        std::cout << "Rolls (" << ROLL_COUNT << ") finished. " << std::endl; 
    }
    else {
        std::cout << "Roll finished. " << std::endl;
    }

    std::cout << std::endl;

    return result;
}

std::vector<std::string> formatInput(std::string input) {
    std::vector<std::string> command;
    std::stringstream sstream(input);
    std::string temp;

    while (getline(sstream, temp, ' ')) {
        command.push_back(temp);
    }

    return command;
}

void displayHelp() {
    std::cout << std::endl;
    std::cout << "*----============ Help ============----*" << std::endl;
    std::cout << std::endl;
    std::cout << "roll <# of dice>d<range of dice>   - Roll dice. " << std::endl;
    std::cout << "  EX: 'roll 2d20' will roll 2 d20s. " << std::endl;
    std::cout << std::endl;
    std::cout << "help   - Display this help screen. " << std::endl;
    std::cout << std::endl;
    std::cout << "quit   - Exit the application. " << std::endl;
    std::cout << std::endl;
    std::cout << "*----==============================----*" << std::endl;
}

void processRoll(std::string input) {
    int rollCount = 0;
    int dIndex = 0;
    int max = 0;
    int total = 0;
    int result = 0;
    bool badInput = false;
    bool end = false;

    // Get index of 'd'
    dIndex = input.find('d');

    // Get the number of dice to roll 
    while (!badInput && !end) {
        
        // Check dIndex 
        if (dIndex == std::string::npos) {
            badInput = true;
        }

        try {
            // Get the roll count 
            if (input[0] != 'd') {
                rollCount = std::stoi(input.substr(0, dIndex));
            }
            else {
                rollCount = 1;
            }

            // Get dice type 
            max = std::stoi(input.substr(dIndex + 1, input.length()));
        }
        catch (std::invalid_argument e) {   // If bad input 
            badInput = true;
        }
        catch (std::out_of_range e) {   // If dice range exceeds limits of int 
            badInput = true;
            std::cout << "Dice too large. " << std::endl;
        }

        end = true;
    }

    if (!badInput) {
        roll(rollCount, max);
    }
    else {
        std::cout << "Invalid input. Type 'help' for a list of commands. " << std::endl;
    }
}

void start() {
    std::string input;
    std::string inputSubstr;
    bool quit = false;

    // Display info
    std::cout << "*~~~=== DnD Dice Roller v0.1 ===~~~*" << std::endl;
    std::cout << " - Joshua Snyder " << std::endl << std::endl;

    // Main loop 
    while (!quit) {
        // Get input 
        std::cout << "DDR> ";
        
        getline(std::cin, input);

        std::vector<std::string> command = formatInput(input);

        // Evaluate input 
        if (command[0] == "roll") {
            if (command.size() > 1) {
                processRoll(command[1]);
            }
            else {
                std::cout << "Invalid input. Type 'help' for a list of commands. " << std::endl;
            }
        }
        else if (command[0] == "help") {
            displayHelp();
        }
        else if (command[0] == "quit") {
            quit = true;
        }
        else {
            std::cout << "Invalid input. Type 'help' for a list of commands. " << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Exiting ... " << std::endl;
}

int main(void) {
    srand(time(0));     // Call to ensure random values are generated each time. 

    start();    // Start the main loop of the application 
    
    return 0;
}