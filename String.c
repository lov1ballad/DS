#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct string							//顺序串的结构体
{
	char ch[MAXSIZE + 1];
	int length;
}string;

int StringAssign(string *S, char chs[])				//生成一个其值等于字符串常量chs的串S
{
	int i = 0;
	while (chs[i] != '\0')							//循环，将字符串常量的值赋值给S
	{
		S->ch[i] = chs[i];
		++i;
	}
	S->length = i;									//将i赋值给S的长度
	return 0;
}

void StringCopy(string *S1, string *S2)			//将串S2复制到串S1
{
	int i = 0;
	for (i = 0; i < S2->length; i++)			//循环 复制字符
	{
		S1->ch[i] = S2->ch[i];
	}
	S1->length = S2->length;				//复制长度
}

int LengthString(string *S)					//求串S的长度
{
	return S->length;
}

int ShowString(string *S)					//打印串S
{
	if (S->length == 0)
	{
		printf("当前串为空！\n");
		return 0;
	}
	int i;
	for (i = 0; i < S->length; i++)
	{
		printf("%c", S->ch[i]);
	}
	printf("\n");
	return 0;
}

int StringCompare(string *S1, string *S2)				//比较串S1和串S2
{														//若S1 = S2，则返回0
	int i = 0;											//若S1 > S2,则返回1
	while ((i < S1->length) && (i < S2->length))		//若S1 < S2,则返回-1
	{
		if ((int)(S1->ch[i]) >(int)(S2->ch[i]))		//将字符强制转换为整型比较大小
			return 1;
		if ((int)(S1->ch[i]) < (int)(S2->ch[i]))
			return -1;
		if (S1->ch[i] == S2->ch[i])
		{
			++i;
			continue;								//如果两字符相等，则退出该次循环，进行下一次循环
		}
		++i;
	}
	if ((i == S1->length) && (i != S2->length))
		return -1;
	else if ((i != S1->length) && (i == S2->length))
		return 1;
	else
		return 0;
}

int ConcatString(string *S, string *S1, string *S2)			//用S返回由S1和S2连接而成的新串
{
	int i, j;
	for (i = 0; i < S1->length; i++)			//循环，首先将S1复制到串S
	{
		S->ch[i] = S1->ch[i];
	}
	S->length = S1->length;
	for (j = 0; j < S2->length; j++)			//再次循环，将S2复制到串S
	{
		S->ch[S->length] = S2->ch[j];
		++S->length;
	}
	return 0;
}

int SubString(string *Sub, string *S, int pos, int len)		//用Sub返回串S的第pos个字符起长度为len的子串
{
	if ((1 > pos) || (pos > S->length) || (len < 0) || (len > S->length - pos + 1))
	{
		printf("输入有误！\n");
		return 0;
	}
	int j = 0;
	while (j < len)
	{
		Sub->ch[j] = S->ch[pos - 1];
		++j;
		++pos;
	}
	Sub->length = len;
	return 0;
}

int StrInsert(string *S1, int pos, string *S2)		//在串S1的第pos个字符之前插入串S2
{
	if (pos < 1 || (pos > S1->length))
	{
		printf("输入有误！\n");
		return 0;
	}
	int i;
	for (i = (S1->length - 1); i >= pos - 1; i--)	//循环，将S1从第pos个字符往后的
	{												//所有字符都后移S2->length个位置
		S1->ch[i + S2->length] = S1->ch[i];
	}
	int j = 0;
	int k = pos - 1;
	for (j = 0; j < S2->length; j++)			//循环，将串S2依次插入到S1移动后空出来的位置
	{
		S1->ch[k] = S2->ch[j];
		k++;
	}
	S1->length += S2->length;					//更新S1的长度
	return 0;
}

int StrDelete(string *S, int pos, int len)			//从串S中删除第pos个字符起长度为len的子串
{
	if (pos < 1 || pos >(S->length - len + 1))
	{
		printf("输入有误！\n");
		return 0;
	}
	int i;
	for (i = pos + len; i <= S->length; i++)
	{
		S->ch[i - len - 1] = S->ch[i - 1];
	}
	S->length -= len;						//更新S的长度，超过S->length后的字符会被省略
	return 0;
}

//朴素的模式匹配算法
int Index(string *S, string *T, int pos)		//返回子串T在主串S中第pos个字符之后的位置，若不存在，返回0
{
	if (pos < 1 || pos > S->length)
	{
		printf("输入有误！");
		return 0;
	}
	int i = pos;
	int j = 0;
	while (i <= S->length && j <= T->length)
	{
		if (S->ch[i - 1] == T->ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;				//i退回到上次匹配首位的下一位
			j = 0;
		}
	}
	if (j == T->length)
		return i - T->length;
	else
		return 0;
}

void get_next(string *T, int *next)			//计算出当前要匹配的串T的next数组
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T->length)
	{
		if (j == 0 || T->ch[i - 1] == T->ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
//KMP模式匹配算法
int Index_KMP(string *S, string *T, int pos)  //返回子串T在主串S中第pos个字符之后的位置，若不存在，返回0
{
	int i = pos;
	int j = 0;
	int next[255];
	get_next(T, next);
	while (i <= S->length && j <= T->length)
	{
		if (j == 0 || S->ch[i] == T->ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T->length)
		return i - T->length;
	else
		return 0;
}

int main()
{
	string S;
	string T;
	string N;
	string M;
	string G;
	string L;
	char ch[] = { "hello world" };
	char ch1[] = { "hello" };
	char ch2[] = { "hello worldd" };
	StringAssign(&S, ch);
	StringAssign(&N, ch1);
	StringAssign(&M, ch2);
	printf("S串：");
	ShowString(&S);
	printf("当前S串的长度为%d\n", LengthString(&S));
	printf("N串：");
	ShowString(&N);
	printf("当前N串的长度为%d\n", LengthString(&N));
	printf("M串：");
	ShowString(&M);
	printf("当前M串的长度为%d\n", LengthString(&M));
	StringCopy(&T, &S);
	printf("将S串复制到T串\nT串：");
	ShowString(&T);
	printf("当前T串的长度为%d\n", LengthString(&T));
	printf("比较串的大小：0代表相等，1代表第一个串比第二个串大，-1代表第一个串比第二个串小\n");
	printf("S串与T串：%d\n", StringCompare(&S, &T));
	printf("S串与N串：%d\n", StringCompare(&S, &N));
	printf("S串与M串：%d\n", StringCompare(&S, &M));
	printf("将N串和M串连接成新串G\n");
	ConcatString(&G, &N, &M);
	printf("G串：");
	ShowString(&G);
	printf("当前G串的长度为%d\n", LengthString(&G));
	SubString(&L, &S, 7, 5);
	printf("显示S串中第7个字符起长度为5的子串L：");
	ShowString(&L);
	StrInsert(&N, 3, &L);
	printf("在N串第3个字符之前插入L串，插入后的N串为：");
	ShowString(&N);
	printf("当前N串的长度为%d\n", LengthString(&N));
	StrDelete(&N, 3, 5);
	printf("删除第三个字符起长度为5的子串后，N：");
	ShowString(&N);
	printf("当前N串的长度为%d\n", LengthString(&N));
	printf("(朴素模式匹配算法)子串L在主串S中的位置为%d\n", Index(&S, &L, 1));
	printf("(KMP模式匹配算法)子串L在主串S中的位置为%d\n", Index_KMP(&S, &L, 1));
	system("pause");
	return 0;
}

