#include "test.h"

int main()
{
	int k;
	char TempPC[10];
	char TempPC2[8];
	int K[10];
	int K1[8], K2[8];
	int PC1[10], PC2[8];
	int C0[5], D0[5];
	int C1D1[10], C2D2[10];

	//��ȡ��ʼ��Կk
	printf("�������ʼ��Կk��ֵ:");
	scanf("%d", &k);
	getchar();
	system("cls");

	//��ȡ��ʼ��Կk��ʮ��������λ��������K
	int sz = sizeof(K) / sizeof(K[0]);//��ȡ����K�Ĵ�С
	GetLimitedArray(K, k, sz);//(����K,��ʼ��Կ��ʮ��������,Ҫ��õĶ����Ƹ���)
	printf("����K��\n");
	printfArray(K, sz);//��ӡ����K


	//��ȡPC-1
	sz = sizeof(TempPC) / sizeof(TempPC[0]);//���´�ʱsz��ֵ
	GetPC(TempPC, sz);
	getchar();
	sz = sizeof(PC1) / sizeof(PC1[0]);//���´�ʱsz��ֵ
	TransformArray(TempPC, PC1, sz);
	printf("�����PC-1��\n");
	printfArray(PC1, sz);


	//����PC - 1�ı�����K��Ԫ�ص�����˳��
	sz = sizeof(K) / sizeof(K[0]);//���´�ʱsz��ֵ
	Mapping(K, PC1, sz);//(����K,����PC1,����K��С)��K��PC1��С��ͬ
	printf("���µĳ�ʼ��Կ����K��\n");
	printfArray(K, sz);


	//������K���Ϊ������С��ͬ������C0��D0
	sz = sizeof(C0) / sizeof(C0[0]);//���´�ʱsz��ֵ��
	Split(K, C0, D0, sz);//(����K,������C0,������D0,������C0��С)��������C0��D0��С��ͬ
	printf("����C0��\n");
	printfArray(C0, sz);
	printf("����D0��\n");
	printfArray(D0, sz);


	//��C0��D0���������һλ
	sz = sizeof(C0) / sizeof(C0[0]);//���´�ʱsz��ֵ
	int num = 1;//���ƴ���
	ShiftArray(C0, num, sz);//(������C0,���ƴ���,����C0��С)
	ShiftArray(D0, num, sz);//(������D0,���ƴ���,����C0��С),��������C0��D0��С��ͬ
	printf("����һλ�������C0��\n");
	printfArray(C0, sz);
	printf("����һλ�������D0��\n");
	printfArray(D0, sz);


	//������һ�ε�������C0��D0�ϲ�������C1D1
	sz = sizeof(C1D1) / sizeof(C1D1[0]);//���´�ʱsz��ֵ
	Combine(C0, D0, C1D1, sz);//(������C0,������D0,����C1D1,����C1D1��С)
	printf("�ϲ��������C1D1��\n");
	printfArray(C1D1, sz);


	//��ȡPC-2
	sz = sizeof(TempPC2) / sizeof(TempPC2[0]);//���´�ʱsz��ֵ
	GetPC2(TempPC2, sz);
	getchar();
	sz = sizeof(PC2) / sizeof(PC2[0]);//���´�ʱsz��ֵ
	TransformArray(TempPC2, PC2, sz);
	printf("�����PC-2��\n");
	printfArray(PC2, sz);


	//��ȡ����ԿK1
	sz = sizeof(K1) / sizeof(K1[0]);//���´�ʱsz��ֵ
	SecondMapping(C1D1, PC2, K1, sz);//(�ϲ�����C1D1,PC2����,����Կ����K1,����Կ����K1��С)
	printf("����Կ����K1��\n");
	printfArray(K1, sz);


	//��C0��D0������ԭ�л����ϼ���������λ
	sz = sizeof(C0) / sizeof(C0[0]);//���´�ʱsz��ֵ
	num = 2;//���ƴ���
	ShiftArray(C0, num, sz);//(������C0,���ƴ���,����C0��С)
	ShiftArray(D0, num, sz);//(������C0,���ƴ���,����D0��С)
	printf("������λ�������C0��\n");//��ʵ���ܵ���˵��������Ѿ�������������
	printfArray(C0, sz);
	printf("������λ�������D0��\n");
	printfArray(D0, sz);


	//����������(��)��������C0��D0�ϲ�������C2D2
	sz = sizeof(C2D2) / sizeof(C2D2[0]);//���´�ʱsz��ֵ
	Combine(C0, D0, C2D2, sz);//(������C0,������D0,����C2D2,����C2D2��С)
	printf("�ϲ��������C2D2��\n");
	printfArray(C2D2, sz);


	//��ȡ����ԿK2
	sz = sizeof(K2) / sizeof(K2[0]);//���´�ʱsz��ֵ
	SecondMapping(C2D2, PC2, K2, sz);//(�ϲ�����C2D2,PC2����,����Կ����K2,����Կ����K2��С)
	printf("����Կ����K2��\n");
	printfArray(K2, sz);


	//���ļ���

	int s;
	int SGroup[8];
	int IP[8], ReverseIP[8];
	int L0[4], R0[4];
	int EP[8];
	int R0Pro[8];
	int XOR[8];
	int S0[4][4] = { 1,0,2,3,  3,1,0,2,  2,0,3,1,  1,3,2,0 }, S1[4][4] = { 0,3,1,2,  3,2,0,1,  1,0,3,2,  2,1,3,0 };
	int OR0[2], OR1[2];
	int ORALL[4];
	int P[4];
	int FirstTemp[4], SecondTemp[4];
	int Results[8];

	//��ȡ��������s
	printf("���������������ֵ:");
	scanf("%d", &s);
	getchar();
	system("cls");

	//��ȡ��������SGroup
	sz = sizeof(SGroup) / sizeof(SGroup[0]);//���´�ʱsz��ֵ
	GetLimitedArray(SGroup, s, sz);//(��������SGroup,���������ʮ��������,Ҫ��õĶ����Ƹ���)
	printf("��������SGroup��\n");
	printfArray(SGroup, sz);


	//��ȡ��ʼ��λIP
	sz = sizeof(IP) / sizeof(IP[0]);//���´�ʱsz��ֵ
	GetArray(IP, sz);//(��ʼ��λIP,��ʼ��λIP�����С)
	printf("����ĳ�ʼ��λIP���飺\n");
	printfArray(IP, sz);


	//����IP�ı�����SGroup������
	sz = sizeof(SGroup) / sizeof(SGroup[0]);//���´�ʱsz��ֵ
	Mapping(SGroup, IP, sz);
	printf("���µ���������SGroup��\n");
	printfArray(SGroup, sz);

	//��һ�ֵ������㣺
	//�������µ�SGroup����Ӷ���õ�һ�ֵ����������ֵ������L0����ֵ������R0
	sz = sizeof(L0) / sizeof(L0[0]);//���´�ʱsz��ֵ
	Split(SGroup, L0, R0, sz);//(������������SGroup,��ֵ������L0,��ֵ������R0,�������С)
	printf("��һ�ֵ����������ֵ������L0��\n");
	printfArray(L0, sz);
	printf("��һ�ֵ����������ֵ������R0��\n");
	printfArray(R0, sz);


	//�ڵ�1�ε��������У���ֵ��Ϊ�ڶ����ֵ���ֵ��FirstTemp�ǵڶ��ֵ���ֵ��
	sz = sizeof(L0) / sizeof(L0[0]);//���´�ʱsz��ֵ
	Update(FirstTemp, R0, sz);//����ֵ�����鿽��������FirstTemp
	printf("�ڶ��ֵ����������ֵ������FirstTemp��\n");
	printfArray(FirstTemp, sz);

	//EP��չ
	sz = sizeof(EP) / sizeof(EP[0]);//���´�ʱsz��ֵ
	GetArray(EP, sz);
	printf("���������EP��\n");
	printfArray(EP, sz);

	//��һ�ֵ��������F�������ݣ�
	//����EP��չ��һ�ֵ����������ֵ������R0
	sz = sizeof(R0Pro) / sizeof(R0Pro[0]);//���´�ʱsz��ֵ
	SecondMapping(R0, EP, R0Pro, sz);//(��ֵ������,EP����,��չ������R0PR0,��չ�������С)
	printf("��һ�ֵ��������У���ֵ������R0��F�����н���EP��չ���������R0Pro��\n");
	printfArray(R0Pro, sz);


	//��չ�����ֵ������R0Pro������Կ����K1������������γ��µ�����XOR
	sz = sizeof(XOR) / sizeof(XOR[0]);//���´�ʱsz��ֵ
	OR(R0Pro, K1, XOR, sz);//(��չ�����ֵ������R0Pro,����ԿK1,�����������XOR,����������XOR��С)
	printf("��һ�ֵ��������У���ֵ������R0��F�����н���EP��չ�������R0Pro������Կ����K1��������õ���������XOR��\n");
	printfArray(XOR, sz);


	//s������(��СXOR���������������)
	sz = sizeof(XOR) / sizeof(XOR[0]);//���´�ʱsz��ֵ
	BoxS(XOR, OR0, S0, OR1, S1, sz);//(�����������XOR,XOR����ֵ��������С���������OR0(ԭʼ�汾),S0������,XOR����ֵ��������С���������OR1(ԭʼ�汾),S1������)
	sz = sizeof(OR0) / sizeof(OR0[0]);//���´�ʱsz��ֵ
	printf("XOR����ֵ��������С���������OR0����ʼ�汾����\n");
	printfArray(OR0, sz);
	printf("XOR����ֵ��������С���������OR0����ʼ�汾����\n");
	printfArray(OR1, sz);


	//��ȡP��
	sz = sizeof(P) / sizeof(P[0]);//���´�ʱsz��ֵ
	GetArray(P, sz);//(P������,�����С)
	printf("���������P��\n");
	printfArray(P, sz);


	//�ϲ�����OR0��OR1
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//���´�ʱsz��ֵ
	Combine(OR0, OR1, ORALL, sz);//(XOR����ֵ��������С���������OR0,XOR����ֵ��������С���������OR1,�ϲ�������ORALL,�ϲ�������ORALL��С)
	printf("��һ�ֵ��������У�F����S���û��������������ϲ��ɵ�����ORALL����һ�ֳ�ʼ�汾����\n");
	printfArray(ORALL, sz);


	//P�л�λ
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//���´�ʱsz��ֵ
	Mapping(ORALL, P, sz);//(�ϲ�������ORALL,P������,�ϲ�������ORALL��С)
	printf("��һ�ֵ��������У�F������S���û��������������ϲ��ɵ�������ORALL����P���û���Ľ������������ORALL����\n");
	printfArray(ORALL, sz);


	//P�л�λ�������ORALL���һ�ֿ�ʼʱ����ֵ����������㣬�õ��ڶ��ֵ���ֵ
	sz = sizeof(R0) / sizeof(R0[0]);//���´�ʱsz��ֵ
	OR(ORALL, L0, R0, sz);//(��һ�ֵ�������P���û��������ORALL,��һ�ֵ������㿪ʼʱ����ֵ����L0,��һ�ֵ������㿪ʼʱ����ֵ����R0���˺�����Ŀ�ľ��Ǹ���R0��,��ֵ����R0�Ĵ�С)
	printf("�ڶ��ֵ����������ֵ������ԭ�ȵ�R0��ֵ����\n");
	printfArray(R0, sz);

	//�ڶ��ֵ������㿪ʼʱ����ֵ������ΪFirstTemp,��ֵ������ΪR0

	//�ڵ�2�ε��������У���ֵ��Ϊ����������ֵ��SecondTempΪ���ս������ֵ�����飩
	sz = sizeof(L0) / sizeof(L0[0]);//���´�ʱsz��ֵ
	Update(SecondTemp, R0, sz);//����һ�ֵ����������ֵ�����鿽��������SecondTemp
	printf("�ڶ��ֵ����������Ϊ���ս����ֵ�������SecondTemp��\n");
	printfArray(SecondTemp, sz);


	//�ڶ��ֵ��������f�������ݣ��Ե�һ�ֵ����������ֵ����
	//EP��չ������R0
	sz = sizeof(R0Pro) / sizeof(R0Pro[0]);//���´�ʱsz��ֵ
	SecondMapping(R0, EP, R0Pro, sz);//(��ֵ������R0,EP����,��չ������R0Pro,��չ�������С)
	printf("�ڶ��ֵ��������У���ֵ������R0��F�����н���EP��չ���������R0Pro��\n");
	printfArray(R0Pro, sz);


	//��չ���R0������ԿK2����������㣨����XOR��������ݣ�
	sz = sizeof(XOR) / sizeof(XOR[0]);//���´�ʱsz��ֵ
	OR(R0Pro, K2, XOR, sz);//(��ֵ��չ������R0Pro,����Կ����K2,���������������XOR,���������������XOR��С)
	printf("�ڶ��ֵ��������У���ֵ������R0��f�����н���EP��չ�������R0Pro������Կ����K2��������õ���������XOR(����XOR����)��\n");
	printfArray(XOR, sz);


	//S�����㣨���µ�һ�ֵ��������е�ĳЩ���飩
	sz = sizeof(XOR) / sizeof(XOR[0]);//���´�ʱsz��ֵ
	BoxS(XOR, OR0, S0, OR1, S1, sz);//(�����������XOR,XOR����ֵ��������С���������OR0(���°汾),S0������,XOR����ֵ��������С���������OR1(���°汾),S1������)
	sz = sizeof(OR0) / sizeof(OR0[0]);//���´�ʱsz��ֵ
	printf("XOR����ֵ��������С���������OR0�����°汾����\n");
	printfArray(OR0, sz);
	printf("XOR����ֵ��������С���������OR1�����°汾����\n");
	printfArray(OR1, sz);


	//�ϲ�����OR0��OR1
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//���´�ʱsz��ֵ
	Combine(OR0, OR1, ORALL, sz);//
	printf("�ڶ��ֵ��������У�f����s���û��������������ϲ��ɵ�������ORALL���ڶ��ָ��°汾����\n");
	printfArray(ORALL, sz);


	//p�л�λ
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//���´�ʱsz��ֵ
	Mapping(ORALL, P, sz);//(�ϲ�������ORALL,P������,�ϲ�������ORALL��С)
	printf("�ڶ��ֵ��������У�F������S���û��������������ϲ��ɵ�������ORALL����P���û���Ľ������������ORALL����\n");
	printfArray(ORALL, sz);


	//��ֵͨ��f( )����������Կ��Ϻ�����ڶ��ֳ�ʼʱ����ֵ������first����������㣬�õ���������������ֵ����Ȼ������R0���нӣ�������ʱ��R0���������������������ֵ��
	sz = sizeof(R0) / sizeof(R0[0]);//���´�ʱsz��ֵ
	OR(ORALL, FirstTemp, R0, sz);//(P�����û������ֵ������,�ڶ��ֵ��������ʼʱ����ֵ������FirstTemp,�����������ֵ������R0(��Ȼ��R0�������ʾ�Ѿ�����ֵ��),�����������ֵ������R0��С)
	printf("�ڶ��ֵ���������,����������ֵ��\n");
	printfArray(R0, sz);


	//�ϲ�����
	sz = sizeof(Results) / sizeof(Results[0]);//���´�ʱsz��ֵ
	Combine(R0, SecondTemp, Results, sz);//(�ڶ��ֵ������������ֵ������R0���ڶ��ֵ������������ֵ������SecondTemp,�ϲ�����results,�ϲ�����results�Ĵ�С)
	printf("�ڶ��ֵ��������,�����������ϲ��������Results��\n");
	printfArray(Results, sz);

	//��ȡReverseIP
	sz = sizeof(ReverseIP) / sizeof(ReverseIP[0]);//���´�ʱsz��ֵ
	GetArray(ReverseIP, sz);//(���ʼ��λReverseIP,���ʼ��λReverseIP�����С)
	printf("��������ʼ��λReverseIP���飺\n");
	printfArray(ReverseIP, sz);


	//����ReverseIP�ı�����Results������
	sz = sizeof(Results) / sizeof(Results[0]);//���´�ʱsz��ֵ
	Mapping(Results, ReverseIP, sz);//(�ϲ�������Results,���ʼ��λReverseIP,�ϲ�������Results�Ĵ�С)
	printf("�������ļ��ܺ�Ľ����\n");
	printfArray(Results, sz);

	return 0;
}