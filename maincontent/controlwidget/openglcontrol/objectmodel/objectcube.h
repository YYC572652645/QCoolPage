#ifndef OBJECTCUBE_H
#define OBJECTCUBE_H
#include "objectparent.h"

class ObjectCube : public ObjectParent
{
public:
    ObjectCube();
    ~ObjectCube() override;
    void makeObject() override;
};

#endif // OBJECTCUBE_H
