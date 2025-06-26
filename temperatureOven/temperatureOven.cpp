#include "temperatureOven.h"

double simulateOven(double temp, double power, double dt) {
    const double heating_rate = 0.1;
    const double cooling_rate = 0.02;
    temp += heating_rate * power * dt;
    temp -= cooling_rate * (temp - 25.0) * dt;
    return temp;
}
