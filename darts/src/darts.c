#include "darts.h"

const float inner_rad = 1.0f;
const float mid_rad = 5.0f;
const float outer_rad = 10.0;
const float inner_test = inner_rad * inner_rad;
const float mid_test = mid_rad * mid_rad;
const float outer_test = outer_rad * outer_rad;
const uint8_t inner_score = 10;
const uint8_t mid_score = 5;
const uint8_t outer_score = 1;

uint8_t score(coordinate_t pos) {
  float rad = pos.x * pos.x + pos.y * pos.y;
  if (rad > outer_test) {
      return 0;
  } else if (rad > mid_test) {
      return outer_score;
  } else if (rad > inner_test) {
      return mid_score;
  } else {
      return inner_score;
  }
}

