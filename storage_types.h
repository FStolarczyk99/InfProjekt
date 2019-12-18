#ifndef NETSIM_STORAGE_TYPES_H
#define NETSIM_STORAGE_TYPES_H


class IPackageStockpile {

};

class IPackageQueue {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue {

};

enum class PackageQueueType {
    FIFO,
    LIFO
};

#endif //NETSIM_STORAGE_TYPES_H
