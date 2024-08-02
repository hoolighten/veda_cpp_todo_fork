#ifndef __USER_TODO_H
#define __USER_TODO_H
#include<string>
#include<vector>
#include"Todo.h"

class UserTodo
{
	std::string userName;
	std::vector<Todo> data;
	std::vector<Todo> finishData;
public:

	UserTodo() = default;
	UserTodo(std::string userName, std::vector<Todo> data, std::vector<Todo> finish);
	UserTodo(const UserTodo& obj);

	std::string getUserName();
	std::vector<Todo> getData();
	std::vector<Todo> getFinishData();

	void setUserName(std::string userName);
	void setData(std::vector<Todo> data);

	/// <summary>
	/// data�� �ִ� ���� �� �ش� �����Ͱ� �������� ��������, finishData ���ͷ� �ű�
	/// </summary>
	/// <param name="id"> finishData�� �ű� Todo ��ü�� id</param>
	void moveToFinish(unsigned int id);
};
#endif // !__USER_TODO_H
