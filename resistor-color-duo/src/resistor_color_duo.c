#include "resistor_color_duo.h"
#include <stdio.h>
#include <stdlib.h>

uint16_t color_code(resistor_band_t colors[]) {
  uint16_t resistance = 10 * colors[0] + colors[1];
  return resistance;
}
