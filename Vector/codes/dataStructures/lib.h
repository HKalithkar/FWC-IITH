//Defining the Node
typedef struct Node {
    int value;
    int row;
    int col;
    struct Node* next;
} Node;


//Function to traverse through node and print the node values
void check(Node* a){
    while(a != NULL){
        printf("%d", a->value);
        a = a->next;
    }
}


//Function to create a node
Node* createNode(int value, int row, int col) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}


//Function to insert a node
void insert_node(Node **head, int row, int col, int val) {
    Node* new_node = createNode(val, row, col);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}


// Function to load values from .dat file and create a matrix using linked lists
Node* loadtxt(char *str) {
    FILE *fp = fopen(str, "r");
    Node* head = NULL;
    Node* currentRow = NULL;

    int numRows = 2;
    int numCols = 1;

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++) {
            int value;
            fscanf(fp,"%d", &value);

            if (value != 0) {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } else {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }
    fclose(fp);
    return head;
}


//Function to add only x value of linkedlist with the given integer
Node* linalg_add_x(Node* a, int x){
    a->value = x + a->value;
    return a;
}


//Function to add only y value of linkedlist with given integer
Node* linalg_add_y(Node* a, int y){
    Node* result = a;
    a = a->next;
    a->value = y + a->value;
    return result;
}


//Print function
void print(Node *head) {
    if (head == NULL) {
        printf("Empty matrix\n");
        return;
    }

    int max_row = head->row;
    int max_col = head->col;

    Node *current = head;
    while (current != NULL) {
        if (current->row > max_row) {
            max_row = current->row;
        }
        if (current->col > max_col) {
            max_col = current->col;
        }
        current = current->next;
    }

    for (int i = 0; i <= max_row; i++) {
        for (int j = 0; j <= max_col; j++) {
            current = head;
            int val;
            while (current != NULL) {
                if (current->row == i && current->col == j) {
                    val = current->value;
                    break;
                }
                current = current->next;
            }
            printf("%d ", val);
        }
        printf("\n");
    }
}


//Function to multiply integer x with values in linkedlist
Node* matmult(int x, Node* head){
    Node *result = NULL;
    while(head != NULL){
         int val = x * head->value;
         insert_node(&result, head->row, head->col, val);
         head = head->next;
    }
    
    return result;
}


//Addition function
Node *linalg_add(Node *a, Node *b) {
    Node *result = NULL;
    
    while (a != NULL && b != NULL) {
        int x = a->value;
        int y = b->value;
        int val = x + y;

        insert_node(&result, a->row, a->col, val);

        a = a->next;
        b = b->next;
    }

    // Handle remaining nodes in list 'a'
    while (a != NULL) {
        insert_node(&result, a->row, a->col, a->value);
        a = a->next;
    }

    // Handle remaining nodes in list 'b'
    while (b != NULL) {
        insert_node(&result, b->row, b->col, b->value);
        b = b->next;
    }

    return result;

}


//Function to save the linkedlist in .dat file
void save(Node* head, char* filename) {
    // Open the file in binary write mode
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Traverse the linked list and write each element to the file
    Node* current = head;
    while (current != NULL) {
        fprintf(fp, "%d \n", current->value);
        current = current->next;
    }

    // Close the file
    fclose(fp);
}
