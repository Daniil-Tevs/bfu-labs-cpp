#pragma once
#include <iostream>

namespace dt{
    struct Pixel
    {
        uint8_t r, g, b, a;
    };

	struct Point
	{
		double x, y, z;
        Pixel color;
	};

	struct Angles
	{
		double roll, pitch, yaw;
	};


	struct Intrinsic
	{
		double fu, fv;
		double du, dv;
	};

	class Camera
	{
	public:
		Camera(int width, int height, Intrinsic intrinsic, Point position, Angles angles);
		~Camera();

		Pixel* Picture();
		void Fill(Pixel pixel);
		void Clear();
		void ProjectPoint(Point p, Pixel c);
		void dX(double d);
		void dZ(double d);
		void dRoll(double droll);
		void dPitch(double dpitch);
        void setPositionBase(Point base);

	private:
		int m_width;
		int m_height;
		Pixel* m_picture;
		Intrinsic m_intrinsic;

		Point m_position;
		Angles m_angles;
	};
}