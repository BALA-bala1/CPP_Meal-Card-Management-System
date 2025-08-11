#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 
#define SIXMAX 999999
void jlwj(int x); 
void mf(int q);
void xq(int c);
void tj(int t);
void zx(int z);
void gs(int s);
void cxk(int h);
void cx();
void cxj(double j);
void cxm(char *m);
void cxg(int g);
int ffsri(char *zc);
double ffsrf(char *zc);
int i=0;
char ch=' ',gh='\n';
char zc[100];
FILE *fp;
const int MAX_PEOPLE = 10000;
typedef struct {
    int k;
	char name[100];
	double j;
	int g;
} Person;
Person people[1000];
int main() 
{
	int a=8,x,q,c,t,z,s,h;
	printf("欢迎使用本系统\n\n特此声明\n饭卡号和饭卡数量为整数\n饭卡余额和买饭金额为整数或小数\n持卡人姓名为中文名或英文名\n\n"); 
	while (a != 0) 
	{ 
		printf("请输入选项编号(0~7)\n\n1--建立饭卡文件\n2--买饭\n3--续钱\n4--添加新饭卡\n5--注销旧饭卡\n6--设置与解除挂失\n7--查询饭卡信息\n0--退出系统\n");
		scanf(" %s",zc);
		a=ffsri(zc);
		switch (a) 
		{
			case 1:
				printf("请输入饭卡数量\n"); 
				scanf(" %s",zc);
				x=ffsri(zc);
                jlwj(x);
				break;
			case 2:
			    printf("请输入买饭饭卡号\n");
				scanf(" %s",zc);
				q=ffsri(zc);
				mf(q);
				break;
			case 3:
				printf("请输入充值饭卡号\n");
				scanf(" %s",zc);
				c=ffsri(zc);
				xq(c);
				break;
			case 4:
			    printf("请输入添加饭卡数量\n"); 
			    scanf(" %s",zc);
			    t=ffsri(zc);
			    tj(t);
			    break;
			case 5:
				printf("请输入注销饭卡数量\n");
				scanf(" %s",zc);
				z=ffsri(zc);
				zx(z);
				break;
			case 6:
				printf("请输入设置饭卡号\n");
				scanf(" %s",zc);
				s=ffsri(zc);
				gs(s);
				break;
			case 7:
				cx();
				break;
			case 0:
				printf("感谢使用本软件！已正常退出，按任意键结束!\n");
			    break; 
			default:
				printf("请输入0~8的整数\n\n"); 
		}
	}
	return 0;
}
int ffsri(char *zc)
{
	int re;
	int pd,pd2,nm;
	pd=0;
	while(pd==0)
	{
		pd2=1;
		nm=0;
		while(zc[nm]!='\0'&&pd2==1)
		{
			if(zc[nm]<'0'||zc[nm]>'9')
			{
				printf("输入非法\n请输入整数\n");
				pd2=0;
				scanf(" %s",zc);
			}
			nm++;
		}
		if(pd2==1)
		{
			pd=1;
		}
	}
	re=atoi(zc);
	return re;
}
double ffsrf(char *zc)
{
	double re;
	int pd=0,pd2,pd3,pd4,nm;
	while(pd==0)
	{
		pd2=1;
		pd3=0;
	    nm=0;
		if(zc[0]!='.')
		{
			while(zc[nm]!='\0'&&pd2==1)
			{
				pd4=0;
				if(pd3==0)
				{
					if(zc[nm]=='.')
					{
						pd3=1;
						pd4=1;
					}
				}
				if(pd3==0)
				{
					if(zc[nm]<'0'||zc[nm]>'9')
					{
						printf("输入非法\n请输入整数或小数\n");
						pd2=0;
						scanf(" %s",zc);
					}
				}
				if(pd3==1&&pd4==0)
				{
					if(zc[nm]<'0'||zc[nm]>'9')
					{
						printf("输入非法\n请输入整数或小数\n");
						pd2=0;
						scanf(" %s",zc);
					}
				}
				nm++;
			}
			if(pd2==1)
			{
				pd=1;
			}
		}
		else
		{
			printf("输入非法\n请输入整数或小数\n");
			scanf(" %s",zc);
		}
	}
	re=atof(zc);
	return re;
}
int readPeopleFromFile(const char *filename, Person *people, int maxCount) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
	{
        printf("File open error!\n");
		exit(0);
    }
    int count = 0;
    char line[10000];
    while (fgets(line, sizeof(line), fp) && count < maxCount)
	{
        // 去除行尾的换行符
        line[strcspn(line, "\n")] = 0;
        // 使用空格分割字符串
        char *token = strtok(line, " ");
        if (token != NULL)
		{
            people[count].k = atoi(token);//atoi把字符转为整型数字 
            token = strtok(NULL, " ");//继续分割字符串 
            if (token != NULL)
			{
                strncpy(people[count].name, token, sizeof(people[count].name) - 1);//sizeof(people[count].name) - 1为最大字符复制数量 
                people[count].name[sizeof(people[count].name) - 1] = '\0';
                token = strtok(NULL, " ");
                if (token != NULL)
				{
                    people[count].j = atof(token);//atof把字符转为浮点型数字 
                    token = strtok(NULL, " ");
                    if (token != NULL)
					{
                    	people[count].g = atoi(token);
                    	count++;
                    }
                }
            }
        }
    }
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	} 
    return count;
}
int writePeopleToFile(const char *filename, Person *people, int count)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
	{
        printf("File open error!\n");
		exit(0);
    }
    for (int i = 0; i < count; i++)
	{
       // 写入文件
        fprintf(fp, "%06d %s %lf %d\n", people[i].k, people[i].name, people[i].j,people[i].g );
    }
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	} 
    return 0;
}
void jlwj(int x)
{
	int n,a;
	i=0;
	if((fp=fopen("card.txt","w"))==NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	while(x!=0)
	{
		srand(time(NULL));
		people[i].k=rand()%SIXMAX+1;
		if(i!=0)
		{
			for(n=0;n<i;n++)
			{
				if(people[i].k==people[n].k)
				{
					n=-1;
					people[i].k=rand()%SIXMAX+1;
				}
			}
		}
		printf("第%d张饭卡\n饭卡号为%06d\n",i+1,people[i].k);
		fprintf(fp,"%06d",people[i].k);
		fprintf(fp,"%c",ch);
		printf("请输入持卡人姓名\n");
		scanf("%s",&people[i].name);
		fprintf(fp,"%s",people[i].name);
		fprintf(fp,"%c",ch);
		printf("请输入余额\n");
		scanf(" %s",zc);
		people[i].j=ffsrf(zc);
		while(people[i].j<0)
		{
			printf("请输入不小于零的数\n");
			scanf(" %s",zc);
			people[i].j=ffsrf(zc);
		} 
		fprintf(fp,"%lf",people[i].j);
		fprintf(fp,"%c",ch);
		printf("请输入挂失状态（0为挂失，1为正常）\n");
		scanf("%s",zc);
		people[i].g=ffsri(zc);
		while(people[i].g!=0&&people[i].g!=1)
		{
			printf("输入不合法\n请重新输入挂失状态（0为挂失，1为正常）\n");
			scanf("%s",zc);
			people[i].g=ffsri(zc); 
		}
		fprintf(fp,"%d",people[i].g);
		fprintf(fp,"%c",gh);
		x--;
		i++;
	}
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	} 
 } 
void mf(int q)
{
 	int n,m=-1,a,b=0;
 	double f,c;
 	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
 	while(b==0)
	{
 		for(i=0;i<n;i++)
 	 	{
 	 		if(people[i].k==q)
 	 		{
 	 			m=i;
 	 			b=1;
 	 			break;
	  		}
	  	}
	 	if(m==-1)
		{
	 		printf("饭卡不存在\n请重新输入饭卡号\n");
	 		scanf(" %s",zc);
	 		q=ffsri(zc); 
		}
	}
	if(people[m].j<5)
	{
	 	printf("余额不够，请充钱\n");
	}
	if(people[m].j>=5)
	{
	 	c=people[m].j;
	 	if(people[m].g!=0)
		{
	 		printf("请输入饭钱\n");
	 		scanf(" %s",zc);
	 		f=ffsrf(zc);
	 		while(f<=0)
			{
				printf("请输入大于零的数\n");
				scanf(" %s",zc);
	 			f=ffsrf(zc);
		 	} 
	 		if(people[m].j>=f)
			{
	 			people[m].j=people[m].j-f;
	 			printf("买饭前余额为%f\n买饭后余额为%f\n买饭成功\n",c,people[m].j);
		 	}
	 		else
	 		printf("余额不足\n");
		}
		else
		printf("饭卡已冻结\n");
	}
	a=writePeopleToFile("card.txt", people, n);
}
void xq(int c)
{
	int n,m=-1,a,d=0;
	double cq,b;
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(d==0)
	{
 	 	for(i=0;i<n;i++)
 	 	{
 	 		if(people[i].k==c)
 	 		{
 	 			d=1;
 	 			m=i;
 	 			break;
	  		}
	  	}
	 	if(m==-1)
		{
	 		printf("饭卡不存在\n请重新输入饭卡号\n");
	 		scanf(" %s",zc);
	 		c=ffsri(zc);
		}
	}
	if(people[m].g!=0)
	{
 		b=people[m].j;
 		printf("请输入充值金额\n");
		scanf(" %s",zc);
		cq=ffsrf(zc);
		while(cq<=0)
		{
			printf("请输入大于零的数\n");
			scanf(" %s",zc);
	 		cq=ffsrf(zc);
		} 
		people[m].j=people[m].j+cq;
		printf("续钱成功\n续钱前余额为%f\n续钱后余额为%f\n",b,people[m].j);
	}
	else
	{
	 	printf("饭卡已挂失，无法续钱\n");
	}
	a=writePeopleToFile("card.txt", people,n);
}
void tj(int t)
{
 	int n,a,b;
 	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
 	srand(time(NULL)); 
 	for(i=n;i<n+t;i++)
 	{
 		people[i].k=rand()%SIXMAX+1;
 		for(b=0;b<i;b++)
		{
			if(people[i].k==people[b].k)
			{
				b=-1;
				people[i].k=rand()%SIXMAX+1;
			}
		}
 		printf("第%d张新饭卡\n饭卡号为%06d\n",i-n+1,people[i].k);
		printf("请输入持卡人姓名\n");
		scanf("%s",&people[i].name);
		printf("请输入余额\n");
		scanf(" %s",zc);
		people[i].j=ffsrf(zc);
		while(people[i].j<0)
		{
			printf("请输入不小于零的数\n");
			scanf(" %s",zc);
			people[i].j=ffsrf(zc);
		} 
		printf("请输入挂失状态（0为挂失，1为正常）\n");
		scanf(" %s",zc);
		people[i].g=ffsri(zc);
		while(people[i].g!=0&&people[i].g!=1)
		{
			printf("输入不合法\n请重新输入挂失状态（0为挂失，1为正常）\n");
			scanf(" %s",zc);
			people[i].g=ffsri(zc); 
		}
		printf("添加第%d张新饭卡成功\n",i-n+1);
	}
	 a=writePeopleToFile("card.txt", people, n+t);
 }
void zx(int z)
{
	int n,b,m,a,c;
	c=z;
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(z!=0)
	{
		printf("请输入需注销的饭卡号\n");
		scanf(" %s",zc);
		b=ffsri(zc);
		for(i=0;i<n;i++)
		{
			if(b==people[i].k&&i!=n-1)
			{
				n=n-1;
				for(m=i;m<=n;m++)
				{
					people[m]=people[m+1];
				}
				printf("注销第%d张旧饭卡成功\n",c-z+1);
				break;
			}
			else if(b==people[i].k&&i==n-1)
			{
				n=n-1;
				printf("注销第%d张旧饭卡成功\n",c-z+1);
			} 
			else if(b!=people[i].k&&i==n-1)
			{
				printf("饭卡不存在，注销第%d张旧饭卡失败\n",c-z+1);
			}
		}
		z--;
	}
	a=writePeopleToFile("card.txt", people, n);
}
void gs(int s)
{
	int n,m=-1,a,b=0;
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(b==0)
	{
		for(i=0;i<n;i++)
 	 	{
 	 		if(people[i].k==s)
 	 		{
 	 			m=i;
 	 			b=1;
 	 			break;
	  		}
	  	}
		if(m==-1)
		{
	 		printf("饭卡不存在\n");
	 		printf("请重新输入卡号\n");
	 		scanf(" %s",zc);
	 		s=ffsri(zc);
		}
	}
	if(people[m].g==1)
	printf("此饭卡当前未挂失\n");
	if(people[m].g==0)
	printf("此饭卡当前已挂失\n");
	printf("请输入挂失状态（0为挂失，1为正常）\n");
	scanf(" %s",zc);
	people[m].g=ffsri(zc);
	while(people[m].g!=0&&people[m].g!=1)
	{
		printf("输入不合法\n请重新输入挂失状态（0为挂失，1为正常）\n");
		scanf(" %s",zc);
		people[m].g=ffsri(zc);
	}
	printf("设置与解除挂失成功\n"); 
	a=writePeopleToFile("card.txt", people,n);
}
void cx()
{
	int a=5,k,g;
	double j;
	char m[100];
	while (a != 0)
	{
		printf("请输入选项编号(0~4)\n\n1--根据卡号查询\n2--根据姓名查询\n3--根据余额查询\n4--根据挂失状态查询\n0--退出查询\n");
		scanf(" %s",zc);
		a=ffsri(zc);
		switch (a)
		{
			case 1:
				printf("请输入饭卡号\n"); 
				scanf(" %s",zc);
				k=ffsri(zc);
                cxk(k);
				break;
			case 2:
			    printf("请输入持卡人姓名\n");
				scanf("%s",m);
				cxm(m);
				break;
			case 3:
				printf("请输入余额\n");
				scanf(" %s",zc);
				j=ffsrf(zc);
				while(j<0)
				{
					printf("请输入大于零的数\n");
					scanf(" %s",zc);
					j=ffsrf(zc);
				}
				cxj(j);
				break;
			case 4:
			    printf("请输入挂失状态（0为挂失，1为正常）\n"); 
			    scanf(" %s",zc);
			    g=ffsri(zc);
			    while(g!=0&&g!=1)
			    {
			    	printf("输入不合法\n请重新输入挂失状态（0为挂失，1为正常）\n");
					scanf(" %s",zc);
			    	g=ffsri(zc);
				}
			    cxg(g);
			    break;
			case 0:
				printf("已正常退出\n\n");
			    break; 
			default:
				printf("请输入0~4的整数\n");
		}
	}
}
void cxk(int k)
{
	int n,b=0,m=-1;
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(b==0)
	{
		for(i=0;i<n;i++)
 	 	{
 	 		if(people[i].k==k)
 	 		{
 	 			m=i;
 	 			b=1;
 	 			break;
	  		}
	  	}
	 	if(m==-1)
		{
	 		printf("饭卡不存在\n");
	 		printf("请重新输入卡号\n");
	 		scanf(" %s",zc);
	 		k=ffsri(zc);
		}
	}
	printf("此饭卡所有人为%s\n",people[m].name);
	printf("此饭卡余额为%f\n",people[m].j);
	if(people[m].g==1) 
	printf("此饭卡未挂失\n");
	if(people[m].g==0)
	printf("此饭卡已挂失\n");
}
void cxm(char *m)
{
	int n,a=-1,c=0,j=0;
	Person b[1000];
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(c==0)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(m,people[i].name)==0)
			{
				c++;
				b[j]=people[i];
				j++;
			}
		}
		if(c==0)
		{
			printf("不存在对应姓名的饭卡\n");
			printf("请重新输入持卡人姓名\n");
	 		scanf("%s",m);
		}
	} 
	printf("共计%d个查询结果\n",c);
	for(i=0;i<c;i++)
	{
	 	printf("第%d个查询结果\n",i+1); 
		printf("此饭卡卡号为%06d\n",b[i].k);
		printf("此饭卡余额为%f\n",b[i].j);
		if(b[i].g==1) 
		printf("此饭卡未挂失\n");
		if(b[i].g==0)
		printf("此饭卡已挂失\n"); 
	 }
}
void cxj(double j)
{
	int n,a=-1,c=0,k=0;
	Person b[1000];
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(c==0)
	{
		for(i=0;i<n;i++)
		{
			if(people[i].j==j)
			{
				c++;
				b[k]=people[i];
				k++;
			}
		}
		if(c==0)
		{
			printf("不存在相应余额的饭卡\n");
			printf("请重新输入余额\n");
			scanf(" %s",zc);
			j=ffsrf(zc);
		}
	 } 
	 printf("共计%d个查询结果\n",c);
	 for(i=0;i<c;i++)
	 {
	 	printf("第%d个查询结果\n",i+1); 
		printf("此饭卡卡号为%06d\n",b[i].k);
		printf("此饭卡所有人为%s\n",b[i].name);
		if(b[i].g==1) 
		printf("此饭卡未挂失\n");
		if(b[i].g==0)
		printf("此饭卡已挂失\n"); 
	 }
}
void cxg(int g)
{
	int n,a=-1,c=0,k=0;
	Person b[1000];
	n=readPeopleFromFile("card.txt", people,  MAX_PEOPLE);
	while(c==0)
	{
		for(i=0;i<n;i++)
		{
			if(people[i].g==g)
			{
				c++;
				b[k]=people[i];
				k++;
			}
		}
		if(c==0)
		{
			printf("不存在此挂失状态的饭卡\n");
			printf("请重新输入挂失状态\n");
			scanf(" %s",zc);
			g=ffsri(zc);
		}
	} 
	printf("共计%d个查询结果\n",c);
	for(i=0;i<c;i++)
	{
	 	printf("第%d个查询结果\n",i+1); 
		printf("此饭卡卡号为%06d\n",b[i].k);
		printf("此饭卡余额为%f\n",b[i].j);
		printf("此饭卡所有人为%s\n",b[i].name);
	}
}
