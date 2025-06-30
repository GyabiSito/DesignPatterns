#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
private:
    static Singleton *instancia;
    Singleton();

public:
    static Singleton *getInstance();
    void operacion();
};

#endif