/*********************************************************************************************/
/*  Name: PROG1.CPP                                                                          */
/*                                                                                           */
/*  Description: Mean & Std deviation. (Made for PSP0.0)                                     */                          
/*  Calculates the Mean and std deviation of N numbers using linked lists                    */                                                                                                                                 /*  Date        Version  Name       Description           */                       
/*																							 */
/*  Date:			Version  		By														 */
/*  26.11.2017  	1.0      		José Orozco                                              */                                                                                  
/*********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<iostream>

struct test_struct
{
	double val;
	struct test_struct *next;
};

struct test_struct2
{
	double val2;
	struct test_struct2 *next;
};


struct test_struct *head = NULL;
struct test_struct *curr = NULL;
struct test_struct2 *head2 = NULL;
struct test_struct2 *curr2 = NULL;

struct test_struct* create_list(double val)
{
	printf("\n Creando lista con valor inicial: [%f]",val);
	struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
	if(NULL == ptr)
	{
		printf("\n Node creation failed \n");
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	
	head = curr = ptr;
	return ptr;
}

struct test_struct* add_to_list(double val, bool add_to_end)
{
	if(NULL == head)
	{
		return (create_list(val));
	}
	
	if(add_to_end)
	   printf("\n Agregando nodo a la lista: [%f]",val);
	else
		printf("\n Agregando nodo al inicio de la lista [%f]",val);
	
	struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
	if(NULL == ptr)
	{
		printf("\n Node creation failed \n");
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	
	if(add_to_end)
	{
		curr->next = ptr;
		curr = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
	return ptr;
}

struct test_struct2* create_list2(double val2)
{
	printf("\n Creando lista con valor inicial: [%f]",val2);
	struct test_struct2 *ptr2 = (struct test_struct2*)malloc(sizeof(struct test_struct2));
	if(NULL == ptr2)
	{
		printf("\n Node creation failed \n");
		return NULL;
	}
	ptr2->val2 = val2;
	ptr2->next = NULL;
	
	head2 = curr2 = ptr2;
	return ptr2;
}

struct test_struct2* add_to_list2(double val2, bool add_to_end)
{
	if(NULL == head2)
	{
		return (create_list2(val2));
	}
	
	if(add_to_end)
	   printf("\n Agregando nodo a la lista: [%f]",val2);
	else
		printf("\n Agregando nodo al inicio de la lista [%f]",val2);
	
	struct test_struct2 *ptr2 = (struct test_struct2*)malloc(sizeof(struct test_struct2));
	if(NULL == ptr2)
	{
		printf("\n Node creation failed \n");
		return NULL;
	}
	ptr2->val2 = val2;
	ptr2->next = NULL;
	
	if(add_to_end)
	{
		curr2->next = ptr2;
		curr2 = ptr2;
	}
	else
	{
		ptr2->next = head2;
		head2 = ptr2;
	}
	return ptr2;
}

void print_lists_and_values(void)
{
	double med, stdev, sigma;
	int count=0;
	struct test_struct *ptr = head;
		
	printf("\n ------- Lista 1 ------- \n");
	while(ptr != NULL)
	{
		printf("\nNodo %d: [%lf] ",1+count, ptr->val);
		med = med + ptr->val;
		ptr = ptr->next;
		count+=1;
	}
	count-=1;
	printf("\n ------- Final de la Lista 1 ------- \n");
	med = med/count;
	printf("\n Media de los valores de la Lista 1: [%lf]", med); //media OK
	ptr = head;
	sigma = 0;
	while(ptr != NULL)
	{
		if(ptr->val > 0)
			sigma += ((ptr->val - med)*(ptr->val - med));
		ptr = ptr->next;
	}
	stdev = sqrt(sigma/(count-1));
	printf("\nDesviacion estandar de los valores en la Lista 1: [%lf] \n", stdev);
	
	count = 0;
	med = 0;
	sigma = 0;
	stdev = 0;
	
	struct test_struct2 *ptr2 = head2;
	printf("\n ------- Lista 2 ------- \n");
	while(ptr2 != NULL)
	{
		printf("\nNodo %d: [%f] ",1+count, ptr2->val2);
		med = med + ptr2->val2;
		ptr2 = ptr2->next;
		count+=1;
	}
	count-=1;
	printf("\n ------- Final de la Lista 2 ------- \n");
	med = med/count;
	printf("\n Media de los valores de la Lista 2: [%f] \n", med);
	ptr2 = head2;
	while(ptr2 != NULL)
	{
		if(ptr2->val2 > 0)
			sigma += ((ptr2->val2 - med)*(ptr2->val2 - med));
		ptr2 = ptr2->next;
	}
	stdev = sqrt(sigma/(count-1));
	printf("\n Desviacion estandar de los valores en la Lista 2: [%f] \n", stdev); 
	
	return;
}

bool isvalid(float ch)
{
	if((ch != 0.0))
		return false;
	else 
		return true;
}

int main(void)
{
	struct test_struct *ptr = NULL;
	struct test_struct2 *ptr2 = NULL;
	double data;
	
	printf("\n Ingresa los datos de la lista 1 [0 para terminarla]: ");
		do
		{
			scanf("%lf", &data);
			add_to_list(data,true);
		}while(!isvalid(data));
		
	
	printf("\n Ingresa los datos de la lista 2 [0 para terminarla]: ");
		do
		{
			scanf("%lf", &data);
			add_to_list2(data,true);
		}while(!isvalid(data));	
		
	print_lists_and_values();
	
	
	return 0;
}

