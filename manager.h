#pragma once
#include"worker.h"


class manager :public worker {
public:
	manager(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();
};
