
#include <iostream>

using namespace std;


class Doubly_Linked_List{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* frist,*last;
	int length;

public:

	Doubly_Linked_List()
{
		frist=last=NULL;
		length=0;
}
	bool Isempty()
	{
		return (length == 0);
	}
	void insertfrist(int value)
	{
		Node* newnode=new Node;
		newnode->data = value;

		if(Isempty())
		{
			frist=last=newnode;
			newnode->next=newnode->prev=NULL;
		}
		else
		{
			newnode->next=frist;
			newnode->prev=NULL;
			frist->prev=newnode;
			frist=newnode;
		}
		++length;
	}

	void insertlast(int value)
	{
		Node* newnode=new Node;
		newnode->data = value;
		newnode->next=NULL;
		if(Isempty())
		{
			newnode->next=newnode->prev=NULL;
			frist=last=newnode;
		}
		else
		{
			newnode->prev=last;
			last->next=newnode;
			last=newnode;

		}
		++length;
	}
	void insertatpos(int pos, int value)
	{
		if(pos<0  || pos>length)
		{
			cout<<"Out Of Range";
		}
		else{
			if(Isempty()|| pos==0)
				insertfrist(value);
			else if(pos == length)
				insertlast(value);
			else
			{
				Node* newnode=new Node;
				newnode->data = value;
				Node* temp=frist;
				for(size_t i=1;i<pos;i++)
				{
					temp=temp->next;
				}
				newnode->next=temp->next;
				newnode->prev=temp;
				temp->next->prev=newnode;
				temp->next=newnode;
				++length;
			}
		}
	}
	void Delete( int item)
	{
		if(Isempty())
		{
			cout<<"List is empty, no items to delete";
			return ;
		}
		else{
			Node *delptr=frist;
			if(frist->data == item)
			{
				frist=frist->next;
				frist->prev=NULL;
			}
			else{
				Node *temp=NULL;
				while(delptr->data != item )
				{
					temp=delptr;
					delptr=delptr->next;
				}
				temp->next=delptr->next;
				if(delptr->next != NULL )
					delptr->next->prev=temp;
				else
				{
					last=temp;
				}
			}
			delete delptr;
			--length;
		}
	}
	int getlength()
	{
		return length;
	}
	void Display()
	{
		Node* temp=frist;
		while(temp!=NULL)
		{
			cout<<temp->data<< " ";
			temp=temp->next;
		}
		cout<<"\n";
	}
	void ReverseDisplay()
	{
		Node* temp=last;
		while(temp!=NULL)
		{
			cout<<temp->data<< " ";
			temp=temp->prev;
		}
		cout<<"\n";
	}
	void destory()
	{
		Node* temp;
		while(frist!=NULL)
		{
			temp=frist;
			frist=frist->next;
			delete temp;
		}
		last=NULL;
		length=0;
	}
};
int main()
{
	Doubly_Linked_List D;
	D.insertfrist(30);
	D.insertlast(10);
	D.insertlast(40);
	D.insertlast(60);
	D.insertlast(50);
	D.Display();
	D.ReverseDisplay();
	cout<<"  ----------- \n";
	D.insertatpos(2,20);
	D.Display();
	D.ReverseDisplay();
	cout<<"  ----------- \n";
	D.Delete(10);
	D.Display();
	D.ReverseDisplay();
	D.destory();

	return 0;
}








































