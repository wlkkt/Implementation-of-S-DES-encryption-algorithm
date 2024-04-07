#include "test.h"

//获取包含字符的PC数组
void GetPC(char* arr, int size)//(字符数组，字符数组大小)
{
	printf("向PC数组中写入%d个数据：\n", size);
	scanf("%c %c %c %c %c %c %c %c %c %c", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
}

//获取包含字符的PC2数组
void GetPC2(char* arr, int size)//(字符数组，字符数组大小)
{
	printf("向PC数组中写入%d个数据：\n", size);
	scanf("%c %c %c %c %c %c %c %c", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);
}

//转换字符数组至整型数组
void TransformArray(char* arr1, int* arr2, int size)//(字符数组，整型数组，整型数组大小)
{
	for (int i = 0; i < size; i++)
	{

		if (arr1[i] >= '0' && arr1[i] <= '9')//遍历input数组的每一个元素，如果该元素为整数就利用atoi函数将该字符转换为对应的整数，比如“123” -> 123
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

//左移数组
void ShiftArray(int* arr, int num, int size)  //(数组名,左移次数,数组大小)
{
	for (int i = 0; i < num; i++)
	{
		int temp = arr[0];//temp存放每次循环前的数组首元素
		//开始移位，将数组后一个元素的值赋值给前一个元素
		for (int j = 0; j < size - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);//arr[j] = arr[]
		}
		arr[size - 1] = temp;  //将存放的原来arr[0]的值赋值给数组尾元素
	}
}

//获取子密钥（处理映射后会形成新数组的情况）
void SecondMapping(int* arr1, int* arr2, int* arr3, int size)//(原数组名，映射数组名，新数组名，新数组大小)
{
	for (int i = 0; i < size; i++)
	{
		*(arr3 + i) = *(arr1 + *(arr2 + i) - 1); //arr3[i] = arr1[arr2[i]-1]; 
	}
}
