#include <iostream>
#include "DoublyList.h"
#include "UserInterface.h"

int main()
{
	DoublyList* pHead = new DoublyList;
	init(pHead);
	workWithUser(pHead);
	clearMemory(pHead);
}