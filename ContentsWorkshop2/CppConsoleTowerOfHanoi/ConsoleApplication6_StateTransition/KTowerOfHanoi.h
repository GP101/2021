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

	enum class EDiskAnimState
	{
		DISKANIM_INIT = 0,
		DISKANIM_MOVE_TO_TOP,
		DISKANIM_MOVE_TO_DEST,
		DISKANIM_END,
	};

	EDiskAnimState	m_eDiskAnimState;
	int				m_iAnimSrcTower;
	int				m_iAnimDestTower;
	int				m_iAnimDisk;
	KVector2		m_vAnimBegin;
	KVector2		m_vAnimEnd;
	double			m_diskAnimTimer;

public:
	KTowerOfHanoi();
	void Initialize(int numOfDisks);
	void Iterate(double elapsedTime);
	void Draw();
private:
	void MoveDisk(char fromPeg, char toPeg, int disk);
	void MoveDisksBetweenTwoPoles(int iSrc, int iDest);
	void MoveDisksBetweenTwoPoles_INIT(int iSrc, int iDest);
};

