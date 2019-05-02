#ifndef TEXT_SHAPE_CLASS
#define TEXT_SHAPE_CLASS

#include <string>
#include "y_shape.h"

using namespace std;

class textShape : public shape
{
public: 
	textShape(double x = 0.0, double y = 0.0,
		const string& s = "", shapeColor c = darkgray);

	string getText() const;
	void setText(const string& s);

	virtual void draw();

private:
	string text;
};

textShape::textShape(double x, double y, const string& s,
	shapeColor c) :
	shape(x, y, c), text(s)
{}

string textShape::getText() const
{
	return text;
}

void textShape::setText(const string& s)
{
	text = s;
}

void textShape::draw()
{
	EZDCOLORVAL old_color;

	old_color = ezdSetColor(color.convertToEzdColor());
		// 执行方法绘制文本框
	ezdSetColor(old_color);
}

#endif // !TEXT_SHAPE_CLASS
