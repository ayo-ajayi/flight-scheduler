#include "head.h"

typedef struct island
{
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

void display(island *place)
{
	for (; place != NULL; place = place->next)
	{
		printf("Name:%s\nOpening Time:%s\nClosing Time:%s\n", place->name, place->opens, place->closes);
	}
}

//I'm tryin to create a memory location, hence the reason why the return type is a pointer
island *create(char *name)
{
	island *i = malloc(sizeof(island));
	/*island i; i =(island*)malloc(sizeof(island));*/
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;
	return i;
}

/*
island *p = malloc(sizeof(island));
free(p);
*/

int main()
{

	island amity = {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island shutter = {"Shutter", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &shutter;

	display(&amity);

	char name[80];
	printf("Enter the name of the new Island: ");
	fgets(name, 80, stdin);
	island *p_island0 = create(name);
	shutter.next = p_island0;

	printf("Enter the name of another Island: ");
	fgets(name, 80, stdin);
	island *p_island1 = create(name);
	p_island0->next = p_island1;
	display(&amity);
	return 0;
}
