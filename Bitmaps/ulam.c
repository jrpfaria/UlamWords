#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define bit(p,x) (p[x / 8] >> (x % 8) & 1) /*Get the xth bit of p*/
#define set(p,x) p[x / 8] |= 1 << (x % 8) /*Set the xth bit of p to 1*/
#define ones(x) ((1ULL << x) - 1) /*Get a variable of length x with just '1's*/
#define max_length 30

int is_ulam(uint64_t word, char** UlamWords, int l) {
    int num_reps = 0;
    uint64_t subword1, subword2;
    for (int i = 1; i < l; i++)
    {
        subword1 = word >> l-i;
        subword2 = word & ones(l-i);
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
    FILE* fp = fopen("results.txt", "w");
    uint64_t size = 0;

    // Generate Ulam Words
    for (int i = 0, j = 3; i < max_length; i++, size=0)
    {
        UlamWords[i] = (char*)calloc(ones(i+1) / 8 + 1, 1);
        if (UlamWords[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for UlamWords[%d]\n", i);
            exit(EXIT_FAILURE);
        }
        if (i < 2)
        { 
            *UlamWords[i] = j<<i;
            size=2;
        }
        else
        {
            for (uint64_t word = 0; word <= ones(i+1); word++)
            {   if (is_ulam(word, UlamWords, i+1))
                {    
                    set(UlamWords[i], word);
                    size++;
                }
            }
        }
        fprintf(fp, "Length %d\n%ld\n", i+1, size);
    }
    
    // Free allocated memory
    for (int i = 0; i < max_length; i++) {
        free(UlamWords[i]); // Free each char array
    }
    free(UlamWords); // Free the pointer array
    
    // Close the file
    fclose(fp);

    return 0;
}