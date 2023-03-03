#include <iostream>
#include <bits/stdc++.h>

/*
 * 구현 문제
 *
 * 문제에서 주어진 단계에 맞게 구현하면 끝.
 */

using namespace std;

int n;
// 문자열의 끝에 null을 위해 + 1
char words[30][5][10 + 1];
bool is_shortcut[30][5][10];
int word_cnts[30];
bool is_used[26];

bool step_1_ret_is_entry(int i)
{
	for (int j = 0; j < word_cnts[i]; j++)
	{
		char upper = toupper(words[i][j][0]) - 'A';
		if (is_used[upper])
			continue;
		is_used[upper] = true;
		return is_shortcut[i][j][0] = true;
	}
	return false;
}

void step_2(int i)
{
	for (int j = 0; j < word_cnts[i]; j++)
		for (int k = 0; words[i][j][k]; k++)
		{
			char upper = toupper(words[i][j][k]) - 'A';
			if (is_used[upper] == false)
			{
				is_used[upper] = true;
				is_shortcut[i][j][k] = true;
				return;
			}
		}
}

void make_shortcut()
{
	for (int i = 0; i < n; i++)
	{
		if (step_1_ret_is_entry(i))
			continue;
		step_2(i);
	}
}

void print_words()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < word_cnts[i]; j++)
		{
			for (int k = 0; words[i][j][k]; k++)
				if (is_shortcut[i][j][k])
					printf("[%c]", words[i][j][k]);
				else
					putchar(words[i][j][k]);

			if (j < word_cnts[i] - 1)
				putchar(' ');
			else
				putchar('\n');
		}
}

void solution()
{
	make_shortcut();
	print_words();
}

void input()
{
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		char c;
		int j = 0;
		int len = 0;

		while (1)
		{
			scanf("%c", &c);
			if (c == '\n' || c == '\0')
			{
				words[i][j][len] = '\0';
				break;
			}

			if (c == ' ')
			{
				words[i][j][len] = '\0';
				len = 0;
				j++;
				continue;
			}
			words[i][j][len] = c;
			len++;
		}
		word_cnts[i] = j + 1;
	}
}

int main()
{
	input();
	solution();
}
