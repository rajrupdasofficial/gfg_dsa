#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse the subarray from 'start' to 'end'
void reverse(int arr[], int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Function to compute the next permutation of the array
void nextPermutation(int arr[], int n) {
  // Step 1: Find the first index 'i' such that arr[i] < arr[i+1] from the
  // right.
  int i = n - 2;
  while (i >= 0 && arr[i] >= arr[i + 1]) {
    i--;
  }

  // If such an index is found, then find the element to swap with.
  if (i >= 0) {
    // Step 2: Find the largest index 'j' (to the right of 'i') such that arr[j]
    // > arr[i]
    int j = n - 1;
    while (j > i && arr[j] <= arr[i]) {
      j--;
    }
    // Swap arr[i] and arr[j]
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  // Step 3: Reverse the subarray from i+1 to the end of the array.
  reverse(arr, i + 1, n - 1);
}

// Driver code
int main() {
  char ts[1001];
  fgets(ts, sizeof(ts), stdin);
  int t = atoi(ts);
  while (t--) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);

    int *nums = (int *)malloc(1000000 * sizeof(int));
    int n = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      nums[n++] = atoi(token);
      token = strtok(NULL, " ");
    }

    int brr[n];
    for (int i = 0; i < n; i++) {
      brr[i] = nums[i];
    }

    nextPermutation(brr, n);

    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printf("%d\n", brr[i]);
      } else {
        printf("%d ", brr[i]);
      }
    }
    printf("%s\n", "~");

    free(nums);
    free(line);
  }

  return 0;
}
