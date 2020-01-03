#ifndef INFPROJEKT_NODES_H
#define INFPROJEKT_NODES_H

//plik nagłówkowy "nodes.hpp" zawierający definicję klas IPackageReceiver,
// Storehouse, ReceiverPreferences, PackageSender, Ramp i Worker

#include <map>
#include "types.h"
#include "package.h"
#include "list"
#include "helpers.h"

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

#endif //INFPROJEKT_NODES_H
