#include <iostream>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depid = dId;
}


void manager::showInfo() {
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string manager::getDeptName() {
	return string("����");
}