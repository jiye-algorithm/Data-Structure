#ifndef GEOMETRIC_FIGURES_BASE
#define GEOMETRIC_FIGURES_BASE

#include "y_draw.h"

	// ͼ�ε���ɫ
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
		// ���캯��
	shapeColor(drawing_color c = blue);

		// �������Լ������
	shapeColor operator++(int);
	shapeColor& operator++();
	shapeColor operator--(int);
	shapeColor& operator--();

		// �ȽϺ���
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

		// ת��ΪWindows����ĺ���
	ezdColor convertToEzdColor();

private:
	drawing_color color;

		// �Ӽ򵥵Ķ���table��ɫת��Ϊ��Ҫ��windows�������ɫ
	static const ezdColor g_aColors[];
};


/************************************************************************/
/*				shapeColor	ʵ��                                                                     */
/************************************************************************/


	// color conversion lookup table
const ezdColor shapeColor::g_aColors[] = {
	ezdWhite,
	ezdBlue,
	ezdTeal,	// ����ɫ
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
		// ���θ���ö����ʱ��Ҫǿ������ת��
	color = drawing_color((color + 1) % 16);
	return *this;
}

shapeColor shapeColor::operator--(int)
{
	drawing_color origColor = color;

		// ����Ǹ����ͻ����bug��-1�� -2��Ӧ��ֵͬ
	if (color == white)
		color = black;
	else
		color = drawing_color(color - 1);

	return shapeColor(origColor);
}

shapeColor& shapeColor::operator--()
{
	// ����Ǹ����ͻ����bug��-1�� -2��Ӧ��ֵͬ
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

	// ͼ�λ������ͣ� �����л����ĵ����ɫ������һЩ�����޸���Щ���Եķ����� 
	// ������ͼ���ͼ̳и���
class shape
{
public:
		// ��ʼ������������ɫ
	shape(double x, double y, shapeColor c);

		// ��������������� �м̳й�ϵ�� �麯���Ǳ�Ҫ��
	virtual ~shape();

	double getX() const;
	double getY() const;

		// �ƶ��㵽������λ��
	void move(double x, double y);

		// �õ�ͼ�ε����ɫ
	shapeColor getColor() const;

		// ����ͼ�ε����ɫ
	void setColor(shapeColor c);

		// ����ͼ��
	virtual void draw() = 0;

		// ����ͼ��
	void erase();

		//����
	virtual void update();

protected:
		// ������
	double baseX, baseY;

		// ͼ����ɫ
	shapeColor color;

		// ͼ�ľ��, һ���޷�������ֵ
	EZDHANDLE shape_handle;
};


/************************************************************************/
/*					shape�� ʵ��                                                                     */
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
