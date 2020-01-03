#ifndef NETSIM_STORAGE_TYPES_H
#define NETSIM_STORAGE_TYPES_H

#include "package.h"
#include "list"


enum class PackageQueueType {
    FIFO,
    LIFO
};

class IPackageStockpile {
    using iterator = std::list<Package>::const_iterator;
public:
    virtual void push(Package&&) = 0 ;
    virtual bool empty() const = 0;
    virtual int size()   const = 0;

    virtual iterator begin()  const = 0;
    virtual iterator end()    const = 0;
    virtual iterator cbegin() const = 0;
    virtual iterator cend()   const = 0;
};

class IPackageQueue {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue : public IPackageQueue{
public:
    PackageQueue(PackageQueueType);
};


#endif //NETSIM_STORAGE_TYPES_H
