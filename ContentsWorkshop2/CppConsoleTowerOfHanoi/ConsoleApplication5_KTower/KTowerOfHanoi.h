#pragma once
#include "KStack.h"
#include <string>
#include "KTower.h"

class KTowerOfHanoi
{
private:
	enum class EMoveState
	{
		ESTATE_INIT = 0,
		ESTATE_DOING,
		ESTATE_FINISHED
	};

	static const char m_stackLookup[4];

	//KStack m_stack[3];
	KTower m_tower[3];
	int m_iStackSrc;
	int m_iStackAux;
	int m_iStackDest;
	int m_numOfDisks;
	int m_totalNumOfMoves;
	int m_iterationCounter;
	EMoveState m_moveState;
	std::vector<std::string> m_log;
	double m_oneStepTimer;

public:
	KTowerOfHanoi();
	void Initialize(int numOfDisks);
	void Iterate(double elapsedTime);
	void Draw();
private:
	void MoveDisk(char fromPeg, char toPeg, int disk);
	void MoveDisksBetweenTwoPoles(int iSrc, int iDest);
};

