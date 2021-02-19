#include "isogram.h"
#include "string.h"

bool is_isogram(const char phrase[]) {
  if (!phrase) {
    return false;
  }

  size_t len = strlen(phrase); 
  bool seen[26] = {false};
  for (size_t i=0; i<len; i++) {
    char ch = phrase[i];
    size_t ix;
    if (ch>='A' && ch<='Z') {
      ix = ch - 'A';
    } else if (ch>='a' && ch<='z') {
      ix = ch - 'a';
    } else {
       continue;
    }
    if (seen[ix]) {
      return false;
    }
    seen[ix] = true;
  }
  return true;
}
