#include "cube.h"
#include <cstdlib>
#include <utility>
#include <iostream>

int solved_corner_config[] = {1, 3, 5, 7, 13, 15, 17, 19};
int solved_edge_config[] = {2, 4, 6, 8, 9, 10, 11, 12, 14, 16, 18, 20};

// constructor for a solved Rubik's Cube
Cube::Cube() : _isSolved(true)
{
	for (int i = 0; i < 8; i++) {
		mCorners[i] = (corner)solved_corner_config[i];
	}
	for (int i = 0; i < 12; i++) {
		mEdges[i] = (edge_piece)solved_edge_config[i];
	}
}

bool Cube::isSolved() const
{
	return _isSolved;
}

// checks to see if the cube is solved
void Cube::checkSolved() {
	for(int i = 0; i < 8; i++) {
		if (solved_corner_config[i] != mCorners[i]) {
			_isSolved = false;
			return;
		}
	}

	for(int i = 0; i < 12; i++) {
		if (solved_edge_config[i] != mEdges[i]) {
			_isSolved = false;
			return;
		}
	}
	_isSolved = true;
}

// overloading of equals operator
bool Cube::operator==(const Cube& rhs) const {
	for (auto i = 0; i < 8; i++) {
		if (mCorners[i] != rhs.mCorners[i]) return false;
		if (mEdges[i] != rhs.mEdges[i]) return false;
	}
	for (auto i = 8; i < 12; i++) {
		if (mEdges[i] != rhs.mEdges[i]) return false;
	}
	return true;
}

// turn the top face clockwise
Cube& Cube::turnUp()
{
	quarterTurn(mCorners[0], mCorners[1], mCorners[2], mCorners[3]);
	quarterTurn(mEdges[0], mEdges[1], mEdges[2], mEdges[3]);
	checkSolved();
	return *this;
}

// turn the top face clockwise twice
Cube& Cube::turnUp2()
{
	halfTurn(mCorners[0], mCorners[1], mCorners[2], mCorners[3]);
	halfTurn(mEdges[0], mEdges[1], mEdges[2], mEdges[3]);
	checkSolved();
	return *this;
}

// turn the top face counterclockwise
Cube& Cube::turnUpI()
{
	quarterTurn(mCorners[3], mCorners[2], mCorners[1], mCorners[0]);
	quarterTurn(mEdges[3], mEdges[2], mEdges[1], mEdges[0]);
	checkSolved();
	return *this;
}

// turn the bottom face clockwise
Cube& Cube::turnDown()
{
	quarterTurn(mCorners[7], mCorners[6], mCorners[5], mCorners[4]);
	quarterTurn(mEdges[10], mEdges[9], mEdges[8], mEdges[11]);
	checkSolved();
	return *this;
}

// turn the bottom face clockwise twice
Cube& Cube::turnDown2()
{
	halfTurn(mCorners[7], mCorners[6], mCorners[5], mCorners[4]);
	halfTurn(mEdges[10], mEdges[9], mEdges[8], mEdges[11]);
	checkSolved();
	return *this;
}

// turn the bottom face counterclockwise
Cube& Cube::turnDownI()
{
	quarterTurn(mCorners[4], mCorners[5], mCorners[6], mCorners[7]);
	quarterTurn(mEdges[11], mEdges[8], mEdges[9], mEdges[10]);
	checkSolved();
	return *this;
}

// turn the front face clockwise
Cube& Cube::turnFront()
{
	quarterTurn(mCorners[4], mCorners[5], mCorners[1], mCorners[0]);
	quarterTurn(mEdges[8], mEdges[5], mEdges[0], mEdges[4]);
	checkSolved();
	return *this;
}

// turn the front face clockwise twice
Cube& Cube::turnFront2()
{
	halfTurn(mCorners[4], mCorners[5], mCorners[1], mCorners[0]);
	halfTurn(mEdges[8], mEdges[5], mEdges[0], mEdges[4]);
	checkSolved();
	return *this;
}

// turn the front face counterclockwise
Cube& Cube::turnFrontI()
{
	quarterTurn(mCorners[0], mCorners[1], mCorners[5], mCorners[4]);
	quarterTurn(mEdges[4], mEdges[0], mEdges[5], mEdges[8]);
	checkSolved();
	return *this;
}

// turn the back face clockwise
Cube& Cube::turnBack()
{
	quarterTurn(mCorners[6], mCorners[7], mCorners[3], mCorners[2]);
	quarterTurn(mEdges[10], mEdges[7], mEdges[2], mEdges[6]);
	checkSolved();
	return *this;
}

// turn the back face clockwise twice
Cube& Cube::turnBack2()
{
	halfTurn(mCorners[6], mCorners[7], mCorners[3], mCorners[2]);
	halfTurn(mEdges[10], mEdges[7], mEdges[2], mEdges[6]);
	checkSolved();
	return *this;
}

// turn the back face counterclockwise
Cube& Cube::turnBackI()
{
	quarterTurn(mCorners[2], mCorners[3], mCorners[7], mCorners[6]);
	quarterTurn(mEdges[6], mEdges[2], mEdges[7], mEdges[10]);
	checkSolved();
	return *this;
}

// turn the left face clockwise
Cube& Cube::turnLeft()
{
	quarterTurn(mCorners[7], mCorners[4], mCorners[0], mCorners[3]);
	quarterTurn(mEdges[11], mEdges[4], mEdges[3], mEdges[7]);
	checkSolved();
	return *this;
}

// turn the left face clockwise twice
Cube& Cube::turnLeft2()
{
	halfTurn(mCorners[7], mCorners[4], mCorners[0], mCorners[3]);
	halfTurn(mEdges[11], mEdges[4], mEdges[3], mEdges[7]);
	checkSolved();
	return *this;
}

// turn the left face counterclockwise
Cube& Cube::turnLeftI()
{
	quarterTurn(mCorners[3], mCorners[0], mCorners[4], mCorners[7]);
	quarterTurn(mEdges[7], mEdges[3], mEdges[4], mEdges[11]);
	checkSolved();
	return *this;
}

// turn the right face clockwise
Cube& Cube::turnRight()
{
	quarterTurn(mCorners[5], mCorners[6], mCorners[2], mCorners[1]);
	quarterTurn(mEdges[9], mEdges[6], mEdges[1], mEdges[5]);
	checkSolved();
	return *this;
}

// turn the right face clockwise twice
Cube& Cube::turnRight2()
{
	halfTurn(mCorners[5], mCorners[6], mCorners[2], mCorners[1]);
	halfTurn(mEdges[9], mEdges[6], mEdges[1], mEdges[5]);
	checkSolved();
	return *this;
}

// turn the right face counterclockwise
Cube& Cube::turnRightI()
{
	quarterTurn(mCorners[1], mCorners[2], mCorners[6], mCorners[5]);
	quarterTurn(mEdges[5], mEdges[1], mEdges[6], mEdges[9]);
	checkSolved();
	return *this;
}
