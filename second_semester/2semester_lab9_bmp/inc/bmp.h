#include <fstream>
#include <string>
#include <vector>
#pragma pack()
class bmp{
public:
    bmp(std::string from){
        std::ifstream in(from,std::ios::binary);
        in.read(reinterpret_cast<char *>(&m_header), sizeof(bmp_header));
        in.read(reinterpret_cast<char *>(&m_info), sizeof(bmp_info));
        m_height=m_info.Height;
        m_width = m_info.Width;
        std::vector<pixel> v;
        pixel tmp{};
        for (int i = 0; i < m_height; i++)
        {
            for (int j = 0; j <m_width; j++)
            {
                in.read(reinterpret_cast<char*>(&tmp), sizeof(pixel));
                v.push_back(tmp);
            }
            if((3 * m_width) % 4 != 0)
                for (int j = 0; j < 4 - (3*m_width) % 4; j++)
                {
                    char c;
                    in.read(&c, 1);
                }
            pixels.push_back(v);
            v.clear();
        }
    };

    ~bmp(){};
    void write(std::string where)
    {
        std::ofstream out(where, std::ios::binary);
        out.write(reinterpret_cast<char*>(&m_header), sizeof(bmp_header));
        out.write(reinterpret_cast<char*>(&m_info), sizeof(bmp_info));
        for (int i = 0; i < m_height; i++)
        {
            for (int j = 0; j < m_width; j++)
                out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(pixel));

            if ((3 * m_width) % 4 != 0)
                for (int j = 0; j < 4 - (3*m_width) % 4; j++)
                {
                    char c = 0;
                    out.write(&c, 1);
                }
        }
    }
    void filter(char color,char up_or_down,int power)
    {
        if(up_or_down == 'd')
            power *= -1;
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                if(pixels[i][j].b + power > 0 && color == 'b')
                    pixels[i][j].b += power;
                if (pixels[i][j].g + power > 0 && color == 'g')
                    pixels[i][j].g += power;
                if (pixels[i][j].r + power > 0 && color == 'r')
                    pixels[i][j].r += power;
            }
    }
    int getHeight() const{return m_height;}
    int getWidth() const{return m_width;}
private:
#pragma pack(1)
    struct bmp_header
    {
        unsigned short    Type;
        unsigned int      Size;
        unsigned short    Reserved1;
        unsigned short    Reserved2;
        unsigned int      OffBits;
    };
#pragma pack()
#pragma pack(1)
    struct bmp_info
    {
        unsigned int    Size;
        int             Width;
        int             Height;
        unsigned short  Planes;
        unsigned short  BitCount;
        unsigned int    Compression;
        unsigned int    SizeImage;
        int             XPelsPerMeter;
        int             YPelsPerMeter;
        unsigned int    ClrUsed;
        unsigned int    ClrImportant;
    };
#pragma pack()
#pragma pack(1)
    struct pixel
    {
        unsigned char b;
        unsigned char g;
        unsigned char r;
    };
#pragma pack()
    int m_height, m_width;
    bmp_header m_header;
    bmp_info m_info;
    std::vector<std::vector<pixel>> pixels;
};