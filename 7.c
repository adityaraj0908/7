#include <stdio.h> 
#include <string.h> 

#define MAX_SIZE 20

void lcsAlgo(char S1[], char S2[]) {
    int i, j, m, n;
    int LCS_table[MAX_SIZE][MAX_SIZE];
    
    m = strlen(S1); 
    n = strlen(S2); 

    // Initialize the LCS_table with zeros
    for (i = 0; i <= m; i++) 
        LCS_table[i][0] = 0; 
    for (i = 0; i <= n; i++) 
        LCS_table[0][i] = 0; 

    // Fill the LCS_table based on the LCS algorithm
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) { 
            if (S1[i - 1] == S2[j - 1]) { 
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1; 
            } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) { 
                LCS_table[i][j] = LCS_table[i - 1][j]; 
            } else { 
                LCS_table[i][j] = LCS_table[i][j - 1]; 
            } 
        }
    }

    // Length of the LCS
    int index = LCS_table[m][n]; 
    char lcs[index + 1]; 
    lcs[index] = '\0'; 

    // Trace the LCS_table to get the LCS string
    i = m; 
    j = n; 
    while (i > 0 && j > 0) { 
        if (S1[i - 1] == S2[j - 1]) { 
            lcs[index - 1] = S1[i - 1]; 
            i--; 
            j--; 
            index--; 
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) {
            i--; 
        } else {
            j--; 
        }
    }

    // Print the result
    printf("S1: %s\nS2: %s\n", S1, S2); 
    printf("LCS: %s\n", lcs); 
}

int main() { 
    char S1[MAX_SIZE], S2[MAX_SIZE]; 

    printf("Enter the first string (S1): ");
    fgets(S1, sizeof(S1), stdin);
    // Remove newline character if present
    S1[strcspn(S1, "\n")] = '\0';

    printf("Enter the second string (S2): ");
    fgets(S2, sizeof(S2), stdin);
    // Remove newline character if present
    S2[strcspn(S2, "\n")] = '\0';

    lcsAlgo(S1, S2); 
    return 0; 
}
