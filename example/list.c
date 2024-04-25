#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct listnode
{
	struct listnode *next;
	int val;
};

struct listnode *createlist(int a[], int n)
{
	struct listnode *head = NULL, *cur = NULL;
	for (int i = 0; i < n; i++)
	{
		if (head == NULL)
		{
			head = cur = (struct listnode *)calloc(1, sizeof(struct listnode));
			head->val = a[i];
		}
		else
		{
			cur->next = (struct listnode *)calloc(1, sizeof(struct listnode));
			cur = cur->next;
			cur->val = a[i];
		}
	}
	cur = NULL;
	return head;
}

void printlist(struct listnode *p)
{
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void delist(struct listnode *l)
{
	struct listnode *cu = NULL;
	while (l != NULL)
	{
		cu = l;
		free(cu);
		l = l->next;
	}
	l = NULL;
}

// merge 2 sorted lists into one list
struct listnode *merge2(struct listnode *l, struct listnode *r)
{
	struct listnode dumph = {.val = 0, .next = NULL}, *cur = &dumph;
	while (l && r)
	{
		if (l->val < r->val) // asic
		{
			cur->next = l;
			l = l->next;
		}
		else
		{
			cur->next = r;
			r = r->next;
		}
		cur = cur->next;
	}
	cur->next = (l != NULL ? l : r);
	cur = l = r = NULL;
	return dumph.next;
}

struct listnode *sortl(struct listnode *hh)
{
	if (hh == NULL || hh->next == NULL)
		return hh;

	// find middle node and split list
	struct listnode *f = hh, *s = hh, *p = hh;
	while (f && f->next)
	{
		p = s;
		f = f->next->next;
		s = s->next;
	}
	p->next = NULL; // split list into 2 lists
	f = p = NULL;
	return merge2(sortl(hh), sortl(s));
}

void helper(char *res, size_t len, size_t idx);
int hamingw(int a)
{
	int res = 0;
	while (a)
	{
		a &= a - 1;
		res++;
	}
	return res;
}
int main(int argc, char *argv[])
{
	srand(time(NULL));

	printf("%lu\n", sizeof(long long));

	if (argc < 2)
	{
		printf("Parameters error\n");
		return -1;
	}
	int n = atoi(argv[1]);
	int *a = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	struct listnode *p = createlist(a, n);
	printlist(p);
	printlist(p = sortl(p));
	printlist(p);
	delist(p);

	return 0;
	printf("2 << 18:%u  <> 1 << 18:%u\n", 2 << 18, 1 << 18);

	printf("%d\n", hamingw(atoi(argv[1])));

	size_t N = atoi(argv[1]);
	printf("have N:%td\n", N);
	char *res = (char *)calloc(N, sizeof(char));

	for (size_t i = 0; i < 10; i++)
	{
		res[0] = i + '0';
		helper(res, N, 0);
	}

	return EXIT_SUCCESS;
}

void helper(char *res, size_t len, size_t idx)
{

	if (len - 1 == idx)
	{
		printf("%s ", res);
		return;
	}

	for (size_t i = 0; i < 10; i++)
	{
		res[idx + 1] = i + '0';
		helper(res, len, idx + 1);
	}
}
