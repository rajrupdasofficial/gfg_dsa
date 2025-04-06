//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
public:
  // Function to find maximum circular subarray sum.
  int circularSubarraySum(vector<int> &a) {
    int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX;
    int curr_max = 0, curr_min = 0;
    bool all_negative = true;
    for (int num : a) {
      total_sum += num;
      curr_max = max(num, curr_max + num);
      max_sum = max(max_sum, curr_max);
      curr_min = min(num, curr_min + num);
      min_sum = min(min_sum, curr_min);
      if (num > 0)
        all_negative = false;
    }
    if (all_negative)
      return max_sum;
    return max(max_sum, total_sum - min_sum);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    vector<int> arr;
    string input;

    // Read first array
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
      arr.push_back(number);
    }

    Solution ob;
    int res = ob.circularSubarraySum(arr);

    cout << res << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends
