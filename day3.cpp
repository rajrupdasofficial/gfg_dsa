// reverse an array
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User function Template for C
void reverseArray(int arr[], int n) {
  int start = 0;   // Start index
  int end = n - 1; // End index

  // Swap elements until the start index is less than the end index
  while (start < end) {
    // Swap arr[start] and arr[end]
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Move towards middle
    start++;
    end--;
  }
}

// Driver Code Starts
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

    // Create a new array to hold the numbers
    int brr[n];
    for (int i = 0; i < n; i++) {
      brr[i] = nums[i];
    }

    // Reverse the array using the defined function
    reverseArray(brr, n);

    // Output the reversed array
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printf("%d\n", brr[i]);
        continue;
      }
      printf("%d ", brr[i]);
    }

    printf("%s\n", "~");

    free(nums); // Free dynamically allocated memory for the nums array
    free(line); // Free dynamically allocated memory for the input line
  }

  return 0; // Return 0 to indicate successful execution
}
// Driver Code Ends
