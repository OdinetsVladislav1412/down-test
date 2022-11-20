#include <iostream>
#include "Stack.h"
#include "ArithmeticExpression.h"
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "rus");
	
	cout << "Проверка класса Stack" << endl;
	int n, c, p;
	cout << "Колличество мест в Стеке: ";
	cin >> n;
	TStack<int> prov(n);
	bool w;
	cout << "Хотите заполнить Стек? (0 - нет, 1 - да): ";
	cin >> w;
	if (w == true) 
	{
		cout << "Сколько значений хотите заполнить?: ";
		cin >> c;
		for (int i = 1; i < c+1; i++)
		{
			cout << "Введите " << i << " значение: ";
			cin >> p;
			prov.Push(p);
		}
	}
	cout << "Стек создан"<< endl;

	cout << "Хотите извлечь значения из Стека? (0 - нет, 1 - да): ";
	cin >> w;
	if (w == true)
	{
		cout << "Сколько значений хотите извлечь?: ";
		cin >> c;
		for (int i = 1; i < c + 1; i++)
		{
			cout << prov.Pop() << " ";
		}
	}
	cout << "\n\n\n";



	cout << "Проверка класса ArithmeticExpression" << endl;
	string exprStr;
	cout << "Введите выражение: ";
	cin >> exprStr;
	TArithmeticExpression expr(exprStr);
	cout << "\nИнфиксная форма: " << expr.GetInfix() << endl;
	cout << "Постфиксная форма: " << expr.GetPostfix() << "\n" << endl;
	vector<string> operands = expr.GetOperands();
	map<string, double> values;
	double val;

	for (const auto& op : operands)
	{
		cout << "Введите значение перменной " << op << ": ";
		cin >> val;
		values[op] = val;
	}

	cout << "Итог: " << expr.Calculate(values) << endl;

	return 0;
}