#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//看版本添加(bool类型) 
//日历显示 calendar
 
//声明所有用到的函数
void printMonth(int, int);
void printMonthTitle(int, int);
void printMonthBody(int, int);
int getStartDay(int, int);
int getTotalNumOfDays(int, int); 
int getNumOfDaysInMonth(int, int); 
bool isLeapYear(int);

bool isLeapYear(int year) {
	return (year%400==0) || (year%4==0 &&year%100!=0);
}
int getNumOfDaysInMonth(int year, int month) {
	if(month==1 || month==3 || month==5 || month==7 || month==8
	|| month==10 || month==12) {
		return 31;
	}
	if(month==4 || month==6 || month==9 || month==11) {
		return 30;
	}
	if(month==2) {
		return isLeapYear(year)? 29: 28;
	}
	return 0;
}
int getTotalNumOfDays(int year, int month) {
	int i, total=0;
	for(i=1800; i<year; i++) {
		if(isLeapYear(i)) {
			total += 366;
		} else {
			total += 365;
		}
	}
	for(i=1; i<month; i++) {
		total += getNumOfDaysInMonth(year, i);
	}
	return total;
}
int getStartDay(int year, int month) {
	int week;
	const int START_DAY_FOR_JAN_1_1800 = 3;
	int totalNumOfDays = getTotalNumOfDays(year, month);
	return (totalNumOfDays+START_DAY_FOR_JAN_1_1800)%7;
}
void printMonthBody(int year, int month) {
	int startDay = getStartDay(year, month);
	int numOfDaysInMonth = getNumOfDaysInMonth(year, month);
	int i=0;
	for(i=0; i<startDay; i++) {
		printf("    ");
	}
	for(i=1; i<=numOfDaysInMonth; i++) {
		printf("%4d", i);
		if( (i+startDay) %7==0) {
			printf("\n");
		}
	}
}
void printMonthTitle(int year, int month) {
	printf("\n        %d 年 %d 月\n", year, month);
	printf("-----------------------------\n");
	printf("  日  一  二  三  四  五  六\n"); 
}
void printMonth(int year, int month) {
	printMonthTitle(year, month);
	printMonthBody(year, month);
}
int main(int argc, char *argv[]) {
	int year, month;
	printf("请输入一个年份(例如:2021):");
	scanf("%d", &year);
	printf("请输入一个月份(例如:10):"); 
	scanf("%d", &month);
	printMonth(year, month);
	return 0;
}

