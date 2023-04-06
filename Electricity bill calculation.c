#define _CRT_SECURE_NO_WARNINGS	// scanf ��ȯ�� ����

#include<stdio.h>
int low_pressure();	// ���ÿ� ���� (����)
int high_pressure();	// ���ÿ� ���� (���)
int normal();		// �Ϲݿ�����

int main(void) {
	int num = 0;

	printf("\n********** ���� ��� ���� **********\n\n\n");
	printf("1. ���ÿ� ����(����)\n");
	printf("2. ���ÿ� ����(���)\n");
	printf("3. �Ϲݿ�����\n");
	printf("0. ����\n");
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



int low_pressure() // ���ÿ� ���� (����)
{
	double wattage = 0;			// ���·�
	double total = 0;				// ���
	int ck = 0;					// ���� Ȯ��

	printf("          [���ÿ� ����(����) ��� ��� ���]\n\n");
	printf("     �⺻ ���(��)               ���·� ���(��/kwh)\n\n");
	printf("     200kwh ���� ��� -> 910     ó�� 200kwh���� -> 93.3\n");
	printf("     201~400kwh ��� -> 1,600    ���� 200kwh���� -> 187.9\n");
	printf("     400kwh �ʰ� ��� -> 7,300   400kwh �ʰ� -> 280.6\n\n");

	printf("���� ����� ���·� : ");
	scanf("%lf", &wattage);

	if (wattage <= 200) {								// ��� ���
		total += 910 + (wattage * 93.3);
	}
	else if (wattage <= 400) {
		total += 1600 + (200 * 93.3) + ((wattage - 200) * 187.9);
	}
	else {
		total += 7300 + (200 * 93.3) + (200 * 187.9) + ((wattage - 400) * 280.6);
	}

	printf("\n");
	printf("��� : % .0lf(��) \n\n", total);			// ��� ���

	printf("1. ���\n");
	printf("0. ����\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// ���� Ȯ��
		main();
	}

	return 0;
}



int high_pressure() // ���ÿ� ���� (���)
{
	double wattage = 0;				// ���·�
	double total = 0;				// ���
	int ck = 0;						// ���� Ȯ��

	printf("          [���ÿ� ����(���) ��� ��� ���]\n\n");
	printf("     �⺻ ���(��)               ���·� ���(��/kwh)\n\n");
	printf("     200kwh ���� ��� -> 730     ó�� 200kwh���� -> 78.3\n");
	printf("     201~400kwh ��� -> 1,260    ���� 200kwh���� -> 147.3\n");
	printf("     400kwh �ʰ� ��� -> 6,060   400kwh �ʰ� -> 215.6\n\n");

	printf("���� ����� ���·� : ");
	scanf("%lf", &wattage);

	if (wattage <= 200) {								// ��� ���
		total += 730 + (wattage * 78.3);
	}
	else if (wattage <= 400) {
		total += 1260 + (200 * 78.3) + ((wattage - 200) * 147.3);
	}
	else {
		total += 6060 + (200 * 78.3) + (200 * 147.3) + ((wattage - 400) * 215.6);
	}

	printf("\n");
	printf("��� : %.0lf(��) \n\n", total);				// ��� ���

	printf("1. ���\n");								
	printf("0. ����\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// ���� Ȯ��
		main();
	}

	return 0;
}



int normal()		// �Ϲݿ�����
{
	double wattage = 0;		// ���·�
	double total = 0;		// ���
	int season = 0;			// ����
	int ck = 0;				// ���� Ȯ��

	printf("               [�Ϲݿ� ����]\n\n");
	printf("     �⺻ ���(��)               ���·� ���(�������� �ٸ�)\n\n");
	printf("     6,160 (����)                ����ö (6~8) -> 105.7\n");
	printf("     6,160 (����)                ��, ����ö (3~5, 9~10) -> 65.2\n");
	printf("     6,160 (����)                �ܿ�ö (11~2) -> 92.3\n\n");

	printf("     1. ��   (3~5)\n");
	printf("     2. ���� (6~8)\n");
	printf("     3. ���� (9~10)\n");
	printf("     4. �ܿ� (11~2)\n");

	printf("\n");
	printf("��� �� ���� : ");				
	scanf("%d", &season);
	printf("\n");

	printf("���� ����� ���·� : ");
	scanf("%lf", &wattage);

	if (6 <= season <= 8) {								// ��� ���
		total += 6160 + (wattage * 105.7);				// ����
	}
	else if (3 <= season <= 5 || 9 <= season <= 10) {	// ��, ����
		total += 6160 + (wattage * 92.3);
	}
	else {												// �ܿ�
		total += 6160 + (wattage * 65.2);
	}

	printf("\n");
	printf("��� : %.0lf(��) \n\n", total);				// ��� ���

	printf("1. ���\n");
	printf("0. ����\n\n");

	printf(">>> ");
	scanf("%d", &ck);

	if (ck) {											// ���� Ȯ��
		main();
	}

	return 0;
}
