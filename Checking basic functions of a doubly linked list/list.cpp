#include "list.hpp"
#include <iostream>

// Реализация конструктора ListNode
ListNode::ListNode(int value, ListNode* prev, ListNode* next)
	: value(value), prev(prev), next(next) {
	if (prev != nullptr) prev->next = this;
	if (next != nullptr) next->prev = this;
}

// Конструктор списка
List::List()
	: m_head(new ListNode(0)), m_size(0), m_tail(new ListNode(0, m_head)) {
}

// Деструктор списка
List::~List() {
	Clear();
	delete m_head;
	delete m_tail;
}

// Проверка на пустоту списка
bool List::Empty() {
	return m_size == 0;
}

// Получение размера списка
unsigned long List::Size() {
	return m_size;
}

// Добавление элемента в начало
void List::PushFront(int value) {
	new ListNode(value, m_head, m_head->next);
	++m_size;
}

// Добавление элемента в конец
void List::PushBack(int value) {
	new ListNode(value, m_tail->prev, m_tail);
	++m_size;
}

// Удаление элемента из начала
int List::PopFront() {
	if (Empty()) throw std::runtime_error("list is empty");
	auto node = extractPrev(m_head->next->next);
	int ret = node->value;
	delete node;
	return ret;
}

// Удаление элемента с конца
int List::PopBack() {
	if (Empty()) throw std::runtime_error("list is empty");
	auto node = extractPrev(m_tail);
	int ret = node->value;
	delete node;
	return ret;
}

// Очистка списка
void List::Clear() {
	auto current = m_head->next;
	while (current != m_tail) {
		current = current->next;
		delete extractPrev(current);
	}
}

// Вспомогательная функция для удаления узла
ListNode* List::extractPrev(ListNode* node) {
	auto target = node->prev;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	--m_size;
	return target;
}