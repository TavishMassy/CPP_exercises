#pragma once
#include <string>
#include <vector>
namespace protein_translation {

const std::vector<std::string> amino_acids{
    "Methionine",
    "Phenylalanine",
    "Leucine",
    "Serine",
    "Tyrosine",
    "Cysteine",
    "Tryptophan",
    "STOP"
};

const std::vector<std::vector<std::string>> colons{
    {"AUG"},
    {"UUU", "UUC"},
    {"UUA", "UUG"},
    {"UCU", "UCC", "UCA", "UCG"},
    {"UAU", "UAC"},
    {"UGU", "UGC"},
    {"UGG"},
    {"UAA", "UAG", "UGA"}
};

// TODO: add your solution here
std::vector<std::string> proteins(std::string target_codon);

}  // namespace protein_translation
