#include "VectorMyJosephus.h"
#include <chrono>
using namespace std::chrono;

VectorMyJosephus::VectorMyJosephus()
{
	this->N = 0;
	this->M = 0;
	size = 0;
}

VectorMyJosephus::VectorMyJosephus(int N, int M)
{
	init(N, M);
}

VectorMyJosephus::~VectorMyJosephus()
{

}

void VectorMyJosephus::init(int N, int M)
{
	this->N = N;
	this->M = M;
	this->size = N;
	int i = 0;

	while (i < N)
	{
		this->circ.push_back(i);
		i++;
	}
}

void VectorMyJosephus::clear()
{
	this->circ.clear();
}

int VectorMyJosephus::currentSize()
{
	return circ.size();
}

bool VectorMyJosephus::isEmpty()
{
	bool empty = false;
	if (this->circ.empty())
	{
		empty = true;
	}
	else
	{
		empty = false;
	}
	return empty;
}

Person VectorMyJosephus::eliminateNext()
{
	int i = 0;
	Person positon();

	while (i < M)
	{
		if (playerPosition == circ.end())
		{
			playerPosition = circ.begin();
		}
		playerPosition++;
		i++;
	}

	if (playerPosition == circ.end())
	{
		playerPosition = circ.begin();
	}

	this->playerElimination.push_back((*playerPosition).getpostion());
	playerPosition = circ.erase(playerPosition);

	size--;
	return *circ.begin();
}

void VectorMyJosephus::printAll()
{
	vector<Person>::iterator list = circ.begin();
	cout << "Current Players: ";
	do
	{
		cout << list->getpostion() << ", ";
		list++;
	} while (list != circ.end());
	cout << endl;

}

void VectorMyJosephus::game()
{
	double time = 0.0, averageTime = 0.0;
	playerPosition = circ.begin();
	do
	{
		auto start = chrono::high_resolution_clock::now();
		eliminateNext();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count() + time;
		printAll();
	} while (size != 1);
	averageTime = time / (N - 1);
	cout << endl <<  "Total game time: " << time/1.0 << " microseconds" << endl;
	cout << "Elimination Time Average (List): " << averageTime << " microseconds" << endl;
	vector<int>::iterator Eliminationlist = playerElimination.begin();
	cout << "Elimination Sequence: ";
	do
	{
		cout << *Eliminationlist << ", ";
		Eliminationlist++;
	} while (Eliminationlist != playerElimination.end());
	cout << endl;
	cout << "Winner: " << circ.begin()->getpostion() << endl;

}