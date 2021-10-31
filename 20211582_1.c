#include <stdio.h>
#include <stdlib.h>
void seatstatus(int a[10][10]);
void reservation();
void cancel();
void stop();
int p,q;
int seat[10][10] = { 0 };
int main(void){
	int a;
	while(1){
		printf("\n");
		printf("[1] 예약        [2] 취소        [3] 현황        [4] 종료        \n");
		printf("메뉴 선택 : ");
		scanf("%d",&a);
		if (a==1)   
			reservation();
		else if (a==2)
			cancel();
		else if (a==3)
			seatstatus(seat);
		else if (a == 4) {
			stop();
		}
		else
			printf("Wrong number\n");
	}
	return 0;
}

void seatstatus(int a[10][10]){
	for (int i=0;i<61;i++)
		printf("=");
	printf("\n");
	printf("     1    2    3    4    5    6    7    8    9    10         \n");
	for (int i = 0; i < 10; i++) {
		if (i == 9)
			printf("%d   ", i + 1);
		else
			printf("%d    ", i + 1);
		for (int j=0;j<10;j++){
			printf("%d    ", seat[i][j]);
		}
		printf("\n");
	}
	for (int i=0;i<61;i++)
		printf("-");
	printf("\n");
	printf("\n");
	for (int i = 0; i < 61; i++)
		printf("=");
	printf("\n");
}

void stop(){
	printf("프로그램을 종료합니다.");
	printf("\n");
	exit(0);
}

void reservation(){
	seatstatus(seat);
	printf("예약할 좌석의 가로 번호 : ");
	scanf("%d", &q);
	printf("예약할 좌석의 세로 번호 : ");
	scanf("%d", &p);
	if ((p < 11) & (q < 11)) {
		if (seat[p - 1][q - 1] == 0) {
			if ((seat[p - 2][q - 2] == 1) || (seat[p - 2][q - 1] == 1) || (seat[p - 1][q - 2] == 1) || (seat[p][q - 1] == 1) || (seat[p - 1][q] == 1) || (seat[p - 2][q] == 1) || (seat[p][q - 2] == 1) || (seat[p][q] == 1)) {
				printf("해당 좌석은 사회적 거리두기로 인해 예매할 수 없습니다.\n");
			}
			else
				seat[p - 1][q - 1] = 1;
		}
		else if (seat[p - 1][q - 1] == 1)
			printf("해당 좌석은 이미 예약되어있습니다.\n");
	}
	else
		printf("해당 좌석은 존재하지 않습니다.\n");
}

void cancel(){
	seatstatus(seat);
	printf("취소할 좌석의 가로 번호 : ");
	scanf("%d", &q);
	printf("취소할 좌석의 세로 번호 : ");
	scanf("%d", &p);
	if ((p < 11) & (q < 11)) {
		if (seat[p - 1][q - 1] == 1)
			seat[p - 1][q - 1] = 0;
		else if (seat[p - 1][q - 1] == 0)
			printf("해당 좌석은 이미 취소되어 있습니다.\n");
	}
	else
		printf("해당 좌석은 존재하지 않습니다.\n");
}
