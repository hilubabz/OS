#include <iostream>
using namespace std;

int main()
{
    int bt[10], btt[10], n, i, count = 0, t = 0, qt, tat[10], wt[10];
    float avgwt,avgtat;
    cout << "Enter number of processes :";
    cin >> n;
    cout << "Enter the burst time for " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ":";
        cin >> bt[i];
    }
    for (i = 0; i < n; i++)
    {

        btt[i] = bt[i];
    }
    cout << "Enter the quantum time :";
    cin >> qt;
    cout << "Process\tBurst_Time\tTurn_Around_Time\tWaiting_Time" << endl;

    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (bt[i] > 0)
            {
                if (bt[i] > qt)
                {
                    bt[i] = bt[i] - qt;
                    t = t + qt;
                }
                else
                {
                    t = t + bt[i];
                    bt[i] = 0;
                    tat[i] = t;
                    wt[i] = tat[i] - btt[i];
                    avgtat+=tat[i];
                    avgwt+=wt[i];
                    cout << "P" << i + 1 << "\t\t" << btt[i] << "\t\t" << tat[i] << "\t\t\t" << wt[i] << endl;
                    count++;
                }
            }
        }
    }
    avgtat=avgtat/n;
    avgwt=avgwt/n;
    cout<<"Average turn around time ="<<avgtat<<endl;
    cout<<"Average waiting time ="<<avgwt<<endl;
    return 0;
}