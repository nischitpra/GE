#include "TerminalMode.h"

#include <termios.h>
#include <unistd.h>

#include <iostream>

static struct termios oldt, newt;

void TerminalMode::initializeTerminal() {
    // Get the terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Turn off echoing and enable non-canonical mode
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::cout << "Terminal initialized.\n";
}

void TerminalMode::cleanupTerminal() {
    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << "Terminal cleaned up.\n";
}
