#include <iostream>
#include "DoublyList.h"

void init(DoublyList*& pHead)
{
	pHead->pPrevious = pHead;
	pHead->pNext = pHead;
}

bool isEmpty(DoublyList* pHead)
{
	return (pHead->pNext == pHead->pPrevious);
}

bool forwardSearch(DoublyList* pHead, DoublyList*& pPrevious, DoublyList*& pCurrent, int searchedData)
{
	pPrevious = pHead;
	pCurrent = pHead->pNext;
	while (pCurrent != pHead)
	{
		if (pCurrent->data == searchedData) { return true; }
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == pHead) { return false; }
}

bool searchBackward(DoublyList* pHead, DoublyList*& pPrevious, DoublyList*& pCurrent, int searchedData)
{
	pPrevious = pHead->pPrevious->pPrevious;
	pCurrent = pHead->pPrevious;
	while (pCurrent != pHead)
	{
		if (pCurrent->data == searchedData) { return true; }
		pPrevious = pCurrent;
		pCurrent = pCurrent->pPrevious;
	}
	if (pCurrent == pHead) { return false; }
}

void deleteItem(DoublyList* pHead, DoublyList*& pCurrent)
{
	pCurrent->pPrevious->pNext = pCurrent->pNext;
	pCurrent->pNext->pPrevious = pCurrent->pPrevious;
	delete pCurrent;
	pCurrent = nullptr;
}

void addAfter(DoublyList*& pHead, DoublyList*& pCurrent, int data)