#define _CRT_SECURE_NO_WARNINGS	// scanf 반환값 무시

#include<stdio.h>
int low_pressure();	// 주택용 전력 (저압)
int high_pressure();	// 주택용 전력 (고압)
int normal();		// 일반용전력

int main(void) {
	int num = 0;

	printf("\n********** 전기 요금 계산기 **********\n\n\n");
	printf("1. 주택용 전력(저압)\n");
	printf("2. 주택용 전력(고압)\n");
	printf("3. 일반용전력\n");
	printf("0. 종료\n");
	printf("\n>>> ");
	scanf("%d", &num);
	printf("\n");

	switch (num)
	{
	case 1:
		low_pressure();
		break;

	case 2:
		high_pressure();
		break;
	case 3:
		normal();
		break;
	case 0:
		return 0;
	}
}



int low_pressure() // 주택용 전력 (저압)
{
	double wattage = 0;			// 전력량
	double total = 0;				// 요금
	int ck = 0;					// 종료 확인

	printf("          [주택용 전력(저압) 요금 계산 방식]\n\n");
	printf("     기본 요금(원)               전력량 요금(원/kwh)\n\n");
	printf("     200kwh 이하 사용 -> 910     처음 200kwh까지 -> 93.3\n");
	printf("     201~400kwh 사용 -> 1,600    다음 200kwh까지 -> 187.9\n");
	printf("     400kwh 초과 사용 -> 7,300   400kwh 초과 -> 280.6\n\n");

	printf("내가 사용한 전력량 : ");
	scanf("%lf", &wattage);

	if (wattage <= 200) {								// 요금 계산
		total += 910 + (wattage * 93.3);
	}
	else if (wattage <= 400) {
		total += 1600 + (200 * 93.3) + ((wattage - 200) * 187.9);
	}
	else {
		total += 7300 + (200 * 93.3) + (200 * 187.9) + ((wattage - 400) * 280.6);
	}

	printf("\n");
	printf("요금 : % .0lf(원) \n\n", total);			// 요금 출력

	printf("1. 계속\n");
	printf("0. 종료\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// 종료 확인
		main();
	}

	return 0;
}



int high_pressure() // 주택용 전력 (고압)
{
	double wattage = 0;				// 전력량
	double total = 0;				// 요금
	int ck = 0;						// 종료 확인

	printf("          [주택용 전력(고압) 요금 계산 방식]\n\n");
	printf("     기본 요금(원)               전력량 요금(원/kwh)\n\n");
	printf("     200kwh 이하 사용 -> 730     처음 200kwh까지 -> 78.3\n");
	printf("     201~400kwh 사용 -> 1,260    다음 200kwh까지 -> 147.3\n");
	printf("     400kwh 초과 사용 -> 6,060   400kwh 초과 -> 215.6\n\n");

	printf("내가 사용한 전력량 : ");
	scanf("%lf", &wattage);

	if (wattage <= 200) {								// 요금 계산
		total += 730 + (wattage * 78.3);
	}
	else if (wattage <= 400) {
		total += 1260 + (200 * 78.3) + ((wattage - 200) * 147.3);
	}
	else {
		total += 6060 + (200 * 78.3) + (200 * 147.3) + ((wattage - 400) * 215.6);
	}

	printf("\n");
	printf("요금 : %.0lf(원) \n\n", total);				// 요금 출력

	printf("1. 계속\n");								
	printf("0. 종료\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// 종료 확인
		main();
	}

	return 0;
}



int normal()		// 일반용전력
{
	double wattage = 0;		// 전력량
	double total = 0;		// 요금
	int season = 0;			// 계절
	int ck = 0;				// 종료 확인

	printf("               [일반용 전력]\n\n");
	printf("     기본 요금(원)               전력량 요금(계절별로 다름)\n\n");
	printf("     6,160 (고정)                여름철 (6~8) -> 105.7\n");
	printf("     6,160 (고정)                봄, 가을철 (3~5, 9~10) -> 65.2\n");
	printf("     6,160 (고정)                겨울철 (11~2) -> 92.3\n\n");

	printf("     1. 봄   (3~5)\n");
	printf("     2. 여름 (6~8)\n");
	printf("     3. 가을 (9~10)\n");
	printf("     4. 겨울 (11~2)\n");

	printf("\n");
	printf("계산 할 계절 : ");				
	scanf("%d", &season);
	printf("\n");

	printf("내가 사용한 전력량 : ");
	scanf("%lf", &wattage);

	if (6 <= season <= 8) {								// 요금 계산
		total += 6160 + (wattage * 105.7);				// 여름
	}
	else if (3 <= season <= 5 || 9 <= season <= 10) {	// 봄, 가을
		total += 6160 + (wattage * 92.3);
	}
	else {												// 겨울
		total += 6160 + (wattage * 65.2);
	}

	printf("\n");
	printf("요금 : %.0lf(원) \n\n", total);				// 요금 출력

	printf("1. 계속\n");
	printf("0. 종료\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// 종료 확인
		main();
	}

	return 0;
}
