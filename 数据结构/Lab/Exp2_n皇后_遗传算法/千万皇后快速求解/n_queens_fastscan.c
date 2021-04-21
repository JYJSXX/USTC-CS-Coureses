#include<stdio.h>
#include<time.h>
int* series_init(int n){//��ʼ��1-n���� 
	int* series=(int*)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++){
		series[i]=i;
	}
	return series;
}
void swap(int* a,int* b){//����ֵ 
	int c=*a;
	*a=*b;
	*b=c;
}
void series_shuffle(int* series,int n){//��������� 
	int i;
	for(i=0;i<n;i++){
		swap(&series[i],&series[randInt(i)]);
	}
}
int randInt(int i){//���������(0-i) 
	return ((rand()<<15)+rand())%(i+1);
}
int printP(int * panel,int n){//��ӡ����(ʹ������java����) 
	int i;
	FILE *fp = NULL;
    fp = fopen("tmp.txt", "w+");
    fprintf(fp,"%d",n);
    for(i=0;i<n;i++)
	    fprintf(fp,"\n%d",panel[i]);
	fclose(fp);
	system("java -jar chessprt.jar");
	system("tmp.jpg");
}
int printPs(int * panel,int n){//���ַ���ӡ���� 
	int i,j;
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
	   	if(j==panel[i])printf("1");
	   	else printf("0");
		}
		printf("\n");
	}
}

int main(){
	int n=8;
	printf("Input for n:>");
	scanf("%d",&n);
	int *diaX;//�Խ���һ 
	int *diaY;//�Խ��߶�,��¼�Խ����ϵ����Ӹ��� 
	clock_t start,end; //��ʱ 
	diaX=(int *)malloc((2*n-1)*sizeof(int));
	diaY=(int *)malloc((2*n-1)*sizeof(int));
	int i,j,p,q;
	int crash=0;//�Խ����ϵ���ײ�������� 
	int restartC=0;//������������ 
	int deltax=0;//��ʱ��ײ�ı� 
	int crashcount;//�Խ����ϴ���һ�����ϵ��λ�õļ��� 
	start =clock();
	int *panel=series_init(n);//��ʼ������,�����ó���Ϊn������,ÿ������Ψһ��0~n-1�����ֱ�ʾ����λ��,������û�����м����ײ,ֻҪ�����Խ����ϵ���ײ 
	series_shuffle(panel,n);//�����ʼ������ 
	for(i=0;i<2*n-1;i++){//��ʼ���Խ��߼��� 
	   diaX[i]=0;
	   diaY[i]=0;
	}
	for(i=0;i<n;i++){//����Խ��������Ӹ���
	 	diaX[panel[i]-i+n-1]++; 
		diaY[i+panel[i]]++;
	}
	for(i=0;i<2*n-1;i++){//����Խ�����ײ���� 
		crash+=diaX[i]*(diaX[i]-1)/2;
		crash+=diaY[i]*(diaY[i]-1)/2;
	}
	while(crash>0){//һֱ���� ,ֱ���½�����ײ����Ϊ0 
		crashcount=0;
		for(p=0;p<n;p++)
			if(diaX[panel[p]-p+n-1]>1||diaY[panel[p]+p]>1)
			{
				crashcount++;
				for(q=n-1;q>=0;q--){
					if(q!=p){//�öԽ��߼�����ײ��ʱ�ı� 
						deltax=0;
						deltax-=diaX[panel[p]-p+n-1]-1;
						deltax-=diaY[panel[p]+p]-1;
						deltax-=diaX[panel[q]-q+n-1]-1;
						deltax-=diaY[panel[q]+q]-1;
						deltax+=diaX[panel[q]-p+n-1];
						deltax+=diaY[panel[q]+p];
						deltax+=diaX[panel[p]-q+n-1];
						deltax+=diaY[panel[p]+q];
						if(panel[p]+q==panel[q]+p||panel[p]+p==panel[q]+q)deltax+=2;//���p,q���ӱ������һ���Խ�����,�������һ��2�����,���� 
						if(deltax<0){//����½��˾�Ӧ�ý��� 
							crash+=deltax;
							diaX[panel[p]-p+n-1]--;
							diaY[panel[p]+p]--;
							diaX[panel[q]-q+n-1]--;
							diaY[panel[q]+q]--;
							diaX[panel[q]-p+n-1]++;
							diaY[panel[q]+p]++;
							diaX[panel[p]-q+n-1]++;
							diaY[panel[p]+q]++;
							swap(panel+p,panel+q);
							break;
						}
					}
				}
			}
		restartC+=crashcount;
		if(restartC>n*50){//������δ�ɹ�,�������ʼ��(��ʵ��ֻ�ڽ�С��ģʱ���ܴ���) 
			restartC=0;
			series_shuffle(panel,n);
			crash=0;
			for(i=0;i<2*n-1;i++){
	  			diaX[i]=0;
	  			diaY[i]=0;
			}
			for(i=0;i<n;i++){
				diaX[panel[i]-i+n-1]++; 
				diaY[i+panel[i]]++;
			}
			for(i=0;i<2*n-1;i++){
				crash+=diaX[i]*(diaX[i]-1)/2;
				crash+=diaY[i]*(diaY[i]-1)/2;
			}
		}
	}
	end=clock();
	if(n<=100)printP(panel,n);//�Խ�С���̴�ӡ��� 
	printf("Time:%d ms\n",end-start);
	scanf("%d",&i);
	return 114514;
}

