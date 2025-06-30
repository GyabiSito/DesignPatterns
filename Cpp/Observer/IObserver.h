#pragma once
#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "ICollection/interfaces/ICollectible.h"

class IObserver : public ICollectible 
{
public:
    IObserver();
    virtual void notify(int) = 0;
    virtual ~IObserver();
};

#endif