#include"boss.h"
#include<iostream>
using namespace std;

boss::boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depid = dId;
}


void boss::showInfo() {
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

string boss::getDeptName() {
	return string("�ܲ�");
}