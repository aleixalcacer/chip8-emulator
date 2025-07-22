#include "chip8.h"
#include <SDL3/SDL_time.h>

int main() {

    say_hello();
    SDL_Time ticks = 0;  // Declare a variable to hold the time value

    bool res = SDL_GetCurrentTime( &ticks); // Gets the current value of the system realtime clock in nanoseconds since Jan 1, 1970 in Universal Coordinated Time (UTC).

    if (res) {
        printf("Current time in nanoseconds: %lld\n", ticks);
    } else {
        printf("Failed to get current time.\n");
        return -1;
    }

    return 0;
}
