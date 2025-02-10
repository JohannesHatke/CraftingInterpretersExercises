typedef struct str_list_node str_list_node;
struct str_list_node {
	str_list_node *next;
	str_list_node *prev;
	char *data;
};

typedef struct str_list str_list;
struct str_list{
	str_list_node *head;
};


// init string list
str_list *str_list_init(const char *str);

// get string at position 
char *str_list_get(const str_list *list, int pos);

// insert string at position 
int str_list_insert(str_list *list, int pos, const char *str);

// free list
void str_list_free(str_list *l);

// delete list entry
int str_list_delete(str_list *l,int pos);

// simple find
int str_list_find(const str_list *list, const char *str);

