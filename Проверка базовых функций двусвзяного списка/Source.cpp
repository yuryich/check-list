#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "list.hpp"

TEST_CASE("Проверка функции Empty()") {
	List list;

	SECTION("Список должен быть пустой после создания") {
		REQUIRE(list.Empty() == true);
	}

	SECTION("Список не пустой после добавления элемента") {
		list.PushBack(10);
		REQUIRE(list.Empty() == false);
	}

	SECTION("Список снова пустой после удаления всех элементов") {
		list.PushBack(10);
		list.PopBack();
		REQUIRE(list.Empty() == true);
	}
}

TEST_CASE("Проверка функции Size()") {
	List list;

	SECTION("Размер списка должен быть 0 после создания") {
		REQUIRE(list.Size() == 0);
	}

	SECTION("Размер списка увеличивается после добавления элементов") {
		list.PushBack(5);
		list.PushFront(3);
		REQUIRE(list.Size() == 2);
	}

	SECTION("Размер списка уменьшается после удаления элементов") {
		list.PushBack(5);
		list.PushFront(3);
		list.PopBack();
		REQUIRE(list.Size() == 1);
	}
}

TEST_CASE("Проверка функции Clear()") {
	List list;

	SECTION("После вызова Clear список должен стать пустым") {
		list.PushBack(10);
		list.PushFront(20);
		REQUIRE(list.Size() == 2);
		list.Clear();
		REQUIRE(list.Size() == 0);
		REQUIRE(list.Empty() == true);
	}

	SECTION("Clear работает на пустом списке") {
		REQUIRE_NOTHROW(list.Clear());
		REQUIRE(list.Empty() == true);
	}
}