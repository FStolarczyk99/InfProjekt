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

Storehouse::Storehouse(ElementID ID) : id(ID)
{
    depot = std::make_unique<PackageQueue>();
}

void Storehouse::receivePackage(Package package)
{
    depot->push(package);
}

Worker::Worker(ElementID _id, TimeOffset _time, std::unique_ptr<IPackageQueue> ptr)
        :id(_id), processingDuration(_time)
{
    queue = std::move(ptr);
}

void Worker::doWork()
{
    if (currentlyProcessedPackage.size() == 0)
    {
        currentlyProcessedPackage.push_back(queue->pop());
        packageProcessingStartTime = 1;
    }
    else
    {
        if (packageProcessingStartTime<processingDuration)
        {
            packageProcessingStartTime++;
        }
        else
        {
            sendingBuffer.push_back(queue->pop());
            if (queue->size()==0)
            {
                packageProcessingStartTime = 0;
            }
            else
            {
                packageProcessingStartTime = 1;
                currentlyProcessedPackage.push_back(queue->pop());
            }

        }
    }
}
