#include "StringKey.h"

ComparisonRes StringKey::compare(OrderedKey *k) const
{
    auto o = dynamic_cast<StringKey *>(k);
    if (!o)
        return GREATER; // or handle error
    if (key < o->key)
        return LESSER;
    if (key > o->key)
        return GREATER;
    return EQUAL;
}

bool StringKey::equals(IKey *other) const
{
    auto o = dynamic_cast<StringKey *>(other);
    return o && o->key == key;
}

StringKey::~StringKey()
{
    // Destructor implementation if needed
}

