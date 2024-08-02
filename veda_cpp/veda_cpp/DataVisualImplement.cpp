#include <string>
#include <vector>
#include "DataVisualConsole.h"
#include "iostream"
#include "DataManage.h"
#include <vector>
using namespace std;

DataVisualConsole::DataVisualConsole(Datamanage* manage)
{
	this->manage = manage;
}

vector<Todo> DataVisualConsole::setUserData() {
	string name;
	cout << "�̸��� �Է��� �ּ���.";
	cin >> name;
	vector<Todo> res;
	manage->getUserData(res, name);
	return res;
}

void DataVisualConsole::ShowOneData(Todo TodoData) {
	cout
		<< "ID : " << TodoData.getId()
		<< ", name : " << TodoData.getUserName()
		<< ", Content : " << TodoData.getContent()
		<< ", InsertDate :" << TodoData.getInsertDate()
		<< ", DueDate : " << TodoData.getDueDate()
		<< ", Is Done?" << boolalpha << TodoData.getIsDone() <<
		" Is Finished?" << boolalpha << TodoData.getIsFin() << endl;
}

void DataVisualConsole::showUserData(vector<Todo> v) {
	if (v.size() == 0) {
		cout << "�Էµ� �����Ͱ� �����ϴ�." << endl;
		return;
	}
	for (auto iter : v) {
		ShowOneData(iter);
	}
}

void DataVisualConsole::start()
{
	cout << "Todo ���α׷� �Դϴ�." << endl;
	int i = -1;
	do {
		cout << "��� : 1, �Է� : 2, ���� : 3 ���� : -1 \n ---�޴��� �����ϼ���---" << endl;
		cout << "��ȣ �Է� : ";
		cin >> i;
		if (i == 1) {
			vector<Todo> UserDatas = setUserData();
			showUserData(UserDatas);
		}
		else if (i == 2) {
			cout << "������ �����͸� �Է��� �ּ���"<<endl;
			unsigned int id;
			string userName, content, insertDate, dueDate;
			cout << "�̸� >> ";
			cin >> userName;
			cout << userName << endl;
			cout << "���̵� >> ";
			cin >> id;
			cout << id << endl;
			cout << (unsigned int)id << endl;
			cout << "���� >> ";
			cin >> content;
			cout << content << endl;
			cout << "�߰����� >> ";
			cin >> insertDate;
			cout << insertDate << endl;
			cout << "�������� >> ";
			cin >> dueDate;
			cout << dueDate << endl;
			Todo Data;
			Data.setId(id);
			Data.setUserName(userName);
			Data.setContent(content);
			Data.setInsertDate(insertDate);
			Data.setDueDate(dueDate);
			Data.setIsDone(false);
			Data.setIsDone(false);
			Todo resultData = this->manage->addTodoData(userName, Data);
			ShowOneData(resultData);
		}
		else if (i == 3) {
			cout << "������ �����͸� �Է��� �ּ���";
			int id;
			string userName;
			cin >> userName >> id;
			bool result = this->manage->removeTodoData(userName, id);
			cout << "Result : " << boolalpha << result << endl;
		}
	} while (i != -1);

}
