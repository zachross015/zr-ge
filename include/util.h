#ifndef UTIL_H
#define UTIL_H

#include <vector>

template <typename T>
std::vector<T> flags_to_enums(unsigned int flags, std::vector<T> all_enums) {
    std::vector<T> enums;
    for(auto e : all_enums) {
        if (flags & e) {
            enums.push_back(e);
        } 
    }
    return enums;
}


template <typename T>
unsigned int enums_to_flags(std::vector<T> enums) {
    unsigned int flags = 0;
    for(unsigned int flag : enums) {
        flags = flags | flag;
    }
    return flags;
}


#endif
