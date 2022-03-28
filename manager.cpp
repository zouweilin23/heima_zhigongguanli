#include <iostream>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depid = dId;
}


void manager::showInfo() {
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string manager::getDeptName() {
	return string("经理");
}