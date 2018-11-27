#include <thread>
#include <chrono>
#include "shooter_game.h"

int main() {
	
	ShooterGame game("Shooter Game", "Shooter Game", 1600, 900);
	game.mainLoop();

	return 0;
}