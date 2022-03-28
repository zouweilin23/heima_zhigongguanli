#include "workmanager.h"
#include <iostream>
#include"boss.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"

using namespace std;


workmanager::workmanager() {

	ifstream ifs;
	ifs.open(filename, ios::in);
	//文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		this->e_num = 0;//初始化人数
		this->e_array = NULL;//初始化数组指针
		this->fileisEmpty = true;
		ifs.close();
		return;
	}
	else {
		//文件存在但为空
		if (ifs.eof()) {
			cout << "文件为空！" << endl;
			this->e_num = 0;//初始化人数
			this->e_array = NULL;//初始化数组指针
			this->fileisEmpty = true;
			ifs.close();
			return;

		}
		else {
			//文件中存在职工，则初始化类
			this->e_num = this->get_num();//读取文件中职工数
			this->e_array = new worker * [this->e_num];
			init_emp();
			this->fileisEmpty = false;
			cout << "职工个数为：" << this->e_num << endl;

		}
	}

}

workmanager::~workmanager() {
	if (this->e_array != NULL) {
		delete[]this->e_array;
		this->e_array = NULL;
	}
}


//菜单显示
void workmanager::showmenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void workmanager::exitsystem() {
	cout << "欢迎下次使用！" << endl;
	exit(0);
}

//添加职工
void workmanager::add_num() {
	cout << "请输入增加的员工数量：" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {

		//计算新空间大小
		int newsize = this->e_num + addnum;
		//开辟新空间
		worker** newspace = new worker * [newsize];
		//将原空间下内容存放到新空间下
		if (this->e_array != NULL) {
			for (int i = 0; i < e_num; i++) {
				if (i < newsize) {   //编译器下需要判断i是否越界，否者会报错
					newspace[i] = this->e_array[i];
				}
			}
			//输入新数据
			for (int i = 0; i < addnum; i++)
			{
				int id;
				string name;
				int dSelect;

				cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
				cin >> id;


				cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
				cin >> name;


				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;

				worker* worker = NULL;
				switch (dSelect)
				{
				case 1: //普通员工
					worker = new employee(id, name, 1);
					break;
				case 2: //经理
					worker = new manager(id, name, 2);
					break;
				case 3:  //老板
					worker = new boss(id, name, 3);
					break;
				default:
					break;
				}
				if ((this->e_num + i) < newsize) {
					*(newspace+(this->e_num + i)) = worker;
				}
			}
			//释放原有空间
			delete[] this->e_array;

			//更改新空间的指向
			this->e_array = newspace;

			//更新新的个数
			this->e_num = newsize;

			//提示信息
			cout << "成功添加" << addnum << "名新职工！" << endl;
			this->save();

		}
		else {
			this->e_num = addnum;
			this->e_array = new worker * [this->e_num];
			//输入新数据
			for (int i = 0; i < addnum; i++)
			{
				int id;
				string name;
				int dSelect;

				cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
				cin >> id;


				cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
				cin >> name;


				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;

				worker* worker = NULL;
				switch (dSelect)
				{
				case 1: //普通员工
					worker = new employee(id, name, 1);
					break;
				case 2: //经理
					worker = new manager(id, name, 2);
					break;
				case 3:  //老板
					worker = new boss(id, name, 3);
					break;
				default:
					break;
				}
				this->e_array[i] = worker;
			}
			//提示信息
			cout << "成功添加" << addnum << "名新职工！" << endl;
			this->save();
		}
		this->fileisEmpty = false;
	}
	else {
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");

}

void workmanager::save() {
	ofstream ofs;
	ofs.open(filename, ios::out);//写入职工信息
	for (int i = 0; i < this->e_num; i++) {
		ofs << this->e_array[i]->m_id << " "
			<< this->e_array[i]->m_name << " "
			<< this->e_array[i]->m_depid << " " << endl;
	}

	ofs.close();
}

int workmanager::get_num() {
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;

}

//将文件中的数据写入程序中的类中
void workmanager::init_emp() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new manager(id, name, dId);
		}
		else //总裁
		{
			worker = new boss(id, name, dId);
		}
		//存放在数组中
		this->e_array[index] = worker;
		index++;


	}

}

//显示职工信息
void workmanager::show_emp() {
	if (this->fileisEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < e_num; i++) {
			this->e_array[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//是否表中存在编号为id的职工，有则返回其下标
int workmanager::is_exist(int id) {
	int index = -1;

	for (int i = 0; i < this->e_num; i++)
	{
		if (this->e_array[i]->m_id == id)
		{
			index = i;

			break;
		}
	}

	return index;
}


//删除职工信息，删除编号为Index的职工信息
void workmanager::del_emp() {
	if (this->fileisEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除职工的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->is_exist(id);
		if (index != -1) {
			for (int i = index; i < this->e_num - 1; i++) {

				this->e_array[i] = this->e_array[i + 1];
			}
			this->e_num--;
			this->save(); //删除后数据同步到文件中
			if (this->e_num == 0) {
				this->fileisEmpty = true;//删除后文件中可能没有职工信息，及时更新
			}
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}


//修改职工信息
void workmanager::mod_emp() {
	if (this->fileisEmpty) {
		cout << "文件不存在或记录为空，不能修改！" << endl;
	}
	else {
		cout << "请输入要修改的职工编号：" << endl;
		int id = 0;
		cin >> id;
		if (this->is_exist(id) != -1) {
			delete this->e_array[this->is_exist(id)];

			int newId = 0;
			string newName;
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, newName, dSelect);
				break;
			case 2:
				worker = new manager(id, newName, dSelect);
				break;

			case 3:
				worker = new boss(id, newName, dSelect);
				break;
			default:
				break;
			}
			//更改数据 到数组中
			this->e_array[this->is_exist(id)] = worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败，查无此人" << endl;
		}

	}
	system("pause");
	system("cls");
}

//功能描述：提供两种查找职工方式，一种按照职工编号，一种按照职工姓名
void workmanager::find_emp() {
	if (this->fileisEmpty) {
		cout << "文件不存在或记录为空，查找失败！" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: {
			cout << "请输入要查找职工的编号：" << endl;
			int id = 0;
			cin >> id;
			if (this->is_exist(id) != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->e_array[this->is_exist(id)]->showInfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}
			break;
		}
		case 2: {
			cout << "请输入要查找的职工姓名：" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->e_num; i++) {
				if (this->e_array[i]->m_name == name) {
					cout << "查找成功，该职工信息为：" << endl;
					this->e_array[i]->showInfo();
					flag = true;
				}//按名查找，可能有同名的，需遍历全部序列
			}
			if (flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
			break;
		}
		default: {
			cout << "输入有误！" << endl;
			break;
		}
		}
	}
	system("pause");
	system("cls");
}


//排序
//功能描述：按照职工编号进行排序，排序的顺序由用户指定

void workmanager::sort_emp() {
	if (this->fileisEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		//升序
		if (select == 1) {
			for (int i = 0; i < this->e_num - 1; i++) {
				int min = i;
				for (int j = i + 1; j < this->e_num; j++) {
					if (this->e_array[j]->m_id < this->e_array[min]->m_id) {
						min = j;
					}
				}
				worker* temp = this->e_array[min];
				this->e_array[min] = this->e_array[i];
				this->e_array[i] = temp;

			}

		}
		//降序
		if (select == 2) {
			for (int i = 0; i < this->e_num - 1; i++) {
				int max = i;
				for (int j = i + 1; j < this->e_num; j++) {
					if (this->e_array[j]->m_id > this->e_array[max]->m_id) {
						max = j;
					}
				}
				worker* temp = this->e_array[max];
				this->e_array[max] = this->e_array[i];
				this->e_array[i] = temp;

			}

		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->show_emp();

	}
}


void workmanager::clean_file() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		////打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs;
		ofs.open(filename, ios::trunc);
		ofs.close();
		//释放建立的类
		if (this->e_array != NULL) {
			for (int i = 0; i < this->e_num; i++) {
				if (this->e_array[i] != NULL) {
					delete this->e_array[i];
				}
			}
			this->e_num = 0;
			this->fileisEmpty = true;
			delete[] this->e_array;
			this->e_array = NULL;
		}

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");

}