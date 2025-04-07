#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Finds starting indices of substrings in `s` that are
 * concatenations of `words`.
 * @s: input string.
 * @words: array of words.
 * @nb_words: number of words.
 * @n: pointer to int.
 * Return: array of starting indices of substrings or NULL.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	int word_len = strlen(words[0]);
	int total_len = word_len * nb_words, s_len = strlen(s);
	int *result = malloc(sizeof(int) * s_len), count = 0;

	if (!result)
		return (NULL);

	for (int i = 0; i <= s_len - total_len; i++)
	{
		int found[nb_words], j = 0;

		memset(found, 0, sizeof(found));
		for (; j < nb_words; j++)
		{
			char temp[word_len + 1];

			strncpy(temp, s + i + j * word_len, word_len);
			temp[word_len] = '\0';

			int k = 0;

			for (; k < nb_words; k++)
			{
				if (!found[k] && strcmp(temp, words[k]) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			result[count++] = i;
	}
	*n = count;
	return (count ? realloc(result, sizeof(int) * count) : (free(result), NULL));
}
