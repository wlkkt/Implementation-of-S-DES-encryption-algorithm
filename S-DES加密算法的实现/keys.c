#include "test.h"

//��ȡ�����ַ���PC����
void GetPC(char* arr, int size)//(�ַ����飬�ַ������С)
{
	printf("��PC������д��%d�����ݣ�\n", size);
	scanf("%c %c %c %c %c %c %c %c %c %c", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
}

//��ȡ�����ַ���PC2����
void GetPC2(char* arr, int size)//(�ַ����飬�ַ������С)
{
	printf("��PC������д��%d�����ݣ�\n", size);
	scanf("%c %c %c %c %c %c %c %c", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);
}

//ת���ַ���������������
void TransformArray(char* arr1, int* arr2, int size)//(�ַ����飬�������飬���������С)
{
	for (int i = 0; i < size; i++)
	{

		if (arr1[i] >= '0' && arr1[i] <= '9')//����input�����ÿһ��Ԫ�أ������Ԫ��Ϊ����������atoi���������ַ�ת��Ϊ��Ӧ�����������硰123�� -> 123
		{
			arr2[i] = arr1[i] - '0';
		}
		else
		{
			int num = arr1[i];
			switch (num)
			{
			case 65:
				arr2[i] = 10;
				break;
			case 66:
				arr2[i] = 11;
				break;
			case 67:
				arr2[i] = 12;
				break;
			case 68:
				arr2[i] = 13;
				break;
			case 69:
				arr2[i] = 14;
				break;
			case 70:
				arr2[i] = 15;
				break;
			}
		}
	}
}

//��������
void ShiftArray(int* arr, int num, int size)  //(������,���ƴ���,�����С)
{
	for (int i = 0; i < num; i++)
	{
		int temp = arr[0];//temp���ÿ��ѭ��ǰ��������Ԫ��
		//��ʼ��λ���������һ��Ԫ�ص�ֵ��ֵ��ǰһ��Ԫ��
		for (int j = 0; j < size - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);//arr[j] = arr[]
		}
		arr[size - 1] = temp;  //����ŵ�ԭ��arr[0]��ֵ��ֵ������βԪ��
	}
}

//��ȡ����Կ������ӳ�����γ�������������
void SecondMapping(int* arr1, int* arr2, int* arr3, int size)//(ԭ��������ӳ���������������������������С)
{
	for (int i = 0; i < size; i++)
	{
		*(arr3 + i) = *(arr1 + *(arr2 + i) - 1); //arr3[i] = arr1[arr2[i]-1]; 
	}
}
