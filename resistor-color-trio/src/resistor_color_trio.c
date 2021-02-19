#include "resistor_color_trio.h"
#include <stdio.h>
#include <stdlib.h>


resistor_mag_t pow10(uint16_t y) {
  // Use my own integer power function
  resistor_mag_t res = 1;
  for (uint16_t i=0; i<y; i++) {
    res *= 10;
  }
  return res;
}

resistor_value_t color_code(resistor_band_t colors[]) {
  resistor_value_t value;
  resistor_mag_t mag;
  if (colors[1] == BLACK) { 
    mag = colors[0];
    colors[2] += 1; 
  }  else {
    mag = 10 * colors[0] + colors[1];
  }
  switch (colors[2]) {
      case BLACK:
        value.value = mag;
        value.unit = OHMS;
        break;
      case BROWN:
        value.value = mag * 10;
        value.unit = OHMS;
        break;
      case RED:
        value.value = mag * 100;
        value.unit = OHMS;
        break;
      case ORANGE:
        value.value = mag;
        value.unit = KILOOHMS;
        break;
      case YELLOW:
        value.value = mag * 10;
        value.unit = KILOOHMS;
        break;
      case GREEN :
        value.value = mag * 100;
        value.unit = KILOOHMS;
        break;
      case BLUE:
        value.value = mag;
        value.unit = MEGAOHMS;
        break;
      case VIOLET:
        value.value = mag * 10;
        value.unit = MEGAOHMS;
        break;
      case GREY:
        value.value = mag * 100;
        value.unit = MEGAOHMS;
        break;
      case WHITE:
        value.value = mag;
        value.unit = GIGAOHMS;
        break;

  }
  return value;
}


