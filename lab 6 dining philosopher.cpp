#include<iostream>

using namespace std;

bool wait(int a){
    if(a!=0){
        return true;
    }
    else
        return false;
}

int main(){
    int n,chopstick[10],count=0,i,check[10],phil[10];
    cout<<"Enter the total number of philosophers :";
    cin>>n;
    for(i=0;i<n;i++){
        chopstick[i]=1;
        check[i]=0;
        phil[i]=0;
    }
    
    while(count<n){
        for(i=0;i<n;i++){
            if(check[i]==1){
                cout<<"Philosopher "<<i+1<<" has finished eating "<<endl;
                check[i]=0;
                phil[i]=1;
                chopstick[i]++;
                chopstick[(i+1)%n]++;
                count++;
            }
            if(phil[i]==0){
            
            if(wait(chopstick[i])&&wait(chopstick[(i+1)%n])){
                chopstick[i]--;
                chopstick[(i+1)%n]--;
                cout<<"Philosopher "<<i+1<<" is eating"<<endl;
                check[i]=1;
            }
            else{
                cout<<"Philosopher "<<i+1<<" is waiting"<<endl;
            }
        }
        }
    }
}