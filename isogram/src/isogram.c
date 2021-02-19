#include "isogram.h"
#include <ctype.h>

bool is_isogram(const char phrase[]) {
  if (!phrase) {
    return false;
  }

  bool seen[26] = {false};
  for (; *phrase; phrase++) {
    size_t ix;
    if (isupper(*phrase)) {
      ix = *phrase - 'A';
    } else if (islower(*phrase)) {
      ix = *phrase - 'a';
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
