#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int bt[20], wt[20], tat[20], n;
    float wtavg = 0.0, tatavg = 0.0;

    cout << "\nEnter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
    }

    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0; // First process has no waiting time
    tat[0] = bt[0]; // Turnaround time for the first process is its burst time

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time for current process
        tat[i] = tat[i - 1] + bt[i]; // Turnaround time for current process
        wtavg += wt[i]; // Accumulate waiting time
        tatavg += tat[i]; // Accumulate turnaround time
    }

    // Display results
    cout << "\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << "\tP" << i + 1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << (wtavg / n);
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << (tatavg / n) << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore(); // Ignore the newline left in the input buffer
    cin.get(); // Wait for user to press Enter

    return 0;
}
