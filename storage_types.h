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

class IPackageQueue: public IPackageStockpile{
    using iterator = std::list<Package>::const_iterator;
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue: public IPackageQueue{
    using iterator = std::list<Package>::const_iterator;
private:
    PackageQueueType mQueueType;
    std::list<Package> mQueue;
public:
    PackageQueue(PackageQueueType queueType) : mQueueType(queueType) {}
    PackageQueueType get_queue_type() const override { return mQueueType; }

    Package pop() override;
    void push(Package&& pck) override;
    bool empty() const override     { return mQueue.empty();  }
    int size() const override    { return mQueue.size();   }
    iterator begin() const override { return mQueue.begin();  }
    iterator end() const override   { return mQueue.end();    }
    iterator cbegin()const override { return mQueue.cbegin(); }
    iterator cend() const override  { return mQueue.cend();   }
};


#endif //NETSIM_STORAGE_TYPES_H
