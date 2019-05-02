/*
	2014��7��8�� 18:15:24
	��ҳ
	���ܣ�
		�������û��� �̶ȳߵ���ʽ�� ���ֵݹ�˼���е��۰�˼ά
*/

#include <string>

#include "y_draw.h"	// ��ͼlib
#include "y_linesh.h"
#include "y_textsh.h"

using namespace std;

	// ��һ��ĵط�����һ����ʶ�� �߶ȣ� h * baseHeight
void drawMark(double mid, int h);

	// ����ÿ�� 1/2 λ�õı�ʶ
void drawRuler(double low, double high, int h);

int main()
{
		// ����һ��û�б�ʶ�Ŀ̶ȳ�
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