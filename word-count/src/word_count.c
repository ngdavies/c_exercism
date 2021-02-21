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
    
    if (sentence == NULL || words == NULL) {
        return OTHER_ERRORS;
    }
    
    size_t len = strlen(sentence);
    int count = 0;
    enum {INIT, SPACE, LETTER, SP2APOS, WD2APOS, ENDNULL} state = INIT;
    char* word = calloc(len+1, sizeof(char));
    for (size_t isen=0, iw=0; isen<len+1; isen++) {
        char ch = sentence[isen];
        switch (state) {
            case INIT:
                if (isalnum(ch)) {
                    word[iw++] = tolower(ch);
                    state = LETTER;
                } else {
                    state = SPACE;
                }
                break;
                
            case SPACE:
                if (ch == '\'') {
                    state = SP2APOS;
                }
                if (isalnum(ch)) {
                    word[iw++] = tolower(ch);
                    state = LETTER;
                }
                break;
                
            case LETTER:
                if (ch == '\'') {
                    state = WD2APOS;
                } else if (isalnum(ch)) {
                    word[iw++] = tolower(ch);
                } else {
                    // End of word, add it to the word count.
                    size_t index = find_word(word, words);
                    if (index > MAX_WORDS) {
                        // Not found, add new word
                        strcpy(words[count].text, word);
                        words[count].count = 1;
                        count++;
                    } else {
                        // Seen word before, increase the count
                        words[index].count += 1;
                    }
                    iw = 0;
                    memset(word, 0, (len+1*sizeof(char)));
                    state = SPACE;
                }
                break;
                
            case SP2APOS:
                if (isalnum(ch)) {
                    word[iw++] = tolower(ch);
                    state = LETTER;
                } else {
                    state = SPACE;
                }
                break;
                
            case WD2APOS:
                // design for a single included ' till tests fail
                if (isalnum(ch)) {
                    word[iw++] = '\'';
                    word[iw++] = tolower(ch);
                    state = LETTER;
                } else {
                    // End of word, add it to the word count.
                    size_t index = find_word(word, words);
                    if (index > MAX_WORDS) {
                        // Not found, add new word
                        strcpy(words[count].text, word);
                        words[count].count = 1;
                        count++;
                    } else {
                        // Seen word before, increase the count
                        words[index].count += 1;
                    }
                    iw = 0;
                    memset(word, 0, (len+1*sizeof(char)));
                    state = SPACE;
                }
                break;
                
            case ENDNULL:
                break;
        }
    }
#if 0
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
    
    size_t lenc = strlen(copy);
    char* word = calloc(lenc+1, sizeof(char));
    for (size_t isen=0, iw=0; isen<lenc+1; isen++) {
        char ch = copy[isen];
        if (ch == ' ' || ch == '\0') {
            size_t index = find_word(word, words);
            if (index > MAX_WORDS) {
                // Not found, add new word
                strcpy(words[count].text, word);
                words[count].count = 1;
                count++;
            } else {
                // Seen word before, increase the count
                words[index].count += 1;
            }
            iw = 0;
            memset(word, 0, (lenc+1*sizeof(char)));
        } else {
            // keep building the word
            word[iw++] = ch;
        }
    }
#endif
    return count;
}
