#include "TestVectorMyJosephus.h"

void TestVectorMyJosephus::runVectorGame()
{
	int N = 0, M = 0;
	cout << "Enter player amount: ";
	cin >> N;
	cout << "Enter play interval: ";
	cin >> M;
	cout << endl;

	VectorMyJosephus newVectorGame(N, M);
	newVectorGame.printAll();
	newVectorGame.game();
	cout << endl;
}

