#include<iostream>
using namespace std;

#include "LinkedStack.h"

void legalMove(LinkedStack<int>& a, LinkedStack<int>& b)
{
	if (b.size() == 0)
	{
		int top;
		top = a.peek();
		a.pop();
		b.push(top);
	}
	else if (a.size() == 0)
	{
		int top;
		top = b.peek();
		b.pop();
		a.push(top);
	}
	else
	{
		if (a.peek() > b.peek())
		{
			int btop = b.peek();
			b.pop();
			a.push(btop);

		}
		else
		{
			int atop = a.peek();
			a.pop();
			b.push(atop);
		}
	}


}

void PrintTower(LinkedStack<int>& a, LinkedStack<int>& b, LinkedStack<int>& c)
{
	cout << "A";
	a.displayStack(cout);
	cout << "B";
	b.displayStack(cout);
	cout << "C";
	c.displayStack(cout);

	cout << "....................." << endl;

}
void towerSln(int rings, LinkedStack<int>& a, LinkedStack<int>& b, LinkedStack<int>& c) // for loop condition is when c.size ==  rings
{
	if (rings % 2 == 0)
	{
		bool complete = false;
		PrintTower(a, b, c);
		for (int i = 0; complete == false; i++)
		{

			legalMove(a, b);
			PrintTower(a, b, c);
			legalMove(a, c);
			PrintTower(a, b, c);
			legalMove(b, c);
			PrintTower(a, b, c);
			if (c.size() == rings)
				complete = true;

		}
	}
	else
	{
		bool complete = false;
		PrintTower(a, b, c);
		for (int i = 0; complete == false; i++)
		{
			legalMove(a, c);
			PrintTower(a, b, c);
			legalMove(a, b);
			PrintTower(a, b, c);
			legalMove(b, c);
			PrintTower(a, b, c);
			if (c.size() == rings)
				complete = true;
		}

	}
}
int main() //TODO: try catch 
{
	LinkedStack<int> stacka;
	LinkedStack<int> stackb;
	LinkedStack<int> stackc;

	int rings;
	cout << "Enter a number of rings between 3 and 10" << endl;
	cin >> rings;

	if (rings < 3 || rings>10)
	{
		cout << "Rings are must be between 3 and 10 try again" << endl;
	}
	else
	{
		for (int i = rings; i > 0; i--)
		{
			stacka.push(i);
		}
		//stacka.displayStack(cout);
	}

	towerSln(rings, stacka, stackb, stackc);

	return 0;
}