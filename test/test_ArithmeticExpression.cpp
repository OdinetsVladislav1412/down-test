#include "ArithmeticExpression.h"
#include "gtest.h"
#include <map>


TEST(ArithmeticExpression_Test, can_create_formula_from_string_without_prohibited_symbols)
{
  string str("a+b");
  ASSERT_NO_THROW(TArithmeticExpression f(str));
}


TEST(ArithmeticExpression_Test, formula_getinfix_returns_correct)
{
  string str("a+b");
  TArithmeticExpression f(str);
  EXPECT_EQ(f.GetInfix(), str);
}


TEST(ArithmeticExpression_Test, can_create_expression)
{
	string ex = "(a+b*c)*(c/d-e)";
	ASSERT_NO_THROW(TArithmeticExpression example(ex));
}


TEST(ArithmeticExpression_Test, can_get_infix_form_of_expression)
{
	string ex = "(a+b*c)*(c/d-e)";
	TArithmeticExpression example(ex);
	EXPECT_EQ(ex, example.GetInfix());
}


TEST(ArithmeticExpression_Test, can_get_operands_of_expression_without_const_and_with_several_symb)
{
	string str = "(ap+b*cln)*(cln/d-e)"; 
	TArithmeticExpression example(str);
	ASSERT_NO_THROW(example.GetOperands());
	vector<string> res;
	vector<string> ex = example.GetOperands();
	res.push_back("ap");
	res.push_back("b");
	res.push_back("cln");
	res.push_back("d");
	res.push_back("e");
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], ex[i]);
}

TEST(ArithmeticExpression_Test, can_calculate_expession_without_const)
{
	string str = "(a*b+c)*(c-d/e)";
	TArithmeticExpression example(str);
	map<string, double> op;
	op.emplace("a", 21.0);
	op.emplace("b", 42.0);
	op.emplace("c", 555.0);
	op.emplace("d", 190.0);
	op.emplace("e", 2.0);
	double res = example.Calculate(op);
	EXPECT_EQ(661020, int(res));
}


TEST(ArithmeticExpression_Test, can_calculate_expession_with_const)
{
	string str = "(a+b*c)/(2.5/d-c)";
	TArithmeticExpression example(str);
	map<string, double> op;
	op.emplace("a", 2.0);
	op.emplace("b", 4.0);
	op.emplace("c", 6.0);
	op.emplace("d", 0.5);
	double res = example.Calculate(op);
	EXPECT_EQ(-26, int(res));
}