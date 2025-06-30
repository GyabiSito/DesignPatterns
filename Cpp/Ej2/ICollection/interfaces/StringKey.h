#ifndef STRINGKEY_H
#define STRINGKEY_H

#include "OrderedKey.h"
#include <string>

class StringKey : public OrderedKey {
protected:
    std::string key;
public:
    StringKey(const std::string& s) : key(s) {}

    // Elimina el '= 0', porque aquí tienes implementación en el cpp
    virtual ComparisonRes compare(OrderedKey *k) const override;

    bool equals(IKey *other) const;

    virtual ~StringKey();
};

#endif // STRINGKEY_H
