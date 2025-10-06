namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };
enum class Action { read, write, remove };

bool display_post(AccountStatus poster, AccountStatus viewer) {
    return (poster == AccountStatus::troll) ? (viewer == AccountStatus::troll) : true;
}

// Task 3
bool permission_check(Action action, AccountStatus account) {
    switch (account) {
        case AccountStatus::mod:
            return true;
        case AccountStatus::user:
        case AccountStatus::troll:
            return action == Action::read || action == Action::write;
        case AccountStatus::guest:
            return action == Action::read;
    }
    return false;
}

// Task 4
bool valid_player_combination(AccountStatus a, AccountStatus b) {
    if (a == AccountStatus::guest || b == AccountStatus::guest) return false;
    const bool a_t = (a == AccountStatus::troll);
    const bool b_t = (b == AccountStatus::troll);
    return (a_t && b_t) || (!a_t && !b_t);
}

// Task 5
bool has_priority(AccountStatus first, AccountStatus second) {
    auto rank = [](AccountStatus s) {
        switch (s) {
            case AccountStatus::mod:   return 3;
            case AccountStatus::user:  return 2;
            case AccountStatus::guest: return 1;
            case AccountStatus::troll: return 0;
        }
        return -1;
    };
    return rank(first) > rank(second);
}

} // namespace hellmath
