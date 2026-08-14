#include "hexadecimal.h"

namespace hexadecimal {

// TODO: add your solution here
int convert(std::string num) {
    int memo{0};
    for (char c : num) {
        c = tolower(c);
        memo *= 16;
        if (isalpha(c) && c <= 'f') {
            memo += static_cast<int>(c - 'a') + 10;
        } else if (c >= '0' && c <= '9') {
            memo += static_cast<int>(c - '0');
        } else {
            return 0;
        }
    }
    return memo;
}

}  // namespace hexadecimal
