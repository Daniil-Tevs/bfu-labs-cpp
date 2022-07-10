#include "object.h"
#include <string>
namespace dt
{
    Sphere ::Sphere()
    {
        m_radius = 0;
        m_fi = 0;
        m_tet = 0;
    }
    Sphere ::Sphere(int radius, double first_angle, double second_angle) {
        m_radius = radius;
        m_fi = first_angle;
        m_tet = second_angle;
        m_points = new Point[(int(m_fi / m_frequency) + 1) * (int(m_tet / m_frequency) + 1)];
        for (double i = 0; i < m_fi; i += m_frequency)
            for (double j = 0; j < m_tet; j += m_frequency) {
                m_points[m_size].x = m_radius * sin(j) * cos(i);
                m_points[m_size].y = m_radius * sin(j) * sin(i);
                m_points[m_size].z = m_radius * cos(j);
                m_size++;
            }
    }
    Sphere::Sphere(std::string from) {
        if(from.find(".txt")!=-1) {
            std::ifstream in(from);
            std::string tmp;
            std::string tmp_offset;
            Point offset = {0,0,0};
            in >> tmp;
            in >> m_fi >> m_tet;
            int itb, ite;
            if(tmp.find("(x")!=-1) {
                itb = tmp.find("(") + 3;
                ite = tmp.find(")");
                offset.x = std::stoi(tmp.substr(itb, ite - itb));
                if(tmp[itb-1] == '+')
                    offset.x *= -1;
                tmp_offset = tmp.substr(ite+4, tmp_offset.size() - ite-4);
            }
            else
                tmp_offset = tmp.substr(4, tmp.size() - 4);
            if(tmp.find("(y")!=-1) {
                itb = tmp_offset.find("(") + 3;
                ite = tmp_offset.find(")");
                offset.y = std::stoi(tmp_offset.substr(itb , ite - itb));
                if(tmp_offset[itb-1] == '+')
                    offset.y *= -1;
                tmp_offset = tmp_offset.substr(ite+4, tmp_offset.size() - ite-4);
            }
            else
                tmp_offset = tmp_offset.substr(4, tmp.size() - 4);
            if(tmp.find("(z")!=-1) {
                itb = tmp_offset.find("(") + 3;
                ite = tmp_offset.find(")");
                offset.z = std::stoi(tmp_offset.substr(itb , ite - itb ));
                if(tmp_offset[itb-1] == '+')
                    offset.z *= -1;
            }
            itb = tmp.find('=')+1;
            m_radius = sqrt(std::stoi(tmp.substr(itb,tmp.size()-itb)));
            m_points = new Point[(int(m_fi / m_frequency) + 1) * (int(m_tet / m_frequency) + 1)];
            for (double i = 0; i < m_fi; i += m_frequency)
                for (double j = 0; j < m_tet; j += m_frequency) {
                    m_points[m_size].x = m_radius * sin(j) * cos(i)+offset.x;
                    m_points[m_size].y = m_radius * sin(j) * sin(i)+offset.y;
                    m_points[m_size].z = m_radius * cos(j)+offset.z;
                    m_size++;
                }
        }
    }
    Sphere::Sphere(std::string equation, double first_angle, double second_angle) {
        m_fi = first_angle;
        m_tet = second_angle;
        std::string tmp_offset;
        Point offset= {0,0,0};
        int itb, ite;
        if(equation.find("(x")!=-1) {
            itb = equation.find("(") + 3;
            ite = equation.find(")");
            offset.x = std::stoi(equation.substr(itb, ite - itb));
            if(equation[itb-1] == '+')
                offset.x *= -1;
            tmp_offset = equation.substr(ite+4, tmp_offset.size() - ite-4);
        }
        else
            tmp_offset = equation.substr(4, equation.size() - 4);
        if(equation.find("(y")!=-1) {
            itb = tmp_offset.find("(") + 3;
            ite = tmp_offset.find(")");
            offset.y = std::stoi(tmp_offset.substr(itb , ite - itb));
            if(tmp_offset[itb-1] == '+')
                offset.y *= -1;
            tmp_offset = tmp_offset.substr(ite+4, tmp_offset.size() - ite-4);
        }
        else
            tmp_offset = equation.substr(4, equation.size() - 4);
        if(equation.find("(z")!=-1) {
            itb = tmp_offset.find("(") + 3;
            ite = tmp_offset.find(")");
            offset.z = std::stoi(tmp_offset.substr(itb , ite - itb ));
            if(tmp_offset[itb-1] == '+')
                offset.z *= -1;
        }
        itb = equation.find('=');
        m_radius = sqrt(std::stoi(equation.substr(itb+1,equation.size()-itb-1)));
        m_points = new Point[(int(m_fi / m_frequency) + 1) * (int(m_tet / m_frequency) + 1)];
        for (double i = 0; i < m_fi; i += m_frequency)
            for (double j = 0; j < m_tet; j += m_frequency) {
                m_points[m_size].x = m_radius * sin(j) * cos(i)+offset.x;
                m_points[m_size].y = m_radius * sin(j) * sin(i)+offset.y;
                m_points[m_size].z = m_radius * cos(j)+offset.z;
                m_size++;
            }
    }
}