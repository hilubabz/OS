#include<iostream>
using namespace std;
int main(){
    int bt[10],i,n,wt[10],tt[10];
    float aw=0,at=0;
    cout<<"Enter number of processes :";
    cin>>n;
        cout<<"Enter the burst time of process "<<endl;
    for(i=0;i<n;i++){
        cout<<"P"<<i+1<<":";
        cin>>bt[i];
    }
    wt[0]=0;
    cout<<"Process\t\tBurst Time\t\tWaiting Time\tTurn Around Time"<<endl;
    for(i=0;i<n;i++){
        tt[i]=wt[i]+bt[i];
        cout<<"P"<<i+1<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
        wt[i+1]=wt[i]+bt[i];
    }
    
    for(i=0;i<n;i++){
        aw=aw+wt[i];
        at=at+tt[i];
    }
        aw=aw/n;
        at=at/n;
        cout<<"Average waiting time="<<aw<<endl;
        cout<<"Average turn around time="<<at<<endl;
    return 0;
}