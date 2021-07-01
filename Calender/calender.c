#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void make(int year, int month);
int yoon(int year); //윤년 판별함수
int start_day(int year, int month); //해당 년도의 월의 요일을 찾는 함수
int total_lastdays(int year); //1970년부터 해당년도까지의 총 일수를 나타낸다.
int find_total_day(int year); //해당 년도의 총 일수를 구한다.
int total_lastdays_month(int year, int month); //해당년도 달의 이전달까지 일수를 구한다.
void make_calendar(int year, int month, int day_today); //달력출력함수.

int main()
{
	//최종버전 달력출력

	int year; //년도를 나타내는 변수. 년
	int month; //달을 나타내는 변수. 월

	printf("연 월을 입력하세요: \n");
	scanf("%d %d", &year, &month);

	make(year, month);

	return 0;
}

//달력모양을 보여주는 함수
void make(int year, int month) {
	//printf("%d년 %d월\n", year, month);

	int day_today = start_day(year, month);
	//printf("시작요일 = %d요일\n", day_to_day);
	make_calendar(year, month, day_today);
}

//특정 연도와 달의 시작하는 요일을 구하는 함수.
//요일은 0 ~ 6 의 정수로 나타낸다.
int start_day(int year, int month) {
	//1970년도부터 지난년도 까지 날을 모두 더한다.
	int lastdays = total_lastdays(year - 1);


	//오는 년도에서 지난달까지의 날을 모두 더한다.
	int lastdays1 = total_lastdays_month(year, month);

	int total = lastdays + lastdays1 + 4; //목요일을 더한다.

	int day_today = total % 7;

	return day_today;
}

//1970년도부터 지난년도 까지 날을 보여주는 함수
int total_lastdays(int year) {
	int total = 0;

	for (int y = 1970; y <= year; y++) {
		total += find_total_day(y);
	}

	return total;
}

//해당년도의 총 일수
int find_total_day(int year) {

	//윤년이면 return값이 366일, 평년이면 365일
	if (yoon(year)) {
		return 366;
	}
	else {
		return 365;
	}
}

//윤년을 판별하는 함수. return값이 1이면 윤년, 0이면 평년
int yoon(int y) {
	//4로 나누어지지 않는 년도
	if (y % 4 != 0) {
		return 0;
	}
	//4로 나누어짐
	if (y % 100 != 0) {
		return 1;
	}
	//100으로 나누어짐
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

	//윤년일때 2월의 상황별 일수 더하기 29일 or 28일
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

//달력출력
void make_calendar(int year, int month, int day_today) {
	printf(" 일 월 화 수 목 금 토\n");
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