#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "list.hpp"

TEST_CASE("�������� ������� Empty()") {
	List list;

	SECTION("������ ������ ���� ������ ����� ��������") {
		REQUIRE(list.Empty() == true);
	}

	SECTION("������ �� ������ ����� ���������� ��������") {
		list.PushBack(10);
		REQUIRE(list.Empty() == false);
	}

	SECTION("������ ����� ������ ����� �������� ���� ���������") {
		list.PushBack(10);
		list.PopBack();
		REQUIRE(list.Empty() == true);
	}
}

TEST_CASE("�������� ������� Size()") {
	List list;

	SECTION("������ ������ ������ ���� 0 ����� ��������") {
		REQUIRE(list.Size() == 0);
	}

	SECTION("������ ������ ������������� ����� ���������� ���������") {
		list.PushBack(5);
		list.PushFront(3);
		REQUIRE(list.Size() == 2);
	}

	SECTION("������ ������ ����������� ����� �������� ���������") {
		list.PushBack(5);
		list.PushFront(3);
		list.PopBack();
		REQUIRE(list.Size() == 1);
	}
}

TEST_CASE("�������� ������� Clear()") {
	List list;

	SECTION("����� ������ Clear ������ ������ ����� ������") {
		list.PushBack(10);
		list.PushFront(20);
		REQUIRE(list.Size() == 2);
		list.Clear();
		REQUIRE(list.Size() == 0);
		REQUIRE(list.Empty() == true);
	}

	SECTION("Clear �������� �� ������ ������") {
		REQUIRE_NOTHROW(list.Clear());
		REQUIRE(list.Empty() == true);
	}
}