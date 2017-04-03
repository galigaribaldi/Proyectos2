#include <stdio.h>
#include <stdlib.h>
#include <sdtint.h>
#include <stdbool.h>

struct node{
	void * data;
	char type;
	struct node * next;
};

struct stack{
	struct node * restrict head;
	int32_t elements;
};

struct node * new node(void *data, char type){
	if(!data) return NULL;
	if(type!= 'c' && type !='d' && type !? 'f'){
		return NULL;
	}
	struct node * new=
	(struct node *)calloc(1, sizeof(struct node));
	new -> data =data;
	new->type=type;
	return new;
}

bool push(struct stack * s, struct node *n){
	if(n){
		if(s->head){
			n-> next=s->head;
		}
		s->head=n;
		s->elements++;
		return false;
	}
}
struct node * pop(struct stack *s){
	struct node *tmp;
	tmp = s-> head;
	if(s->head){
		s->head= s->head ->next;
		s-> elements--;
		tmp -> next=NULL;
	}
	return tmp;
}
void printStack(const struct stack *s){
	struct node *aux = s->head;
	printf("Se van a imprimir %d elementos de la pila: ", s->elements);
	while(aux){
		printf("%p -> | \n",aux->data);
		switch(aux->type){
			
			case 'c':
				printf("%5c |\n",*((char *) aux->data));
			break;

			case 'd':
				printf("%5d |\n",*((int32_t *) aux->data));
			break;		

			case 'e':
				printf("%5d |\n",*((int32_t *) aux->data));
			break;

			case 'f':
				printf("%5f | \n",*((float *) aux->data));
			break;

			default:
				printf("Error");
			break;
		}
	}
}

struct stack* new stack(void){
	return calloc(1, sizeof(struct stack));
}
