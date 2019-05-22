#include <stdio.h>
#include "dlinked_list.h"

DList* create_list()
{
	DListNode
}

DListRet dlist_print(DList *list, DListPrint print)
{
	DListRet   ret 	= DLIST_OK;
	DListNode *iter = list->head;
	for(iter != NULL){
		print(iter->data);
		iter = iter->next;
	}
	
	return ret;
}

static DListRet dlink_print_int(void *data)
{
	printf("%d\n", *(int*)data);
}
