#include "test.h"

//�������
void OR(int* arr1, int* arr2, int* arr3, int size)//(���������������������������������С)��Ĭ�����������С����ͬ
{
	for (int i = 0; i < size; i++)
	{
		*(arr3 + i) = (*(arr1 + i) ^ *(arr2 + i));//arr3[i] = [arr1[i] ^ arr2[i]]
	}
}

//S���û�
void BoxS(int* arr1, int* arr2, int(*arr3)[4], int* arr4, int(*arr5)[4], int size)//(������������,�û�������,�û���������,�û�������,�û���������,�û�ǰ�����С) == XOR S0 OR1 S1 sz��Ĭ���û��������С��ͬ����������û��ѡ������Ľ���𿪺��ٽ���S���û�����ֱ���ڸ������Ͻ���
{
	for (int i = 0; i < 1; i++) //ֻ����һ�ε�forѭ����Ϊ�˷������������û��Ĺ��̣����ڱ������������ڣ�����Ҳ����ʵ��һ�δ�����ظ�ʹ��
	{
		//�±�0~3
		int first = 0, second = 0;//first��ʾ�����꣬second��ʾ������

		//��ȡ������Ĺ���
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

		//��ȡ������Ĺ���
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

		int num5 = arr3[first][second];//���ú����������û�����ȷ���û����ʮ��������
		GetLimitedArray(arr2, num5, 2);//��������תΪ�涨�Ķ�����λ������û���������
	}
	for (int i = 0; i < 1; i++)
	{
		//�±�4~7
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

//���ݺ���(����˵�Ǹ��º�������˵��ͨ��������ʱ������Ӧ�Ե�������ʱ������ֵ�Ļ���)
void Update(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr1 + i) = *(arr2 + i);//arr1[i] = arr2[i]
	}
}