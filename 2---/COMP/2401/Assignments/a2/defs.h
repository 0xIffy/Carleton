#define MAX_STR 40
#define MAX_PRODUCTS 15

typedef struct{
	int id;
	char name[MAX_STR];
	int stock;
	float price;
} ProductType;

typedef struct{
	ProductType **pArr;
	int numProducts;
	int nextId;
} ProductArrType;

typedef struct{
	char name[MAX_STR];
	ProductArrType *products;
} InventoryType;

// menu functions
void printMenu();
void printInventory(InventoryType*);

// store functions
int initStore(InventoryType**);
int initProductArr(ProductArrType**);
int createProduct(ProductType**,char*,float,int);
void addProduct(ProductType*, ProductArrType*);
int findProduct(ProductArrType*, ProductType**);
void restock(ProductType*);
void buyProduct(ProductType*,float*);
void freeAll(InventoryType*);