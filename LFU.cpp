#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main() {
    int numFrames, numReferences;
    
    cout << "Enter the number of page frames: ";
    cin >> numFrames;
    cout << "Enter the number of page references: ";
    cin >> numReferences;

    vector<int> pages(numReferences);
    cout << "Enter the page reference string: ";
    for (int &page : pages) cin >> page;

    vector<int> frames(numFrames, -1);
    map<int, int> frequency;
    int pageFaults = 0;

    for (int i = 0; i < numReferences; i++) {
        int currentPage = pages[i];
        bool found = false;

        // Check if the page is in frames
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                found = true;
                frequency[currentPage]++;
                break;
            }
        }

        // Page fault handling
        if (!found) {
            pageFaults++;
            int victimIndex = 0, minFreq = INT_MAX;

            // Find the least frequently used page
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] != -1 && frequency[frames[j]] < minFreq) {
                    minFreq = frequency[frames[j]];
                    victimIndex = j;
                }
            }

            frames[victimIndex] = currentPage; // Replace victim page
            frequency[currentPage] = 1; // Set frequency for new page
        }

        // Print current frame state
        for (int frame : frames) cout << frame << " ";
        if (!found) cout << "   Page Fault: " << pageFaults;
        cout << endl;
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
