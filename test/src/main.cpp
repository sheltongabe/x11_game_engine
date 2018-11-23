#include <thread>
#include <chrono>
#include "pong.h"

int main() {
	
	Pong game("Pong", "Pong", 800, 600);
	game.mainLoop();

	return 0;
}