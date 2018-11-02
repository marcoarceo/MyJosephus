#include "TestListMyJosephus.h"

void TestListMyJosephus::runListGame()
{
	int N = 0, M = 0;
	cout << "Enter player amount: ";
	cin >> N;
	cout << "Enter play interval: ";
	cin >> M;
	cout << endl;

	ListMyJosephus newListGame(N, M);
	newListGame.printAll();
	newListGame.game();
	cout << endl;
}