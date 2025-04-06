//{ Driver Code Starts
#include <limits.h>
#include <stdio.h>
// } Driver Code Ends

// User function Template for C
int myAtoi(char *s) {
  // Your code here
  int ans = 0;
  int i = 0;
  int sign = 1;

  // 1. Skip leading whitespace
  while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' ||
         s[i] == '\f' || s[i] == '\v') {
    i++;
  }

  // 2. Handle optional sign
  if (s[i] == '-' || s[i] == '+') {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  // 3. Process numeric characters
  while (s[i] >= '0' && s[i] <= '9') {
    // 4. Handle integer overflow
    if (ans > INT_MAX / 10 ||
        (ans == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }
    ans = ans * 10 + (s[i] - '0');
    i++;
  }

  return sign * ans;
}

//{ Driver Code Starts.
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[20];
    scanf("%s", s);
    int ans = myAtoi(s);
    printf("%d\n~\n", ans);
  }
}
// } Driver Code Ends
