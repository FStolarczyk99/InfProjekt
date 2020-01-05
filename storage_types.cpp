#include "storage_types.h"
#include "package.h"

Package PackageQueue::pop() {
    Package pack;
    switch(get_queue_type())
    {
        case PackageQueueType::FIFO :
        {
            pack = std::move(mQueue.front());
            mQueue.pop_front();
        }
            break;
        case PackageQueueType::LIFO :
        {
            pack = std::move(mQueue.back());
            mQueue.pop_back();
        }
            break;
    }
    return pack;

}

void PackageQueue::push(Package &&pack) {
    mQueue.push_back(std::move(pack));
}
