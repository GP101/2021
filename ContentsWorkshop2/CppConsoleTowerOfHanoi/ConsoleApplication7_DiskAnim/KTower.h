#pragma once
#include "KStack.h"
#include "KVector2.h"

class KTower
{
public:
	typedef std::vector<int>::iterator iterator;
private:
	KStack		m_stack;
	KVector2	m_position;
	int			m_numOfDisks;

public:
	KTower(int x = 0, int y = 0);
	void PushDisk(int d) { m_stack.push(d); }
	void PopDisk() { m_stack.pop(); }
	bool Empty() const { return m_stack.empty(); }
	int TopDisk() const { return m_stack.back(); }
	int GetDisk(int i) { return m_stack.at(i); }

	void Clear() { m_stack.clear(); }
	//KStack& GetStack() { return m_stack; }
	int GetDiskCount() const { return (int)m_stack.size(); }
	bool GetTopDiskPosition( KVector2& vOut );
	KVector2 GetPosition() { return m_position; }
	void Init(int x, int y, int numOfDisk);
	void Draw();
};

