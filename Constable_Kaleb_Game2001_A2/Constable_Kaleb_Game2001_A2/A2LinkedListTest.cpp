#include <iostream>
#include "A2LinkedList.h"
using namespace std;

int main()
{
	cout << "Singly Linked List" << endl << endl;

	LinkedList<int> linkedList;

	linkedList.Push(10);
	linkedList.Pop();
	linkedList.Push(32);
	linkedList.Push(301);
	linkedList.Push(40);
	linkedList.Push(1);
	linkedList.Pop();
	linkedList.Push(7010);

	cout << "Front element: " << linkedList.Front() << endl;

	LinkIterator<int> it;

	for (it = linkedList.Begin(); it != linkedList.End(); it++)
	{
		cout << " " << *it;
	}

	cout << endl << endl;

	return 0;
}