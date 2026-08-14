#include "darts.h"

namespace darts {

// TODO: add your solution here
int score(double x, double y) {
    double radius{sqrt(pow(x, 2) + pow(y, 2))};
    if (radius <= 1) {
        return 10;
    } else if (radius <= 5) {
        return 5;
    } else if (radius <= 10) {
        return 1;
    } else {
        return 0;
    }
}

}  // namespace darts
