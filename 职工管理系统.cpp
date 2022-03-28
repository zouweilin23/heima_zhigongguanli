#include <iostream>
#include <string>
#include "workmanager.h"
using namespace std;

int main() {
	workmanager wm;
	int choice = 0;
	//菜单选项分支
	while (true) {
		wm.showmenu();//保证菜单一直在前面
		cout << "请输入你的选项：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.exitsystem(); 
			break;
		case 1: //添加职工
			wm.add_num();
			break;
		case 2: //显示职工
			wm.show_emp();
			break;
		case 3: //删除职工
			wm.del_emp();
			break;
		case 4: //修改职工
			wm.mod_emp();
			break;
		case 5: //查找职工
			wm.find_emp();
			break;
		case 6: //排序职工
			wm.sort_emp();
			break;
		case 7: //清空文件
			wm.clean_file();
			break;
		default:
			system("cls");//清屏操作
			break;
		}

	}
	return 0;
}

