#include "KTower.h"

KTower::KTower(int x, int y)
{
	m_stack.clear();
	m_position = KVector2::zero;
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