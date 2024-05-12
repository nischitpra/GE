#include "InputHandler.h"

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

InputHandler::InputHandler() : lastKey(0), keepListening(false) {}

InputHandler::~InputHandler() { stopListening(); }

void InputHandler::startListening() {
    keepListening = true;
    inputThread = std::thread(&InputHandler::listenForKeyPresses, this);
}

void InputHandler::stopListening() {
    keepListening = false;
    if (inputThread.joinable()) inputThread.join();
}

char InputHandler::getLastKey() { return lastKey; }

void InputHandler::clearKey() {
    lastKey = 0;  // Reset the last key after processing
}

void InputHandler::listenForKeyPresses() {
    // Make stdin non-blocking
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    while (keepListening) {
        char key;
        int result = read(STDIN_FILENO, &key, 1);
        if (result > 0) {
            lastKey = key;
        } else if (result < 0 && errno != EAGAIN) {
            // Handle read error
            perror("read");
            break;
        }
        // Sleep a bit to prevent this loop from consuming too much CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }
}
