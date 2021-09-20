#include <iostream>
#include "io.h"

int readNumber() {
	int a;
	int b;
	std::cout << "Enter the first digit\n";
	std::cin >> a;
	std::cout << "Enter the second digit\n";
	std::cin >> b;
	return a + b;
}

void writeAnswer(int a) {
	std::cout << "The answer is " << a << std::endl;
}

int isHeight() {
	int x;
	std::cout << "Enter the height of Tower\n";
	std::cin >> x;
	return x;
}

double getHeight(int height, int sec) {

	return height - myConstants::gravity * sec * sec / 2;
}

void show(int height, int sec) {
	double res = getHeight(height, sec);
	if (res > 0.0) {
		std::cout << "At " << sec << " seconds, the ball is at height: " << res << " meters\n";
	}
	else {
		std::cout << "The ball is on the ground\n";
	}
}