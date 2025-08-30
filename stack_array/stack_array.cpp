/* stack */
#include <iostream>
using namespace std;

template <class t>

#define max_size 100

class stack
{
  /*by default private */
  int top;
  /*size of stack>>>> store in int array data */
  t item[max_size];

public:
  /* construct >>> initial (call automatic  */
  stack() : top(-1) {}
  /* Add element in the stack  */
  void push(t element)
  {
    if (top >= max_size - 1)
      cout << "stack full on push" << endl;
    else
    {
      ++top;
      item[top] = element;
    }
  }
  bool IsEmpty()
  {
    return top < 0;
  }
  /* Delete element from the stack  */
  void pop()
  {
    if (IsEmpty())
      cout << "stack empty on pop" << endl;
    else
      --top;
  }
  /* Delete element from the stack and return it  */
  void pop(t &element)
  {
    if (IsEmpty())
      cout << "stack empty on pop" << endl;
    else
    {
      element = item[top];
      --top;
    }
  }
  void gettop(t &stacktop)
  {
    if (IsEmpty())
      cout << "stack empty on getpop" << endl;
    else
      stacktop = item[top];
  }
  void print()
  {
    cout << "[";
    for (int i = top; i >= 0; i--)
      cout << item[i] << " ";
    cout << "]";
    cout << endl;
  }
};
