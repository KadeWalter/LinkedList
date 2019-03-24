#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

Node *newNode(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void PrintList(Node *List)
{
	Node *current = List;
	while (current != NULL)
	{
		cout << current->value << endl;
		current = current->next;
	}
}

void InsertAtTail(Node *&List, int value)
{
	if (List == NULL)
		List = newNode(value);
	else
	{
		Node *curr = List;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = newNode(value);
	}
}

void InsertAtHead(Node *&List, int value)
{
	if (List == NULL)
		List = newNode(value);
	else
	{
		Node *nodeToAdd = newNode(value);
		nodeToAdd->next = List;
		List = nodeToAdd;
	}
}

void InsertInOrder(Node *&List, int value)
{
	if (List == NULL)
		List = newNode(value);
	else
	{
		Node *curr = List;
		if (curr->value > value) // check if we need to insert at the start
		{
			InsertAtHead(List, value);
		}
		else
		{
			while (curr->next != NULL && curr->next->value < value)
				curr = curr->next;
			if (curr->next != NULL) // used for inserting in the middle
			{
				Node *temp = newNode(value);
				temp->next = curr->next;
				curr->next = temp;
			}
			else
			{
				InsertAtTail(List, value); // used to insert at the end
			}
		}
	}
}

int main()
{
	Node *LinkedList = NULL;

	/* uncomment to test add at tail.
	// Insert always at the tail.
	for (int i = 0; i <= 100; i++)
		InsertAtTail(LinkedList, i);
	*/

	/* uncomment to test add at tail.
	// Insert always at the head.
	for(int i = 100; i >= 0; i--)
		InsertAtHead(LinkedList, i);
	*/

	// Insert in order.
	for (int i = 100; i >= 0; i--)
	{
		int randomNumToInsert;
		randomNumToInsert = rand() % 100 + 1;
		InsertInOrder(LinkedList, randomNumToInsert);
	}
	PrintList(LinkedList);
	cout << "Press Enter to Continue." << endl;
	cin.ignore();
	cin.ignore();
}