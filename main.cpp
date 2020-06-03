#include <iostream>

using namespace std;

// Вычисление суммы чисел
int CalcSumm(int number)
{
	if (number < 10) 
		return number;
	return number % 10 + CalcSumm(number / 10);
}
// Вычисление предельного значения
int CalcBounb(int a, int b, int bound, int increment)
{
	int statr_a = a;
	int statr_b = b;
	bool run = true;
	int valABound;
	int valBBound = CalcSumm(statr_b);
	while (run)
	{
		valABound = CalcSumm(statr_a);
		if (valABound + valBBound < bound)
			statr_a += increment;
		else
			run = false;
	}
	return statr_a;
}
// Вычисление точек в секторе
int CalcPointInSector(int a, int b)
{
	if (a != b)
		return (((a + 1) * (b + 1)) / 2) + 1;
	else
		return ((a * a  + 3 * a) / 2) + 1;
}

int main()
{
	int x;
	int y;
	int bound;
	while (true)
	{
		cout << "Insert X: ";
		cin >> x;
		cout << "Insert Y: ";
		cin >> y;
		cout << "Insert Bound: ";
		cin >> bound;
		cout << "Count of Point: " << CalcPointInSector((CalcBounb(x, y, bound, 1) - CalcBounb(x, y, bound, -1)), (CalcBounb(y, x, bound, 1) - CalcBounb(y, x, bound, -1))) << "\n"<< endl;
	}
	return 0;
}


