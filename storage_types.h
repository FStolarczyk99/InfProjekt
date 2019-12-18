#ifndef NETSIM_STORAGE_TYPES_H
#define NETSIM_STORAGE_TYPES_H


#include "package.h"

enum class PackageQueueType {
    FIFO,
    LIFO
};

class IPackageStockpile {

};

class IPackageQueue {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue {

};


#endif //NETSIM_STORAGE_TYPES_H
