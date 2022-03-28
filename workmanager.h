#pragma once
#include <iostream>
#include"worker.h"
#include<fstream>
#define filename "empFile.txt"

using namespace std;


//头文件中申明类或函数，可在另一源文件中定义具体函数
//该类用于操控界面，定义各种操作函数
class workmanager {
public:
	workmanager();
	~workmanager();
	void showmenu();//显示菜单
	void exitsystem();//退出系统
	void add_num();//添加职工
	void save();//保存添加的职工到文件
	int get_num(); //读取文件中的职工数量


	void init_emp();//初始化，用于构造函数，若文件已有数据，则将数据读入程序中的类，以便后续操作
	void show_emp();//显示职工信息

	int is_exist(int id);//职工是否存在
	void del_emp();//删除职工
	void mod_emp();//修改职工信息
	void find_emp();//查找职工信息并显示
	void sort_emp();//按编号排序
	void clean_file();//清空文件

	bool fileisEmpty;//记录文件是否为空
	int e_num;//记录文件中员工数量
	worker** e_array;//员工数组的指针

};
