#include "bob.h"

namespace bob {

// TODO: add your solution here
std::string hey(std::string text) {
    bool is_empty{true};
    bool is_alpha{false};
    bool is_lower{false};
    bool is_question{false};
    for (auto it = text.rbegin(); it != text.rend(); ++it) {
        if (!isspace(*it)) {
            is_empty = false;
            if (isalpha(*it)) {
                is_alpha = true;
                if (islower(*it)) {
                    is_lower = true;
                }
            } else if (text.back() == '?') {
                is_question = true;
            }
        } else {
            text.pop_back();
        }
    }
    if (is_empty) {
        return "Fine. Be that way!";
    } else if (is_alpha && !is_lower && is_question) {
        return "Calm down, I know what I'm doing!";
    } else if (is_alpha && !is_lower) {
        return "Whoa, chill out!";
    } else if (is_question) {
        return "Sure.";
    }
    return "Whatever.";
}

}  // namespace bob
