#include "acronym.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


char* abbreviate(const char* phrase) {
  if (!phrase) {
    return NULL;
  }
  size_t len = strlen(phrase);
  if (len == 0) {
    return NULL;
  }
  char* tla = calloc(len, sizeof(char));
  size_t itla = 0;
  bool take_next = true;
  for (size_t ix=0; ix<len; ix++) {
    char ch = phrase[ix];
    if (ch == ' ' || ch == '-' || ch == '_') {
      take_next = true;
    } else {
      if (take_next) {
        tla[itla++] = toupper(ch);
        take_next = false;
      }
    }
  }
  tla = realloc(tla, (strlen(tla)+1)*sizeof(char));
  return tla;
}
