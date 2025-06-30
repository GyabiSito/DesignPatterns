#include "singleton.h"
Singleton * Singleton::instancia=nullptr;
Singleton::Singleton(){}
Singleton * Singleton::getInstance(){
    if(instancia==nullptr){
        instancia=new Singleton();
    }
    return instancia;
}