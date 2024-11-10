#include <iostream>
#include <vector>

#define MAX 25

using namespace std;

int main() {
    int frag[MAX], b[MAX], f[MAX], nb, nf;
    vector<bool> allocated(MAX, false); // Track allocated blocks

    cout << "Enter the number of blocks: ";
    cin >> nb;

    cout << "Enter the number of files: ";
    cin >> nf;

    // Input block sizes
    cout << "\nEnter the size of the blocks:\n";
    for (int i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    // Input file sizes
    cout << "Enter the size of the files:\n";
    for (int i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    // First Fit Allocation
    cout << "\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n";
    for (int i = 1; i <= nf; i++) {
        bool allocatedFlag = false;
        for (int j = 1; j <= nb; j++) {
            if (!allocated[j] && b[j] >= f[i]) { // Check if block is free and large enough
                frag[i] = b[j] - f[i]; // Calculate fragmentation
                allocated[j] = true; // Mark block as allocated
                cout << i << "\t\t" << f[i] << "\t\t" << j << "\t\t" << b[j] << "\t\t" << frag[i] << "\n";
                allocatedFlag = true;
                break; // Break as the file is allocated
            }
        }
        if (!allocatedFlag) {
            cout << i << "\t\t" << f[i] << "\t\t" << "Not Allocated" << "\n";
        }
    }

    return 0;
}
