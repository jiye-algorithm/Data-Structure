/*
	2014��4��6�� 09:07:40
	��ҳ
	���ܣ� �˳�����ʾ�û������ļ���·��������ʹ��string�������ʶ�����·�������ļ���
	����ļ�������չ����cpp�����򴴽������exe���滻��չ��
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string pathname, path, filename, executableFile;

	// "/" and "." ��λ��
	int backslashIndex, dotIndex;
	cout << "Enter the path name: ";
	cin >> pathname;

	backslashIndex = pathname.find_first_of('/');

	// ·�����Ǻ�һ�� / ֮ǰ���ַ�
	path = pathname.substr(0, backslashIndex);

	cout << "Path : " << path << endl;

	// ·������β�����ļ���
	filename = pathname.substr(backslashIndex + 1, - 1);
	cout << "Filename : " << filename << endl;

	// �鿴�ļ��Ƿ���".cpp"��չ��
	//�����ҵ����һ����������λ�ã����û��"."����dotIndex = -1
	dotIndex = filename.find_last_of('.');

	if (dotIndex != -1 && filename.substr(dotIndex+1) == "cpp")
	{
		// ɾ��"cpp"��������"exe"���ÿ�ִ���ַ���
		executableFile = filename;
		executableFile.erase(dotIndex + 1,3);
		executableFile += "exe";
		cout << "Executable: " << executableFile << endl;
	}

	return 0;

}