#include "test.h"

//异或运算
void OR(int* arr1, int* arr2, int* arr3, int size)//(数组名，数组名，新数组名，新数组大小)，默认三个数组大小均相同
{
	for (int i = 0; i < size; i++)
	{
		*(arr3 + i) = (*(arr1 + i) ^ *(arr2 + i));//arr3[i] = [arr1[i] ^ arr2[i]]
	}
}

//S盒置换
void BoxS(int* arr1, int* arr2, int(*arr3)[4], int* arr4, int(*arr5)[4], int size)//(异或后新数组名,置换后数组,置换表数组名,置换后数组,置换表数组名,置换前数组大小) == XOR S0 OR1 S1 sz，默认置换后数组大小相同，这里我们没有选择将异或后的结果拆开后再进行S盒置换而是直接在该数组上进行
{
	for (int i = 0; i < 1; i++) //只进行一次的for循环，为了分离两次数组置换的过程，由于变量的生命周期，这样也可以实现一段代码的重复使用
	{
		//下标0~3
		int first = 0, second = 0;//first表示横坐标，second表示纵坐标

		//获取横坐标的过程
		int num1 = arr1[0];//0
		int num2 = arr1[size / 2 - 1];//3

		if (num1 == 0 && num2 == 0)
			first = 0;
		else if (num1 == 0 && num2 == 1)
			first = 1;
		else if (num1 == 1 && num2 == 0)
			first = 2;
		else if (num1 == 1 && num2 == 1)
			first = 3;

		//获取纵坐标的过程
		int num3 = arr1[1];//1
		int num4 = arr1[size / 2 - 2];//2

		if (num3 == 0 && num4 == 0)
			second = 0;
		else if (num3 == 0 && num4 == 1)
			second = 1;
		else if (num3 == 1 && num4 == 0)
			second = 2;
		else if (num3 == 1 && num4 == 1)
			second = 3;

		int num5 = arr3[first][second];//利用横纵坐标在置换表中确定置换后的十进制整数
		GetLimitedArray(arr2, num5, 2);//将该数字转为规定的二进制位后放入置换后数组中
	}
	for (int i = 0; i < 1; i++)
	{
		//下标4~7
		int first = 0, second = 0;
		int num1 = arr1[size / 2];//4
		int num2 = arr1[size - 1];//7

		if (num1 == 0 && num2 == 0)
			first = 0;
		else if (num1 == 0 && num2 == 1)
			first = 1;
		else if (num1 == 1 && num2 == 0)
			first = 2;
		else if (num1 == 1 && num2 == 1)
			first = 3;


		int num3 = arr1[size / 2 + 1];//5
		int num4 = arr1[size - 2];//6

		if (num3 == 0 && num4 == 0)
			second = 0;
		else if (num3 == 0 && num4 == 1)
			second = 1;
		else if (num3 == 1 && num4 == 0)
			second = 2;
		else if (num3 == 1 && num4 == 1)
			second = 3;

		int num5 = arr5[first][second];
		GetLimitedArray(arr4, num5, 2);
	}
}

//备份函数(与其说是更新函数不如说是通过创建临时数组以应对迭代运算时，左右值的互换)
void Update(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr1 + i) = *(arr2 + i);//arr1[i] = arr2[i]
	}
}