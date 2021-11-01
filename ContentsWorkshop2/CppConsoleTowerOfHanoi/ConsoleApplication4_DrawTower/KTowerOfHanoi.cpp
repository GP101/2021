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
void KTowerOfHanoi::MoveDisksBetweenTwoPoles(int iSrc, int iDest)
{
	KStack& src = m_stack[iSrc];
	KStack& dest = m_stack[iDest];
	char s = m_stackLookup[iSrc];
	char d = m_stackLookup[iDest];

	// When pole 1 is empty 
	if (src.empty()) {
		int pole2TopDisk = dest.top();
		dest.pop();
		src.push(pole2TopDisk);
		MoveDisk(d, s, pole2TopDisk);
	}
	// When pole2 pole is empty 
	else if (dest.empty()) {
		int pole1TopDisk = src.top();
		src.pop();
		dest.push(pole1TopDisk);
		MoveDisk(s, d, pole1TopDisk);
	}
	else {
		int pole1TopDisk = src.top();
		int pole2TopDisk = dest.top();
		src.pop();
		dest.pop();
		// When top disk of pole1 > top disk of pole2 
		if (pole1TopDisk > pole2TopDisk) {
			src.push(pole1TopDisk);
			src.push(pole2TopDisk);
			MoveDisk(d, s, pole2TopDisk);
		}
		// When top disk of pole1 < top disk of pole2 
		else {
			dest.push(pole2TopDisk);
			dest.push(pole1TopDisk);
			MoveDisk(s, d, pole1TopDisk);
		}
	}
}

//Function to implement TOH puzzle 
void KTowerOfHanoi::Initialize(int numOfDisks)
{
 	for (KStack& s : m_stack) {
		s.clear();
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

	KStack& src = m_stack[m_iStackSrc];
	//Larger disks will be pushed first 
	for (int i = m_numOfDisks; i >= 1; i--)
		src.push(i);
}

//Function to implement TOH puzzle 
void KTowerOfHanoi::Iterate(double elapsedTime)
{
	if (m_moveState == EMoveState::ESTATE_FINISHED) {
		return;
	}

	m_oneStepTimer += elapsedTime;
	if (m_oneStepTimer < 1.0) {
		return;
	}
	m_oneStepTimer = 0.0;

	KStack& src = m_stack[m_iStackSrc];
	KStack& aux = m_stack[m_iStackAux];
	KStack& dest = m_stack[m_iStackDest];
	m_iterationCounter += 1;
	if (m_iterationCounter > m_totalNumOfMoves) {
		m_moveState = EMoveState::ESTATE_FINISHED;
		return;
	}

	if (m_iterationCounter % 3 == 1)
		MoveDisksBetweenTwoPoles(m_iStackSrc, m_iStackDest);
	else if (m_iterationCounter % 3 == 2)
		MoveDisksBetweenTwoPoles( m_iStackSrc, m_iStackAux);
	else if (m_iterationCounter % 3 == 0)
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
		for (int n : m_stack[i]) {
			_itoa_s(n, buffer, 10);
			PutText(x, y, buffer);
			PrintDisc(x - n, 20 + y, n); // jintaek on 20211031
			y -= 1;
		}
	}
}
