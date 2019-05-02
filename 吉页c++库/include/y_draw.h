#ifndef GRAPHICS_OPERATIONS
#define GRAPHICS_OPERATIONS


#include "E:\study\data stucture\data STL\DataStruct_CppSTL\include/ezdraw.h"

void openWindow();	//初始画板
void viewWindow();	// 暂停
void eraseWindow(); //	擦除窗口
void closeWindow();	// 关闭窗口

	// 在执行下一条指令之前等待几秒
void delayWindow(double secs);
	// 判断是否有按键输入
bool keyPress();


/************************************************************************/
/*						实现		                                                */
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
