#include <iostream>
using namespace std;

int main()
{
    int at[10], bt[10], pr[10], i, n, t ,smallest, count = 0, att[10], btt[10], prr[10], process[10], j = 0, count1 = 0, tat[10], wt[10];
    float avgtat = 0, avgwt = 0;
    cout << "Enter number of processes";
    cin >> n;
    cout << "Enter the arrival time, burst time, and priority of" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ":";
        cin >> at[i] >> bt[i] >> pr[i];
    }
    smallest=at[0];
    for(i=0;i<n-1;i++){
        if(at[i]>at[i+1])
            smallest=at[i+1];
    }
    t=smallest;
    cout << "Process\t Arrival_Time\tBurst_Time\tPriority\tTurn_Around_Time\tWaiting_Time" << endl;
    while (count1 < n)
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= t && bt[i] != 0)
            {
                att[count] = at[i];
                btt[count] = bt[i];
                prr[count] = pr[i];
                process[count] = i + 1;
                count++;
            }
        }
        for (i = 0; i < count - 1; i++)
        {
            for (j = i + 1; j < count; j++)
            {
                int temp;
                if (prr[i] > prr[j])
                {
                    temp = prr[i];
                    prr[i] = prr[j];
                    prr[j] = temp;

                    temp = btt[i];
                    btt[i] = btt[j];
                    btt[j] = temp;

                    temp = att[i];
                    att[i] = att[j];
                    att[j] = temp;

                    temp = process[i];
                    process[i] = process[j];
                    process[j] = temp;
                }
            }
        }
        t = t + btt[0];
        tat[process[0] - 1] = t - att[0];
        wt[process[0] - 1] = tat[process[0] - 1] - btt[0];
        bt[process[0] - 1] = 0;
        count1++;
        avgtat = avgtat + tat[process[0] - 1];
        avgwt = avgwt + wt[process[0] - 1];
        cout << "P" << process[0] << "\t\t" << att[0] << "\t\t" << btt[0] << "\t\t" << prr[0] << "\t\t" << tat[process[0] - 1] << "\t\t\t" << wt[process[0] - 1] << endl;
    }
    avgtat = avgtat / n;
    avgwt = avgwt / n;
    cout << "Average turn around time =" << avgtat << endl;
    cout << "Average waiting time =" << avgwt << endl;
    return 0;
}