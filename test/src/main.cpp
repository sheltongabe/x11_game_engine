#include <thread>
#include <chrono>
#include "x11_game_engine/x_screen.h"

int main() {

	XScreen screen("Main name", "Main title", 800, 600);
	for(int i = 0; i < 5; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds{1000});
		screen.flushEvents();
	}

	return 0;
}