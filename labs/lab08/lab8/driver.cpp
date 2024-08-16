/*
* Name: Angelica Vargas
* Lab: 08
* Date: 1, 2022
*/

#include "doublylinkedlist.h"

int main(int argc, char* argv[]) 
{
	IntDLLNode* root = nullptr;
	root = new IntDLLNode(4);
	root->next = new IntDLLNode(13);
	root->next->prev = root;
	root->next->next = new IntDLLNode(7);
	root->next->next->prev = root->next;
	root->next->next->next = new IntDLLNode(29);
	root->next->next->next->prev = root->next->next;
	root->next->next->next->next = new IntDLLNode(15);
	root->next->next->next->next->prev = root->next->next->next;

	//printing the unmodified list
	cout << "Original list: ";
	printList(root);
	
	//inserting an elements
	insert(root->next->next, new IntDLLNode(35), true);
	cout << "List with inserted element: ";
	printList(root);

	//tests
	//insert(root, new IntDLLNode(-1), false);
	//cout << "Inserted element before root: ";
	//printList(root);

	//insert(root->next->next->next->next->next, new IntDLLNode(5), true);
	//cout << "Inserted element after list ends: ";
	//printList(root);

	//swap two elements
	swap(root, root->next->next->next);
	cout << "Swapping 4 and 35: ";
	printList(root);

	while (root->prev != NULL) {
		root = root->prev;
	}

	//swap adjacent elements
	cout << "Swapping 29 and 15: ";
	swap(root->next->next->next->next, root->next->next->next->next->next);
	printList(root);

	return 0;
}