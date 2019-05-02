/*
	2014年4月6日 09:07:40
	吉页
	功能： 此程序提示用户输入文件的路径名，它使用string类操作来识别并输出路径名和文件名
	如果文件名有扩展名“cpp”，则创建输出“exe”替换扩展名
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string pathname, path, filename, executableFile;

	// "/" and "." 的位置
	int backslashIndex, dotIndex;
	cout << "Enter the path name: ";
	cin >> pathname;

	backslashIndex = pathname.find_first_of('/');

	// 路径名是后一个 / 之前的字符
	path = pathname.substr(0, backslashIndex);

	cout << "Path : " << path << endl;

	// 路径名的尾部是文件名
	filename = pathname.substr(backslashIndex + 1, - 1);
	cout << "Filename : " << filename << endl;

	// 查看文件是否有".cpp"扩展名
	//首先找到最后一个“。”的位置，如果没有"."，则dotIndex = -1
	dotIndex = filename.find_last_of('.');

	if (dotIndex != -1 && filename.substr(dotIndex+1) == "cpp")
	{
		// 删除"cpp"，并加上"exe"设置可执行字符串
		executableFile = filename;
		executableFile.erase(dotIndex + 1,3);
		executableFile += "exe";
		cout << "Executable: " << executableFile << endl;
	}

	return 0;

}