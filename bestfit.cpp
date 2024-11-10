#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits

#define MAX 25

using namespace std;

int main() {
    vector<int> frag(MAX, 0), b(MAX, 0), f(MAX, 0);
    vector<int> bf(MAX, 0), ff(MAX, 0);
    
   

    int nb, nf, temp, lowest;

    // Input number of blocks and files
    cout << "\nEnter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    // Input block sizes
    cout << "\nEnter the size of the blocks:-\n";
    for (int i = 1; i <= nb; ++i) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    // Input file sizes
    cout << "Enter the size of the files :-\n";
    for (int i = 1; i <= nf; ++i) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    // First Fit Memory Allocation with Best Fit Calculation
    for (int i = 1; i <= nf; ++i) {
        lowest = numeric_limits<int>::max(); // Reset lowest for each file
        for (int j = 1; j <= nb; ++j) {
            if (bf[j] != 1) { // Check if block is not allocated
                temp = b[j] - f[i]; // Calculate remaining space after allocation
                if (temp >= 0 && lowest > temp) { // Check for best fit
                    ff[i] = j; // Store the block number for the file
                    lowest = temp; // Update the lowest fragmentation
                }
            }
        }
        frag[i] = lowest; // Store fragmentation
        bf[ff[i]] = 1; // Mark the block as allocated
    }

    // Output the results
    cout << "\nFile No\tFile Size \tBlock No\tBlock Size\tFragment";
    for (int i = 1; i <= nf && ff[i] != 0; ++i) {
        cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    }

    return 0;
}
