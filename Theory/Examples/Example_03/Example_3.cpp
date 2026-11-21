#include <iostream>
#include <string>

int primer1()
{
	int a{ 5 };
	int b{ 8 };
	int c{};
	if (a > b)
	{
		c - a - b;
	}
	else
	{
		c = a + b;
	}
	std::cout << "C = " << c << std::endl;
}

int primer2()
{
	int a{ 5 };
	int b{ 8 };
	int c{};
	int c = a > b ? a - b : a + b;
	std::cout << "c = " << c << std::endl;
}

//int main()
//{
//    int step{ 1 };
//    for (инициализатор; условие; итераци€)
//    {
//         “ело цикла
//    }
//}

int first_primer()
{
	for (int i[1]; i < 10; i++)
	{
		std::cout << i << " * " << i << i * i << std::endl;
	}
}

int second_primer()
{
	int i{ 1 };
	for (; i < 10;)
	{
		std::cout << i << " * " << i << i * i << std::endl;
		i++;
	}
}

//int main()
//{
//    for (тип переменна€ : последовательность)
//    {
//        инструкции;
//    }
//}

int big_primer()
{
	for (int n : {2, 3, 4, 5})
	{
		std::cout << n << std::endl;
		if (n == 4)
		{
			break;
		}
	}
}

for (char c : "Hello")
{
	if (c == 'e')
	{
		continue;
	}
	std::cout << c << std::endl;
}

// int main()
//{
//    do
//    {
//        инструкции
//    } while (условие);
//}

int example()
{
	int i{ 6 };
	do
	{
		std::cout << i << std::endl;
		i--;
	} while (i > 0);
}

int example2() {
	for (int i{ 1 }; i < 10; i++)
	{
		for (int j{ 1 }; j < 10; j++)
		{
			std::cout << i * j << "/t";
		}
		std::cout << std::endl;
	}
}