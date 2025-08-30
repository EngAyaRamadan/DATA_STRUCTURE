#include <iostream>
#include <cassert>
/* circular queue based on array */
using namespace std;

template <class t>
class linkedQueue
{
  struct Node
  {
    t item;
    Node *next;
  };
  Node *rear;
  Node *Front;
  int length;

public:
  linkedQueue() : Front(NULL), rear(NULL), length(0)
  {
  }
  bool isEmpty()
  {
    return (length == 0);
  }
  int getsize()
  {
    return length;
  }
  void enqueue(t element)
  {
    Node *newnode = new Node;
    newnode->item = element;
    newnode->next = NULL;

    if (isEmpty())
    {
      Front = newnode;
    }

    else
    {
      rear->next = newnode;
    }
    rear = newnode;
    ++length;
  }
  void dequeue()
  {
    if (isEmpty())
      cout << "Queue is empty\n";
    else
    {
      Node *temp = Front;
      if (Front == rear)
      {
        Front = rear = NULL;
      }
      else
      {
        Front = Front->next;
      }
      delete temp;
      --length;
    }
  }
  t getfront()
  {
    assert(!isEmpty());
    return Front->item;
  }
  t getrear()
  {
    assert(!isEmpty());
    return rear->item;
  }

  void printQueue()
  {
    if (isEmpty())
      cout << "Queue is empty\n";
    else
    {
      Node *current = Front;
      while (current != NULL)
      {
        cout << current->item << " ";
        current = current->next;
      }
      cout << "\n";
    }
  }
};
