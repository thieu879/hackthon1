#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertLast(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAt(Node **head, int data, int position)
{
    if (position <= 0)
    {
        printf("Vị trí không hợp lệ.\n");
        return;
    }

    if (position == 1)
    {
        insertHead(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;
    int currentPos = 1;

    while (temp != NULL && currentPos < position - 1)
    {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL)
    {
        printf("Vị trí vượt quá danh sách.\n");
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void deleteHead(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteLast(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(temp);
}

void deleteByValue(Node **head, int value)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                *head = temp->next;
            }

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    }

    printf("Không tìm thấy phần tử với giá trị %d.\n", value);
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node *temp = head;
    printf("NULL");
    while (temp != NULL)
    {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

void printListEnd(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("NULL");
    while (temp != NULL)
    {
        printf(" <--> %d", temp->data);
        temp = temp->prev;
    }
    printf(" <--> NULL\n");
}

int main()
{
    Node *head = NULL;
    int data, position;

    do
    {
        printf("\n=========================Menu=========================\n");
        printf("1. Thêm phần tử vào đầu danh sách\n");
        printf("2. Thêm phần tử vào cuối danh sách\n");
        printf("3. Chèn phần tử vào vị trí cụ thể\n");
        printf("4. Xóa phần tử đầu danh sách\n");
        printf("5. Xóa phần tử cuối danh sách\n");
        printf("6. Xóa phần tử theo giá trị\n");
        printf("7. Duyệt danh sách từ đầu đến cuối\n");
        printf("8. Duyệt danh sách từ cuối đến đầu\n");
        printf("9. Thoát\n");
        printf("Nhập lựa chọn: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhập giá trị cho phần tử: ");
            scanf("%d", &data);
            insertHead(&head, data);
            break;
        case 2:
            printf("Nhập giá trị cho phần tử: ");
            scanf("%d", &data);
            insertLast(&head, data);
            break;
        case 3:
            printf("Nhập vị trí: ");
            scanf("%d",&position);
            printf("Nhập giá trị: ");
            scanf("%d", &data);
            insertAt(&head, data, position);
            break;
        case 4:
            deleteHead(&head);
            break;
        case 5:
            deleteLast(&head);
            break;
        case 6:
            printf("Nhập giá trị cần xóa: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 7:
            printf("Danh sách từ đầu đến cuối: ");
            printList(head);
            break;
        case 8:
            printf("Danh sách từ cuối đến đầu: ");
            printListEnd(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}
