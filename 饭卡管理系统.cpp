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
	printf("��ӭʹ�ñ�ϵͳ\n\n�ش�����\n�����źͷ�������Ϊ����\n���������򷹽��Ϊ������С��\n�ֿ�������Ϊ��������Ӣ����\n\n"); 
	while (a != 0) 
	{ 
		printf("������ѡ����(0~7)\n\n1--���������ļ�\n2--��\n3--��Ǯ\n4--����·���\n5--ע���ɷ���\n6--����������ʧ\n7--��ѯ������Ϣ\n0--�˳�ϵͳ\n");
		scanf(" %s",zc);
		a=ffsri(zc);
		switch (a) 
		{
			case 1:
				printf("�����뷹������\n"); 
				scanf(" %s",zc);
				x=ffsri(zc);
                jlwj(x);
				break;
			case 2:
			    printf("�������򷹷�����\n");
				scanf(" %s",zc);
				q=ffsri(zc);
				mf(q);
				break;
			case 3:
				printf("�������ֵ������\n");
				scanf(" %s",zc);
				c=ffsri(zc);
				xq(c);
				break;
			case 4:
			    printf("��������ӷ�������\n"); 
			    scanf(" %s",zc);
			    t=ffsri(zc);
			    tj(t);
			    break;
			case 5:
				printf("������ע����������\n");
				scanf(" %s",zc);
				z=ffsri(zc);
				zx(z);
				break;
			case 6:
				printf("���������÷�����\n");
				scanf(" %s",zc);
				s=ffsri(zc);
				gs(s);
				break;
			case 7:
				cx();
				break;
			case 0:
				printf("��лʹ�ñ�������������˳��������������!\n");
			    break; 
			default:
				printf("������0~8������\n\n"); 
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
				printf("����Ƿ�\n����������\n");
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
						printf("����Ƿ�\n������������С��\n");
						pd2=0;
						scanf(" %s",zc);
					}
				}
				if(pd3==1&&pd4==0)
				{
					if(zc[nm]<'0'||zc[nm]>'9')
					{
						printf("����Ƿ�\n������������С��\n");
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
			printf("����Ƿ�\n������������С��\n");
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
        // ȥ����β�Ļ��з�
        line[strcspn(line, "\n")] = 0;
        // ʹ�ÿո�ָ��ַ���
        char *token = strtok(line, " ");
        if (token != NULL)
		{
            people[count].k = atoi(token);//atoi���ַ�תΪ�������� 
            token = strtok(NULL, " ");//�����ָ��ַ��� 
            if (token != NULL)
			{
                strncpy(people[count].name, token, sizeof(people[count].name) - 1);//sizeof(people[count].name) - 1Ϊ����ַ��������� 
                people[count].name[sizeof(people[count].name) - 1] = '\0';
                token = strtok(NULL, " ");
                if (token != NULL)
				{
                    people[count].j = atof(token);//atof���ַ�תΪ���������� 
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
       // д���ļ�
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
		printf("��%d�ŷ���\n������Ϊ%06d\n",i+1,people[i].k);
		fprintf(fp,"%06d",people[i].k);
		fprintf(fp,"%c",ch);
		printf("������ֿ�������\n");
		scanf("%s",&people[i].name);
		fprintf(fp,"%s",people[i].name);
		fprintf(fp,"%c",ch);
		printf("���������\n");
		scanf(" %s",zc);
		people[i].j=ffsrf(zc);
		while(people[i].j<0)
		{
			printf("�����벻С�������\n");
			scanf(" %s",zc);
			people[i].j=ffsrf(zc);
		} 
		fprintf(fp,"%lf",people[i].j);
		fprintf(fp,"%c",ch);
		printf("�������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
		scanf("%s",zc);
		people[i].g=ffsri(zc);
		while(people[i].g!=0&&people[i].g!=1)
		{
			printf("���벻�Ϸ�\n�����������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
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
	 		printf("����������\n���������뷹����\n");
	 		scanf(" %s",zc);
	 		q=ffsri(zc); 
		}
	}
	if(people[m].j<5)
	{
	 	printf("���������Ǯ\n");
	}
	if(people[m].j>=5)
	{
	 	c=people[m].j;
	 	if(people[m].g!=0)
		{
	 		printf("�����뷹Ǯ\n");
	 		scanf(" %s",zc);
	 		f=ffsrf(zc);
	 		while(f<=0)
			{
				printf("��������������\n");
				scanf(" %s",zc);
	 			f=ffsrf(zc);
		 	} 
	 		if(people[m].j>=f)
			{
	 			people[m].j=people[m].j-f;
	 			printf("��ǰ���Ϊ%f\n�򷹺����Ϊ%f\n�򷹳ɹ�\n",c,people[m].j);
		 	}
	 		else
	 		printf("����\n");
		}
		else
		printf("�����Ѷ���\n");
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
	 		printf("����������\n���������뷹����\n");
	 		scanf(" %s",zc);
	 		c=ffsri(zc);
		}
	}
	if(people[m].g!=0)
	{
 		b=people[m].j;
 		printf("�������ֵ���\n");
		scanf(" %s",zc);
		cq=ffsrf(zc);
		while(cq<=0)
		{
			printf("��������������\n");
			scanf(" %s",zc);
	 		cq=ffsrf(zc);
		} 
		people[m].j=people[m].j+cq;
		printf("��Ǯ�ɹ�\n��Ǯǰ���Ϊ%f\n��Ǯ�����Ϊ%f\n",b,people[m].j);
	}
	else
	{
	 	printf("�����ѹ�ʧ���޷���Ǯ\n");
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
 		printf("��%d���·���\n������Ϊ%06d\n",i-n+1,people[i].k);
		printf("������ֿ�������\n");
		scanf("%s",&people[i].name);
		printf("���������\n");
		scanf(" %s",zc);
		people[i].j=ffsrf(zc);
		while(people[i].j<0)
		{
			printf("�����벻С�������\n");
			scanf(" %s",zc);
			people[i].j=ffsrf(zc);
		} 
		printf("�������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
		scanf(" %s",zc);
		people[i].g=ffsri(zc);
		while(people[i].g!=0&&people[i].g!=1)
		{
			printf("���벻�Ϸ�\n�����������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
			scanf(" %s",zc);
			people[i].g=ffsri(zc); 
		}
		printf("��ӵ�%d���·����ɹ�\n",i-n+1);
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
		printf("��������ע���ķ�����\n");
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
				printf("ע����%d�žɷ����ɹ�\n",c-z+1);
				break;
			}
			else if(b==people[i].k&&i==n-1)
			{
				n=n-1;
				printf("ע����%d�žɷ����ɹ�\n",c-z+1);
			} 
			else if(b!=people[i].k&&i==n-1)
			{
				printf("���������ڣ�ע����%d�žɷ���ʧ��\n",c-z+1);
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
	 		printf("����������\n");
	 		printf("���������뿨��\n");
	 		scanf(" %s",zc);
	 		s=ffsri(zc);
		}
	}
	if(people[m].g==1)
	printf("�˷�����ǰδ��ʧ\n");
	if(people[m].g==0)
	printf("�˷�����ǰ�ѹ�ʧ\n");
	printf("�������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
	scanf(" %s",zc);
	people[m].g=ffsri(zc);
	while(people[m].g!=0&&people[m].g!=1)
	{
		printf("���벻�Ϸ�\n�����������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
		scanf(" %s",zc);
		people[m].g=ffsri(zc);
	}
	printf("����������ʧ�ɹ�\n"); 
	a=writePeopleToFile("card.txt", people,n);
}
void cx()
{
	int a=5,k,g;
	double j;
	char m[100];
	while (a != 0)
	{
		printf("������ѡ����(0~4)\n\n1--���ݿ��Ų�ѯ\n2--����������ѯ\n3--��������ѯ\n4--���ݹ�ʧ״̬��ѯ\n0--�˳���ѯ\n");
		scanf(" %s",zc);
		a=ffsri(zc);
		switch (a)
		{
			case 1:
				printf("�����뷹����\n"); 
				scanf(" %s",zc);
				k=ffsri(zc);
                cxk(k);
				break;
			case 2:
			    printf("������ֿ�������\n");
				scanf("%s",m);
				cxm(m);
				break;
			case 3:
				printf("���������\n");
				scanf(" %s",zc);
				j=ffsrf(zc);
				while(j<0)
				{
					printf("��������������\n");
					scanf(" %s",zc);
					j=ffsrf(zc);
				}
				cxj(j);
				break;
			case 4:
			    printf("�������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n"); 
			    scanf(" %s",zc);
			    g=ffsri(zc);
			    while(g!=0&&g!=1)
			    {
			    	printf("���벻�Ϸ�\n�����������ʧ״̬��0Ϊ��ʧ��1Ϊ������\n");
					scanf(" %s",zc);
			    	g=ffsri(zc);
				}
			    cxg(g);
			    break;
			case 0:
				printf("�������˳�\n\n");
			    break; 
			default:
				printf("������0~4������\n");
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
	 		printf("����������\n");
	 		printf("���������뿨��\n");
	 		scanf(" %s",zc);
	 		k=ffsri(zc);
		}
	}
	printf("�˷���������Ϊ%s\n",people[m].name);
	printf("�˷������Ϊ%f\n",people[m].j);
	if(people[m].g==1) 
	printf("�˷���δ��ʧ\n");
	if(people[m].g==0)
	printf("�˷����ѹ�ʧ\n");
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
			printf("�����ڶ�Ӧ�����ķ���\n");
			printf("����������ֿ�������\n");
	 		scanf("%s",m);
		}
	} 
	printf("����%d����ѯ���\n",c);
	for(i=0;i<c;i++)
	{
	 	printf("��%d����ѯ���\n",i+1); 
		printf("�˷�������Ϊ%06d\n",b[i].k);
		printf("�˷������Ϊ%f\n",b[i].j);
		if(b[i].g==1) 
		printf("�˷���δ��ʧ\n");
		if(b[i].g==0)
		printf("�˷����ѹ�ʧ\n"); 
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
			printf("��������Ӧ���ķ���\n");
			printf("�������������\n");
			scanf(" %s",zc);
			j=ffsrf(zc);
		}
	 } 
	 printf("����%d����ѯ���\n",c);
	 for(i=0;i<c;i++)
	 {
	 	printf("��%d����ѯ���\n",i+1); 
		printf("�˷�������Ϊ%06d\n",b[i].k);
		printf("�˷���������Ϊ%s\n",b[i].name);
		if(b[i].g==1) 
		printf("�˷���δ��ʧ\n");
		if(b[i].g==0)
		printf("�˷����ѹ�ʧ\n"); 
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
			printf("�����ڴ˹�ʧ״̬�ķ���\n");
			printf("�����������ʧ״̬\n");
			scanf(" %s",zc);
			g=ffsri(zc);
		}
	} 
	printf("����%d����ѯ���\n",c);
	for(i=0;i<c;i++)
	{
	 	printf("��%d����ѯ���\n",i+1); 
		printf("�˷�������Ϊ%06d\n",b[i].k);
		printf("�˷������Ϊ%f\n",b[i].j);
		printf("�˷���������Ϊ%s\n",b[i].name);
	}
}
