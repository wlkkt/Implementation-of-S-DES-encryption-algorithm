#include "test.h"

//获取有限的二进制位组成的数组(由于整数在IDE中是以补码的形式存在的，一般为32位，而我们想要的明文数组和初始密钥对应的二进制位数均为10bit，所以需要人为截断它们的补码并将截断结果放入相应的数组中)
void GetLimitedArray(int* arr, int num, int size)//(数组名,整数值（明文数组或初始密钥未转为二进制前的十进制整数）,存放阶段后结果的数组大小)
{
	for (int i = size - 1; i >= 0; i--)  //不能交换int i = szie-1; i >= 0的顺序，否则二进制就是0010010000,倒着来了明显不符合要求
	{
		*(arr + i) = num % 2;//arr[i] = num % 2，利用%获取该数的二进制位
		num = num / 2; //利用/使得该数不断减小
		//%和/的使用是基于十进制转二进制的计算办法
	}
}

//获取各类数组
void GetArray(int* arr, int size)//(需要人为数组的数组名,该数组大小)
{
	printf("请输入%d比特大小的内容：\n", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);//逐个数组，注意每次输入需要换行，且只能输入整数
	}
}

//打印各类数组
void printfArray(int* arr, int size)//(要打印的数组名，数组大小)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(arr + i));//arr[i];
	}
	system("pause");//暂停程序只有按任意键后才会继续执行：为检查结果是否正确提供时间
	printf("\n");
	system("cls");//清屏：为下一次的输入或者打印数组留出足够的空间（腾位置）
}

//映射改变原数组中二进制数的排列顺序（处理映射后不形成新数组只在原本数组上进行更改的情况）
void Mapping(int* arr1, int* arr2, int size)//(原数组名,映射数组名,数组大小)
{
	int arr[100];//设定一个足够大的临时数组，如果利用临时数组就会导致PC1 + K的结果不为0100000010，而是0110000000
	int* temp = arr;//temp指向该临时数组（可要可不要）
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(arr1 + i);//将原数组内容拷贝给临时数组
	}
	for (int i = 0; i < size; i++)
	{

		*(arr1 + i) = *(temp + *(arr2 + i) - 1);//arr1[i] = temp[arr2[i] - 1] 或 arr1[i] = arr[arr2[i] - 1]
	}
}

//分离数组
void Split(int* arr1, int* arr2, int* arr3, int size)//(原数组名，子数组名，子数组名，子数组大小)，默认子数组大小相同
{
	int temp = size;//用temp获取size的值,如果不用temp可能会导致i的范围由于size++而发生变化，影响arr2
	for (int i = 0; i < size; i++)
	{
		*(arr2 + i) = *(arr1 + i);//arr2[i] = arr1[i]
		*(arr3 + i) = *(arr1 + temp);//arr3[i] = arr1[temp]
		temp++;
	}
}

//合并数组
void Combine(int* arr1, int* arr2, int* arr3, int size)//(合并子数组名,合并子数组名,合并数组名,合并后数组大小)
{
	for (int i = 0; i < size / 2; i++)//这里可以直接size/2的原因是数组都是偶数
	{
		*(arr3 + i) = *(arr1 + i);  //arr3[i] = arr1[i] 第一个子数组拷贝至合并数组(如何对应下标自己思考不予解释)
	}

	for (int j = 0; j < size / 2; j++)
	{
		*(arr3 + size / 2 + j) = *(arr2 + j);//arr3[size / 2 + j] = arr2[j] 第二个子数组拷贝至合并数组
	}
}