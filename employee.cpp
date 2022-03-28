#include"employee.h"
#include <iostream>


//普通职工类行为的定义


employee::employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depid = dId;
}

//显示个人信息
void employee::showInfo() {
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成经理交给的任务" << endl;


}

//岗位名称
string employee::getDeptName() {
	return string("员工");
}

