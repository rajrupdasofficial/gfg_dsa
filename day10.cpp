//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  long long maxSubarraySum(vector<int> &arr) {
    long long maxh = 0, maxf = LLONG_MIN;

    for (auto num : arr) {
      maxh = std::max(num + maxh, (long long)num);
      maxf = std::max(maxf, maxh);
    }

    return maxf;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  cin.ignore(); // To discard any leftover newline characters
  while (t--)   // while testcases exist
  {
    vector<int> arr;
    string input;
    getline(cin, input); // Read the entire line for the array elements
    stringstream ss(input);
    int number;
    while (ss >> number) {
      arr.push_back(number);
    }

    Solution ob;
    cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
  }
}
// } Driver Code Ends
