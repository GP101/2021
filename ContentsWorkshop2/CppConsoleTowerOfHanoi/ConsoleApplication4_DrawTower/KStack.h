#pragma once

#include <stack>
#include <vector>

class KStack : public std::vector<int>
{
private:
	using std::vector<int>::push_back;
	using std::vector<int>::pop_back;
public:
	void push(int d)
	{
		__super::push_back(d);
	}
	void pop()
	{
		__super::pop_back();
	}
	bool empty()
	{
		return __super::size() == 0;
	}
	int top()
	{
		return __super::back();
	}
};
