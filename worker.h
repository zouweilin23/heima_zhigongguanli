#pragma once
#include <iostream>
#include <string>
using namespace std;

//父类，多态实现普通员工、经理、老板

//职工的属性为：职工编号、职工姓名、职工所在部门编号

//职工的行为为：岗位职责信息描述，获取岗位名称
class worker {
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_id=0;//职工编号
	string m_name;//姓名
	int m_depid=0;//部门编号
};

