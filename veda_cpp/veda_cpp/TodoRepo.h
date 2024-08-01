#ifndef _TODO_REPO_H
#define _TODO_REPO_H
#include "Todo.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <mutex>

class TodoRepo
{
public:
	TodoRepo() = default;
	virtual ~TodoRepo() = default;
	/// <summary>
	/// Todo ������ 1�� ���� ����
	/// </summary>
	/// <param name="data"> ������ Todo ��ü</param>
	/// <returns>����� Todo ��ü</returns>
	virtual Todo& save(Todo& data) = 0;
	/// <summary>
	/// vector<Todo>�� �����ϴ� ��� �����͸� ���� ����
	/// ���α׷� ����� ȣ��
	/// </summary>
	/// <param name="data"> ������ Todo �迭</param>
	/// <returns>����� ��ü ��</returns>
	virtual unsigned int saveArray(std::vector<Todo> data) = 0;
	/// <summary>
	/// Todo�� id�� ������ �ش��ϴ� Todo�� ���� ����ҿ��� ����
	/// </summary>
	/// <param name="id">Todo�� id</param>
	/// <returns>������ ��ü�� id</returns>
	virtual unsigned int deleteById(unsigned int id) = 0;
	/// <summary>
	/// ���α׷� ���� �� ���� ������� Todo ������ ��� ������
	/// </summary>
	/// <returns> Todo �������� �迭</returns>
	virtual std::vector<Todo>& load() = 0;
	/// <summary>
	/// Todo �����͸� ����
	/// </summary>
	/// <param name="id"> �����ϰ��� �ϴ� Todo�� id</param>
	/// <param name="data">�����ϰ����ϴ� ������ Todo ��ü</param>
	/// <returns> ������ Todo��ü</returns>
	virtual Todo& modify(unsigned int id, Todo data) = 0;
};

class TodoRepoFile : public TodoRepo
{
private:
	std::fstream file;
	std::mutex lock;

public:

	Todo& save(Todo& data);

	unsigned int saveArray(std::vector<Todo> data);
	unsigned int deleteById(unsigned int id);
	std::vector<Todo>& load();
	Todo& modify(unsigned int id, Todo data);

};
#endif // !_TODO_REPO_H
