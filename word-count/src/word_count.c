#include "word_count.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

// find_word - routine to search my words for a duplicate.
// inputs:
//   word = the word to test
//   words = the words found so far
//
// outputs
//   index = (if found) ? the index : SIZE_MAX

size_t find_word(const char* word, word_count_word_t* words) {
    for (size_t index = 0; index < MAX_WORDS; index++) {
        if (strcmp(word, words[index].text) == 0) {
            words[index].count += 1;
            return index;
        }
    }
    return SIZE_MAX;
}

// count_words - routine to classify the unique words and their frequency in a sentence
// inputs:
//    sentence =  a null-terminated string containing that is analyzed
//
// outputs:
//    words = allocated structure to record the words found and their frequency
//    uniqueWords - number of words in the words structure
//           returns a negative number if an error.
//           words will contain the results up to that point.
int count_words(const char *sentence, word_count_word_t * words) {
    int count = 0;
    
    if (sentence == NULL || words == NULL) {
        return OTHER_ERRORS;
    }
    
    size_t len = strlen(sentence);
    char* copy = calloc(len+1, sizeof(char));
    for (size_t isen=0, icop=0; isen<len; isen++) {
        // copy phrase and keep only alpha numeric. clean up spaces
        char ch = sentence[isen];
        if (isalpha(ch)) {
            copy[icop++] = tolower(ch);
        } else if (isnumber(ch)) {
            copy[icop++] = ch;
        } else if (isblank(ch)) {
            copy[icop++] = ' ';
        }
    }

    // debug
    printf("<%s>\n<%s>\n",sentence,copy);
    // end debug

    size_t lenc = strlen(copy);
    char* word = calloc(lenc+1, sizeof(char));
    for (size_t isen=0, iw=0; isen<lenc+1; isen++) {
        char ch = copy[isen];
        if (ch == ' ' || ch == '\0') {
            size_t index = find_word(word, words);
            if (index > MAX_WORDS) {
                strcpy(words[count].text, word);
                words[count].count = 1;
                count++;
                iw = 0;
                memset(word, 0, (lenc+1*sizeof(char)));
            } else {
                words[index].count += 1;
            }
        } else {
            // keep building the word
            word[iw++] = ch;
        }
    }

    return count;
}
