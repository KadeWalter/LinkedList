#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node* newNode(int value)
{
	Node* temp = new Node;
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

void Insert(Node* &List, int value)
{
    if(List == NULL)
        List = newNode(value);
    else 
    {
        Node* curr = List;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = newNode(value);
    }
}

int main()
{
	Node* LinkedList = NULL;
	for (int i = 0; i <= 100; i++)
		Insert(LinkedList, i);
	PrintList(LinkedList);
	cout << "Press Enter to Continue." << endl;
	cin.ignore(); cin.ignore();
}