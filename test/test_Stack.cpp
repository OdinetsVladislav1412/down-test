/*#include "Stack.h"
#include <gtest.h>

using testing::Types;


template <class T>
class Stack_Test : public testing::Test {};
typedef Types<int> Implementations;

TYPED_TEST_CASE(Stack_Test, Implementations);

TYPED_TEST(Stack_Test, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<TypeParam> st(3));
}

TYPED_TEST(Stack_Test, can_add_item_into_stack)
{
  TStack<TypeParam> st(3);
  ASSERT_NO_THROW(st.Push(0));
}

TYPED_TEST(Stack_Test, can_pop_item_from_stack)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  ASSERT_NO_THROW(st.Pop());
}

TYPED_TEST(Stack_Test, pop_item_from_stack_returns_correct)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  EXPECT_EQ(st.Pop(), 0);
}

TYPED_TEST(Stack_Test, can_check_stack_emptiness)
{
  TStack<TypeParam> st(3);
  EXPECT_EQ(st.isEmpty(), true);
}

TYPED_TEST(Stack_Test, can_check_stack_fullness)
{
  TStack<TypeParam> st(1);
  st.Push(0);
  EXPECT_EQ(st.isFull(), true);
}

TYPED_TEST(Stack_Test, cannot_add_item_into_full_stack)
{
  TStack<TypeParam> st(1);
  st.Push(0);
  ASSERT_ANY_THROW(st.Push(0));
}

TYPED_TEST(Stack_Test, cannot_pop_item_from_empty_stack)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  st.Pop();
  ASSERT_ANY_THROW(st.Pop());
}*/

#include "gtest.h"
#include "Stack.h"

TEST(Stack_Test, can_create_stack_with_positive_length_int)
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(Stack_Test, can_create_stack_with_positive_length_double)
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(Stack_Test, can_get_size_of_stack)
{
	TStack<int> a(5);
	EXPECT_EQ(0, a.Number());
	a.Push(3);
	a.Push(3);
	EXPECT_EQ(2, a.Number());
}

TEST(Stack_Test, can_check_is_empty_stack)
{
	TStack<int> a(5);
	EXPECT_EQ(true, a.isEmpty());
}

TEST(Stack_Test, can_check_stack_emptiness)
{
	TStack<int> st(3);
	EXPECT_EQ(st.isEmpty(), true);
}

TEST(Stack_Test, can_check_stack_fullness)
{
	TStack<int> st(1);
	st.Push(0);
	EXPECT_EQ(st.isFull(), true);
}

TEST(Stack_Test, can_pop_item_from_stack)
{
	TStack<int> st(3);
	st.Push(0);
	ASSERT_NO_THROW(st.Pop());
}

TEST(Stack_Test, pop_item_from_stack_returns_correct)
{
	TStack<int> st(3);
	st.Push(0);
	EXPECT_EQ(st.Pop(), 0);
}