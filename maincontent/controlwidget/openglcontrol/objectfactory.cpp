/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：简单工厂模式，这个工厂用于生产3D模型
 * ***************************************/

#include "objectfactory.h"

ObjectFactory* ObjectFactory::instance = new ObjectFactory();

ObjectFactory::ObjectFactory()
{

}

ObjectFactory::~ObjectFactory()
{

}

ObjectFactory *ObjectFactory::getInstance()
{
    return instance;
}

ObjectParent *ObjectFactory::makeObject(ObjectType objectType)
{
    ObjectParent *objectParent = nullptr;
    switch (objectType)
    {
    case OBJECT_CUBE: objectParent = new ObjectCube(); break;
    case OBJECT_MAX: break;
    default: break;
    }
    if (nullptr != objectParent)
    {
        m_allObjectList.append(objectParent);
    }
    return objectParent;
}

void ObjectFactory::processMouseEvent(float deltaX, float deltaY)
{
    for (ObjectParent* object : m_allObjectList)
    {
        object->getCameraLibrary().processMouseEvent(deltaX, deltaY);
    }
}

void ObjectFactory::moveToForward()
{
    for (ObjectParent* object : m_allObjectList)
    {
        object->getCameraLibrary().moveToForward();
    }
}

void ObjectFactory::moveToBackward()
{
    for (ObjectParent* object : m_allObjectList)
    {
        object->getCameraLibrary().moveToBackward();
    }
}
