
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
public:
  int getMinDiff(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    vector<pair<int, int>> modifiedHeights;
    vector<int> frequency(n, 0);

    for (int i = 0; i < n; i++) {
      if (arr[i] - k >= 0) {
        modifiedHeights.emplace_back(arr[i] - k, i);
      }
      modifiedHeights.emplace_back(arr[i] + k, i);
    }

    sort(modifiedHeights.begin(), modifiedHeights.end());

    int left = 0, right = 0, covered = 0, minDifference = INT_MAX;

    while (right < modifiedHeights.size()) {
      if (frequency[modifiedHeights[right].second]++ == 0) {
        covered++;
      }

      while (covered == n) {
        minDifference = min(minDifference, modifiedHeights[right].first -
                                               modifiedHeights[left].first);

        if (--frequency[modifiedHeights[left].second] == 0) {
          covered--;
        }
        left++;
      }
      right++;
    }

    return minDifference;
  }
}

;

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int n, k;
    cin >> k;
    cin.ignore();
    vector<int> a, b, c, d;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num)
      a.push_back(num);

    Solution ob;
    auto ans = ob.getMinDiff(a, k);
    cout << ans << "\n";
    cout << '~' << endl;
  }
  return 0;
}
// } Driver Code Ends
