#ifndef MANAGERIMPL_H
#define MANAGERIMPL_H

#include "Manager.h"


class ManagerImpl : public Manager{
public:
    ManagerImpl();
    virtual ~ManagerImpl();

    int import(const char*);
    void makeSurfaces();
    void cleaning();
    int exportJSON(string f_path);
    //TODO
    void makeSolids() {};
protected:


private:
};

#endif // MANAGERIMPL_H