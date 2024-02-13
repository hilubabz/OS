#include<iostream>
using namespace std;

int main() {
    int at[10], bt[10], i, n, t = 0, count = 0, att[10], btt[10], process[10], j = 0, tat[10], wt[10], bt2[10];
    float avgtat = 0, avgwt = 0;

    cout << "Enter number of processes";
    cin >> n;
    cout << "Enter the arrival time and burst time:" << endl;
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ":";
        cin >> at[i] >> bt[i];
        bt2[i]=bt[i];
    }

    cout << "Process\t Arrival_Time\tBurst_Time\tTurn_Around_Time\tWaiting_Time" << endl;
    while (count < n) {
        int count1 = 0;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && bt[i] != 0) {
                att[count1] = at[i];
                btt[count1] = bt2[i];
                
                process[count1] = i + 1;
                count1++;
            }
        }

        for (i = 0; i < count1 - 1; i++) {
            for (j = i + 1; j < count1; j++) {
                int temp;
                if (btt[i] > btt[j]) {
                    
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

        t++;
        bt[process[0] - 1]--;

        if (bt[process[0] - 1] == 0) {
            tat[process[0] - 1] = t - att[0];
            wt[process[0] - 1] = tat[process[0] - 1] - btt[0];
            avgtat += tat[process[0] - 1];
            avgwt += wt[process[0] - 1];
            cout <<"P"<< process[0] << "\t\t" << att[0] << "\t\t" << btt[0] << "\t\t" << tat[process[0] - 1] << "\t\t\t" << wt[process[0] - 1] << endl;
            count++;
        }
    }

    avgtat = avgtat / n;
    avgwt = avgwt / n;
    cout << "Average turn around time =" << avgtat << endl;
    cout << "Average waiting time =" << avgwt << endl;

    return 0;
}