/*
	2014年7月8日 18:15:24
	吉页
	功能：
		程序利用绘制 刻度尺的形式， 表现递归思想中的折半思维
*/

#include <string>

#include "y_draw.h"	// 绘图lib
#include "y_linesh.h"
#include "y_textsh.h"

using namespace std;

	// 在一半的地方绘制一个标识， 高度： h * baseHeight
void drawMark(double mid, int h);

	// 绘制每个 1/2 位置的标识
void drawRuler(double low, double high, int h);

int main()
{
		// 绘制一条没有标识的刻度尺
	lineShape line(1.0, 4.0, 9.0, 4.0, black);

		// use for label each drawing
	string labelStr = "h = ";
	textShape label(4.75, 5, "", black);

	int h;

	openWindow();

	for (h = 1; h <= 7; ++h)
	{
		line.draw();
		drawRuler(1.0, 9.0, h);

		viewWindow();
		eraseWindow();
	}

	closeWindow();

	return 0;

}

void drawMark(double mid, int h)
{
	static lineShape mark(0, 0, 0, 0, black);
	const double baseLength = 0.125;

	mark.move(mid, 4.0 + h * baseLength);
	mark.setEndPoint(mid, 4.0 - h * baseLength);
	mark.draw();
}

void drawRuler(double low, double high, int h)
{
	double midpt;

	if (h >= 1)
	{
		midpt = (high + low) / 2;

		drawMark(midpt, h);

		drawRuler(low, midpt, h - 1);
		drawRuler(midpt, high, h - 1);
	}


}