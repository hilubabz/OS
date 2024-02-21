#include<iostream>
using namespace std;

int main(){
    int i,j,block[10],process[10],n1,n2,check;
    cout<<"Enter the number of memory blocks";
    cin>>n1;
    cout<<"Enter the number of processes :";
    cin>>n2;
    for(i=0;i<n1;i++){
        cout<<"Enter memeory block "<<i+1<<":";
        cin>>block[i];
    }
    for(i=0;i<n2;i++){
        cout<<"Enter the memory required by process "<<i+1<<":";
        cin>>process[i];
    }
    cout<<"Process\tProcess Size\tMemory Block"<<endl;
    for(i=0;i<n2;i++){
        check=0;
        for(j=0;j<n1;j++){
             if(process[i]<=block[j]){
                 block[j]=block[j]-process[i];
                 check=1;
                 break;
             }
        }
        if(check!=1){
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<"Not allocated"<<endl;
        }
        else{
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<j+1<<endl;
        }
    }
}
