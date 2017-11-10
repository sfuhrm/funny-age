/*
 * age.c
 *
 *  Created on: 10.11.2017
 *      Author: Stephan Fuhrmann
 */

#define _XOPEN_SOURCE
#include<stdio.h>
#include<string.h>
#include<time.h>

char *wdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday" };

#define SECS_PER_DAY (60 * 60 * 24)

int main(int argc, char **argv) {
	char birthday_string[32];
	struct tm birthday_broken_time;
	time_t birthday_time_t;
	time_t now_time_t;
	memset((void *) &birthday_broken_time, 0, sizeof(birthday_broken_time));

	printf("Enter your data of birth in format YYYY-MM-DD: ");
	scanf("%s", birthday_string);

	strptime(birthday_string, "%Y-%m-%d", &birthday_broken_time);

	printf("Your birthday is %04d-%02d-%02d\n", birthday_broken_time.tm_year + 1900,
			birthday_broken_time.tm_mon + 1, birthday_broken_time.tm_mday);
	printf("This was a %s\n", wdays[birthday_broken_time.tm_wday]);

	birthday_time_t = mktime(&birthday_broken_time);
	now_time_t = time(NULL);

	double diff_seconds = difftime(now_time_t, birthday_time_t);
	printf("Your age is %g days\n", diff_seconds / SECS_PER_DAY);

	return 0;
}
