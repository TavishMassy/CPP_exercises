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

    // std::max_element returns an iterator to the largest element.
    // The * dereferences it to return the actual integer value.
    return *std::max_element(scores.begin(), scores.end());

    // OR Manual way: 
    
    // int highest_score{0};
    // for (int& score : HighScores::scores) {
    //     if (highest_score < score) {
    //         highest_score = score;
    //     }
    // }
    // return highest_score; 
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    std::vector<int> result = scores;

    // Only sort the top 3 elements, leave the rest unsorted. 
    // This runs in O(N) time!
    size_t count = std::min<size_t>(3, result.size());
    std::partial_sort(result.begin(), result.begin() + count, result.end(), std::greater<int>());
    
    result.resize(count);
    return result;

    // OR Manual way: 

    // int size{static_cast<int>(scores.size())};
    // std::vector<int> top3_scores{0, 1, 2};
    // for (int i{0}; i < size; ++i) {
    //     if (scores.at(top3_scores[0]) < scores.at(i)) {
    //         top3_scores[2] = top3_scores[1];
    //         top3_scores[1] = top3_scores[0];
    //         top3_scores[0] = i;
    //     } else if (size > 1 && (scores.at(top3_scores[1]) < scores.at(i) && i != top3_scores[0])) {
    //         top3_scores[2] = top3_scores[1];
    //         top3_scores[1] = i;
    //     } else if (size > 2 && (scores.at(top3_scores.at(2)) < scores.at(i) && (i != top3_scores[0] && i != top3_scores[1]))) {
    //         top3_scores[2] = i;
    //     }
    // }
    // for (int i{0}; i < 3; ++i) {
    //     if (i < size) {
    //         top3_scores[i] = scores.at(top3_scores[i]);
    //     }
    // }
    // if (size < 3) {
    //     top3_scores.resize(size);
    // }
    // return top3_scores;
}

}  // namespace arcade
