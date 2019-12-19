#ifndef NETSIM_PACKAGE_H
#define NETSIM_PACKAGE_H

#include "types.h"
#include <set>


class Package {
public:
    Package();
    Package(Package&&) = default;
    Package operator=(const Package& pack);
    int get_id() const { return id_; }
    ~Package();
private:
    ElementID id_;
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
};


#endif //NETSIM_PACKAGE_H
