#ifndef GRAPHICS_OPERATIONS
#define GRAPHICS_OPERATIONS


#include "E:\study\data stucture\data STL\DataStruct_CppSTL\include/ezdraw.h"

void openWindow();	//��ʼ����
void viewWindow();	// ��ͣ
void eraseWindow(); //	��������
void closeWindow();	// �رմ���

	// ��ִ����һ��ָ��֮ǰ�ȴ�����
void delayWindow(double secs);
	// �ж��Ƿ��а�������
bool keyPress();


/************************************************************************/
/*						ʵ��		                                                */
/************************************************************************/


void openWindow()
{
	ezdInitialize();
}

void viewWindow()
{
	ezdWaitForKeyPress();
}

void eraseWindow()
{
	ezdClearDrawSurface();
}

void closeWindow()
{
	ezdCleanUp();
}

void delayWindow(double secs)
{
	ezdWait((EZDUINT)(secs * 1000));
}


bool keyPress()
{
	if (ezdKeyPress() != 0)
		return true;
	else
		return false;
}

#endif // !GRAPHICS_OPERATIONS
