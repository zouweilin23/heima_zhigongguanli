#pragma once
#include"worker.h"
class boss:public worker {
public:
	boss(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDeptName();
};