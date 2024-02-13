#include<iostream>

using namespace std;

struct stack{
    char A[10];
    int top=-1;
}S;

void push(char a){
    S.A[++S.top]=a;
}
void pop(){
    S.top--;
}

int main(){
    string str;
    int len,state=0;
    cout<<"Enter a string :";
    cin>>str;
    len=str.length();
    if((len%2)!=0){
        cout<<"String rejected";
        return 0;
    }
    for(int i=0;i<len/2;i++){
        push(str[i]);
    }
    for(int i=len/2;i<len;i++){
        if(str[i]==S.A[S.top])
            pop();
    }
    if(S.top==-1)
        cout<<"String accepted";
    else
        cout<<"String rejected";
}