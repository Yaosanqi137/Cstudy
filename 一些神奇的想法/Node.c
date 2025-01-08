#include <stdio.h>
#include <stdlib.h>

// 定义双链表节点结构
typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

// 创建新节点
Node *createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 初始化双链表和哈希表
Node *initList(int n, Node **hashTable) {
    Node *head = createNode(1);
    hashTable[1] = head;
    Node *current = head;
    for (int i = 2; i <= n; i++) {
        Node *newNode = createNode(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        hashTable[i] = newNode;
    }
    return head;
}

// 将节点 x 移动到节点 y 的左边
void moveLeft(Node **head, Node *nodeX, Node *nodeY, Node **hashTable) {
    if (nodeX->next == nodeY) {
        return; // x 已经在 y 的左边
    }

    // 将 x 从当前位置删除
    if (nodeX->prev != NULL) {
        nodeX->prev->next = nodeX->next;
    } else {
        *head = nodeX->next; // 如果 x 是头节点，更新头节点
    }
    if (nodeX->next != NULL) {
        nodeX->next->prev = nodeX->prev;
    }

    // 将 x 插入到 y 的左边
    nodeX->prev = nodeY->prev;
    nodeX->next = nodeY;
    if (nodeY->prev != NULL) {
        nodeY->prev->next = nodeX;
    } else {
        *head = nodeX; // 如果 y 是头节点，更新头节点
    }
    nodeY->prev = nodeX;
}

// 将节点 x 移动到节点 y 的右边
void moveRight(Node **head, Node *nodeX, Node *nodeY, Node **hashTable) {
    if (nodeX->prev == nodeY) {
        return; // x 已经在 y 的右边
    }

    // 将 x 从当前位置删除
    if (nodeX->prev != NULL) {
        nodeX->prev->next = nodeX->next;
    } else {
        *head = nodeX->next; // 如果 x 是头节点，更新头节点
    }
    if (nodeX->next != NULL) {
        nodeX->next->prev = nodeX->prev;
    }

    // 将 x 插入到 y 的右边
    nodeX->prev = nodeY;
    nodeX->next = nodeY->next;
    if (nodeY->next != NULL) {
        nodeY->next->prev = nodeX;
    }
    nodeY->next = nodeX;
}

// 交换节点 x 和节点 y 的值
void swapNodes(Node *nodeX, Node *nodeY) {
    int temp = nodeX->val;
    nodeX->val = nodeY->val;
    nodeY->val = temp;
}

// 计算奇数位置的编号和
int sumOddPositions(Node *head) {
    int sum = 0;
    int pos = 1;
    Node *current = head;
    while (current != NULL) {
        if (pos % 2 == 1) {
            sum += current->val;
        }
        pos++;
        current = current->next;
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 哈希表：存储每个盒子编号对应的节点指针
    Node *hashTable[n + 1];
    for (int i = 1; i <= n; i++) {
        hashTable[i] = NULL;
    }

    Node *head = initList(n, hashTable);

    for (int i = 0; i < m; i++) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);

        Node *nodeX = hashTable[x];
        Node *nodeY = hashTable[y];

        if (op == 1) {
            moveLeft(&head, nodeX, nodeY, hashTable);
        } else if (op == 2) {
            moveRight(&head, nodeX, nodeY, hashTable);
        } else if (op == 3) {
            swapNodes(nodeX, nodeY);
        }
    }

    int result = sumOddPositions(head);
    printf("%d\n", result);

    return 0;
}
