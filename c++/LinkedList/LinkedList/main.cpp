#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node *newNode(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void PrintList(Node* List)
{
	Node *current = List;
	while (current != NULL)
	{
		cout << current->value << endl;
		current = current->next;
	}

}

int main()
{
	Node *LinkedList = NULL;
	Node *current = NULL;
	for (int i = 0; i <= 100; i++)
	{
		Node *temp = newNode(i);
		if (LinkedList == NULL)
		{
			LinkedList = temp; // this is the head of the list
			current = LinkedList;
		}
		else
		{
			current->next = temp;
			current = temp;
		}
	}
	PrintList(LinkedList);
	cout << "Press Enter to Continue." << endl;
	cin.ignore();
}