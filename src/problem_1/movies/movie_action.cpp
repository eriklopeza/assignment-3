#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */

    // from test case: using mercy formula & fees formulas
    // if num_of_days_past_due >= 5 then double fee
    // if mercy rule applies to action movie return 0
    // else just base fee for action movie
    bool has_mercy = this->get_inventory_id() % 13 == 0 && this->action_movie_mercy_rule_apply();
    if (has_mercy) {
        return 0;
    }

    // Calculate late fees if mercy rule doesnt apply
    // for ranges 1-4, 5 and up, and 0
    if (num_of_days_past_due >= 5) {
        return (this->late_fee_per_day * num_of_days_past_due) * 2;
    }
    else if (num_of_days_past_due > 0) {
        return this->late_fee_per_day * num_of_days_past_due;
    }
    else {
        return 0;
    }

}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}