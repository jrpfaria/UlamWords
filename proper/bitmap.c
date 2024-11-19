#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define bit(p,x) (p[x / 8] >> (x % 8) & 1) /*Get the xth bit of p*/
#define set(p,x) p[x / 8] |= 1 << (x % 8) /*Set the xth bit of p to 1*/
#define ones(x) ((1U << i+1) - 1) /*Get a variable of length x with just '1's*/
#define max_length 13 /*Set to 13 because it was instantly completed with the Lists implementation*/

int is_ulam(uint64_t word, char** UlamWords, int l) {
    int num_reps = 0;
    uint64_t subword1, subword2;
    for (int i = 1; i < l; i++)
    {
        subword1 = word >> l-i;
        subword2 = word & ((1U << l-i) - 1);
        if (subword1 != subword2 || i != l - i)
            if (bit(UlamWords[i-1],subword1) && bit(UlamWords[l-i-1],subword2))
                if (++num_reps > 1)
                    return 0;
    }
    return num_reps;
}

int main(void)
{
    // Initialize Variables
    char** UlamWords = (char**)malloc(max_length * sizeof(char*));
    uint64_t* sizes = (uint64_t*)malloc(max_length * sizeof(uint64_t));

    // Initialize UlamWords Lists
    for (int i = 0, j = 3; i < 2; i++) {
        UlamWords[i]=(char*)malloc(sizeof(char));
        *UlamWords[i] = j<<i, sizes[i] = 2;
    }

    // Print stored values
    printf("UlamWords[0][0]: %d\n", UlamWords[0][0]);
    printf("UlamWords[1][0]: %d\n", UlamWords[1][0]);

    // Generate Ulam Words
    for (int i = 2; i < max_length; i++)
        for (int word = 0; word <= ones(i); word++) {
            UlamWords[i] = (char*)malloc(sizeof(char)*ones(i)/8+1);
            if (is_ulam(word, UlamWords, i+1))
                set(UlamWords[i], word), sizes[i]++;
        }

    // Print Results
    FILE* fp = fopen("Words.txt", "w");
    for (int i = 0; i < max_length; i++)
        fprintf(fp, "Length %d\n%ld\n", i+1, sizes[i]);

    // Free allocated memory
    for (int i = 0; i < 2; i++) {
        free(UlamWords[i]); // Free each char array
    }
    free(UlamWords); // Free the pointer array
    free(sizes); // Free the sizes array

    return 0;
}
