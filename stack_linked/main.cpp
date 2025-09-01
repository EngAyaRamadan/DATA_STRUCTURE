#include <iostream>
/* linked stack */
using namespace std;
template <class t>

class Stack{
             struct node
             {
                 t item;
                 node* next;
             };
              node* top;
        public:
              Stack()
              {
                  top=NULL;
              }
              void push(t new_item )
              {
                  node* new_node= new node;
                   if(new_node == NULL)
                     cout<< "Stack push cannot allocate memory";
                   else {
                  new_node->item=new_item;
                  new_node->next= top;
                  top = new_node;
                  }
              }
              bool isEmpty()
              {
                  return (top == NULL);
              }
            void pop()
              {
                if(isEmpty())
                     cout<< "Stack is empty in pop";
                else
                {
                 node* temp=top;
                 top=top->next;
                 temp=temp->next=NULL;
                 delete temp;
                }
              }
            void pop(t &stacktop)
              {
                if(isEmpty())
                     cout<< "Stack is empty in pop";
                else
                {
                 stacktop=top->item;
                 node* temp=top;
                 top=top->next;
                 temp=temp->next=NULL;
                 delete temp;
                }
              }

               void gettop(t &stacktop)
              {
                if(isEmpty())
                     cout<< "Stack is empty in getTop";
                else
                 stacktop=top->item;
              }
              void display()
              {
                  node* current_ptr;
                  cout<< "[";
                  current_ptr=top;
                while(current_ptr!=NULL)
                {
                    cout<< current_ptr->item<<" ";
                    current_ptr=current_ptr->next;
                }
                cout<< "]\n";
              }
};


int main()
{
    Stack<int> s;
    int ret;
    s.push(100);
    s.push(10);
    s.push(3);
    s.push(6);
    s.pop();
    s.pop(ret);
    cout<< ret<<"\n";
    s.gettop(ret);
    cout<< ret<<"\n";
    s.display();
    return 0;
}
