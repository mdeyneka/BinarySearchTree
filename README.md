## Simple template classes for Binary Search Tree (BST) implementation

Binary search tree using shared pointers from C++

Realized operations on BST:
 - add
 - find (by key)
 - remove
 - size
 - get (value by key)
 - get minimum (value)
 - get maximum (value)
 
## Code usage

 Include header file:

    > #include "binarysearchtree.h"
	
 Declare BST:
   
    > BinarySearchTree<int, std::string> btree;
	
  or use pointer to BST:
  
    > BinarySearchTree<int, std::string> *btree = new BinarySearchTree<int, std::string>();
 
## License
New BSD License
