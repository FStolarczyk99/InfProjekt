#include "storage_types.h"

Package PackageQueue::pop() {

    switch(queueType){
        case PackageQueueType::FIFO:{
            Package returnedPackage = std::move(queue.front());
            queue.pop_front();
            return returnedPackage;
        }

        case PackageQueueType ::LIFO: {
            Package returnedPackage = std::move(queue.back());
            queue.pop_back();
            return returnedPackage;
        }
    }
    return Package();
}

