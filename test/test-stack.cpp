#include "stack.h"
#include "stack.cpp"
#include <gtest.h>

TEST(STACK, can_create_stack)
{
	ASSERT_NO_THROW(new Stack<int>());
}

TEST(STACK, can_check_emptiness)
{
	Stack<int>* s = new Stack<int>;
	EXPECT_EQ(1, s->IsEmpty());
}

TEST(STACK, throws_when_pop_from_empty_stack)
{
	Stack<int>* s = new Stack<int>;
	ASSERT_ANY_THROW(s->Pop());
}

TEST(STACK, can_check_fullness)
{
	Stack<int>* s = new Stack<int>;
	s->Push(5);
	EXPECT_EQ(0, s->IsFull());
}

TEST(STACK, can_push_element)
{
	Stack<int>* s = new Stack<int>;
	ASSERT_NO_THROW(s->Push(2));
}

TEST(STACK, can_copy_stack)
{
	Stack<int>* s = new Stack<int>;
	s->Push(6);
	ASSERT_NO_THROW(Stack<int>* s1 = new Stack<int>(*s));
}

TEST(STACK, copied_stack_is_equal_to_source_one)
{
	Stack<int>* s = new Stack<int>;
	s->Push(6);
	s->Print();
	Stack<int>* s1 = new Stack<int>(*s);
	s->Print();
	EXPECT_EQ(*s, *s1);
}

TEST(STACK, can_pop_element)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	int tmp;
	ASSERT_NO_THROW(tmp = s->Pop());
	EXPECT_EQ(6, tmp);
}

TEST(STACK, compare_different_stacks_returns_false)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(2);
	s->Push(3);
	EXPECT_NE(*s, *s1);
}

TEST(STACK, can_compare_different_stacks)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(2);
	s->Push(3);
	ASSERT_NO_THROW(s == s1);
}

TEST(STACK, can_compare_equal_stacks)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(4);
	s->Push(6);
	ASSERT_NO_THROW(s == s1);
}

