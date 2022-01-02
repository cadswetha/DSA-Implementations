#include<iostream>
using namespace std;
void Push(char Stack[] ,int& top ,char x){
    top++;
    Stack[top]=x;
}
char Pop(char Stack[] ,int& top){
    char x = Stack[top];
    top--;
    return x;
}
int priority(char t)
{
    if (t == '*' || t == '/')
        return 2;
    else if (t == '+' || t == '-')
        return 1;
    else
        return -1;
}
int main()
{
    char Stack[50];
    int top=-1;
    string inFix;
    cout<<"enter infix expression:\n";
    cin>>inFix;
    string postFix = "\0";
    for(int i=0;i<inFix.size();i++){
        if(inFix[i]=='('){
            Push(Stack,top,inFix[i]);
        }
        else if(inFix[i]==')'){
            char ch = Pop(Stack ,top);
            while (ch!='(')
            {
                postFix += ch;
                ch =Pop(Stack ,top);
            }  
        }
        else if(inFix[i]=='*'||inFix[i]=='/'||inFix[i]=='-'||inFix[i]=='+'){
            while (top!=-1 && priority(inFix[i]) <= priority(Stack[top]))
            {
                char ch = Pop(Stack ,top);
                postFix += ch;
            }
            Push(Stack,top,inFix[i]);
        }
        else{
            postFix += inFix[i];
        }
    }
    while (top!=-1)
    {
        char ch = Pop(Stack ,top);
        postFix += ch;
    }
    cout<<postFix<<endl;
    return 0;
}
