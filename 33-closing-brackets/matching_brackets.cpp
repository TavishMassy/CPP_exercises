#include "matching_brackets.h"

namespace matching_brackets {

// TODO: add your solution here
bool check(std::string text) {
    std::vector<char> brackets;
    for (char& c : text) {
        if (_to_opening_brackets(c) != 'x' && (brackets.empty() || _to_opening_brackets(c) != brackets.back())) {
            return false;
        } else if (!brackets.empty() && _to_opening_brackets(c) == brackets.back()) {
            brackets.pop_back();
        } else if (c == '(') {
            brackets.emplace_back(c);
        } else if (c == '{') {
            brackets.emplace_back(c);
        } else if (c == '[') {
            brackets.emplace_back(c);
        }
    }
    if (brackets.empty()) {
        return true;
    }
    return false;
}

char _to_opening_brackets(char& c) {
    if (c == ')') {
        return '(';
    } else if (c == '}') {
        return '{';
    } else if (c == ']') {
        return '[';
    }
    return 'x';
}

}  // namespace matching_brackets
