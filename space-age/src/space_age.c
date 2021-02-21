#include "space_age.h"

const float secs2earthYears = 31557600;
const float secs2years[] = {
   1.0f / (secs2earthYears * 0.2408467  ), // - Mercury: orbital period 0.2408467  Earth years
   1.0f / (secs2earthYears * 0.61519726 ), // - Venus:   orbital period 0.61519726 Earth years
   1.0f / (secs2earthYears * 1.0        ), // - Earth:   orbital period 1.0        Earth years, 365.25 Earth days, or 31557600 seconds
   1.0f / (secs2earthYears * 1.8808158  ), // - Mars:    orbital period 1.8808158  Earth years
   1.0f / (secs2earthYears * 11.862615  ), // - Jupiter: orbital period 11.862615  Earth years
   1.0f / (secs2earthYears * 29.447498  ), // - Saturn:  orbital period 29.447498  Earth years
   1.0f / (secs2earthYears * 84.016846  ), // - Uranus:  orbital period 84.016846  Earth years
   1.0f / (secs2earthYears * 164.79132  ), // - Neptune: orbital period 164.79132  Earth years
};

float age(planet_t planet, int64_t seconds) {
    return seconds * secs2years[planet];
}

