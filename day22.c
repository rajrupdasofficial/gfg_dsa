//{ Driver Code Starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// } Driver Code Ends

// User function Template for C

// Function to find the h-index
int hIndex(int citations[], int citationsSize) {
  // code here
  int n = citationsSize;
  int *freq = (int *)malloc((n + 1) * sizeof(int));

  for (int i = 0; i <= n; i++) {
    freq[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    if (citations[i] >= n) {
      freq[n]++;
    } else {
      freq[citations[i]]++;
    }
  }

  int Hindex = n;
  int num = freq[n];

  // Calculate H-Index
  while (num < Hindex) {
    Hindex--;
    num += freq[Hindex];
  }

  free(freq);
  return Hindex;
}

//{ Driver Code Starts.

int main() {
  char ts[1001];
  fgets(ts, sizeof(ts), stdin);
  int t = atoi(ts);
  while (t--) {
    char *line = NULL;
    size_t len = 0;
    long read = getline(&line, &len, stdin);

    int *nums = (int *)malloc(1000000 * sizeof(int));
    int n = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      nums[n++] = atoi(token);
      token = strtok(NULL, " "); // Get the next token
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = nums[i];
    }
    // char ch;
    // scanf("%c", &ch);
    // getchar();
    // Check if the array is sorted using the previously defined function
    int ans = hIndex(arr, n);
    printf("%d\n", ans);

    // printf("%s\n", "~");
    free(nums); // Free dynamically allocated memory for the nums array
    free(line); // Free dynamically allocated memory for the input line
  }

  return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
