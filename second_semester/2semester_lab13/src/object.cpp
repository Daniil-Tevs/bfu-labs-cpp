#include "object.h"

namespace dt
{
    Object::Object() = default;
    Point * Object::getPoints() { return m_points; }
    void Object::setFrequency(double frequency) { m_frequency = frequency; }
    int Object::getSize() const { return m_size; }
    void Object::ProjectPointsObject(const std::shared_ptr<Camera>& camera)
    {
        for (int i = 0; i < m_size; i++)
            camera->ProjectPoint(m_points[i], m_points[i].color);
    }
    void Object::offset(Point point){
        for (int i = 0; i < m_size; i++)
        {
            m_points[i].x += point.x;
            m_points[i].y += point.y;
            m_points[i].z += point.z;
        }
    }
    void Object::setColor(Pixel color) {
        for (int i = 0; i < m_size; i++)
            m_points[i].color = color;
    }

    ObjectText::ObjectText(const std::string &from)
    {
        std::ifstream in(from);
        m_points = new Point[270000];
        double tmp2;
        while(!in.eof())
        {
            in>>m_points[m_size].x;
            in>>m_points[m_size].y;
            in>>m_points[m_size].z;
            if(from.find("points.txt")!=-1) {
                m_points[m_size].x -= 467370.240;
                m_points[m_size].y -= 6063530.860;
                m_points[m_size].z -= 60.770;
            }
            in>>tmp2;
            m_points[m_size].color.r = (uint8_t) tmp2;
            in>>tmp2;
            m_points[m_size].color.g = (uint8_t) tmp2;
            in>>tmp2;
            m_points[m_size].color.b = (uint8_t) tmp2;
            m_points[m_size].color.a = 255;
            m_size++;
        }
    }
}