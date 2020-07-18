/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：简单工厂模式，这个工厂用于生产3D模型
 * ***************************************/

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "objectmodel/objectparent.h"
#include "objectmodel/objectcube.h"

#ifndef OBJECT_FACTORY
#define OBJECT_FACTORY ObjectFactory::getInstance()
#endif

class ObjectFactory
{
public:
    enum ObjectType
    {
        OBJECT_CUBE,
        OBJECT_MAX
    };
    static ObjectFactory* getInstance();
    ObjectParent *makeObject(ObjectType objectType);
private:
    ObjectFactory();
    ~ObjectFactory();
private:
    static ObjectFactory* instance;
};

#endif // OBJECTFACTORY_H
