#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(int arr[], int n, int d) {
  // Normalize d
  d = d % n; // In case d is greater than n
  if (d == 0)
    return; // No rotation needed

  // Step 1: Reverse the entire array
  reverse(arr, 0, n - 1);

  // Step 2: Reverse the first n - d elements
  reverse(arr, 0, n - d - 1);

  // Step 3: Reverse the last d elements
  reverse(arr, n - d, n - 1);
}

//{ Driver Code Starts.

int main() {
  char ts[1001]; // Buffer to store the input for the number of test cases
  fgets(ts, sizeof(ts), stdin); // Read a line from standard input
  int t = atoi(ts);             // Convert to integer (number of test cases)

  while (t--) { // Loop over each test case
    char *line = NULL;
    size_t len = 0;
    long read = getline(&line, &len, stdin);

    int *nums =
        (int *)malloc(1000000 * sizeof(int)); // Allocate memory for integers
    int n = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      nums[n++] = atoi(token); // Convert tokens to integers
      token = strtok(NULL, " ");
    }

    int x;
    scanf("%d\n", &x); // Read number of rotations

    rotateArr(nums, n, x); // Rotate the array

    for (int i = 0; i < n; i++) {
      if (i < n - 1)
        printf("%d ", nums[i]);
      else
        printf("%d\n", nums[i]);
    }

    free(nums); // Free dynamically allocated memory for nums
    free(line); // Free dynamically allocated memory for input line
  }

  return 0;
}
// } Driver Code Ends
