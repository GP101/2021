#pragma once

#include <stack>
#include <vector>

class KStack
{
private:
	std::vector<int>	m_vector;
public:
	KStack() { m_vector.reserve(20); }
	void push(int d)
	{
		m_vector.push_back(d);
	}
	void pop()
	{
		m_vector.pop_back();
	}
	bool empty() const
	{
		return m_vector.size() == 0;
	}
	int top()
	{
		return m_vector.back();
	}
	int back() const { return m_vector.back(); }
	void clear() { m_vector.clear(); m_vector.reserve(20); }
	size_t size() const { return m_vector.size(); }

	int at(int i) { return m_vector.at(i); }
};
