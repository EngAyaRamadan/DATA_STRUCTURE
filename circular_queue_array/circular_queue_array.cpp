#include <iostream>
#include<cassert>
/* circular queue based on array */
using namespace std;

template <class t>
class arrayQueue
{
 int rear;
 int Front;
 int length;
 t *arr;
 int maxsize;
public:
   arrayQueue(int len)
    {
        if(len<=0)
            maxsize=20;
         else
            maxsize=len;
        arr=new t[maxsize];
        Front =0;
        rear=maxsize - 1;
        length=0;

    }
   bool isEmpty()
    {
       return (length == 0);
    }
   bool isFull()
    {
       return (length == maxsize);
    }
   void enqueue(t element)
    {
      if(isFull())
        cout << "Queue is full\n";
      else{
        rear=(rear+1) % maxsize;
        arr[rear]=element;
        ++length;
      }
    }
   void dequeue(t element)
    {
      if(isEmpty())
        cout << "Queue is empty\n";
      else{
        Front=(Front+1) % maxsize;
        --length;
      }
    }
   int getfront ()
    {
      assert(!isEmpty());
      return arr[Front];
    }
   int getrear ()
    {
      assert(!isEmpty());
      return arr[rear];
    }

    t Search (t element)
    {
        int pos=-1;
       if(!isEmpty())
       {
         for(size_t i=Front;i!=rear;i=(i+1)%maxsize)
          {
            if(arr[i] == element)
             {
                pos=i;
                break;
             }
          }
          if(pos==-1)
          {
              if(arr[rear] == element)
                pos=rear;
          }
       }
        else{
            cout<<"Queue is empty";
          }
       return pos;
}
   void printQueue()
    {
      for(size_t i=Front;i!=rear;i=(i+1)%maxsize)
      {
          cout <<arr[i]<<" ";
      }
      cout <<arr[rear]<<"\n";
    }
};

int main()
{
    arrayQueue<int> q1(10);
    int x;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.printQueue();
    q1.dequeue(x);
    q1.printQueue();
    cout << "the front element: "<<q1.getfront()<<"\n";
    cout<< "the rear element: "<<q1.getrear()<<"\n";
    int result= q1.Search (40);
    if( result !=-1 )
        cout<< "the element found in position : "<<result<<"\n";
    else
        cout<< "the element not found ";

    return 0;
}
