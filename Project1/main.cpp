#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getNPCMove();
int getResult(string playerMove, string NPCMove);

int main() {

	// setup
	string input;
	bool gameRunning = true;

	// greet the player and get their selection
	cout << "Hello Player!" << endl;

	while (gameRunning = true) {
		cout << "Please enter ROCK, PAPER, or SCISSORS to play, or QUIT to quit:" << endl;
		getline(cin, input);

		// ensure input is uppercase for later comparison
		transform(input.begin(), input.end(), input.begin(), toupper);

		// roll the game
		if (input == "ROCK" || input == "PAPER" || input == "SCISSORS") {

			// get the computer's move
			string NPCMove = getNPCMove();

			// get the game result
			int result = getResult(input, NPCMove);

			// print game result
			cout << "Computer played: " << NPCMove << endl;
			cout << "You played: " << input << endl;
			if (result == 0) {
				cout << "Game was a draw!" << endl;
			}
			else if (result == 1) {
				cout << "You win!" << endl;
			}
			else {
				cout << "You lost!" << endl;
			}
		}

		// end game
		else if (input == "QUIT") {
			cout << "Goodbye!" << endl;
			gameRunning = false;
			return 0;
		}

		// alert to invalid move
		else {
			cout << "Invalid move!" << endl;
		}
	}
}

string getNPCMove() {

	// setup
	int move;

	// random seed
	srand(time(0));

	// generate random number between 0 and 2
	move = rand() % 3;

	// return computer's move
	if (move == 0) {
		return "PAPER";
	}
	else if (move == 1) {
		return "SCISSORS";
	}
	else {
		return "ROCK";
	}
}

int getResult(string playerMove, string NPCMove) {

	// if draw
	if (playerMove == NPCMove) { return 0; }

	// if win
	if (playerMove == "SCISSORS" && NPCMove == "PAPER" ||
		playerMove == "PAPER" && NPCMove == "ROCK" ||
		playerMove == "ROCK" && NPCMove == "SCISSORS") { return 1; }

	// if loss
	if (playerMove == "SCISSORS" && NPCMove == "ROCK" ||
		playerMove == "PAPER" && NPCMove == "SCISSORS" ||
		playerMove == "ROCK" && NPCMove == "PAPER") { return -1; }
}
