#include "class.h"
void Square::Moving()
{
    if(m_shape->getPosition().x-m_shape->getOrigin().x-v>=0)
            m_shape->setPosition(m_shape->getPosition().x-v,m_shape->getPosition().y);
        else
            m_shape->setPosition(m_shape->getOrigin().x,m_shape->getPosition().y);
}
