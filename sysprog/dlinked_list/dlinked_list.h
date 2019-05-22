#ifndef __DLINKED_LINST_H__
#define __DLINKED_LINST_H__

#ifdef __cplusplus
extern "C"{
#endif

// typedefs 
typedef enum
{
	DLIST_OK,
	DLIST_ERROR

}DListRet;

typedef struct _DListNode
{
	struct _DListNode *prev;
	struct _DListNode *next;
	void   *data

}DListNode;

typedef struct _DList
{
	DListNode *head;
	DlistNode *tail;

}DList;

typedef DListRet (*DListPrint)(void *data);

// functions
DList*      create_list(DList *list); 
DListRet    destroy_list(DList *list);
DListRet    append_element(DList *list, void *data);
DListRet    delete_element(DList *list, int pos);
DListRet    insert_element(DList *list, int pos);
DListRet    dlist_print(DList *list, DListPrint print);


#ifdef __cplusplus
}
#endif

#endif
