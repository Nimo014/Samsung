#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countOminousNumbers(int a, int b, int k, const vector<int>& delNos) {
    int count = 0;
    unordered_set<int> deletedDigits(delNos.begin(), delNos.end()); // Use a set for quick lookups

    for (int i = a; i <= b; i++) {
        int temp = i;
        int deletedCount = 0;

        // Check each digit of the number
        while (temp > 0) {
            int digit = temp % 10;
            // Check if the digit is in the set of deleted digits
            if (deletedDigits.find(digit) != deletedDigits.end()) {
                deletedCount++;
            }

            // Early exit if deletedCount reaches k
            if (deletedCount >= k) {
                break;
            }
            temp /= 10;
        }

        // Count the number if deletedCount is less than k
        if (deletedCount < k) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k; // Input range and threshold
    int n;
    cin >> n; // Number of deleted digits

    vector<int> delNos(n); // Vector to store deleted digits
    for (int i = 0; i < n; i++) {
        cin >> delNos[i]; // Input deleted digits
    }

    cout << countOminousNumbers(a, b, k, delNos) << "\n"; // Call the function and print the result

    return 0;
}
