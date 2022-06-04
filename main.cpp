#include "game.h"
#include <ctime>
int main() {
	Game game;
	srand(time(0));
	game.play();
	return 0;
}