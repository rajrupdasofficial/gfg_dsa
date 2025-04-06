//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution {
public:
  void pushZerosToEnd(vector<int> &arr) {
    // Code here
    int n = arr.size();
    int nonZeroIndex = 0; // Pointer for placing non-zero elements

    // Traverse the array
    for (int i = 0; i < n; ++i) {
      if (arr[i] != 0) {
        // Swap non-zero element to the position of nonZeroIndex
        swap(arr[nonZeroIndex], arr[i]);
        nonZeroIndex++;
      }
    }
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;     // Number of test cases
  cin.ignore(); // Ignore newline character after reading 't'

  while (t--) {
    vector<int> arr;
    string input;

    // Read the entire line of input
    getline(cin, input);

    // Use stringstream to parse integers from the line
    stringstream ss(input);
    int number;

    while (ss >> number) {
      arr.push_back(number);
    }

    Solution ob;
    int n = arr.size();

    // Call the function to move zeros to the end
    ob.pushZerosToEnd(arr);

    // Print the modified array
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }

    cout << "\n";
  }

  return 0;
}
// } Driver Code Ends
