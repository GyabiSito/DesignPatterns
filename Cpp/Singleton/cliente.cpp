#include "singleton.h"

int main(){
    Singleton *ms;
    ms=Singleton::getInstance();
    ms->operacion();
    return 0;
}