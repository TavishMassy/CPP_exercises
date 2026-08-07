#include "atbash_cipher.h"

namespace atbash_cipher {

// TODO: add your solution here
    std::string encode(std::string text) {
        std::string encoded;
        for(char c : text) {
            if(std::isalnum(c)) {
                if(encoded.length() % 6 == 5) {
                    encoded += ' ';
                }
                if(std::isalpha(c)) {
                    encoded += 'z' - (std::tolower(c) - 'a');
                } 
                else {
                    encoded += c;
                }
            }
        }
        return encoded;
    }

    std::string decode(std::string encoded) {
        std::string text;
        for(char c : encoded) {
            if(std::isalnum(c)) {
                if(std::isalpha(c)) {
                    text += 'z' - (std::tolower(c) - 'a');
                } 
                else {
                    text += c;
                }
            }
        }
        return text;
    }
}  // namespace atbash_cipher
