#include "DoubleLinkedList.h"
#include <stdio.h>

#define OUTPUT(list) \
	printf("-----------------------------------\n\n");  \
	print_list(list);  \

void print_list(str_list *a){
	str_list_node *c = a->head;
	int i = 0;
	while(c != NULL){
		printf("%3d:%s\n",i,c->data);
		i++;
		c = c->next;
	}
}
int main(int argc, char *argv[])
{

	str_list *b = str_list_init(".");
	str_list_insert(b, 1, ".....");
	str_list_insert(b, 1, "....");
	str_list_insert(b, 1, "...");
	str_list_insert(b, 1, "..");
	const char *tofind = "..";
	OUTPUT(b);
	printf("found %s at %d\n",tofind,str_list_find(b,tofind));

	str_list_insert(b, 5, "end");
	str_list_insert(b, 0, "start");
	OUTPUT(b);
	printf("found %s at %d\n",tofind,str_list_find(b,tofind));
	str_list_insert(b, 1, "1");
	str_list_insert(b, 3, "3");
	OUTPUT(b);
	printf("found %s at %d\n",tofind,str_list_find(b,tofind));

	int todelete = 0;
	printf("\n\ndeleting at %d\n", todelete);
	str_list_delete(b, todelete);
	OUTPUT(b);

	todelete = 4;
	printf("\n\ndeleting at %d\n", todelete);
	str_list_delete(b, todelete);
	OUTPUT(b);


	todelete = 7;
	printf("\n\ndeleting at %d\n", todelete);
	str_list_delete(b, todelete);
	OUTPUT(b);


	str_list_free(b);
	
	
	return 0;
}
