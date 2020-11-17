/*统计字符串数组中的词频*/
#define _CRT_SECURE_NO_DEPRECAT
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 10000

typedef struct {
	char ss[30];
	int count;
}Word;

Word w[500];
int m = 0;//m用来记录w数组中元素的个数

void Print(char* A) {//打印字符串数组
	int i = 0;
	while (A[i] != '\0') {
		printf("%c", A[i++]);
	}
}

int Count(char* A) {
	int i = 0;
	while (A[i] != '\0') {
		i++;
	}
	return i;
}

int Judge(char a) {
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
		return 1;
	}
	else return 0;
}

void main(void) {
	char A[N] = { "There were a sensitivity and a beauty to her that have nothing to do with looks. She was one to be listened to, whose words were so easy to take to heart. It is said that the true nature of being is veiled.The labor of words, the expression of art, the seemingly ceaseless buzz that is human thought all have in common the need to get at what really is so.The hope to draw close toand possess the truth of being can be a feverish one.In some cases it can even be fatal, if pleasure is one's truth and its attainment more important than life itself. In other lives, though, the search for what is truthful gives life. I used to find notes left in the collection basket, beautiful notes about my homiliesand about the writer's thoughts on the daily scriptural readings. The person who penned the notes would add reflections to my thoughts and would always include some quotes from poets and mystics he or she had read and remembered and loved. The notes fascinated me. Here was someone immersed in a search for truth and beauty. Words had been treasured, words that were beautiful. And I felt as if the words somehow delighted in being discovered, for they were obviously very generous to the as yet anonymous writer of the notes. And now this person was in turn learning the secret of sharing them. Beauty so shines when given away. The only truth that exists is, in that sense, free.It was a long time before I met the author of the notes." };
	Print(A);

	for (int i = 0; i < Count(A); i++) {
		char s[30];
		int j = 0;
		while (Judge(A[i])) {
			s[j++] = A[i++];
		}
		s[j] = '\0';
		int k;
		if (s[0]) {
			for (k = 0; k < m; k++) {
				if (!strcmp(w[k].ss, s)) {
					w[k].count++;
					break;
				}
			}
			if (k == m) {
				strcpy(w[m].ss, s);
				w[m++].count = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%s %d\n", w[i].ss, w[i].count);
	}
}