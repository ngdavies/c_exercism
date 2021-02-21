#include "pangram.h"

#include <string.h>
#include <stdbool.h>
#include <ctype.h>


bool is_pangram(const char *sentence) {
  if (!sentence) {
    return false;
  }
  size_t len = strlen(sentence);
  if (len == 0) {
    return false;
  }

  bool seen_letter[26] = {false};
  for (size_t isen=0; isen<len; isen++) {
    char ch = sentence[isen];
    if (isalpha(ch)) {
        size_t ilet = toupper(ch) - 'A';
        seen_letter[ilet] = true;
    }
  }

  bool is_pan = true; 
  for (size_t ilet=0; ilet<26; ilet++) {
      is_pan &= seen_letter[ilet];
  }
  return is_pan;
}
