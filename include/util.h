#ifndef UTIL_H
#define UTIL_H

#define GET(dt, name) const dt& name()
#define SET(dt, name) void name(const dt& name_val)

#define DEFINE_GET(dt, cla, name) const dt& cla::name()
#define DEFINE_SET(dt, cla, name) void cla::name(const dt& name_val)


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
