#pragma once
struct DoublyList
{
	int data;
	DoublyList* next, *previous;
};

void init(DoublyList*& pHead);
bool isEmpty(DoublyList* pHead);
bool searchForward(DoublyList* pHead, DoublyList*& pCurrent, int searchedData);
bool searchBackward(DoublyList* pHead, DoublyList*& pCurrent, int searchedData);
void deleteItem(DoublyList* pHead, DoublyList*& pCurrent);
void addAfter(DoublyList*& pHead, DoublyList*& pCurrent, int data);
void addBefore(DoublyList*& pHead, DoublyList*& pCurrent, int data);
void showForward(DoublyList* pHead);
void showBackward(DoublyList* pHead);