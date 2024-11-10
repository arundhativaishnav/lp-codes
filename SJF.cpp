#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int p[20], bt[20], wt[20], tat[20], n, i, j, temp;
    float wtavg = 0.0, tatavg = 0.0;

    cout << "\nEnter the number of processes: ";
    cin >> n;

    cout << "\nEnter Burst Time for each process:\n";
    for (i = 0; i < n; i++) {
        p[i] = i + 1; // Process numbers from 1 to n
        cout << "P" << p[i] << ": ";
        cin >> bt[i];
    }

    // Sorting the burst times using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap corresponding process numbers
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0; // Waiting time for the first process is 0
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j]; // Sum of burst times of all previous processes
        }
    }

    // Calculate Turnaround Time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
    }

    // Calculate averages
    for (i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }
    wtavg /= n; // Average waiting time
    tatavg /= n; // Average turnaround time

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << wtavg;
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << tatavg << endl;

    return 0;
}
