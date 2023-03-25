#pragma once

class StoreMediaInterface {
public:
    int get_late_fee_per_day_in_dollar() {
        return late_fee_per_day_in_dollar;
    }

    size_t get_inventory_id() const {
        return inventory_id;
    }

    virtual int calculate_late_fees(int num_of_days_past_due) {
        if (num_of_days_past_due <= 0 || mercy_rule_apply()) {
            return 0;
        }
        return late_fee_per_day_in_dollar * num_of_days_past_due;
    }

    virtual bool mercy_rule_apply() {
        /*
         * TODO: homework
         */

        // mercy rule formula from test case: calculate_late_fees_base_rule
        bool has_mercy = (this->get_inventory_id() % 13 == 0);
        return has_mercy;
    }

    bool operator==(const StoreMediaInterface &other_media) const {
        /*
         * TODO: homework
         */

        // A movie equals another movie only when their id are the same. Same rule for books being equal.
        return other_media.inventory_id == this->inventory_id;
    };

    bool operator!=(const StoreMediaInterface &other_media) const {
        return !(other_media == *this);
    }

    virtual ~StoreMediaInterface() {};

protected:
    int late_fee_per_day_in_dollar = 2;
    size_t inventory_id;

    void set_late_fee_per_day_in_dollar(int fee) {
        this->late_fee_per_day_in_dollar = fee;
    }
};