#include "pch.h"
#include "../list/list.cpp"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(List, can_push_back_element) {
	List<int> l1;
	List<int> l2;
	l1.push_back(1);
	l2.push_back(1);
	l1.push_back(2);
	l2.push_back(2);
	EXPECT_EQ(l1[1], l2[1]);
}

TEST(List, can_push_front_element) {
	List<int> l1;
	List<int> l2;
	l1.push_front(2);
	l2.push_front(2);
	EXPECT_EQ(l1[0], l2[0]);
}

TEST(List, can_pop_element) {
	List<int> l1;
	l1.push_back(1);
	l1.pop_front();
	EXPECT_EQ(l1.GetSize(), 0);
}

TEST(List, can_remove_element) {
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.removeAt(2);
	EXPECT_EQ(l1[2],4);
}

TEST(Polinoms, can_create_polynom) {
	Polinoms p1;
	Polinoms p2;
	Monom m;
	m.degree = 123;
	m.Value = 2;
	p1.polinom.push_back(m);
	p2.polinom.push_back(m);
	m.degree = 312;
	m.Value = 5;
	p1.polinom.push_back(m);
	p2.polinom.push_back(m);
	m.degree = 678;
	m.Value = 6;
	p1.polinom.push_back(m);
	p2.polinom.push_back(m);
	int a = (int)(p1 == p2);

	EXPECT_EQ(a, 1);
}


TEST(Polinoms, can_add_like_terms) {
	Polinoms p1;
	Polinoms p2;
	Monom m;
	m.degree = 123;
	m.Value = 5;
	p2.polinom.push_back(m);
	p1.setTestPolinom(1, 123, 4, 123);
	int a = (int)(p1 == p2);
	EXPECT_EQ(a, 1);
}
TEST(Polinoms, cant_create_polynom_with_too_low_degree) {
	Polinoms p1;
	ASSERT_ANY_THROW(p1.setTestPolinom(3, 20, 5, 456));
}
TEST(Polinoms, cant_create_polynom_with_negative_degree) {
	Polinoms p1;
	ASSERT_ANY_THROW(p1.setTestPolinom(3, 123, 5, -456));
}
TEST(Polinoms, cant_create_polynom_with_zero_value) {
	Polinoms p1;
	ASSERT_ANY_THROW(p1.setTestPolinom(0, 123, 5, 456));
}
TEST(Polinoms, can_add_polynoms) {
	Polinoms p1;
	Polinoms p2;
	Polinoms p3;
	Monom m;
	p1.setTestPolinom(2, 123, 4, 123);
	p2.setTestPolinom(3, 123, 5, 123);
	m.degree = 123;
	m.Value = 14;
	p3.polinom.push_back(m);
	int a = (int)(p1+p2 == p3);
	EXPECT_EQ(a, 1);
}
TEST(Polinoms, can_substract_polynoms) {
	Polinoms p1;
	Polinoms p2;
	Polinoms p3;
	Monom m;
	p1.setTestPolinom(2, 123, 4, 123);
	p2.setTestPolinom(3, 123, 5, 123);
	m.degree = 123;
	m.Value = -2;
	p3.polinom.push_back(m);
	int a = (int)(p1 - p2 == p3);
	EXPECT_EQ(a, 1);
}
TEST(Polinoms, can_multiply_polynoms) {
	Polinoms p1;
	Polinoms p2;
	Polinoms p3;
	Monom m;
	p1.setTestPolinom(2, 123, 4, 123);
	p2.setTestPolinom(3, 123, 5, 123);
	m.degree = 246;
	m.Value = 48;
	p3.polinom.push_back(m);
	int a = (int)(p1 * p2 == p3);
	EXPECT_EQ(a, 1);
}
TEST(Polinoms, cant_create_too_large_degree) {
	Polinoms p1;
	Polinoms p2;
	p1.setTestPolinom(2, 567, 4, 567);
	p2.setTestPolinom(3, 567, 5, 567);
	ASSERT_ANY_THROW(p1 * p2);
}
TEST(Polinoms, can_multiply_by_a_scalar) {
	Polinoms p1;
	double v = 3;
	p1.setTestPolinom(2, 123, 4, 123);

	Polinoms p2;
	Monom m;
	m.degree = 123;
	m.Value = 18;
	p2.polinom.push_back(m);

	int a = (int)(p1*v == p2);
	EXPECT_EQ(a, 1);
}