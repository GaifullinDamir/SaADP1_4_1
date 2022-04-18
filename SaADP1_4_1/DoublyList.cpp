#include <iostream>
#include "DoublyList.h"

void init(DoublyList*& pHead)
{
	pHead->previous = pHead;
	pHead->next = pHead;
}

bool isEmpty(DoublyList* pHead)
{
	return (pHead->next == pHead->previous);
}

bool searchForward(DoublyList* pHead, DoublyList*& pCurrent, int searchedData)
{
	pCurrent = pHead->next;
	while (pCurrent != pHead)
	{
		if (pCurrent->data == searchedData) { return true; }
		pCurrent = pCurrent->next;
	}
	if (pCurrent == pHead) { return false; }
}

bool searchBackward(DoublyList* pHead, DoublyList*& pCurrent, int searchedData)
{
	pCurrent = pHead->previous;
	while (pCurrent != pHead)
	{
		if (pCurrent->data == searchedData) { return true; }
		pCurrent = pCurrent->previous;
	}
	if (pCurrent == pHead) { return false; }
}

void deleteItem(DoublyList*& pCurrent)
{
	pCurrent->previous->next = pCurrent->next;
	pCurrent->next->previous = pCurrent->previous;
	delete pCurrent;
	pCurrent = nullptr;
}

void addAfter(DoublyList*& pHead, DoublyList*& pCurrent, int data)
{
	if (isEmpty(pHead))
	{
		DoublyList* pAdded = new DoublyList;
		pAdded->data = data;
		pAdded->next = pHead;
		pAdded->previous = pHead;
		pHead->next = pAdded;
		pHead->previous = pAdded;
	}
	DoublyList* pTemporary = new DoublyList;
	pTemporary->data = data;
	pTemporary->next = pCurrent->next;
	pTemporary->previous = pCurrent;
	pCurrent->next->previous = pTemporary;
	pCurrent->next = pTemporary;
}

void addBefore(DoublyList*& pHead, DoublyList*& pCurrent, int data)
{
	DoublyList* pTemporary = new DoublyList;
	pTemporary->data = data;
	pTemporary->next = pCurrent;
	pTemporary->previous = pCurrent->previous;
	pCurrent->previous->next = pTemporary;
	pCurrent->previous = pTemporary;
}

void showForward(DoublyList* pHead)
{
	if (!isEmpty(pHead))
	{
		DoublyList* pCurrent = pHead->next;
		while (pCurrent != pHead)
		{
			std::cout << "   " << pCurrent->data << std::endl;
			pCurrent = pCurrent->next;
		}
		std::cout << std::endl;
	}
	else std::cout << "List is empty." << std::endl;
}

void showBackward(DoublyList* pHead)
{
	if (!isEmpty(pHead))
	{
		DoublyList* pCurrent = pHead->previous;
		while (pCurrent != pHead)
		{
			std::cout << "   " << pCurrent->data << std::endl;
			pCurrent = pCurrent->previous;
		}
		std::cout << std::endl;
	}
	else std::cout << "List is empty." << std::endl;
}

void clearMemory(DoublyList*& pHead)
{
	DoublyList* pCurrent = nullptr;

	while (pCurrent != pHead)
	{
		deleteItem(pCurrent);
		pCurrent = pCurrent->next;
	}
	pHead = nullptr;
}