//{ Driver Code Starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort012(int arr[], int n) {
  // code here
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    switch (arr[mid]) {
    case 0: {
      int temp = arr[low];
      arr[low] = arr[mid];
      arr[mid] = temp;
    }
      low++;
      mid++;
      break;

    case 1:
      mid++;
      break;

    case 2: {
      int temp = arr[high];
      arr[high] = arr[mid];
      arr[mid] = temp;
    }
      high--;
      break;
    }
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

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
    sort012(arr, n);
    printArray(arr, n);

    printf("%s\n", "~");
    free(nums);
    free(line);
  }

  return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
