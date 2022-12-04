#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
 };
node * makenode(int data) {
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void duyet(node* head) {
	while (head !=NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int count(node* head) {
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}

void pushfront(node** head, int data) {
	node* newnode = makenode(data);
	newnode->next = *head;
	*head = newnode;
}
void pushback(node**head, int data) {
	node* newnode = makenode(data);
	node* temp = *head;
	if (*head== NULL) {
		*head = newnode;
		return;
	}
	while (temp->next !=NULL)
	{
		temp = temp->next;
		}
	temp->next = newnode;
	}

void insert(node** head,int vitri ,int data) {
	int n = sizeof(*head);
	int i = 1;
	node* temp = *head;
	node* newnode = makenode(data);
	if (vitri<1 || vitri>n + 1) return;
	if (vitri == 1) {
		pushfront(head, data);
		return;
	}
	if (vitri == n) {
		pushback(head, data);
		return;
	}
	for (int i = 1; i < vitri-1;i++) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void xoadau(node** head) {
	node* temp = *head;
	if (*head == NULL) return;
	*head = temp->next;
	delete temp;
}

void xoacuoi(node** head) {
	if (*head == NULL) return;
	node* temp = *head;
	if (temp->next == NULL) {
		*head = NULL;
		delete temp;
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node* last = temp->next;
	temp->next = NULL;
	delete last;
}

void xoagiua(node** head, int vitri) {
	int n = sizeof(*head);
	node* temp = *head;
	if (vitri<1 || vitri>n) return;
	if (vitri==1)
	{
		xoadau(head);
	}
	else {
		for (int i = 1; i < vitri - 2; i++) {
			temp = temp->next;
		}
	}
	node* nutxoa = temp->next;
	temp->next = temp->next->next;
	delete nutxoa;
}

int main() {
	node* head = NULL;
	while (1)
	{
		cout << "----------------------------" << endl;
		cout << " 1. Them vao dau" << endl;
		cout << "2. Them vao cuoi" << endl;
		cout << "3. them vao vi tri k" << endl;
		
		cout << "5. xoa dau" << endl;
		cout << "6. xoa cuoi " << endl;
		cout << "7. duyet" << endl;
		cout << "8. xoa vi tri " << endl;
		cout << "0. thoat " << endl;
		int lc;
		cin >> lc;
		if (lc == 1) {
			int x;
			cout << "nhap x = ";
			cin >> x;
			pushfront(&head, x);
		}
		else
		{
			if (lc == 2) {
				int x;
				cout << "nhap x = ";
				cin >> x;
				pushback(&head, x);
			}
			else
			{
				if (lc == 3) {
					int x, k;
					cout << "nhap data = ";
					cin >> x;
					cout << "nhap vao vi tri can chen ";
					cin >> k;
					insert(&head, k, x);
				}
				else
				{
					if (lc == 7) {
						duyet(head);
					}
					else
					{
						if (lc == 5) {
							xoadau(&head);
						}
						else
						{
							if (lc == 6) {
								xoacuoi(&head);
							}
							else {
								if (lc == 8) {
									int vitri;
									cout << " vi tri xoa : ";
									cin >> vitri;
									xoagiua(&head, vitri);
								}
							}
						}
					}
				}
			}
		}
	}
}
