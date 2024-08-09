#include "DataManage.h"
#include <ctime>

using namespace std;

DataManageImpl::DataManageImpl(TodoRepo* todoRepo, UserTodoConverter* converter)
{
	this->todoRepo = todoRepo;
	this->converter = converter;

	this->converter->load(this->userTodoData);
}
DataManageImpl::~DataManageImpl()
{
	this->converter->save(this->userTodoData);
}
bool DataManageImpl::getCurrentData(vector<Todo>& res, string name)
{
	if (userTodoData.find(name) == userTodoData.end()) {
		//	�Է��� �����Ͱ� ���� ���
		return false;
	}
	UserTodo userData = userTodoData[name];
	res = userData.getCurrentData();

	return true;
}

bool DataManageImpl::getFinishedData(vector<Todo>& res, string name)
{
	if (userTodoData.find(name) == userTodoData.end()) {
		//	�Է��� �����Ͱ� ���� ���
		return false;
	}
	UserTodo userData = userTodoData[name];
	res = userData.getFinishedData();

	return true;
}

Todo DataManageImpl::addTodoData(string name, Todo data)
{
	time_t timer = time(NULL);
	// YYYY-MM-DD
	struct tm* currentTime = localtime(&timer);

	// ó���߰��ϴ� ������ ���
	if (userTodoData.find(name) == userTodoData.end()) {
		vector<Todo> current;
		vector<Todo> finish;

		
		UserTodo userData = UserTodo(0, name, current, finish);
		data.setId(0);
		userData.insertData(data);

		userTodoData.insert({name, userData});

		return data;
	}

	// ������ ������ ���
	unsigned int id = userTodoData[name].getId();
	data.setId(id);

	userTodoData[name].insertData(data);
	

	return data;
}

bool DataManageImpl::removeTodoData(string name, unsigned int id) {

	if (userTodoData.find(name) == userTodoData.end()) {
		return false;
	}
	
	userTodoData[name].removeData(id);

	return true;
}