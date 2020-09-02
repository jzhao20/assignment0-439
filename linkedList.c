#include <stddef.h>
struct node{
	int val;
	struct node*next,*prev;
};
void check(struct node *buffer){
	struct node* iterator = buffer;
	iterator = iterator->next;
	while(iterator != buffer){
		printf("%d\n",iterator->val);
		iterator= iterator->next;
	}
}
void add(struct node* buffer, int val){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->val = val;
	if(buffer->next ==buffer){
		node->prev = node->next = buffer;
		buffer->prev = buffer->next = node;
	}
	else{
		if(val<=buffer->next->val){
			node->prev = buffer;
			node->next = buffer->next;
			node->next->prev = buffer->next = node;
		}
		else if(val>= buffer->prev->val){
			node->next = buffer;
			node->prev = buffer->prev;
			node->prev->next= buffer->prev = node;
		}
		else{
		 	struct node* current = buffer->next;
			while(current->next != buffer && current->next->val < val){
				current = current->next;
			}
			node->next = current->next;
			current->next=  node;
			node->prev = current;
			if(node->next != NULL)node->next->prev = node;

		}
	}
}
int remove(struct node* buffer, int val){
	struct node * current = buffer->next;
	while(current != buffer){
		if(current->val == val)break;
		current = current->next;
	}
	if(current == buffer)return 0;
	else
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		return 1;
	}
}
int main(){
	struct node* buffer= (struct node*)malloc(sizeof(struct node));
	buffer->val = NULL;
	buffer->next=buffer->prev=buffer;
	add(buffer, 3);
	add(buffer, 1);
	add(buffer, 5);
	add(buffer, 2);
	add(buffer, 4);
	check(buffer);
	printf("checking remove\n");
	remove(buffer ,2);
	check(buffer);
	remove(buffer, 3);
	check(buffer);
	remove(buffer, 1);
	check(buffer);
	remove(buffer, 5);
	check(buffer);
	remove(buffer, 4);
	check(buffer);
}
