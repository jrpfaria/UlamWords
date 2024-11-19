#include "list.h"

int is_ulam(uint64_t word, WordList* UlamWords, int l) {
    int num_reps = 0;
    uint64_t subword1, subword2;
    for (int i = 1; i < l; i++)
    {
        subword1 = word >> l-i;
        subword2 = word & ((1U << l-i) - 1);

        if (subword1 != subword2 || i != l - i)
            if (found(subword1, &UlamWords[i-1]) && found(subword2, &UlamWords[l-i-1]))
                if (++num_reps > 1)
                    return 0;
    }
    return num_reps;
}

int main(int argc, char* argv[]) {
    // Read Input Arguments to test for given max length.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./ulam <max_length>\n");
        exit(0);
    }
    int max_length = atoi(argv[1]);

    // Initialize UlamWords Lists
    WordList* UlamWords = malloc(max_length * sizeof(WordList));
    for (int i = 0; i < max_length; i++) {
        UlamWords[i].head = NULL;
        UlamWords[i].tail = NULL;
        UlamWords[i].size = 0;
    }

    // Add static values for lengths 1 and 2
    for (int i = 0; i < 2; i++)
        add(&UlamWords[0], i), add(&UlamWords[1], i+1);
    
    // Minor test
    printf("List 0 size: %d\n", UlamWords[0].size);
    printf("List 1 size: %d\n", UlamWords[1].size);

    // Generate Ulam Words
    for (int i = 2; i < max_length; i++) {
        for (int word = 0; word <= ((1U << i+1) - 1); word++) {
            // printf("Testing Word: %d\n", word);
            if (is_ulam(word, UlamWords, i+1))
                add(&UlamWords[i], word);// printf("Added %d\n", word);
        }
        printf("List %d size: %d\n", i, UlamWords[i].size);
    }

    // Print Results
    FILE* fp = fopen("Words.txt", "w");
    for (int i = 0; i < max_length; i++)
        fprintf(fp, "Length %d\n%d\n", i+1, UlamWords[i].size);
    fclose(fp);

    // Helper print results
    if (max_length < 6){
        FILE* fp2 = fopen("debug.txt", "w");
        for (int i = 0; i < max_length; i++) {
            fprintf(fp2, "Length %2d:\n", i+1);
            Node* current = UlamWords[i].head;
            while (current != NULL) {
                fprintf(fp2, "%ld\n", current->value);
                current = current->next;
            }
        }
    }
    // Cleanup
    for (int i = 0; i < max_length; i++)
        freeWordList(&UlamWords[i]);
    free(UlamWords);

    return 0;
}
