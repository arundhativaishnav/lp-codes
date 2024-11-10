#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits

#define MAX 25

using namespace std;

int main() {
    vector<int> frag(MAX, 0), b(MAX, 0), f(MAX, 0);
    vector<int> bf(MAX, 0), ff(MAX, 0);

    

    int nb, nf;

    // Input number of blocks and files
    
    cout << "\nEnter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    // Input block sizes
    cout << "\nEnter the size of the blocks:\n";
    for (int i = 1; i <= nb; ++i) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    // Input file sizes
    cout << "Enter the size of the files:\n";
    for (int i = 1; i <= nf; ++i) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    // Worst Fit Memory Allocation
    for (int i = 1; i <= nf; ++i) {
        int highest = 0; // Reset highest for each file
        for (int j = 1; j <= nb; ++j) {
            if (bf[j] != 1) { // If the block is not allocated
                int temp = b[j] - f[i]; // Calculate remaining space
                if (temp >= 0 && highest < temp) {
                    ff[i] = j; // Allocate the block
                    highest = temp; // Update the highest fragmentation
                }
            }
        }
        frag[i] = highest; // Store the fragmentation
        if (ff[i] != 0) {
            bf[ff[i]] = 1; // Mark the block as allocated
        }
    }

    // Output results
    cout << "\nFile No\tFile Size\tBlock No\tBlock Size\tFragment";
    for (int i = 1; i <= nf; ++i) {
        if (ff[i] != 0) {
            cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
        }
    }

    return 0;
}
