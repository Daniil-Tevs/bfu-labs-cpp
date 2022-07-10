#include "camera.hpp"
#include <fstream>
#include <string>
namespace dt
{
    class Object {
    public:
      Object();
        Point *getPoints();
        void setFrequency(double frequency);
        int getSize() const;
        void ProjectPointsObject(const std::shared_ptr<Camera>& camera);
        void offset(Point point);
        void setColor(Pixel color);
    protected:
        Point *m_points = nullptr;
        double m_frequency = 0.009;
        int m_size = 0;
    };

    class Sphere : public dt::Object {
    public:
        Sphere();
        Sphere(int radius, double first_angle, double second_angle);
        Sphere(std::string from);
        Sphere(std::string equation, double first_angle, double second_angle);
        virtual ~Sphere() {delete m_points;}

    private:
        double m_radius;
        double m_fi; //first angle
        double m_tet; //second angle
    };

    class Parallelepiped : public Object{
    public:
        Parallelepiped();
        Parallelepiped(double width, double length, double height);
        virtual ~Parallelepiped(){delete m_points;}
    private:
        double m_width, m_length,m_height;
    };

    class ObjectText : public Object{
    public:
        ObjectText(const std::string& from);
        virtual ~ObjectText(){delete m_points;}
    };
}