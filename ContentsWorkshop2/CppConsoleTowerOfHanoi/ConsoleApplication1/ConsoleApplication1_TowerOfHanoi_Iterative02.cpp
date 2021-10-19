// C Program for Iterative Tower of Hanoi 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <limits.h> 
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

//Function to show the movement of disks 
void MoveDisk(char fromPeg, char toPeg, int disk)
{
	printf("Move the disk %d from \'%c\' to \'%c\'\n",
		disk, fromPeg, toPeg);
}

// Function to implement legal movement between 
// two poles 
void MoveDisksBetweenTwoPoles(KStack& src
	, KStack& dest, char s, char d)
{
	// When pole 1 is empty 
	if (src.empty())
	{
		int pole2TopDisk = dest.top();
		dest.pop();
		src.push(pole2TopDisk);
		MoveDisk(d, s, pole2TopDisk);
	}
	// When pole2 pole is empty 
	else if (dest.empty())
	{
		int pole1TopDisk = src.top();
		src.pop();
		dest.push(pole1TopDisk);
		MoveDisk(s, d, pole1TopDisk);
	}
	else
	{
		int pole1TopDisk = src.top();
		int pole2TopDisk = dest.top();
		src.pop();
		dest.pop();
		// When top disk of pole1 > top disk of pole2 
		if (pole1TopDisk > pole2TopDisk)
		{
			src.push(pole1TopDisk);
			src.push(pole2TopDisk);
			MoveDisk(d, s, pole2TopDisk);
		}

		// When top disk of pole1 < top disk of pole2 
		else
		{
			dest.push(pole2TopDisk);
			dest.push(pole1TopDisk);
			MoveDisk(s, d, pole1TopDisk);
		}
	}
}

//Function to implement TOH puzzle 
void TohIterative(int num_of_disks, KStack& src
	, KStack& aux, KStack& dest)
{
	int i, total_num_of_moves;
	char s = 'S', d = 'D', a = 'A';

	//If number of disks is even, then interchange 
	//destination pole and auxiliary pole 
	if (num_of_disks % 2 == 0)
	{
		char temp = d;
		d = a;
		a = temp;
	}
	total_num_of_moves = pow(2, num_of_disks) - 1;

	//Larger disks will be pushed first 
	for (i = num_of_disks; i >= 1; i--)
		src.push(i);

	for (i = 1; i <= total_num_of_moves; i++)
	{
		if (i % 3 == 1)
			MoveDisksBetweenTwoPoles(src, dest, s, d);

		else if (i % 3 == 2)
			MoveDisksBetweenTwoPoles(src, aux, s, a);

		else if (i % 3 == 0)
			MoveDisksBetweenTwoPoles(aux, dest, a, d);
	}
}

// Driver Program 
int main()
{
	// Input: number of disks 
	unsigned num_of_disks = 3;

	KStack src, dest, aux;

	TohIterative(num_of_disks, src, aux, dest);

	KStack::reverse_iterator it = dest.rbegin();
	while (it != dest.rend())
	{
		printf("%i\n", *it);
		++it;
	}
	return 0;
}
