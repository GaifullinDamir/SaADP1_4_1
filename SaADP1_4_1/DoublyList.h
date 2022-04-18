#pragma once
struct DoublyList
{
	int data;
	DoublyList* pNext, *pPrevious;
};

void init(DoublyList*& pHead);
bool isEmpty(DoublyList* pHead);
bool searchForward(DoublyList* pHead, DoublyList*& pPrevious, DoublyList*& pCurrent, int searchedData);
bool searchBackward(DoublyList* pHead, DoublyList*& pPrevious, DoublyList*& pCurrent, int searchedData);
void deleteItem(DoublyList* pHead, DoublyList*& pCurrent);