#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void make(int year, int month);
int yoon(int year); //���� �Ǻ��Լ�
int start_day(int year, int month); //�ش� �⵵�� ���� ������ ã�� �Լ�
int total_lastdays(int year); //1970����� �ش�⵵������ �� �ϼ��� ��Ÿ����.
int find_total_day(int year); //�ش� �⵵�� �� �ϼ��� ���Ѵ�.
int total_lastdays_month(int year, int month); //�ش�⵵ ���� �����ޱ��� �ϼ��� ���Ѵ�.
void make_calendar(int year, int month, int day_today); //�޷�����Լ�.

int main()
{
	//�������� �޷����

	int year; //�⵵�� ��Ÿ���� ����. ��
	int month; //���� ��Ÿ���� ����. ��

	printf("�� ���� �Է��ϼ���: \n");
	scanf("%d %d", &year, &month);

	make(year, month);

	return 0;
}

//�޷¸���� �����ִ� �Լ�
void make(int year, int month) {
	//printf("%d�� %d��\n", year, month);

	int day_today = start_day(year, month);
	//printf("���ۿ��� = %d����\n", day_to_day);
	make_calendar(year, month, day_today);
}

//Ư�� ������ ���� �����ϴ� ������ ���ϴ� �Լ�.
//������ 0 ~ 6 �� ������ ��Ÿ����.
int start_day(int year, int month) {
	//1970�⵵���� �����⵵ ���� ���� ��� ���Ѵ�.
	int lastdays = total_lastdays(year - 1);


	//���� �⵵���� �����ޱ����� ���� ��� ���Ѵ�.
	int lastdays1 = total_lastdays_month(year, month);

	int total = lastdays + lastdays1 + 4; //������� ���Ѵ�.

	int day_today = total % 7;

	return day_today;
}

//1970�⵵���� �����⵵ ���� ���� �����ִ� �Լ�
int total_lastdays(int year) {
	int total = 0;

	for (int y = 1970; y <= year; y++) {
		total += find_total_day(y);
	}

	return total;
}

//�ش�⵵�� �� �ϼ�
int find_total_day(int year) {

	//�����̸� return���� 366��, ����̸� 365��
	if (yoon(year)) {
		return 366;
	}
	else {
		return 365;
	}
}

//������ �Ǻ��ϴ� �Լ�. return���� 1�̸� ����, 0�̸� ���
int yoon(int y) {
	//4�� ���������� �ʴ� �⵵
	if (y % 4 != 0) {
		return 0;
	}
	//4�� ��������
	if (y % 100 != 0) {
		return 1;
	}
	//100���� ��������
	if (y % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int total_lastdays_month(int year, int month) {
	int total_month[12] = { 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;

	//�����϶� 2���� ��Ȳ�� �ϼ� ���ϱ� 29�� or 28��
	for (int m = 0; m < month - 1; m++) {
		if (m == 1 && yoon(year)) {
			sum += 29;
		}
		else {
			sum += total_month[m];
		}
	}
	return sum;
}

//�޷����
void make_calendar(int year, int month, int day_today) {
	printf(" �� �� ȭ �� �� �� ��\n");
	int total_month[12] = { 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
	
	for (int d = 0; d < day_today; d++) {
		printf("   ");
	}

	int this_month_days = total_month[month - 1];
	if (yoon(year) && month == 2) {
		this_month_days = 29;
	}

	for (int d = 1; d <= this_month_days; d++) {
		if ((day_today + d - 1) % 7 == 0) {
			printf("\n");
		}
		printf("%3d", d);
	}

	/*
	for (int d = 0; d < 6 - day_today - 1; d++) {
		printf("  *");
	}
	*/
}