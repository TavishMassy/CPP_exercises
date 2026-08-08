#include <array>
#include <string>
#include <vector>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> round_scores;
    for(double score : student_scores) {
        round_scores.emplace_back(static_cast<int>(std::floor(score)));
    }
    return round_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int count{0};
    for(double score : student_scores) {
        if(score <= 40) {
            ++count;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int difference{(highest_score - 40) / 4};
    std::array<int, 4> thresholds{{41, 41 + difference, 41 + difference * 2, 41 + difference * 3}};
    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<int> sort_scores;
    std::vector<std::string> rankings;
    while(student_scores.size() > 0) {      
        if (rankings.size() > 0) {
            int low = 0;
            int high = sort_scores.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (sort_scores[mid] > student_scores.back()) {
                    low = mid + 1;
                } else {
                    high = mid;
                }       
            }
            sort_scores.insert(sort_scores.begin() + low, student_scores.back());
            rankings.insert(rankings.begin() + low, ". " + student_names.back() + ": " + std::to_string(student_scores.back()));
            student_names.pop_back();
            student_scores.pop_back();
        } else {
            sort_scores.emplace_back(student_scores.back());
            rankings.emplace_back(". " + student_names.back() + ": " + std::to_string(student_scores.back()));
            student_names.pop_back();
            student_scores.pop_back();
        }
    }
    for (size_t i = 0; i < rankings.size(); ++i) {
        rankings[i] = std::to_string(i + 1) + rankings[i];
    }
    return rankings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (size_t i = 0; i < student_scores.size(); ++i) {
        if(student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}