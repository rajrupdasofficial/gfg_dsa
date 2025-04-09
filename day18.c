//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// } Driver Code Ends

// User function Template for C

int *search(char pat[], char txt[], int *resultSize) {
  // code here
  int M = strlen(pat);
  int N = strlen(txt);

  if (M == 0 || N == 0 || M > N) {
    *resultSize = 0;
    return NULL;
  }

  int *lps = (int *)malloc(M * sizeof(int));
  if (!lps)
    return NULL;
  lps[0] = 0;
  int len = 0;
  for (int i = 1; i < M;) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i++] = len;
    } else if (len != 0) {
      len = lps[len - 1];
    } else {
      lps[i++] = 0;
    }
  }
  int capacity = 100;
  int *res = (int *)malloc(N * sizeof(int));
  if (!res) {
    free(lps);
    return NULL;
  }
  int resIndex = 0;
  len = 0;
  for (int i = 0; i < N;) {
    if (pat[len] == txt[i]) {
      len++;
      i++;
    }
    if (len == M) {
      if (resIndex >= capacity) {
        capacity *= 2;
        res = (int *)realloc(res, capacity * sizeof(int));
        if (!res) {
          free(lps);
          return NULL;
        }
      }
      res[resIndex++] = i - len;
      len = lps[len - 1];
    } else if (i < N && pat[len] != txt[i]) {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        i++;
      }
    }
  }
  free(lps);
  res = (int *)realloc(res, resIndex * sizeof(int));
  *resultSize = resIndex;
  return res;
}

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    char *S = (char *)malloc(1000005 * sizeof(char));
    char *pat = (char *)malloc(1000005 * sizeof(char));
    scanf("%s\n", S);
    scanf("%s\n", pat);
    // char ch;
    // scanf("%c", &ch);
    // getchar();
    int resultSize = 0;
    int *res = search(pat, S, &resultSize);

    if (resultSize == 0) {
      printf("[]\n");
    } else {
      for (int i = 0; i < resultSize; i++) {
        printf("%d ", res[i]);
      }
      printf("\n");
    }

    free(res);
    // printf("%s\n","~");
  }
  return 0;
}
// } Driver Code Ends
