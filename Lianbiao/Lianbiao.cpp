#include "pch.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
	int num;
	struct data *next;
}data, *dat;

void init(dat &L)
{
	dat p = (dat)malloc(sizeof(struct data));
	L = p;
}

dat creat()
{	
	dat flag, end;
	dat head = (dat)malloc(sizeof(struct data));
	flag = (dat)calloc(1,sizeof(struct data));
	head->next = flag;
	int num,cj=0;
	while (scanf("%d", &num) != EOF)
	{
		if (num == -1)
		{
			if (cj==1)
			{
				flag->num = 1;
			}
			break;
		}
		else
		{
			cj = 1;
			flag->num = num;
			end = flag;
		    flag->next = (dat)malloc(sizeof(data));
			flag = flag->next;
			
		}
	}

	if ( flag->num == 0)
	{
		head->next = NULL;
	}
	else
	{
		end->next = NULL;
	}
	free(flag);
	return head; 
}
dat merge(dat a, dat b)//合并两个链表，
{
	dat la = a->next;
	dat lb = b->next;
	dat c,lc;
	c = (dat)malloc(sizeof(data));
	lc = c = a;
	while (la&&lb)
	{
		if (la->num <= lb->num)
		{
			c->next = la;
			c = la;
			la = la->next;
		}
		else
		{
			c->next = lb;
			c = lb;
			lb = lb->next;
		}
	}
	c->next = la ? la : lb;
	return lc;
}
int Lengthlist(dat &L)//计算链表长度
{
	dat p = L->next;
	int length = 0;
	while (p) 
	{
		length++;
		p = p->next;
	}
	return length;
}

void  print(dat L)
{
	dat p = L->next;
	int flag = 0;
	while (p != NULL)
	{
		if (!flag) 
		{
			printf("%d", p->num);
			flag = 1;
		}
		else 
		{
			printf(" %d", p->num);
		}
		p = p->next;
	}
	printf("\n");
}
int main()
{
	dat d;
	init(d);
	dat a = creat();
	//print(a);
	dat b = creat();
	//print(b);
	if (Lengthlist(a)==0&& Lengthlist(b)==0)
	{
		printf("NULL\n");
	}
	else
	{
		d = merge(a, b);
		print(d);
	}
	return 0;
}