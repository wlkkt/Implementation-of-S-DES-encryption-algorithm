#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//����������

//��ȡĳ�����������޵Ķ�����λ
void GetLimitedArray(int* arr, int k, int size);

//ӳ��ı�ԭ�����ж�������������˳��
void Mapping(int* arr1, int* arr2, int size);

//�������麯��
void Split(int* arr1, int* arr2, int* arr3, int size);

//��ȡ�������麯��
void GetArray(int* arr, int size);

//��ӡ�������麯��
void printfArray(int* arr, int size);



//��ȡ����Կ������

//�����ַ���PC����
void GetPC(char* arr, int size);

//ת���ַ���������������
void TransformArray(char* arr1, int* arr2, int size);

//���ƺ���
void ShiftArray(int* arr, int num, int size);

//�ϲ����麯��
void Combine(int* arr1, int* arr2, int* arr3, int size);

//��ȡ����Կ
void SecondMapping(int* arr1, int* arr2, int* arr3, int size);


//���ܺ�����

//�������
void OR(int* arr1, int* arr2, int* arr3, int size);

//S���û�
void BoxS(int* arr1, int* arr2, int(*arr3)[4], int* arr4, int(*arr5)[4], int size);//OR0 S0 OR1 S1 sz

//����L0
void Update(int* arr1, int* arr2, int size);