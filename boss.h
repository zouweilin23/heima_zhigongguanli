#pragma once
#include"worker.h"
class boss:public worker {
public:
	boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();
};