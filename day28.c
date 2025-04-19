#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countFreq(int arr[], int n, int target) {
    // code here..
    int count = 0;
    for(int i=0; i<n;i++){
        if(arr[i]==target){
            count++;
        }
    }
    return count;
}


int main() {
    char ts[1001]; // Buffer to store the input for the number of test cases (shouldn't
                   // exceed 100 characters)
    fgets(ts, sizeof(ts),
          stdin);     // Read a line from standard input and store it in 'ts'
    int t = atoi(ts); // Convert the string 'ts' to an integer (number of test cases)

    // Loop over each test case
    while (t--) { // Decrease t by 1 each iteration and continue until t becomes 0

        char *line = NULL; // Pointer to store the input line (dynamically allocated)
        size_t len = 0;    // Size of the allocated buffer, used by getline function
        long read = getline(&line, &len, stdin); // Read a line from standard input into
                                                 // the dynamically allocated buffer

        int *nums = (int *)malloc(
            1000000 *
            sizeof(int)); // Dynamically allocate memory for up to 1e6 integers
        int n = 0; // Variable to count the number of integers in the current test case
        char *token =
            strtok(line, " "); // Tokenize the input line using space as a delimiter
        while (token != NULL) {
            // Print the current token (string) for debugging purposes
            // printf("Token: %s\n", token);

            // Convert each token to an integer and store it in the nums array
            nums[n++] = atoi(token);
            token = strtok(NULL, " "); // Get the next token
        }
        int x;
        scanf("%d\n", &x);
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }
        // Check if the array is sorted using the previously defined function
        int ans = countFreq(brr, n, x);
        printf("%d\n", ans);
        printf("~\n");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0;
}
