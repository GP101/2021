#include "KTowerOfHanoi.h"
#include "MyUtil.h"

/*static*/ const char KTowerOfHanoi::m_stackLookup[4] = "SAD";

// 20211031_jintaeks
void PrintDisc(int left, int top, int width)
{
	char buffer[80];
	int index = 0;
	for (int i = 0; i < width; ++i)
	{
		buffer[index] = '=';
		buffer[index + width + 1] = '=';
		index += 1;
	}
	buffer[width] = '|';
	buffer[width * 2 + 1] = 0; // EOS
	PutText(left, top, buffer);
}

KTowerOfHanoi::KTowerOfHanoi()
{
	m_moveState = EMoveState::ESTATE_INIT;
	m_iStackSrc = 0;
	m_iStackAux = 1;
	m_iStackDest = 2;
	m_numOfDisks = 0;
	m_totalNumOfMoves = 0;
	m_iterationCounter = 0;
	m_oneStepTimer = 0;
	m_eDiskAnimState = EDiskAnimState::DISKANIM_INIT;
	m_iAnimSrcTower = 0;
	m_iAnimDestTower = 0;
	m_iAnimDisk = 0;
	m_diskAnimTimer = 0.0;
}

//Function to show the movement of disks 
void KTowerOfHanoi::MoveDisk(char fromPeg, char toPeg, int disk)
{
	char buffer[80];
	sprintf_s(buffer, sizeof(buffer), "Move the disk %d from \'%c\' to \'%c\'"
		, disk, fromPeg, toPeg);
	m_log.push_back(buffer);
	//PutText(0, 0, buffer);
}

// Function to implement legal movement between 
// two poles 
void KTowerOfHanoi::MoveDisksBetweenTwoPoles_INIT(int iSrc, int iDest)
{
	// When pole 1 is empty 
	if (m_tower[iSrc].Empty()) {
		int pole2TopDisk = m_tower[iDest].TopDisk();
		m_tower[iDest].PopDisk();
		//m_tower[iSrc].PushDisk(pole2TopDisk);
		m_iAnimSrcTower = iDest;
		m_iAnimDestTower = iSrc;
		m_iAnimDisk = pole2TopDisk;
	}
	// When pole2 pole is empty 
	else if (m_tower[iDest].Empty()) {
		int pole1TopDisk = m_tower[iSrc].TopDisk();
		m_tower[iSrc].PopDisk();
		//m_tower[iDest].PushDisk(pole1TopDisk);
		m_iAnimSrcTower = iSrc;
		m_iAnimDestTower = iDest;
		m_iAnimDisk = pole1TopDisk;
	}
	else {
		int pole1TopDisk = m_tower[iSrc].TopDisk();
		int pole2TopDisk = m_tower[iDest].TopDisk();
		// When top disk of pole1 > top disk of pole2 
		if (pole1TopDisk > pole2TopDisk) {
			m_tower[iDest].PopDisk();
			//m_tower[iSrc].PushDisk(pole2TopDisk);
			m_iAnimSrcTower = iDest;
			m_iAnimDestTower = iSrc;
			m_iAnimDisk = pole2TopDisk;
		}
		// When top disk of pole1 < top disk of pole2 
		else {
			m_tower[iSrc].PopDisk();
			//m_tower[iDest].PushDisk(pole1TopDisk);
			m_iAnimSrcTower = iSrc;
			m_iAnimDestTower = iDest;
			m_iAnimDisk = pole1TopDisk;
		}
	}
}

void KTowerOfHanoi::MoveDisksBetweenTwoPoles(int iSrc, int iDest)
{
	char buffer[80];
	sprintf_s(buffer, sizeof(buffer), "state=%i, %i(%i==>%i)"
		, m_eDiskAnimState, m_iAnimDisk, m_iAnimSrcTower, m_iAnimDestTower);
	PutText(50, 1, buffer);
	if (m_eDiskAnimState != EDiskAnimState::DISKANIM_END)
		PrintDisc(50, 2, m_iAnimDisk);

	char s = m_stackLookup[iSrc];
	char d = m_stackLookup[iDest];
	if (m_eDiskAnimState == EDiskAnimState::DISKANIM_INIT)
	{
		MoveDisksBetweenTwoPoles_INIT(iSrc, iDest);
		m_eDiskAnimState = EDiskAnimState::DISKANIM_MOVE_TO_TOP;
		m_diskAnimTimer = 0.0;
	}
	else if (m_eDiskAnimState == EDiskAnimState::DISKANIM_MOVE_TO_TOP)
	{
		if (m_diskAnimTimer >= 1.0) {
			m_eDiskAnimState = EDiskAnimState::DISKANIM_MOVE_TO_DEST;
			m_diskAnimTimer = 0.0;
		}
	}
	else if (m_eDiskAnimState == EDiskAnimState::DISKANIM_MOVE_TO_DEST)
	{
		if (m_diskAnimTimer >= 1.0) {
			m_eDiskAnimState = EDiskAnimState::DISKANIM_END;
			m_diskAnimTimer = 0.0;
			// action
			m_tower[m_iAnimDestTower].PushDisk(m_iAnimDisk);
			MoveDisk(s, d, m_iAnimDisk);
		}
	}
	else if (m_eDiskAnimState == EDiskAnimState::DISKANIM_END)
	{
		if (m_diskAnimTimer >= 1.0) {
			m_eDiskAnimState = EDiskAnimState::DISKANIM_INIT;
			m_diskAnimTimer = 0.0;
			m_iterationCounter += 1; // update iteration
		}
	}
}

//Function to implement TOH puzzle 
void KTowerOfHanoi::Initialize(int numOfDisks)
{
	for (int i = 0; i < 3;++i) {
		m_tower[i].Clear();
	}
	m_log.clear();

	m_moveState = EMoveState::ESTATE_DOING;
	m_iStackSrc = 0;
	m_iStackAux = 1;
	m_iStackDest = 2;
	m_iterationCounter = 0;

	//If number of disks is even, then interchange 
	//destination pole and auxiliary pole 
	if (numOfDisks % 2 == 0) {
		char temp = m_iStackDest;
		m_iStackDest = m_iStackAux;
		m_iStackAux = temp;
	}
	m_numOfDisks = numOfDisks;
	m_totalNumOfMoves = (int)pow(2, numOfDisks) - 1;

	KTower& src = m_tower[m_iStackSrc];
	//Larger disks will be pushed first 
	for (int i = m_numOfDisks; i >= 1; i--)
		src.PushDisk(i);
}

//Function to implement TOH puzzle 
void KTowerOfHanoi::Iterate(double elapsedTime)
{
	if (m_moveState == EMoveState::ESTATE_FINISHED) {
		return;
	}

	//m_oneStepTimer += elapsedTime;
	//if (m_oneStepTimer < 1.0) {
	//	return;
	//}
	//m_oneStepTimer = 0.0;

	//m_iterationCounter += 1;
	if (m_iterationCounter >= m_totalNumOfMoves) {
		m_moveState = EMoveState::ESTATE_FINISHED;
		return;
	}

	m_diskAnimTimer += elapsedTime;
	if (m_iterationCounter % 3 == 0)
		MoveDisksBetweenTwoPoles(m_iStackSrc, m_iStackDest);
	else if (m_iterationCounter % 3 == 1)
		MoveDisksBetweenTwoPoles( m_iStackSrc, m_iStackAux);
	else if (m_iterationCounter % 3 == 2)
		MoveDisksBetweenTwoPoles( m_iStackAux, m_iStackDest);
}

void KTowerOfHanoi::Draw()
{
	int x = 0;
	int y = 1;
	for (std::string& str : m_log) {
		PutText(x, y, str.c_str());
		y += 1;
	}

	char buffer[80];
	int startx = 50;
	int starty = 10;
	const int width = m_numOfDisks * 2 + 2;
	x = startx;
	y = starty;
	for (int i = 0; i < 3; ++i) {
		x += width;
		y = starty;
		for (int j = 0; j < m_numOfDisks + 1; ++j)
			PutText(x, 20 + y - j, "|");
		for (int j=0;j<m_tower[i].GetDiskCount();++j) {
			const int n = m_tower[i].GetDisk(j);
			_itoa_s(n, buffer, 10);
			PutText(x, y, buffer);
			PrintDisc(x - n, 20 + y, n); // jintaek on 20211031
			y -= 1;
		}
	}
}
