/* expression evaluation infix to postfix and pretfix */
#include <iostream>
#include<stack>
#include<string>


using namespace std;

/*function to convert infix expression to postfix*/
string infixToPosrfix(string expression );
/*function to verify whether an operator has higher precedence over other*/
int HasHigherPrecedence(char op1,char op2);
/*function to verify whether a character is operator or not*/
bool IsOperator(char c);
/*function to verify whether a character is alphanumric or not*/
bool IsOperand(char c);
float Evaluate_postfix(string exp);
int main()
{
    string ex;
    cout<<"enter infix expression: ";
    getline(cin,ex);
    string postfix=infixToPosrfix(ex);
    cout<<" postfix output: "<<postfix<<"\n";
    //Evaluate_postfix(postfix);
    cout<<" the output of expression= "<<Evaluate_postfix(postfix)<<"\n";

    return 0;
}
/*function to convert infix expression to postfix*/
string infixToPosrfix(string expression )
{
    stack<char> s;
    string postfix="";/*empty string*/
    for(unsigned int i=0;i<expression.length();i++)
    {
        if(expression[i]== ' ' || expression[i]== ',')
            continue;
        else if(IsOperator(expression[i]))
        {
            while(!s.empty() && s.top() != '(' && HasHigherPrecedence(s.top(),expression[i]) )
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
        else if(IsOperand(expression[i]))
        {
              postfix+=expression[i];
        }
        else if(expression[i]=='(')
        {
            s.push(expression[i]);
        }
        else if(expression[i] == ')')
        {
               while(!s.empty() && s.top() != '('  )
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(! s.empty())
    {

        postfix+=s.top();
        s.pop();
    }

    return postfix;
}


/*function to verify whether a character is operator or not*/
bool IsOperator(char c)
{
    if(c== '+' || c== '-' || c== '*' ||c== '/' || c=='$')
         return true;

    return false;
}

/*function to verify whether a character is alphanumric or not*/
bool IsOperand(char c)
{
    if(c>='0' && c<='9')
        return true;
     else if(c>='a' && c<='z')
        return true;
     else if(c>='A' && c<='Z')
        return true;
    return false;
}

int GetOperatorWeight(char op)
{
    int weight=-1;
    switch(op)
    {
    case '+':
    case '-':
        weight=1;break;
    case '*':
    case '/':
        weight=2;break;
    case'$':
        weight=3;break;
    }
    return weight;
}

int IsRightAssociative(char op)
{
    if(op == '$')
        return true;
    return false;
}
/*function to verify whether an operator has higher precedence over other*/
int HasHigherPrecedence(char op1,char op2)
{

    int wop1=GetOperatorWeight(op1);
    int wop2=GetOperatorWeight(op2);
    if(wop1 == wop2)
    {
        if(IsRightAssociative(op1))
            return false;
        else
            return true;
    }
    return wop1>wop2?true:false;
}

float Evaluate_postfix(string exp)
{
    stack <float> s1;
    int i=0;
    float res=0;
    float operand1,operand2,value;
    while( i < exp.length())
    {
        if(isdigit(exp[i]))
            s1.push(float(exp[i]-'0'));
        else{
            operand2=s1.top();
            //cout<<operand2<<"\n";
            s1.pop();
            operand1=s1.top();
            //cout<<operand1<<"\n";
             s1.pop();
            switch(exp[i])
            {
            case '+':
                value=operand1+operand2;
                break;
            case '-':
                value=operand1-operand2;
                break;
            case '*':
                value=operand1*operand2;
                break;
            case '/':
                value=operand1/operand2;
                break;
            case '%':
                value=(int)operand1%(int)operand2;
                break;
            }
            s1.push(value);
        }
        ++i;
    }
      res=s1.top();
      s1.pop();
return res;
}
