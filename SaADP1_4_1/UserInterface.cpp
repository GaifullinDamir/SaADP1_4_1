#include "UserInterface.h"
#include <iostream>
#include <string>
#include "DoublyList.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add an element to the list." << std::endl;
	std::cout << "2. Remove an element from the list." << std::endl;
	std::cout << "3. Display list on screen." << std::endl;
	std::cout << "4. Exit." << std::endl;
	std::cout << std::endl;
}

void printAddMenu()
{
	std::cout << std::endl;
	std::cout << "1. Insert element before specified." << std::endl;
	std::cout << "2. Insert element after specified." << std::endl;
	std::cout << std::endl;
}

void printDisplayMenu()
{
	std::cout << std::endl;
	std::cout << "1. Display list forward - (1)." << std::endl;
	std::cout << "2. Display list backward - (2)." << std::endl;
	std::cout << std::endl;
}

void printSearchMenu()
{
	std::cout << std::endl;
	std::cout << "1. Search forward - (1)." << std::endl;
	std::cout << "2. Search backward - (2)." << std::endl;
	std::cout << std::endl;
}

int userInput()
{
	int option = 0;
	bool check = true;
	std::string optionInput;
	while (check)
	{
		try
		{
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}
	}
	return option;
}

void workWithUser(DoublyList*& pHead)
{
	bool work = true;
	while (work)
	{
		printMainMenu();
		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput();
		switch (option)
		{
			case(AddItem):
			{
				caseAddItem(pHead);
				break;
			}
			case(DeleteItem):
			{
				caseDeleteItem(pHead);
				break;
			}
			case(Show):
			{
				caseShow(pHead);
				break;
			}
			case(Exit):
			{
				work = false;
				break;
			}
			default:
				std::cout << "   There is no such menu item." << std::endl;
				break;
		}
	}
}

void caseAddItem(DoublyList*& pHead)
{
	DoublyList* pCurrent = new DoublyList;

	if (isEmpty(pHead))
	{
		std::cout << "   Enter the item to add." << std::endl;
		int data = userInput();
		addAfter(pHead, pCurrent, data);
		std::cout << std::endl;
		std::cout << "   Item added." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   Enter an element instead of or after which to insert a new one." << std::endl;
		int currentData = userInput();
		bool check = true;
		printSearchMenu();
		int var = userInput();
		switch (var)
		{
			case(Forward):
				check = searchForward(pHead, pCurrent, currentData);
				break;
			case(Backward):
				check = searchBackward(pHead, pCurrent, currentData);
				break;
			default:
				std::cout << "   There is no such menu item." << std::endl;
				break;
		}
		if (check)
		{
			printAddMenu();
			int beforeOrAfter = userInput();
			std::cout << "   Enter the item to add." << std::endl;
			int data = userInput();

			switch (beforeOrAfter)
			{
				case(Before):
				{
					addBefore(pHead, pCurrent, data);
					break;
				}
				case(After):
				{
					addAfter(pHead, pCurrent, data);
					break;
				}
				default:
					std::cout << "   There is no such menu item." << std::endl;
					break;
			}
			std::cout << std::endl;
			std::cout << "   Item added." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such element." << std::endl;
		}
	}
}

void caseDeleteItem(DoublyList*& pHead)
{
	if (isEmpty(pHead))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	std::cout << "   Enter the item to delete." << std::endl;
	int currentData = userInput();
	DoublyList* pCurrent = new DoublyList;
	bool check = true;
	printSearchMenu();
	switch (userInput())
	{
	case(Forward):
		check = searchForward(pHead, pCurrent, currentData);
		break;
	case(Backward):
		check = searchBackward(pHead, pCurrent, currentData);
		break;
	default:
		std::cout << "   There is no such menu item." << std::endl;
		break;
	}
	if (check)
	{
		deleteItem(pCurrent);
		std::cout << std::endl;
		std::cout << "   Item deleted." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
}

void caseShow(DoublyList* pHead)
{
	if (isEmpty(pHead)) { std::cout << "   Nothing to show." << std::endl; }
	else
	{
		printDisplayMenu();
		switch (userInput())
		{
		case(Forward):
			showForward(pHead);
			break;
		case(Backward):
			showBackward(pHead);
			break;
		default:
			std::cout << "   There is no such menu item." << std::endl;
			break;
		}
	}
}