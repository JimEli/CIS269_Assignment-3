/*************************************************************************
* Title: Linked List Driver (CIS-269 Assignment #3)
* File: main.cpp
* Author: James Eli
* Date: 9/29/2018
*
* Block list driver program. Test list of blocks.
*
* Part 1 Node and Linked List Class (50 pts):
*   Create node with public properties: Block type block and block ptr
*   next. Create a linked list class that uses the node you generated
*   without an add or delete method with a head and optional tail and
*   counter. Make a driver that generates a node to test your
*   implementation.
*
* Part 2 Add Method (30 pts):
*   Create an add method in your linked list class which will add nodes
*   to the end of the list. Append to your driver function a way to test
*   your add function.
*
* Part 3 Find Method (10 pts):
*   Create a find method in linked list class that will find a node based
*   on its id from the block, if the node is found return the block object,
*   if not return NULL. Add code to your driver that checks for an
*   existing node and a non-existing node.
*
* Part 4 Delete Method (10 pts):
*   Create delete method, that will find and delete a node from the linked
*   list. If the node is removed the method return 0, and if the node
*   doesn't exist return -1. Add to your driver a few lines that checks
*   the delete methods.
*
* Notes:
*  (1) This program is a more general solution to the assignment by creating 
*      a templated singly-linked-list class. List contains only required 
*      functionality for demo.
*  (2) List "find" doesn’t function per assignment instructions, but I
*      think it meets the intent of the assignment.
*  (3) "delete" is C++ keyword, function renamed to "remove".
*  (4) UTSL, Singly-linked list researched by dissecting MS Visual Studio
*      list include file located on my computer here:
*      C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\
*      VC\Tools\MSVC\14.15.26726\include\list
*  (5) Iterator support researched per chapter 19, "The C++ Programming
*      Language", 3rd Edition, Bjarne Stroustrup.
*  (6) Smart pointers researched in "Using C++11’s Smart Pointers",
*      David Kieras, EECS Department, University of Michigan,
*      http://www.umich.edu/~eecs381/handouts/C++11_smart_ptrs.pdf
*  (7) Blockchain information researched in "Mastering Blockchain",
*      2nd Edition, Imram Bashir.
*  (8) Hash returns std:size_t, so it’s a 32-bit value on a 32-bit system, 
*      and a 64-bit value on a 64-bit system. Hash set to uinst32_t.
*  (9) Compiled/tested with MS Visual Studio 2017 Community (v141), and
*      Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse 
*      Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-269.
*************************************************************************
* Change Log:
*   09/29/2018: Initial release. JME
*************************************************************************/
#include <iostream> // cout
#include <ctime>    // time for random seed
#include <random>   // random
#include <string>   // string
#include <cassert>  // assert

#include "block.h"  // Block definitions
// myList has 2 versions (with & without smart pointers).
#include "list_with_smart_pointers.h"
//#include "list.h"

using namespace std;
using namespace myBlock;
using namespace myList;

// List size for demonstration.
const int LIST_SIZE = 5;

int main()
{
	// Lambda random number generator 0-5. Used to demonstrate a random block deletion.
	auto rng = []()-> uint32_t { return int((LIST_SIZE) * rand() / (RAND_MAX + 1.0)); };
	// Seed the rng.
	srand((unsigned)time(0)), rng();
	// Randomly select an ID for deletion.
	unsigned long id = rng() + 1;

	// Catch exceptions.
	try
	{
		// Part 1: Make list of blocks.
		list<Block> blockList;

		// Part 2: Fill list.
		for (std::size_t i = 0; i < LIST_SIZE; i++) 
		{
			Block b = Block(static_cast<unsigned long>(i+1), (i ? blockList.back().getHash() : (char*)"0"), static_cast<unsigned long>(i+1), time(0));
			blockList.add(b);
		}

		// Display list.
		cout << "Singly-linked list of blocks:\n" << blockList;

		// Delete a randomly selected block, iterated through list.
		for (auto it = blockList.begin(); it != blockList.end(); ++it)
		{
			// Check for id match.
			if (id == it->getID())
			{
				// Part 3: Test find exitsting & non-existing block.
				assert(blockList.find(*it));
				assert(!blockList.find(Block(0, (char*)"abc", 0, time(0))));

				// Part 4: Delete the random block and display updated list.
				if (blockList.remove(*it) == DELETE_SUCCESS)
					cout << "Singly-linked list after deleting block with ID: " << id << endl << blockList << endl;
				break;
			}
		}
	}
	catch (std::exception& e)
	{
		// Report exception and exit with failure code.
		cout << "Encountered exception: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}