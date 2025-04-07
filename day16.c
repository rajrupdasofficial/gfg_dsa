#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool areAnagrams(char s1[], char s2[]) {
  if (strlen(s1) != strlen(s2))
    return false;

  int freq1[26] = {0};
  int freq2[26] = {0};

  for (int i = 0; i < strlen(s1); i++) {
    freq1[s1[i] - 'a']++;
    freq2[s2[i] - 'a']++;
  }

  // Compare the frequency arrays
  for (int i = 0; i < 26; i++) {
    if (freq1[i] != freq2[i])
      return false;
  }

  return true;
}

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d\n", &t);

  while (t--) {
    // Dynamically allocate memory for strings
    char *c = (char *)malloc(100005 * sizeof(char));
    char *d = (char *)malloc(100005 * sizeof(char));

    // Input the strings
    scanf("%s\n", c);
    scanf("%s\n", d);
    // Check if they are anagrams and print the result
    if (areAnagrams(c, d))
      printf("true\n");
    else
      printf("false\n");
    printf("%s\n", "~");

    // Free the allocated memory
    free(c);
    free(d);
  }

  return 0;
}

// } Driver Code Ends
