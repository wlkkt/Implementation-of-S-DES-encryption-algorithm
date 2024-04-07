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

	//获取初始密钥k
	printf("请输入初始密钥k的值:");
	scanf("%d", &k);
	getchar();
	system("cls");

	//获取初始密钥k的十个二进制位放入数组K
	int sz = sizeof(K) / sizeof(K[0]);//获取数组K的大小
	GetLimitedArray(K, k, sz);//(数组K,初始密钥的十进制整数,要获得的二进制个数)
	printf("数组K：\n");
	printfArray(K, sz);//打印数组K


	//获取PC-1
	sz = sizeof(TempPC) / sizeof(TempPC[0]);//更新此时sz的值
	GetPC(TempPC, sz);
	getchar();
	sz = sizeof(PC1) / sizeof(PC1[0]);//更新此时sz的值
	TransformArray(TempPC, PC1, sz);
	printf("输入的PC-1：\n");
	printfArray(PC1, sz);


	//利用PC - 1改变数组K中元素的排列顺序
	sz = sizeof(K) / sizeof(K[0]);//更新此时sz的值
	Mapping(K, PC1, sz);//(数组K,数组PC1,数组K大小)，K和PC1大小相同
	printf("最新的初始密钥数组K：\n");
	printfArray(K, sz);


	//将数组K拆分为两个大小相同的数组C0和D0
	sz = sizeof(C0) / sizeof(C0[0]);//更新此时sz的值，
	Split(K, C0, D0, sz);//(数组K,子数组C0,子数组D0,子数组C0大小)，子数组C0和D0大小相同
	printf("数组C0：\n");
	printfArray(C0, sz);
	printf("数组D0：\n");
	printfArray(D0, sz);


	//将C0和D0数组均左移一位
	sz = sizeof(C0) / sizeof(C0[0]);//更新此时sz的值
	int num = 1;//左移次数
	ShiftArray(C0, num, sz);//(子数组C0,左移次数,数组C0大小)
	ShiftArray(D0, num, sz);//(子数组D0,左移次数,数组C0大小),，子数组C0和D0大小相同
	printf("左移一位后的数组C0：\n");
	printfArray(C0, sz);
	printf("左移一位后的数组D0：\n");
	printfArray(D0, sz);


	//将左移一次的子数组C0和D0合并成数组C1D1
	sz = sizeof(C1D1) / sizeof(C1D1[0]);//更新此时sz的值
	Combine(C0, D0, C1D1, sz);//(子数组C0,子数组D0,数组C1D1,数组C1D1大小)
	printf("合并后的数组C1D1：\n");
	printfArray(C1D1, sz);


	//获取PC-2
	sz = sizeof(TempPC2) / sizeof(TempPC2[0]);//更新此时sz的值
	GetPC2(TempPC2, sz);
	getchar();
	sz = sizeof(PC2) / sizeof(PC2[0]);//更新此时sz的值
	TransformArray(TempPC2, PC2, sz);
	printf("输入的PC-2：\n");
	printfArray(PC2, sz);


	//获取子密钥K1
	sz = sizeof(K1) / sizeof(K1[0]);//更新此时sz的值
	SecondMapping(C1D1, PC2, K1, sz);//(合并数组C1D1,PC2数组,子密钥数组K1,子密钥数组K1大小)
	printf("子密钥数组K1：\n");
	printfArray(K1, sz);


	//将C0和D0数组在原有基础上继续左移两位
	sz = sizeof(C0) / sizeof(C0[0]);//更新此时sz的值
	num = 2;//左移次数
	ShiftArray(C0, num, sz);//(子数组C0,左移次数,数组C0大小)
	ShiftArray(D0, num, sz);//(子数组C0,左移次数,数组D0大小)
	printf("左移两位后的数组C0：\n");//其实，总的来说到这里就已经左移了三次了
	printfArray(C0, sz);
	printf("左移两位后的数组D0：\n");
	printfArray(D0, sz);


	//将左移两次(三)的子数组C0和D0合并成数组C2D2
	sz = sizeof(C2D2) / sizeof(C2D2[0]);//更新此时sz的值
	Combine(C0, D0, C2D2, sz);//(子数组C0,子数组D0,数组C2D2,数组C2D2大小)
	printf("合并后的数组C2D2：\n");
	printfArray(C2D2, sz);


	//获取子密钥K2
	sz = sizeof(K2) / sizeof(K2[0]);//更新此时sz的值
	SecondMapping(C2D2, PC2, K2, sz);//(合并数组C2D2,PC2数组,子密钥数组K2,子密钥数组K2大小)
	printf("子密钥数组K2：\n");
	printfArray(K2, sz);


	//明文加密

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

	//获取明文数组s
	printf("请输入明文数组的值:");
	scanf("%d", &s);
	getchar();
	system("cls");

	//获取明文数组SGroup
	sz = sizeof(SGroup) / sizeof(SGroup[0]);//更新此时sz的值
	GetLimitedArray(SGroup, s, sz);//(明文数组SGroup,明文数组的十进制整数,要获得的二进制个数)
	printf("明文数组SGroup：\n");
	printfArray(SGroup, sz);


	//获取初始换位IP
	sz = sizeof(IP) / sizeof(IP[0]);//更新此时sz的值
	GetArray(IP, sz);//(初始换位IP,初始换位IP数组大小)
	printf("输入的初始换位IP数组：\n");
	printfArray(IP, sz);


	//利用IP改变数组SGroup的内容
	sz = sizeof(SGroup) / sizeof(SGroup[0]);//更新此时sz的值
	Mapping(SGroup, IP, sz);
	printf("最新的明文数组SGroup：\n");
	printfArray(SGroup, sz);

	//第一轮迭代运算：
	//分离最新的SGroup数组从而获得第一轮迭代运算的左值子数组L0和右值子数组R0
	sz = sizeof(L0) / sizeof(L0[0]);//更新此时sz的值
	Split(SGroup, L0, R0, sz);//(最新明文数组SGroup,左值子数组L0,右值子数组R0,子数组大小)
	printf("第一轮迭代运算的左值子数组L0：\n");
	printfArray(L0, sz);
	printf("第一轮迭代运算的右值子数组R0：\n");
	printfArray(R0, sz);


	//在第1次迭代运算中，右值作为第二轮轮的左值（FirstTemp是第二轮的左值）
	sz = sizeof(L0) / sizeof(L0[0]);//更新此时sz的值
	Update(FirstTemp, R0, sz);//将右值子数组拷贝给数组FirstTemp
	printf("第二轮迭代运算的左值子数组FirstTemp：\n");
	printfArray(FirstTemp, sz);

	//EP扩展
	sz = sizeof(EP) / sizeof(EP[0]);//更新此时sz的值
	GetArray(EP, sz);
	printf("输入的数组EP：\n");
	printfArray(EP, sz);

	//第一轮迭代运算的F函数内容：
	//利用EP扩展第一轮迭代运算的右值子数组R0
	sz = sizeof(R0Pro) / sizeof(R0Pro[0]);//更新此时sz的值
	SecondMapping(R0, EP, R0Pro, sz);//(右值子数组,EP数组,扩展后数组R0PR0,扩展后数组大小)
	printf("第一轮迭代运算中，右值子数组R0在F函数中进行EP扩展后的新数组R0Pro：\n");
	printfArray(R0Pro, sz);


	//扩展后的右值子数组R0Pro与子密钥数组K1进行异或运算形成新的数组XOR
	sz = sizeof(XOR) / sizeof(XOR[0]);//更新此时sz的值
	OR(R0Pro, K1, XOR, sz);//(扩展后的右值子数组R0Pro,子密钥K1,异或后的新数组XOR,异或后新数组XOR大小)
	printf("第一轮迭代运算中，右值子数组R0在F函数中进行EP扩展后的数组R0Pro与子密钥数组K1异或运算后得到的新数组XOR：\n");
	printfArray(XOR, sz);


	//s盒运算(缩小XOR数组的两个子数组)
	sz = sizeof(XOR) / sizeof(XOR[0]);//更新此时sz的值
	BoxS(XOR, OR0, S0, OR1, S1, sz);//(异或后的新数组XOR,XOR的左值子数组缩小后的新数组OR0(原始版本),S0盒数组,XOR的右值子数组缩小后的新数组OR1(原始版本),S1盒数组)
	sz = sizeof(OR0) / sizeof(OR0[0]);//更新此时sz的值
	printf("XOR的左值子数组缩小后的新数组OR0（初始版本）：\n");
	printfArray(OR0, sz);
	printf("XOR的左值子数组缩小后的新数组OR0（初始版本）：\n");
	printfArray(OR1, sz);


	//获取P盒
	sz = sizeof(P) / sizeof(P[0]);//更新此时sz的值
	GetArray(P, sz);//(P盒数组,数组大小)
	printf("输入的数组P：\n");
	printfArray(P, sz);


	//合并数组OR0和OR1
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//更新此时sz的值
	Combine(OR0, OR1, ORALL, sz);//(XOR的左值子数组缩小后的新数组OR0,XOR的右值子数组缩小后的新数组OR1,合并后数组ORALL,合并后数组ORALL大小)
	printf("第一轮迭代运算中，F函数S盒置换后的两个子数组合并成的数组ORALL（第一轮初始版本）：\n");
	printfArray(ORALL, sz);


	//P盒换位
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//更新此时sz的值
	Mapping(ORALL, P, sz);//(合并后数组ORALL,P盒数组,合并后数组ORALL大小)
	printf("第一轮迭代运算中，F函数对S盒置换后的两个子数组合并成的新数组ORALL进行P盒置换后的结果（更新数组ORALL）：\n");
	printfArray(ORALL, sz);


	//P盒换位后的数组ORALL与第一轮开始时的左值进行异或运算，得到第二轮的右值
	sz = sizeof(R0) / sizeof(R0[0]);//更新此时sz的值
	OR(ORALL, L0, R0, sz);//(第一轮迭代运算P盒置换后的数组ORALL,第一轮迭代运算开始时的左值数组L0,第一轮迭代运算开始时的右值数组R0（此函数的目的就是更改R0）,右值数组R0的大小)
	printf("第二轮迭代运算的右值（更新原先的R0的值）：\n");
	printfArray(R0, sz);

	//第二轮迭代运算开始时的左值子数组为FirstTemp,右值子数组为R0

	//在第2次迭代运算中，右值作为输出结果的右值（SecondTemp为最终结果的右值子数组）
	sz = sizeof(L0) / sizeof(L0[0]);//更新此时sz的值
	Update(SecondTemp, R0, sz);//将第一轮迭代运算的右值子数组拷贝给数组SecondTemp
	printf("第二轮迭代运算后作为最终结果左值子数组的SecondTemp：\n");
	printfArray(SecondTemp, sz);


	//第二轮迭代运算的f函数内容（对第一轮迭代运算的左值）：
	//EP扩展右数组R0
	sz = sizeof(R0Pro) / sizeof(R0Pro[0]);//更新此时sz的值
	SecondMapping(R0, EP, R0Pro, sz);//(右值子数组R0,EP数组,扩展后数组R0Pro,扩展后数组大小)
	printf("第二轮迭代运算中，右值子数组R0在F函数中进行EP扩展后的新数组R0Pro：\n");
	printfArray(R0Pro, sz);


	//扩展后的R0与子密钥K2进行异或运算（更新XOR数组的内容）
	sz = sizeof(XOR) / sizeof(XOR[0]);//更新此时sz的值
	OR(R0Pro, K2, XOR, sz);//(右值扩展后数组R0Pro,子密钥数组K2,异或运算后的新数组XOR,异或运算后的新数组XOR大小)
	printf("第二轮迭代运算中，右值子数组R0在f函数中进行EP扩展后的数组R0Pro与子密钥数组K2异或运算后得到的新数组XOR(更新XOR数组)：\n");
	printfArray(XOR, sz);


	//S盒运算（更新第一轮迭代运算中的某些数组）
	sz = sizeof(XOR) / sizeof(XOR[0]);//更新此时sz的值
	BoxS(XOR, OR0, S0, OR1, S1, sz);//(异或后的新数组XOR,XOR的左值子数组缩小后的新数组OR0(更新版本),S0盒数组,XOR的右值子数组缩小后的新数组OR1(更新版本),S1盒数组)
	sz = sizeof(OR0) / sizeof(OR0[0]);//更新此时sz的值
	printf("XOR的左值子数组缩小后的新数组OR0（更新版本）：\n");
	printfArray(OR0, sz);
	printf("XOR的左值子数组缩小后的新数组OR1（更新版本）：\n");
	printfArray(OR1, sz);


	//合并数组OR0和OR1
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//更新此时sz的值
	Combine(OR0, OR1, ORALL, sz);//
	printf("第二轮迭代运算中，f函数s盒置换后的两个子数组合并成的新数组ORALL（第二轮更新版本）：\n");
	printfArray(ORALL, sz);


	//p盒换位
	sz = sizeof(ORALL) / sizeof(ORALL[0]);//更新此时sz的值
	Mapping(ORALL, P, sz);//(合并后数组ORALL,P盒数组,合并后数组ORALL大小)
	printf("第二轮迭代运算中，F函数对S盒置换后的两个子数组合并成的新数组ORALL进行P盒置换后的结果（更新数组ORALL）：\n");
	printfArray(ORALL, sz);


	//右值通过f( )函数与子密钥结合后，再与第二轮初始时的左值子数组first进行异或运算，得到最终输出结果的左值（虽然还是用R0来承接，但是这时的R0代表的是最终输出结果的左值）
	sz = sizeof(R0) / sizeof(R0[0]);//更新此时sz的值
	OR(ORALL, FirstTemp, R0, sz);//(P盒子置换后的右值子数组,第二轮迭代运算初始时的左值子数组FirstTemp,最终输出的左值子数组R0(虽然叫R0但这里表示已经是左值了),最终输出的左值子数组R0大小)
	printf("第二轮迭代运算中,最后输出的左值：\n");
	printfArray(R0, sz);


	//合并数组
	sz = sizeof(Results) / sizeof(Results[0]);//更新此时sz的值
	Combine(R0, SecondTemp, Results, sz);//(第二轮迭代运算输出左值子数组R0，第二轮迭代运算输出右值子数组SecondTemp,合并数组results,合并数组results的大小)
	printf("第二轮迭代运算后,两个输出结果合并后的数组Results：\n");
	printfArray(Results, sz);

	//获取ReverseIP
	sz = sizeof(ReverseIP) / sizeof(ReverseIP[0]);//更新此时sz的值
	GetArray(ReverseIP, sz);//(逆初始换位ReverseIP,逆初始换位ReverseIP数组大小)
	printf("输入的逆初始换位ReverseIP数组：\n");
	printfArray(ReverseIP, sz);


	//利用ReverseIP改变数组Results的内容
	sz = sizeof(Results) / sizeof(Results[0]);//更新此时sz的值
	Mapping(Results, ReverseIP, sz);//(合并后数组Results,逆初始换位ReverseIP,合并后数组Results的大小)
	printf("最终明文加密后的结果：\n");
	printfArray(Results, sz);

	return 0;
}