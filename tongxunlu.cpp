#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ͨѶ¼�ṹ��Ĵ���
struct tongxunzhe{
	char name[20];
	char sex[3];
	char phone_number[12];
	char address[30];
	struct tongxunzhe *next;
};
int menu(){
	printf("\t\t�������������������������������������������� \n");
	printf("\t\t    ������������������ӭ������������ʹ��������   \n");
	printf("\t\t  ���������������������������  \n");
	printf("\t\t��joyang����ͨ �����Ѷ¼  ���ϵͳ����  \n");
	printf("\t\t  ��������������������������� \n");
	printf("\t\t    ����������������������������������������  \n");
	printf("\t\t    ���������������������������������������� \n\n");
	printf("\t  ������������������������������ \n");
	printf("\t\t\t\t1��ͨѶ¼����\n"); 
	printf("\t\t\t\t2��ͨѶ¼ɾ��\n"); 
	printf("\t\t\t\t3��ͨѶ¼��ѯ\n"); 
	printf("\t\t\t\t4��ͨѶ¼��ʾ\n"); 
	printf("\t\t\t\t5�����ͨѶ¼\n");
	printf("\t\t\t\t6��ͨѶ¼����\n"); 
	printf("\t\t\t\t7���˳�ϵͳ\n");  
	printf("\t  ������������������������������ \n");
	return 0;
} 

struct tongxunzhe *create()                                 //����ͨѶ¼
{
    int i,n;
    struct tongxunzhe *head,*p,*s;
    s = (struct tongxunzhe*)malloc(sizeof(struct tongxunzhe));
    if(!s)
    {
       printf("memory error------");
       exit(0);
    }
    else
    {
        s -> next = NULL;
        head = s;
    }
    
    p = head;

  printf("O(��_��)OO(��_��)O~O(��_��)O~O(��_��)O~O(��_��)O~O(��_��)O~O(��_��)O~O(��_��)O~\n");
	    printf("\t\t\t  ����ͨѶ¼\n");
    printf("input the numbers of tongxunzhe:");   //����ͨѶ�ߵ�����
    scanf("%d",&n);
    
    for(i = 1; i <= n; i++)
    {
        
        s = (struct tongxunzhe*)malloc(sizeof(struct tongxunzhe));
        s -> next = NULL;
        if(!s)
        {
            printf("memory error------");
            exit(0);
        }
		printf("�������%d��ͨѶ�ߣ�\n",i);
        printf("input the name of tongxunzhe:");                 
        scanf("%s",s -> name);
        printf("input the sex of tongxunzhe:");
        scanf("%s",s -> sex);
		   printf("input the phone_number of tongxunzhe:");
        scanf("%s",s -> phone_number);
		   printf("input the address of tongxunzhe:");
        scanf("%s",s -> address);
        p -> next = s;       //��s������ӵ�p���ĺ���
        p = s;         // ��pָ��s���
    }
    printf("ͨѶ¼������ϣ�\n");
    return head;    //ͷָ�뷵��������
}

 struct tongxunzhe *del(struct tongxunzhe *head)  //ɾ��ͨѶ��
{
        struct tongxunzhe *p,*q;
        int j, k = 1;
        if(!head)
        {
	         printf("memory error----");
	         exit(0);
         }

         char in_char[11];
         printf("������Ҫɾ����ͨѶ��:");
         scanf("%s",in_char);

         p = head->next;

         while(p != NULL)
         {
	           if(strcmp(p->name,in_char) == 0)
	           {  
		             q = head;
		             j = 1;
		            while(j < k && q -> next != p) //�ҵ�Ҫɾ�����p��ǰ��
		            {
			              j++;
			              q = q -> next;                     
		             }
		             q -> next = p -> next; //ɾ��p���
                     printf("ɾ���ɹ���\n");
		             return head;
                }
	            else
	           {
		       if(p -> next == NULL)
		       {
	                printf("��Ǹ��û����Ҫɾ����ͨѶ��!\n"); 
			          //ֱ�����һ����û���ҵ���˵��û�д�ͨѶ��
			        break;
		       }
		       else
		       {
			        k++;
	                p = p -> next; //����һ��һ����������                             
			        continue;
		       }
	       }
       }
}

void query(struct tongxunzhe *head)           //��ѯͨѶ��
{
       struct tongxunzhe *p;
	   char in_char[11];                                    
	   printf("������Ҫ��ѯ��ͨѶ��:");
	   scanf("%s",in_char);
       p = head -> next;
       while(p != NULL)
       {
		   if(strcmp(p->name,in_char) == 0)
		   {
			      printf("��ַ:%s  ����:%s  �Ա�:%s  ͨѶ����:%s\n",p -> address, p -> name, p -> sex, p -> phone_number);
			  printf("���ҳɹ�\n");
		      break;
		    }
		   else
		  {
			     if(p -> next == NULL)
			     {
		             printf("��Ǹ,û����Ҫ���ҵ�ͨѶ�ߣ�\n");                          
			           //ֱ�����һ����û���ҵ���˵��û�д�ͨѶ��
			          break;
			      }
			     else
		      	{
				     p = p -> next;
				     continue;
			    }
		 }
	}
}

struct tongxunzhe *add(struct tongxunzhe *head)       //���ͨѶ��
{
	        struct tongxunzhe *p, *s;
	        s = (struct tongxunzhe *)malloc(sizeof(struct tongxunzhe));
	        s -> next = NULL;
	        p = head -> next;
	        while(p -> next != NULL)
		        p = p -> next; 
	
	        printf("input the name of tongxunzhe:");                 
            scanf("%s",s -> name);
            printf("input the sex of tongxunzhe:");
            scanf("%s",s -> sex);
            printf("input the phone_number of tongxunzhe:");
            scanf("%s",s -> phone_number);
            printf("input the address of tongxunzhe:");
            scanf("%s",s -> address);
	        p -> next = s;       //�������ӵĽ�����ӵ��ѽ��õ�����
	        p = s;               //��pָ�����һ�����
	        printf("add success!\n");
	        return(head);
}

void display(struct tongxunzhe *head)     //��ʾͨѶ¼
{
	          struct tongxunzhe *p;
	          p = head->next;
	          while(p != NULL)
	          {
		            printf("��ַ:%s  ����:%s  �Ա�:%s  ͨѶ����:%s\n",p -> address, p -> name, p -> sex, p -> phone_number);
		            p = p->next;
	          }
}

void save(struct tongxunzhe *head)      //����ͨѶ¼
{
	         FILE *fp;
	         struct tongxunzhe *p;
	         if((fp = fopen("ͨѶ¼.txt","w+")) == NULL)           
				//����Ϊ"ͨѶ¼.txt"���ļ���,�򿪷�ʽ��"wb"
	         {
		          printf("cannot open file!\n");
		          exit(0);
	          }

	          p = head->next ;
	          while(p != NULL)
	          {
		            fputs("��ַ��",fp);
		            fputs(p->address,fp);       //��ָ�����ļ����һ���ַ���
		            fputs("\n",fp);       //��ָ���ļ����ﻻ��
		            fputs("������",fp);
		            fputs(p->name,fp);                          
		            fputs("\n",fp); 
		            fputs("�Ա�",fp);
		            fputs(p->sex,fp);
		            fputs("\n",fp);
		            fputs("�ֻ����룺",fp);
		            fputs(p->phone_number,fp);
		            fputs("\n",fp);
		            fputs("\n",fp);
		            p = p->next;
	         }
	         fclose(fp);
	         printf("save success!\n");
}




int main(){
	system("title joyang��ͨѶ¼ϵͳ");//����cmd���ڱ���
	system("mode con cols=80 lines=35");//���ڿ�ȸ߶�
	system("color 5E");
	system("date /T");
	system("TIME /T");
	menu();
	int choice=0;
	struct tongxunzhe *head;
	while(choice != 7){
		printf("select your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=create();break;
			case 2:
				head=del(head);break;
			case 3:
				query(head);break;
			case 4:
				display(head);break;
			case 5:
				head=add(head);break;
			case 6:
				save(head);break;
			case 7:
				exit(0);break;
		}
	}
	
	return 0;
}

