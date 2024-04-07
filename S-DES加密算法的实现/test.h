#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//公共函数：

//获取某个整数的有限的二进制位
void GetLimitedArray(int* arr, int k, int size);

//映射改变原数组中二进制数的排列顺序
void Mapping(int* arr1, int* arr2, int size);

//分离数组函数
void Split(int* arr1, int* arr2, int* arr3, int size);

//获取各类数组函数
void GetArray(int* arr, int size);

//打印各类数组函数
void printfArray(int* arr, int size);



//获取子密钥函数：

//包含字符的PC数组
void GetPC(char* arr, int size);

//转换字符数组至整型数组
void TransformArray(char* arr1, int* arr2, int size);

//左移函数
void ShiftArray(int* arr, int num, int size);

//合并数组函数
void Combine(int* arr1, int* arr2, int* arr3, int size);

//获取子密钥
void SecondMapping(int* arr1, int* arr2, int* arr3, int size);


//加密函数：

//异或运算
void OR(int* arr1, int* arr2, int* arr3, int size);

//S盒置换
void BoxS(int* arr1, int* arr2, int(*arr3)[4], int* arr4, int(*arr5)[4], int size);//OR0 S0 OR1 S1 sz

//更新L0
void Update(int* arr1, int* arr2, int size);