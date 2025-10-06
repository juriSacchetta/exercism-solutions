#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result;
    result.reserve(student_scores.size());
    for (std::size_t i = 0; i < student_scores.size(); ++i) {
        int rounded = static_cast<int>(student_scores[i]);
        result.push_back(rounded);
    }

    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int c =0;
    for (int x:student_scores){
        if (x<41) c++;
    }
    return c;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    const int span = std::max(0, highest_score - 40);
    const int step = std::max(1, span / 4);

    std::array<int, 4> thresholds{};
    thresholds[0] = 41;
    thresholds[1] = thresholds[0] + step;
    thresholds[2] = thresholds[1] + step;
    thresholds[3] = thresholds[2] + step;
    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> out;
    out.reserve(student_names.size());
    for (std::size_t i = 0; i < student_names.size(); ++i) {
        out.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " +
                      std::to_string(student_scores[i]));
    }
    return out;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for(int i=0; i<student_names.size(); i++){
        if(student_scores[i] == 100)
            return student_names[i];
    }
    return "";
}
