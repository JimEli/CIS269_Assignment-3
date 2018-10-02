# Pima CC CIS269 
## Assignment #3
### Singly-Linked List

Class Driver Program. Tests our singly-linked list.

Part 1 Node and Linked List Class (50 pts):
Create node with public properties: Block type block and block ptr next. Create a linked list class that uses the node you generated without an add or delete method with a head and optional tail and counter. Make a driver that generates a node to test your implementation.

Part 2 Add Method (30 pts):
Create an add method in your linked list class which will add nodes to the end of the list. Append to your driver function a way to test your add function.

Part 3 Find Method (10 pts):
Create a find method in linked list class that will find a node based on its id from the block, if the node is found return the block object, if not return NULL. Add code to your driver that checks for an existing node and a non-existing node.

Part 4 Delete Method (10 pts):
Create delete method, that will find and delete a node from the linked list. If the node is removed the method return 0, and if the node doesn't exist return -1. Add to your driver a few lines that checks the delete methods.

Notes:
* This program is a more generic solution to the assignment by creating a templated singly-linked-list class. List contains only required functionality for demo.
* List "find" doesn’t function per assignment instructions, but I think it meets the intent of the assignment.
* "delete" is C++ keyword, function renamed to "remove".
* UTSL, Singly-linked list researched by dissecting MS Visual Studio list include file located on my computer here: C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.15.26726\include\list
* Iterator support researched per chapter 19, "The C++ Programming Language", 3rd Edition, Bjarne Stroustrup.
* Smart pointers researched in "Using C++11’s Smart Pointers", David Kieras, EECS Department, University of Michigan, http://www.umich.edu/~eecs381/handouts/C++11_smart_ptrs.pdf
* Blockchain information researched in "Mastering Blockchain", 2nd Edition, Imram Bashir.
* Hash returns std:size_t, so it’s a 32-bit value on a 32-bit system, and a 64-bit value on a 64-bit system. Hash set to uinst32_t.
* Compiled/tested with MS Visual Studio 2017 Community (v141), and Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
* Submitted in partial fulfillment of the requirements of PCC CIS-269.

