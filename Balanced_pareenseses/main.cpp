#include <iostream>

#include<stack>
using namespace std;

/* balanced parenceses '( ] } ' */
bool arepair(char open , char close)
{
     if(open =='(' && close == ')')
         return true;
     else if(open =='[' && close == ']')
         return true;
     else if(open =='{' && close == '}')
         return true;
     else
        return false;

}
bool arebalanced(string expresion)
{
    stack<char> s;
    for(size_t i=0; i<expresion.length();i++)
    {
        if(expresion[i]== '[' || expresion[i]=='(' || expresion[i]=='{' )
            s.push(expresion[i]);
        else if(expresion[i]== ']' || expresion[i]==')' || expresion[i]=='}')
        {
            if(s.empty() || !arepair(s.top(),expresion[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty()?true:false;
}

int main()
{
  string exp ;
  cout<< "Enter an expression: ";
  cin>>exp;
  if(arebalanced(exp))
    cout<< "balanced";
  else
    cout<< "not balanced";
    return 0;
}
