#include <stdio.h>
#include <stdlib.h>

// User function Template for C
int *findMajority(int arr[], int n, int *resultSize) {
  // Initialize candidates and their counts
  int c1 = -1, c2 = -1, count1 = 0, count2 = 0;

  // First pass: Find potential candidates for majority elements
  for (int i = 0; i < n; i++) {
    if (arr[i] == c1) {
      count1++;
    } else if (arr[i] == c2) {
      count2++;
    } else if (count1 == 0) {
      c1 = arr[i];
      count1 = 1;
    } else if (count2 == 0) {
      c2 = arr[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }

  // Reset counts for verification
  count1 = 0;
  count2 = 0;

  // Second pass: Count occurrences of candidates
  for (int i = 0; i < n; i++) {
    if (arr[i] == c1) {
      count1++;
    } else if (arr[i] == c2) {
      count2++;
    }
  }

  // Prepare the result array
  int *res = (int *)malloc(2 * sizeof(int));
  *resultSize = 0;

  // Check if candidates are indeed majority elements
  if (count1 > n / 3) {
    res[(*resultSize)++] = c1;
  }
  if (count2 > n / 3) {
    res[(*resultSize)++] = c2;
  }

  // Sort the results if two elements exist
  if (*resultSize == 2 && res[0] > res[1]) {
    int temp = res[0];
    res[0] = res[1];
    res[1] = temp;
  }

  // Return NULL if no majority elements found
  if (*resultSize == 0) {
    free(res);
    return NULL;
  }

  return res;
}
