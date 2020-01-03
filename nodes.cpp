#include "nodes.h"

void ReceiverPreferences::add_receiver(IPackageReceiver* r) {
    preferences_.emplace(std::make_pair(r,1.0)); // get_random()
    rebuild_pref();
}

void ReceiverPreferences::remove_receiver(IPackageReceiver* r) {
    preferences_.erase(r);
    rebuild_pref();
}

IPackageReceiver* ReceiverPreferences::choose_receiver() {
    double number = rng_();
    double sum = 0;
    for (const auto &item: preferences_) {
        sum = sum + item.second;
        if(number <= sum)
            return item.first;
    }
    return preferences_.end()->first;
}

void ReceiverPreferences::rebuild_pref() {
    double sum = 0;
    for(auto& item : preferences_) {
        sum+= item.second;
    }

    for(auto& item : preferences_) {
        item.second /= sum;
    }
}
