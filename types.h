#ifndef NETSIM_TYPES_H
#define NETSIM_TYPES_H

#include <functional>

using ElementID = int;
using Time = double;
using TimeOffset = double;
using ProbabilityGenerator = std::function<double(void)>;

#endif //NETSIM_TYPES_H
