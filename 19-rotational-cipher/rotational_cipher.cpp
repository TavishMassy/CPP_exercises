#include "rotational_cipher.h"

namespace rotational_cipher {

// TODO: add your solution here
std::string rotate(std::string text, int rotation) {
    std::string cipher{};
    bool is_upper = false;
    for (char c : text) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = tolower(c);
                is_upper = true;
            }
            int index(alphabets.find(c));
            c = alphabets.at((index + rotation) % 26);
            if (is_upper) {
                c = toupper(c);
                is_upper = false;
            }
            cipher.push_back(c);
        } else {
            cipher.push_back(c);
        }
    }
    return cipher;
}

}  // namespace rotational_cipher
