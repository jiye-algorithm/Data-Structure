#ifndef GEOMETRIC_FIGURES_BASE
#define GEOMETRIC_FIGURES_BASE

#include "y_draw.h"

	// 图形的颜色
enum drawing_color
{
	white, blue, teal, green, turqqoise, darkgray,
	brown, purple, lightblue, lightgray, gold, red,
	orange, pink, yellow, black
};

#ifdef _MSC_VER

class shapeColor;

bool operator== (const shapeColor& lhs,
	const shapeColor& rhs);

bool operator != (const shapeColor& lhs,
	const shapeColor& rhs);

bool operator < (const shapeColor& lhs,
	const shapeColor& rhs);

bool operator <= (const shapeColor& lhs,
	const shapeColor& rhs);

bool operator > (const shapeColor& lhs,
	const shapeColor& rhs);

bool operator >= (const shapeColor& lhs,
	const shapeColor& rhs);

#endif // _MSC_VER

class shapeColor
{
public:
		// 构造函数
	shapeColor(drawing_color c = blue);

		// 自增和自减运算符
	shapeColor operator++(int);
	shapeColor& operator++();
	shapeColor operator--(int);
	shapeColor& operator--();

		// 比较函数
	friend bool operator== (const shapeColor& lhs,
		const shapeColor& rhs);

	friend bool operator != (const shapeColor& lhs,
		const shapeColor& rhs);

	friend bool operator < (const shapeColor& lhs,
		const shapeColor& rhs);

	friend bool operator <= (const shapeColor& lhs,
		const shapeColor& rhs);

	friend bool operator > (const shapeColor& lhs,
		const shapeColor& rhs);

	friend bool operator >= (const shapeColor& lhs,
		const shapeColor& rhs);

		// 转化为Windows定义的函数
	ezdColor convertToEzdColor();

private:
	drawing_color color;

		// 从简单的定义table颜色转化为必要的windows定义的颜色
	static const ezdColor g_aColors[];
};


/************************************************************************/
/*				shapeColor	实现                                                                     */
/************************************************************************/


	// color conversion lookup table
const ezdColor shapeColor::g_aColors[] = {
	ezdWhite,
	ezdBlue,
	ezdTeal,	// 蓝绿色
	ezdGreen,
	ezdTurquoise,
	ezdDarkGray,
	ezdBrown,
	ezdPurple,
	ezdLightBlue,
	ezdLightGray,
	ezdGold,
	ezdRed,
	ezdOrange,
	ezdPink,
	ezdYellow,
	ezdBlack
};

shapeColor::shapeColor(drawing_color c) : color(c)
{}

shapeColor shapeColor::operator++(int)
{
	drawing_color origColor = color;

	color = drawing_color((color + 1) % 16);
	return shapeColor(origColor);
}

shapeColor& shapeColor::operator++()
{
		// 整形赋给枚举型时需要强制类型转换
	color = drawing_color((color + 1) % 16);
	return *this;
}

shapeColor shapeColor::operator--(int)
{
	drawing_color origColor = color;

		// 如果是负数就会出现bug如-1， -2对应相同值
	if (color == white)
		color = black;
	else
		color = drawing_color(color - 1);

	return shapeColor(origColor);
}

shapeColor& shapeColor::operator--()
{
	// 如果是负数就会出现bug如-1， -2对应相同值
	if (color == white)
		color = black;
	else
		color = drawing_color(color - 1);

	return *this;
}

ezdColor shapeColor::convertToEzdColor()
{
	return g_aColors[color];
}

bool operator== (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color == rhs.color;
}

bool operator!= (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color != rhs.color;
}

bool operator< (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color < rhs.color;
}

bool operator<= (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color <= rhs.color;
}

bool operator> (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color > rhs.color;
}

bool operator>= (const shapeColor& lhs,
	const shapeColor& rhs)
{
	return lhs.color >= rhs.color;
}

	// 图形基本类型， 包含有基本的点和颜色，还有一些访问修改这些属性的方法， 
	// 其他画图类型继承该类
class shape
{
public:
		// 初始化基本点和填充色
	shape(double x, double y, shapeColor c);

		// 基类的析构函数， 有继承关系， 虚函数是必要的
	virtual ~shape();

	double getX() const;
	double getY() const;

		// 移动点到参数的位置
	void move(double x, double y);

		// 得到图形的填充色
	shapeColor getColor() const;

		// 设置图形的填充色
	void setColor(shapeColor c);

		// 绘制图形
	virtual void draw() = 0;

		// 擦出图形
	void erase();

		//更新
	virtual void update();

protected:
		// 基本点
	double baseX, baseY;

		// 图的颜色
	shapeColor color;

		// 图的句柄, 一个无符号整形值
	EZDHANDLE shape_handle;
};


/************************************************************************/
/*					shape类 实现                                                                     */
/************************************************************************/

shape::shape(double x, double y, shapeColor c) :
baseX(x), baseY(y), color(c), shape_handle(0)
{}

shape::~shape()
{}

double shape::getX() const
{
	return baseX; 
}

double shape::getY() const
{
	return baseY;
}

shapeColor shape::getColor() const
{
	return color;
}

void shape::setColor(shapeColor c)
{
	color = c;
}

void shape::move(double x, double y)
{
	baseX = x;
	baseY = y;
}

void shape::erase()
{
	if (shape_handle != 0)
		ezdDeleteShape(shape_handle);

	shape_handle = 0;
}

void shape::update()
{
	erase();
	draw();
}

#endif // !GEOMETRIC_FIGURES_BASE
