#ifndef LINESHAPE_CLASS
#define LINESHAPE_CLASS

#include "y_shape.h"

	// 绘制直线的类
class lineShape : public shape
{
public: 
		// 构造函数， 初始话直线的两个点和颜色
	lineShape(double x = 0.0, double y = 0.0,
		double x2 = 0.0, double y2 = 0.0,
		shapeColor c = darkgray);

	double getEndX() const;
	double getEndY() const;
	void setEndPoint(double x, double y);

		// 绘制图形
	virtual void draw();

private:
	double endX, endY;
};

lineShape::lineShape(double x, double y,
	double x2, double y2, shapeColor c) :
	shape(x, y, c), endX(x2), endY(y2)
{}

double lineShape::getEndX() const
{
	return endX;
}

double lineShape::getEndY() const
{
	return endY;
}

	// 重置终点坐标
void lineShape::setEndPoint(double x, double y)
{
	endX = x;
	endY = y;
}

void lineShape::draw()
{
	EZDCOLORVAL old_color;

	old_color = ezdSetColor(color.convertToEzdColor());
	shape_handle = ezdDrawLine(baseX, baseY, endX, endY);
	ezdSetColor(old_color);
}

#endif // !LINESHAPE_CLASS
