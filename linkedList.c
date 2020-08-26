#include <stddef.h>
struct node{
	int val;
	struct node*next,*prev;
};
struct node *buffer;
void check(){
	struct node* iterator = buffer;
	iterator = iterator->next;
	while(iterator != buffer){
		printf("%d\n",iterator->val);
		iterator= iterator->next;
	}
}
void add(int val){
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
int remove(int val){
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
	buffer= (struct node*)malloc(sizeof(struct node));
	buffer->val = NULL;
	buffer->next=buffer->prev=buffer;
	add(3);
	add(1);
	add(5);
	add(2);
	add(4);
	check();
	printf("checking remove\n");
	remove(2);
	check();
	remove(3);
	check();
	remove(1);
	check();
	remove(5);
	check();
	remove(4);
	check();
}
