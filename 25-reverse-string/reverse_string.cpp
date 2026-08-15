#include "reverse_string.h"

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(std::string text) {
    std::string reverse_text{};
    for (auto it = text.rbegin(); it != text.rend(); ++it) { 
        reverse_text.push_back(*it);
    }
    return reverse_text;
}

}  // namespace reverse_string
