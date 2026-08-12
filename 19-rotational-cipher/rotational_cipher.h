#pragma once

#include <string>
#include <unordered_map>

namespace rotational_cipher {

// TODO: add your solution here
inline const std::string alphabets{"abcdefghijklmnopqrstuvwxyz"};
std::string rotate(std::string text, int rotation);

}  // namespace rotational_cipher
