#include "list.h"
#include "list.cpp"
#include <gtest.h>



TEST(LIST, can_create_list)
{
	ASSERT_NO_THROW(new List<int>());
}

TEST(LIST, can_get_pointer_on_first_node)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	ASSERT_NO_THROW(list->GetFirst());
}

TEST(LIST, created_list_is_empty)
{
	ASSERT_NO_THROW(0, List<int> list()->GetFirst());
}

TEST(LIST, push_element_at_the_beginning)
{
	List<int>* list = new List<int>;
	list->PushStart(1);
	list->PushStart(2);
	EXPECT_EQ(2, list->GetFirst()->key);
}

TEST(LIST, can_push_element_at_the_end)
{
	List<int>* list;
	list = new List<int>;
	ASSERT_NO_THROW(list->PushEnd(2));
}

TEST(LIST, push_element_at_the_end)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushEnd(1);
	List<int>* list1 = new List<int>;
	list1->PushStart(1);
	list1->PushStart(5);
	EXPECT_EQ(*list, *list1);
}

TEST(LIST, can_push_element_after)
{
	List<int>* list;
	list = new List<int>;
	list->PushStart(4);
	ASSERT_NO_THROW(list->PushAfter(4, 6));
}

TEST(LIST, push_after)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushStart(4);
	list->PushAfter(4, 3);
	List<int>* list1 = new List<int>;
	list1->PushStart(5);
	list1->PushStart(3);
	list1->PushStart(4);
	EXPECT_EQ(*list1, *list);
}

TEST(List, throws_when_findkey_does_not_exist_in_PushAfter)
{
	List<int>* list = new List<int>;
	list->PushStart(2);
	ASSERT_ANY_THROW(list->PushAfter(6, 1));
}

TEST(LIST, can_compare_equal_lists)
{
	List<int>* l = new List<int>;
	l->PushEnd(4);
	List<int>* l2 = new List<int>;
	l2->PushEnd(4);
	EXPECT_EQ(*l, *l2);
}

TEST(LIST, can_compare_different_lists)
{
	List<int>* l = new List<int>;
	l->PushEnd(4);
	List<int>* l2 = new List<int>;
	l2->PushEnd(3);
	EXPECT_NE(*l, *l2);
}

TEST(LIST, compare_equal_lists_return_true)
{
	List<int>* list = new List<int>;
	List<int>* list1 = new List<int>;
	list->PushStart(1);
	list1->PushStart(1);
	EXPECT_EQ(*list1, *list);
}

TEST(LIST, compare_different_lists_return_false)
{
	List<int>* list = new List<int>;
	List<int>* list1 = new List<int>;
	list->PushStart(1);
	list1->PushStart(2);
	EXPECT_NE(*list1, *list);
}

TEST(LIST, can_remove_node)
{
	List<int>* l = new List<int>;
	l->PushStart(3);
	l->PushStart(2);
	ASSERT_NO_THROW(l->Remove(3));
}

TEST(LIST, remove_node)
{
	List<int>* list = new List<int>;
	list->PushStart(2);
	list->PushStart(8);
	list->Remove(2);
	List<int>* list1 = new List<int>;
	list1->PushStart(8);
	EXPECT_EQ(*list, *list1);
}

TEST(LIST, throws_when_findkey_was_not_found_in_Remove)
{
	List<int>* list = new List<int>;
	list->PushStart(3);
	ASSERT_ANY_THROW(list->Remove(0));
}

TEST(LIST, can_push_node_at_the_beginning)
{
	List<int>* list;
	list = new List<int>;
	ASSERT_NO_THROW(list->PushStart(3));
}

TEST(LIST, can_find_key)
{
	List<int>* list = new List<int>;
	list->PushStart(2);
	ASSERT_NO_THROW(list->Find(2));
}

TEST(LIST, find_key)
{
	List<int>* list;
	list = new List<int>;
	list->PushStart(4);
	list->PushStart(2);
	EXPECT_EQ(list->Find(4), list->GetFirst()->Next);
}

TEST(LIST, copied_list_is_equal_to_source_one)
{
	List<int>* list = new List<int>;
	list->PushStart(1);
	list->Print();
	List<int>* list1 = new List<int>(*list);
	list1->Print();
	EXPECT_EQ(*list1, *list);
}

TEST(LIST, can_copy_list)
{
	List<int>* list = new List<int>;
	list->PushStart(2);
	ASSERT_NO_THROW(List<int>* list1 = new List<int>(*list));
}

TEST(LIST, throws_when_key_was_not_found)
{
	List<int>* list = new List<int>;
	list->PushStart(2);
	ASSERT_ANY_THROW(list->Find(1));
}

TEST(LIST, can_push_before)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushStart(4);
	ASSERT_NO_THROW(list->PushBefore(4, 8));
}

TEST(LIST, push_before)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushStart(3);
	list->PushBefore(5, 2);
	List<int>* list1 = new List<int>;
	list1->PushStart(5);
	list1->PushStart(2);
	list1->PushStart(3);
	EXPECT_EQ(*list, *list1);
}

TEST(LIST, throws_when_findkey_was_not_found_in_PushBefore)
{
	List<int>* list = new List<int>;
	list->PushStart(8);
	ASSERT_ANY_THROW(list->PushBefore(2, 9));
}

TEST(List, remove_start) 
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushStart(4);
	list->Remove(4);
	List<int>* list1 = new List<int>;
	list1->PushStart(5);
	EXPECT_EQ(*list1, *list);
}

TEST(List, remove_end)
{
	List<int>* list = new List<int>;
	list->PushStart(5);
	list->PushStart(4);
	list->Remove(5);
	List<int>* list1 = new List<int>;
	list1->PushStart(4);
	EXPECT_EQ(*list1, *list);
}

TEST(LIST, throws_when_find_in_empty_list)
{
	List<int>* list = new List<int>;
	ASSERT_ANY_THROW(list->Find(1));
}

TEST(LIST, throws_when_remove_from_empty_list)
{
	List<int>* list = new List<int>;
	ASSERT_ANY_THROW(list->Remove(1));
}