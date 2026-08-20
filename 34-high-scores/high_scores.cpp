#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return HighScores::scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return HighScores::scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    int highest_score{0};
    for (int& score : HighScores::scores) {
        if (highest_score < score) {
            highest_score = score;
        }
    }
    return highest_score; 
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    bool swap{true};
    int temp;
    std::vector<int> scores = HighScores::scores;
    while (swap) {
        swap = false;
        for (size_t i{1}; i < scores.size(); ++i) {
            if (scores.at(i - 1) < scores.at(i)) {
                temp = scores.at(i - 1);
                scores[i - 1] = scores.at(i);
                scores[i] = temp;
                swap = true;
            }
        }
    }
    if (scores.size() > 3) {
        scores.resize(3);
    }
    return scores;
}

}  // namespace arcade
