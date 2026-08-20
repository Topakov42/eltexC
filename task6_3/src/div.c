#include <math.h>

double divv(double a, double b) {
    if (b == 0.0) {
        return NAN;
    }
    return a / b;
}
