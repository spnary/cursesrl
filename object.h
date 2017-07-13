typedef struct object {
	int x;
	int y;
	char icon;
} Object;

void moveObject(Object *obj, int x, int y); 
int handleKey(int key, Object *obj); 
