#pragma once

#include <iostream>
#include <string>
#include <functional>

typedef struct _qListNode
{
	int Data = 0;
	_qListNode* Next = nullptr;

	_qListNode() {}
	_qListNode(int d, _qListNode* n) : Data(d), Next(n) {}
	_qListNode(int d) : Data(d), Next(nullptr) {}
}QListNode;

class MyPriorityQueueException : public std::exception
{
public:
	MyPriorityQueueException(std::string msg)
	{
		_msg = _msg.append(": ");
		_msg = _msg.append(msg);
	}

	virtual const char* what() 
	{
		return _msg.c_str();
	}

private:
	std::string _msg = "MyPriorityQueue exception";
};

class MyPriorityQueue
{
public:
	MyPriorityQueue(std::function<bool(int, int)> cmp = std::less<int>()) {
		_cmp = cmp;
	}
	~MyPriorityQueue() {}

	void Push(int num)
	{
		if (_head) {
			QListNode* node = new QListNode(num);
			QListNode* cur = _head;
			QListNode* pre = nullptr;
			// while (cur && node->Data < cur->Data) {
			while (cur && _cmp(node->Data, cur->Data)) {
				pre = cur;
				cur = cur->Next;
			}

			if (pre) {
				pre->Next = node;
				node->Next = cur;
				if (!cur)
					_end = node;
			}
			else {
				node->Next = cur;
				_head = node;
			}
		}
		else {
			QListNode* node = new QListNode(num);
			_head = node;
			_end = _head;
		}
	}

	int Top()
	{
		if (!Empty()) {
			return _head->Data;
		}
		else {
			throw new MyPriorityQueueException("queue is empty");
		}
	}

	void Pop()
	{
		if (_head) {
			QListNode* cur = _head;
			_head = cur->Next;
			delete cur;

			if (!_head)
				_end = nullptr;
		}
	}

	bool Empty()
	{
		return !_head;
	}

private:
	QListNode* _head = nullptr;
	QListNode* _end = nullptr;
	std::function<bool(int, int)> _cmp;
};