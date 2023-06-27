#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int SUBJECT_NUMS = 20;

float convertGrade(const char grade[3])
{
	if (strcmp(grade, "A+") == 0)
		return 4.5;
	else if (strcmp(grade, "A0") == 0)
		return 4.0;
	else if (strcmp(grade, "B+") == 0)
		return 3.5;
	else if (strcmp(grade, "B0") == 0)
		return 3.0;
	else if (strcmp(grade, "C+") == 0)
		return 2.5;
	else if (strcmp(grade, "C0") == 0)
		return 2.0;
	else if (strcmp(grade, "D+") == 0)
		return 1.5;
	else if (strcmp(grade, "D0") == 0)
		return 1.0;
	else
		return 0;
}


int main()
{
	char subject[51];
	float credit;
	char grade[3];
	float total_credit = 0;
	float total_grade = 0;
	float avearge_credit = 0;

	for (int i = 0; i < SUBJECT_NUMS; i++)
	{
		cin >> subject >> credit >> grade;
		if (strcmp(grade, "P") == 0)
			continue;
		total_credit += credit;
		total_grade += credit * convertGrade(grade);
	}

	avearge_credit = total_grade / total_credit;
	printf("%.6f", avearge_credit);

	return 0;
}
