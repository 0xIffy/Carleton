#include "defs.h"

/*
	purpose: initialize a record type with the provided data
	 in/out: the address of a pointer to the record type being initialized
			 in: a string for the country code
			 in: a string for the country name
			 in: a string for the gender
			 in: a string for the degree type
			 in: the year as an int
			 in: the number of graduates as an int
	 return: 1 if the record is initialized correctly, 0 otherwise			 
*/
int initRecord(RecordType **r, char *cc, char *cn, char *g, char *d, int y, int ng){
	*r = (RecordType *) malloc(sizeof(RecordType));

	if(*r == NULL)
		return C_FALSE;

	strcpy((*r)->countryCode, cc);
	strcpy((*r)->countryName, cn);
	strcpy((*r)->gender, g);
	strcpy((*r)->degree, d);
	(*r)->year = y;
	(*r)->numGrads = ng;

	return C_TRUE;
}

/*
	purpose: initialize a list node with the given record as data
	 in/out: the address of a pointer to the list node being iniialized
	 		 in: a pointer to the record to be stored in the list node
	 return: 1 if the node is initialized correctly, 0 otherwise
*/
int initListNode(ListNodeType **n, RecordType *r){
	*n = (ListNodeType *) malloc(sizeof(ListNodeType));

	if(*n == NULL)
		return C_FALSE;

	(*n)->data = r;
	(*n)->next = NULL;
	(*n)->prev = NULL;

	return C_TRUE;
}

/*
	purpose: initialize a list type for the given country
	 in/out: the address of a pointer to the list to be initialized
	 		 in: the country code of the country the list is for 
	 return: 1 if the list is initialized correctly, 0 otherwise
*/
int initList(ListType **dl, char *cc){
	*dl = (ListType *) malloc(sizeof(ListType));

	if(*dl == NULL)
		return C_FALSE;

	(*dl)->head = NULL;
	(*dl)->tail = NULL;
	strcpy((*dl)->countryCode, cc);

	return C_TRUE;
}

/*
	purpose: initialize a map node with the given key and list as value
	 in/out: the address of a pointer to the map node to be initialized
	 		 in: a pointer to the list to be stored
			 in: a string for the key
	 return: 1 if the node is initialized correctly, 0 otherwise
*/
int initMapNode(MapNodeType **n, ListType *l, char *key){
	*n = (MapNodeType *) malloc(sizeof(MapNodeType));

	if(*n == NULL)
		return C_FALSE;

	(*n)->list = l;
	(*n)->begRange = -1;
	(*n)->endRange = -1;
	strcpy((*n)->key, key);
	(*n)->next = NULL;

	return C_TRUE;
}

/*
	purpose: initialize a map data type
	 in/out: the address of a pointer to the map to be initialized
	 return: 1 if the map is initialized correctly, 0 otherwise
*/
int initMap(MapType **m){
	*m = (MapType *) malloc(sizeof(MapType));

	if(*m == NULL)
		return C_FALSE;

	(*m)->head = NULL;
	(*m)->tail = NULL;
	(*m)->size = 0;

	return C_TRUE;
}

/*
	purpose: initialize a node tha can store any data type as data
	 in/out: the address of a pointer to the node to be initialized
	 		 in: the name of the country the data will be related to
			 in: a string that states the type a data to be stored in this node (int, float etc.)
	 return: 1 if the node is initialized correctly, 0 otherwise
*/
int initVariableNode(VariableNodeType **s, char country[], char type[]){
	*s = (VariableNodeType *) malloc(sizeof(VariableNodeType));

	if(*s == NULL)
		return C_FALSE;

	int a = 0;

	(*s)->data = &a;
	strcpy((*s)->country, country);
	strcpy((*s)->type, type);

	return C_TRUE;
}