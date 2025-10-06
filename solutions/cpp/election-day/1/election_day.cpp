#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(const ElectionResult& ele) {
    return ele.votes;
}

void increment_vote_count(ElectionResult& ele, int num) {
    ele.votes += num;
}

ElectionResult& determine_result(std::vector<ElectionResult>& eles) {
    std::size_t max_idx = 0;
    for (std::size_t i = 1; i < eles.size(); ++i) {
        if (eles[i].votes > eles[max_idx].votes)
            max_idx = i;
    }
    eles[max_idx].name = "President " + eles[max_idx].name;
    return eles[max_idx];
}

}  // namespace election
