#include "acronym.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

const size_t MAX_TLA = 100;

char* abbreviate(const char* phrase) {
  if (!phrase) {
    return NULL;
  }
  size_t len = strlen(phrase);
  if (len == 0) {
    return NULL;
  }
  bool take_next = true;
  char* tla = calloc(MAX_TLA, sizeof(char));
  size_t itla = 0;
  // printf("phrase:%s, len: %zu\n", phrase, len);
  for (size_t ix=0; ix<len; ix++) {
    char ch = phrase[ix];
    assert(itla < MAX_TLA);
    // printf("ix: %2zu, itla: %zu, tla:%s: t_n: %d, ch: %c\n", ix, itla, tla, take_next, ch);
    if (ch == ' ' || ch == '-' || ch == '_') {
      take_next = true;
    } else {
      if (take_next) {
        tla[itla++] = toupper(ch);
        take_next = false;
      }
    }
  }
  // char* res = malloc((strlen(tla)+1) * sizeof(char));
  // strcpy(res,tla);
  // free(tla);
  // return res;
  tla = realloc(tla, (strlen(tla)+1)*sizeof(char));
  return tla;
}
