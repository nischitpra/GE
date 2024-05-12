#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <atomic>
#include <functional>
#include <thread>

class InputHandler {
   public:
    InputHandler();
    ~InputHandler();

    void startListening();
    void stopListening();
    void clearKey();
    char getLastKey();

   private:
    std::thread inputThread;
    std::atomic<char> lastKey;
    std::atomic<bool> keepListening;

    void listenForKeyPresses();
};

#endif
