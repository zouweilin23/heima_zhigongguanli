#include"boss.h"
#include"manager.h"
#include"employee.h"
#include"worker.h"


int main() {
	worker* worker = NULL;
	worker = new employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new boss(3, "王五", 3);
	worker->showInfo();
	delete worker;

	return 0;
}