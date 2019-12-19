#include "package.h"

//??????????????????????????????????????????
Package::Package() {
    if (freed_IDs.empty()) {
        assigned_IDs.insert(assigned_IDs.size() + 1);
        id_ = assigned_IDs.size();
    }
    else {
        auto tmp = freed_IDs.begin();
        id_ = *tmp;
        freed_IDs.erase(*tmp);
        assigned_IDs.insert(*tmp);
    }
}

//FIXME
/*
Package& Package::operator=(class Package pack) {
    pack.id_ = 0;
}
*/
std::set<ElementID> Package::assigned_IDs;
std::set<ElementID> Package::freed_IDs;

Package::~Package() {
    assigned_IDs.erase(id_);
    freed_IDs.insert(id_);
}