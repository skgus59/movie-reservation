#include<stdio.h>
#include<stdlib.h>
void RG(int a[4][4],int b[4][4]);
void Multiple(int a[4][4], int b[4][4]);
int main(void){
	int first[4][4];
	int second[4][4];
	int  p;
	while(1){
		for (int i=0;i<24;i++)
			printf("*");
		printf("\n");
		printf("1. Random Generation\n");
		printf("2. Multiplication\n");
		printf("3. exit\n");
		for (int i=0;i<24;i++)
			printf("*");
		printf("\n");
		scanf("%d", &p);
		if (p==1)
			RG(first, second);
		else if (p==2)
			Multiple(first, second);
		else if (p==3)
			exit(0);
		else
			printf("Wrong number\n");
	}
	return 0;
}

void RG(int a[4][4], int b[4][4]){
   for(int i=0;i<4;i++){
		for(int j=0; j<4;j++){
			a[i][j]=random()%101;
			printf("%3d ",a[i][j]);
		}
		printf("        ");
		for(int k=0; k<4;k++){
			b[i][k]=random()%101;
			printf("%3d  ",b[i][k]);
		}
		printf("\n");
	}
}

void Multiple(int a[4][4], int b[4][4]){
	int third[4][4];
	int i, j;
	for(int i=0;i<4;i++){
		for (int j=0; j<4; j++){
			third[i][j]=a[i][j]*b[i][j];
			printf("%6d ", third[i][j]);
		}
		printf("\n");
	}
}
