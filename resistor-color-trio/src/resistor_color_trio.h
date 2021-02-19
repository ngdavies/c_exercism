#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H


#include <stdint.h>

typedef uint16_t resistor_mag_t;
typedef enum {
  BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;
typedef enum {
    OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS
} resistor_unit_t;
typedef struct {
    resistor_mag_t value;
    resistor_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t[]);

#endif
