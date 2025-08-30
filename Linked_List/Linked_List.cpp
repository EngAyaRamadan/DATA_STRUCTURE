/*Single linked list*/
#include <iostream>

using namespace std;

class Linked_List
{
	struct Node
	{
		int data;
		Node *next;
	};
	Node *frist, *last;
	int length;

public:
	Linked_List()
	{
		frist = last = NULL;
		length = 0;
	}
	bool Isempty()
	{
		return (length == 0);
	}
	void insertfrist(int value)
	{
		Node *newnode = new Node;
		newnode->data = value;

		if (Isempty())
		{
			frist = last = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = frist;
			frist = newnode;
		}
		++length;
	}
	void insertlast(int value)
	{
		Node *newnode = new Node;
		newnode->data = value;
		newnode->next = NULL;

		if (Isempty())
		{
			frist = last = newnode;
		}
		else
		{

			last->next = newnode;
			last = newnode;
		}
		++length;
	}

	void insertatpos(int pos, int value)
	{
		if (pos < 0 || pos > length)
		{
			cout << "Out Of Range";
		}
		else
		{
			if (Isempty() || pos == 0)
			{
				insertfrist(value);
			}
			else
			{
				Node *newnode = new Node;
				newnode->data = value;
				if (pos == length)
					insertlast(value);
				else
				{
					Node *temp = frist;
					for (size_t i = 1; i < pos; i++)
					{
						temp = temp->next;
					}
					newnode->next = temp->next;
					temp->next = newnode;
				}
			}
		}
	}
	void Delete(int item)
	{
		if (Isempty())
		{
			cout << "List is empty, no items to delete";
			return;
		}
		else
		{
			Node *delptr = frist;
			if (frist->data == item)
			{
				frist = frist->next;
			}
			else
			{
				Node *temp = NULL;
				while (delptr->data != item)
				{
					temp = delptr;
					delptr = delptr->next;
				}
				temp->next = delptr->next;
			}
			delete delptr;
			--length;
		}
	}
	int Search(int value)
	{
		int pos = 0;
		Node *temp = frist;
		while (temp != NULL)
		{
			if (temp->data == value)
				return pos;
			temp = temp->next;
			++pos;
		}
		return -1;
	}
	void Reverse()
	{
		Node *prev, *current, *next;
		prev = NULL;
		current = frist;
		next = current->next;
		while (next != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		frist = prev;
	}
	void Display()
	{
		Node *temp = frist;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};
