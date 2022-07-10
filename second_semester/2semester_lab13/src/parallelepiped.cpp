#include "object.h"
namespace dt{
    Parallelepiped::Parallelepiped(){
        m_width = 0;
        m_length = 0;
        m_height = 0;
    }
    Parallelepiped::Parallelepiped(double width, double length, double height)
        {
            m_width = width;
            m_length = length;
            m_height = height;
            m_points = new Point[(2*int(m_width/m_frequency+1) * int(m_length/m_frequency+1))+(2*int(m_width/m_frequency+1) * int(m_height/m_frequency+1))+(2*int(m_height/m_frequency+1) * int(m_length/m_frequency+1)) ];
            for(double j = 0; j<=2*m_width;j+=m_frequency)
                for(double k = 0; k<=m_length;k+=m_frequency) {
                    if ((j + m_frequency) < m_width || j <= m_width) {
                        m_points[m_size].x = j;
                        m_points[m_size].y = k;
                        m_points[m_size].z = 0;
                        m_size++;
                    } else {
                        m_points[m_size].x = j - m_width;
                        m_points[m_size].y = k;
                        m_points[m_size].z = m_height;
                        m_size++;
                    }
                }
            for(double j = 0; j<=2*m_length;j+=m_frequency)
                for(double k = 0; k<=m_height;k+=m_frequency) {
                    if ((j + m_frequency) < m_length || j <= m_length) {
                        m_points[m_size].x = 0;
                        m_points[m_size].y = j;
                        m_points[m_size].z = k;
                        m_size++;
                    } else {
                        m_points[m_size].x = m_width;
                        m_points[m_size].y = j-m_length;
                        m_points[m_size].z = k;
                        m_size++;
                    }
                }
            for(double j = 0; j<=2*m_width;j+=m_frequency)
                for(double k = 0; k<=m_height;k+=m_frequency) {
                    if ((j + m_frequency) < m_width || j <= m_width) {
                        m_points[m_size].x = j;
                        m_points[m_size].y = 0;
                        m_points[m_size].z = k;
                        m_size++;
                    } else {
                        m_points[m_size].x = j-m_width;
                        m_points[m_size].y = m_length;
                        m_points[m_size].z = k;
                        m_size++;
                    }
                }
        }
}