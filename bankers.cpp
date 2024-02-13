#include<iostream>
using namespace std;

int main(){
    int n,m,all[10][10],max[10][10],req[10][10],av[10],i,j,k,l,count=0,check=0,sequence[10],count1=0;
    cout<<"Enter number of processes :";
    cin>>n;
    cout<<"Enter number of resources :";
    cin>>m;
    for(i=0;i<n;i++){
        cout<<"Enter the allocated resources for process "<<i+1<<":";
        for(j=0;j<m;j++){
            cin>>all[i][j];
        }
    }
    for(i=0;i<n;i++){
        cout<<"Enter the maximum required resources for process "<<i+1<<":";
        for(j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter the available resources :";
    for(i=0;i<m;i++){
        cin>>av[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            req[i][j]=max[i][j]-all[i][j];
        }
    }

    while(count<n){
        for(i=0;i<n;i++){
            check=0;
            for(j=0;j<m;j++){
                if(req[i][j]>av[j]){
                    check=1;
                }
            }
            if(check==0){
                sequence[count]=i+1;
                for(k=0;k<m;k++){
                    av[k]+=all[i][k];
                }
                count++;
                count1=0;
            }
            if(check==1){
                count1++;
                if(count1==n){
                    cout<<"The following system is not safe and consists deadlock";
                    return 0;
                }
            }
        }
    }
    cout<<"The following system is safe and the safe sequence is "<<endl;
    for(i=0;i<n;i++){
        cout<<"P"<<sequence[i]<<" -> ";
    }
}