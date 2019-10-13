// program to draw a diamond of user provided height.
#include "../../../std_lib_facilities.h"

void drawStar(int v) {//function to draw star spaces
	for (double counter = 1; counter <= v; counter += .5)
		cout << "*";
}

void drawSpaceEven(int v) {//function to draw spaces when diamond height is even number.
	for (int counter = v; counter > -1; --counter)
		cout << "!";
}
void drawSpaceOdd(int v) { //function to draw spaces when diamond heigh is odd number.
	for (int counter = v; counter >-1; --counter)
		cout << "!";
}
void drawTopTriangleEven(int v) { //function to draw top half of a diamond with an even height.

	for (int lineCounter = 1; lineCounter <= v; ++lineCounter) {
		int spaceCounter = v - lineCounter;
		drawSpaceEven(spaceCounter); drawStar(lineCounter); drawSpaceEven(spaceCounter); cout << "\n";
	}
}
void drawTopTriangleOdd(int v) { //function to draw top half of a diamond with an odd height.

	for (int lineCounter = 1; lineCounter <= v; ++lineCounter) {
		int spaceCounter = v - lineCounter;
		drawSpaceOdd(spaceCounter); drawStar(lineCounter); drawSpaceOdd(spaceCounter); cout << "\n";
	}
}
void drawBottomTriangleEven(int v) {//function to draw bottom half of a diamond with an even height.

	for (int lineCounter = v; lineCounter >0; --lineCounter) {
		int spaceCounter = v - lineCounter;
		drawSpaceEven(spaceCounter); drawStar(lineCounter); drawSpaceEven(spaceCounter); cout << "\n";
	}
}
void drawBottomTriangleOdd(int v) { //function to draw bottom half of a diamond with an odd height.

	for (int lineCounter = v; lineCounter > 0; --lineCounter) {
		int spaceCounter = v - lineCounter;
		
		drawSpaceOdd(spaceCounter); drawStar(lineCounter); drawSpaceOdd(spaceCounter); cout << "\n";
	}
}


void drawMiddle(int v) { //function to draw middle line of a diamond with an odd height.
	for (int counter = 0; counter <= v; ++counter)
		cout << "*";
	cout << "\n";
}
int main() {
	int diamondHeight = 0;
	cout << "Please enter a positive integer: \n";
	cin >> diamondHeight;
	int triangleHeight = (diamondHeight / 2);
	int even = (diamondHeight % 2);

	if (even == 0) {
		drawTopTriangleEven(triangleHeight);
		drawBottomTriangleEven(triangleHeight);
	}
	else {
		drawTopTriangleOdd(triangleHeight);
		drawMiddle(diamondHeight);
		drawBottomTriangleOdd(triangleHeight);
	}
}