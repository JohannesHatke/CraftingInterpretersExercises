#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"


#define MAXSTRLEN 10000
// copies string
char *copy_string_to_heap(const char *str){
	size_t len = strnlen(str,MAXSTRLEN);
	char *output = NULL;
	if (len == MAXSTRLEN)
		return output;
	output = (char*)malloc( (len+1)* sizeof(char)) ;
	strncpy(output, str,len);
	return output;
}


// init string list
str_list_node *str_list_node_init (const char *str){
	char *str_cpy = NULL;
	str_list_node *node = NULL;
	if (str != NULL){
		str_cpy = copy_string_to_heap(str);
	}
	node = malloc(sizeof(str_list_node));
	node->prev = NULL;
	node->next = NULL;
	node->data = str_cpy;
	return node;
}
str_list *str_list_init(const char *str){
	str_list *output = NULL;
	output = malloc(sizeof(str_list));
	output ->head = str_list_node_init(str);
	return output;
}

// get string at position 
char *str_list_get(const str_list *list, int pos){
	str_list_node *curr = list->head;
	while(pos-- && curr->next){
		curr = curr->next;
	}
	return curr->data;
}

// insert string at position 
int str_list_insert(str_list *list, int pos, const char *str){
	str_list_node *curr = list->head;
	str_list_node *new = str_list_node_init(str);
	if(pos == 0){
		new->next = list->head;
		list->head->prev = new;
		list->head = new;
		return 0;
	}

	int i;
	for(i= 0; i<pos-1 && curr->next; i++){
		curr = curr->next;
	}
	if(curr->next){ 
		new->next = curr->next;
		curr->next->prev = new;
	}
	curr->next = new;
	new->prev = curr;
	return 0;
};

void str_list_free(str_list *l){
	str_list_node *curr,*tmp;
	curr = l->head;
	while (curr){
		tmp = curr;
		curr = curr->next;
		free(tmp->data);
		free(tmp);
	}
	free(l);
}


// delete list entry
int str_list_delete(str_list *l,int pos){
	str_list_node *curr,*tmp;
	curr = l->head;
	int i;
	if( pos == 0){
		tmp = l->head;
		if (l->head->next) 
			l->head->next->prev = NULL;
		l->head = l->head->next;
		free(tmp->data);
		free(tmp);
		return 0;
	}

	for(i= 0; i < pos && curr->next; i++){
		curr = curr->next;
	}
	if(i != pos){
		if(i == pos-1){
			

		}
		return -1;
	}

	tmp = curr;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(tmp->data);
	free(tmp);

	return 0;
}

// simple find
int str_list_find(const str_list *list, const char *str){
	str_list_node *curr = list->head;
	int i =0;
	while(curr->next){
		if(!strncmp(curr->data,str,MAXSTRLEN))
			return i;
		curr = curr->next;
		i++;
	}
	return -1;
}

