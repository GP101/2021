#include "KTower.h"
#include "MyUtil.h"

KTower::KTower(int x, int y)
{
	m_stack.clear();
	m_position = KVector2::zero;
	m_numOfDisks = 0;
}

bool KTower::GetTopDiskPosition(KVector2& vOut )
{
	if (Empty())
		return false;

	int y = (int)m_position.y - GetDiskCount();
	int x = (int)m_position.x - TopDisk();
	vOut = KVector2(x, y); // set [out] parameter
	return true;
}

void KTower::Init(int x, int y, int numOfDisk)
{
	m_position = KVector2(x, y);
	m_numOfDisks = numOfDisk;
}

void KTower::Draw()
{
	int x = (int)m_position.x;
	int y = (int)m_position.y;

	char buffer[80];
	for (int j = 0; j < GetDiskCount(); ++j) {
		const int n = GetDisk(j);
		_itoa_s(n, buffer, 10);
		//PutText(x, y, buffer);
		PrintDisc(x - n, y, n); // jintaek on 20211031
		y -= 1;
	}
	y = (int)m_position.y;
	for (int j = 0; j < m_numOfDisks + 1; ++j)
		PutText(x, y - j, "|");
}
