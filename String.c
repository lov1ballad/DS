#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct string							//˳�򴮵Ľṹ��
{
	char ch[MAXSIZE + 1];
	int length;
}string;

int StringAssign(string *S, char chs[])				//����һ����ֵ�����ַ�������chs�Ĵ�S
{
	int i = 0;
	while (chs[i] != '\0')							//ѭ�������ַ���������ֵ��ֵ��S
	{
		S->ch[i] = chs[i];
		++i;
	}
	S->length = i;									//��i��ֵ��S�ĳ���
	return 0;
}

void StringCopy(string *S1, string *S2)			//����S2���Ƶ���S1
{
	int i = 0;
	for (i = 0; i < S2->length; i++)			//ѭ�� �����ַ�
	{
		S1->ch[i] = S2->ch[i];
	}
	S1->length = S2->length;				//���Ƴ���
}

int LengthString(string *S)					//��S�ĳ���
{
	return S->length;
}

int ShowString(string *S)					//��ӡ��S
{
	if (S->length == 0)
	{
		printf("��ǰ��Ϊ�գ�\n");
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

int StringCompare(string *S1, string *S2)				//�Ƚϴ�S1�ʹ�S2
{														//��S1 = S2���򷵻�0
	int i = 0;											//��S1 > S2,�򷵻�1
	while ((i < S1->length) && (i < S2->length))		//��S1 < S2,�򷵻�-1
	{
		if ((int)(S1->ch[i]) >(int)(S2->ch[i]))		//���ַ�ǿ��ת��Ϊ���ͱȽϴ�С
			return 1;
		if ((int)(S1->ch[i]) < (int)(S2->ch[i]))
			return -1;
		if (S1->ch[i] == S2->ch[i])
		{
			++i;
			continue;								//������ַ���ȣ����˳��ô�ѭ����������һ��ѭ��
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

int ConcatString(string *S, string *S1, string *S2)			//��S������S1��S2���Ӷ��ɵ��´�
{
	int i, j;
	for (i = 0; i < S1->length; i++)			//ѭ�������Ƚ�S1���Ƶ���S
	{
		S->ch[i] = S1->ch[i];
	}
	S->length = S1->length;
	for (j = 0; j < S2->length; j++)			//�ٴ�ѭ������S2���Ƶ���S
	{
		S->ch[S->length] = S2->ch[j];
		++S->length;
	}
	return 0;
}

int SubString(string *Sub, string *S, int pos, int len)		//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
{
	if ((1 > pos) || (pos > S->length) || (len < 0) || (len > S->length - pos + 1))
	{
		printf("��������\n");
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

int StrInsert(string *S1, int pos, string *S2)		//�ڴ�S1�ĵ�pos���ַ�֮ǰ���봮S2
{
	if (pos < 1 || (pos > S1->length))
	{
		printf("��������\n");
		return 0;
	}
	int i;
	for (i = (S1->length - 1); i >= pos - 1; i--)	//ѭ������S1�ӵ�pos���ַ������
	{												//�����ַ�������S2->length��λ��
		S1->ch[i + S2->length] = S1->ch[i];
	}
	int j = 0;
	int k = pos - 1;
	for (j = 0; j < S2->length; j++)			//ѭ��������S2���β��뵽S1�ƶ���ճ�����λ��
	{
		S1->ch[k] = S2->ch[j];
		k++;
	}
	S1->length += S2->length;					//����S1�ĳ���
	return 0;
}

int StrDelete(string *S, int pos, int len)			//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
{
	if (pos < 1 || pos >(S->length - len + 1))
	{
		printf("��������\n");
		return 0;
	}
	int i;
	for (i = pos + len; i <= S->length; i++)
	{
		S->ch[i - len - 1] = S->ch[i - 1];
	}
	S->length -= len;						//����S�ĳ��ȣ�����S->length����ַ��ᱻʡ��
	return 0;
}

//���ص�ģʽƥ���㷨
int Index(string *S, string *T, int pos)		//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ�����0
{
	if (pos < 1 || pos > S->length)
	{
		printf("��������");
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
			i = i - j + 1;				//i�˻ص��ϴ�ƥ����λ����һλ
			j = 0;
		}
	}
	if (j == T->length)
		return i - T->length;
	else
		return 0;
}

void get_next(string *T, int *next)			//�������ǰҪƥ��Ĵ�T��next����
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
//KMPģʽƥ���㷨
int Index_KMP(string *S, string *T, int pos)  //�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ�����0
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
	printf("S����");
	ShowString(&S);
	printf("��ǰS���ĳ���Ϊ%d\n", LengthString(&S));
	printf("N����");
	ShowString(&N);
	printf("��ǰN���ĳ���Ϊ%d\n", LengthString(&N));
	printf("M����");
	ShowString(&M);
	printf("��ǰM���ĳ���Ϊ%d\n", LengthString(&M));
	StringCopy(&T, &S);
	printf("��S�����Ƶ�T��\nT����");
	ShowString(&T);
	printf("��ǰT���ĳ���Ϊ%d\n", LengthString(&T));
	printf("�Ƚϴ��Ĵ�С��0������ȣ�1�����һ�����ȵڶ�������-1�����һ�����ȵڶ�����С\n");
	printf("S����T����%d\n", StringCompare(&S, &T));
	printf("S����N����%d\n", StringCompare(&S, &N));
	printf("S����M����%d\n", StringCompare(&S, &M));
	printf("��N����M�����ӳ��´�G\n");
	ConcatString(&G, &N, &M);
	printf("G����");
	ShowString(&G);
	printf("��ǰG���ĳ���Ϊ%d\n", LengthString(&G));
	SubString(&L, &S, 7, 5);
	printf("��ʾS���е�7���ַ��𳤶�Ϊ5���Ӵ�L��");
	ShowString(&L);
	StrInsert(&N, 3, &L);
	printf("��N����3���ַ�֮ǰ����L����������N��Ϊ��");
	ShowString(&N);
	printf("��ǰN���ĳ���Ϊ%d\n", LengthString(&N));
	StrDelete(&N, 3, 5);
	printf("ɾ���������ַ��𳤶�Ϊ5���Ӵ���N��");
	ShowString(&N);
	printf("��ǰN���ĳ���Ϊ%d\n", LengthString(&N));
	printf("(����ģʽƥ���㷨)�Ӵ�L������S�е�λ��Ϊ%d\n", Index(&S, &L, 1));
	printf("(KMPģʽƥ���㷨)�Ӵ�L������S�е�λ��Ϊ%d\n", Index_KMP(&S, &L, 1));
	system("pause");
	return 0;
}

