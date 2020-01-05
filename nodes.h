#ifndef INFPROJEKT_NODES_H
#define INFPROJEKT_NODES_H

//plik nagłówkowy "nodes.hpp" zawierający definicję klas IPackageReceiver,
// Storehouse, ReceiverPreferences, PackageSender, Ramp i Worker

#include <map>
#include "types.h"
#include "package.h"
#include "list"
#include "helpers.h"
#include "PackageQueue.h"
#include <memory>
#include <vector>
#include <optional>
#include <functional>


class IPackageReceiver {
public:
    using iterator = std::list<Package>::const_iterator;
    virtual void receive_package(Package&& pck) = 0;
    virtual ElementID get_ID() const = 0;

    virtual iterator begin()  const = 0;
    virtual iterator end()    const = 0;
    virtual iterator cbegin() const = 0;
    virtual iterator cend()   const = 0;
};


class ReceiverPreferences {
    using preferences_map = std::map<IPackageReceiver*, double>;
    using c_iterator = preferences_map::const_iterator;
    using iterator = preferences_map::iterator;
private:
    preferences_map preferences_;
    void rebuild_pref();
    ProbabilityGenerator rng_;
public:
    ReceiverPreferences(ProbabilityGenerator pg = get_random) : rng_(std::move(pg)) {}
    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();

    iterator begin()          { return preferences_.begin();  }
    iterator end()            { return preferences_.end();    }
    c_iterator cbegin() const { return preferences_.cbegin(); }
    c_iterator cend()   const { return preferences_.cend();   }
};

class PackageSender{
private:
    std::optional<Package> mBuffer;
public:
    ReceiverPreferences receiver_preferences_;
    void send_package();
    std::optional<Package> get_sending_buffer() const {return mBuffer;};
protected:
    void push_package(Package&& pck);
};

class Ramp : public PackageSender{
private:
    TimeOffset mOffset;
    ElementID mID;
public:
    Ramp(ElementID id, TimeOffset di) : mOffset(di), mID(id) {}
    void deliver_goods(Time t);
    TimeOffset get_delivery_interval()  const {return mOffset; }
    ElementID get_ID()                  const { return mID;    }
};

class Storehouse : public IPackageReceiver
{
public:
    Storehouse(ElementID);

    void receivePackage(Package)override;
    inline ElementID getId() const override { return id; }
    void receivePackage(Package) override;
    inline ReciverType getReceiverType() const override { return ReciverType::STORAGEHOUSE; }


private:
    ElementID id;
    std::unique_ptr<IPackageDepot> depot;
};


class Worker :public PackageSender, public IPackageReceiver
{
public:
    Worker(ElementID, TimeOffset, std::unique_ptr<IPackageQueue>);
    void receivePackage(Package) override;
    void doWork();
    inline ReciverType getReceiverType() const override { return ReciverType::WORKER; }
    inline ElementID getId() const override { return id; }
    inline TimeOffset getProcessingDuration() { return processingDuration; }
    inline Time getPackageProcessingStartTime() { return packageProcessingStartTime; }



private:
    ElementID id;
    TimeOffset processingDuration;
    Time packageProcessingStartTime = 0;
    std::unique_ptr<IPackageQueue> queue;
    std::vector<Package> currentlyProcessedPackage;
};

#endif //INFPROJEKT_NODES_H
