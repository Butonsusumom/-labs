/*#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	FILE *f1, *f2;
	char s1[100], s2[100], c, d, my[100];
	int k = 0;

	printf("Plese, enter full way to file1: ");
	//getchar();
	gets(s1);
	//if (symbol_file_exists(s1)) {
	f1 = fopen(s1, "rt");
	if (f1 != NULL) {
		printf("Plese, enter full way to file2: ");
		//getchar();
		gets(s2);
		f2 = fopen(s2, "wt");
		c = ' ';
		while (c != EOF) {
			for (int i = 0; i < k; i++) {
				my[i] = ' ';
			}
			k = 0;
			c = fgetc(f1);
			while ((c != ' ') && (c != EOF)) {
				my[k] = c;
				c = fgetc(f1);
				k++;
			}
			if ((c == ' ') || (c == EOF)) {
				if (atoi(my) % 2 != 0) {
					printf("%d ", atoi(my));
					fprintf(f2, "%d ", atoi(my));
					//fputs(my, f2);
				}
				//c=fgetc(f1);
			}
		}

		fclose(f1);
		fclose(f2);
	}
	else { printf("Such File doesn't exists\n"); }
	system("pause");
	return 0;



	//}

}
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct scores {
	int mathscore;
	int physicsscore;
	int russcore;
};
struct persons {
	char surname[20];
	char address[20];
	struct scores examscore;
	int privatescore;
};
int main()
{
	int i, j;
	system("chcp 1251");
	system("cls");
	struct persons info[10];
	struct persons highinfo[10];
	int averagescore, count, dop;
	struct persons tmp;

	printf("������� ���-�� �����:");
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		printf("���������� � ����� �������� \n");
		printf("������� �������:");
		scanf("%s", info[i].surname);
		getchar();
		printf("������� ����� ����������:");
		scanf("%s", info[i].address);
		getchar();
		printf("������� ���� �� ����������:");
		scanf("%d", &info[i].examscore.mathscore);
		getchar();
		printf("������� ���� �� ������:");
		scanf("%d", &info[i].examscore.physicsscore);
		getchar();
		printf("������� ���� �� ��������:");
		scanf("%d", &info[i].examscore.russcore);
		getchar();
		info[i].privatescore = (info[i].examscore.mathscore + info[i].examscore.physicsscore + info[i].examscore.russcore) / 3;
		printf("������� ����: %d", info[i].privatescore);

		getchar();
		printf("\n");
	}

	averagescore = 0;
	for (i = 0; i < count; i++)
	{
		averagescore = averagescore + info[i].privatescore;
	}
	averagescore = averagescore / count;
	printf("������� ���� �� ������� : %d \n", averagescore);
	getchar();
	printf("\n");
	dop = 0;
	for (i = 0; i < count; i++)
	{
		if (info[i].privatescore >= averagescore)
		{
			highinfo[dop] = info[i];
			dop = dop + 1;
		}

	}

	for (i = 0; i < dop - 1; i++)
	{
		for (j = i + 1; j < dop; j++)
		{
			if (highinfo[i].privatescore < highinfo[j].privatescore)
			{
				tmp = highinfo[i];
				highinfo[i] = highinfo[j];
				highinfo[j] = tmp;
			}
		}


	}

	printf("������ ����� � ��������� ������ \n");
	for (i = 0; i < dop; i++)
	{
		printf(" ������� : %s \n", highinfo[i].surname);
		printf(" ����� ����������:%s \n", highinfo[i].address);
		printf(" ���� �� ����������:%d \n", highinfo[i].examscore.mathscore);
		printf(" ���� �� ������:%d  \n", highinfo[i].examscore.physicsscore);
		printf(" ���� �� ��������:%d \n", highinfo[i].examscore.russcore);
		printf(" ������� ����:%d \n", highinfo[i].privatescore);
		printf("\n");
	}
	getchar();
	return 0;
}