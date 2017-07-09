#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//通讯录结构体的创建
struct tongxunzhe{
	char name[20];
	char sex[3];
	char phone_number[12];
	char address[30];
	struct tongxunzhe *next;
};
int menu(){
	printf("\t\t＃〓§〓〓〓〓〓§〓〓〓〓〓〓§〓〓〓〓〓§〓＃ \n");
	printf("\t\t    ↓欢　　　　↓　　迎　　　↓　　使　　↓用   \n");
	printf("\t\t  ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆  \n");
	printf("\t\t☆joyang☆　☆的通 ☆　　☆讯录  ☆　☆系统　☆  \n");
	printf("\t\t  ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆ \n");
	printf("\t\t    ↓　　　　　↓　　　　　　↓　　　　　↓  \n");
	printf("\t\t    ※　　　　　※　　　　　　※　　　　　※ \n\n");
	printf("\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★ \n");
	printf("\t\t\t\t1、通讯录创建\n"); 
	printf("\t\t\t\t2、通讯录删除\n"); 
	printf("\t\t\t\t3、通讯录查询\n"); 
	printf("\t\t\t\t4、通讯录显示\n"); 
	printf("\t\t\t\t5、添加通讯录\n");
	printf("\t\t\t\t6、通讯录保存\n"); 
	printf("\t\t\t\t7、退出系统\n");  
	printf("\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★ \n");
	return 0;
} 

struct tongxunzhe *create()                                 //建立通讯录
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

  printf("O(∩_∩)OO(∩_∩)O~O(∩_∩)O~O(∩_∩)O~O(∩_∩)O~O(∩_∩)O~O(∩_∩)O~O(∩_∩)O~\n");
	    printf("\t\t\t  建立通讯录\n");
    printf("input the numbers of tongxunzhe:");   //输入通讯者的人数
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
		printf("请输入第%d个通讯者：\n",i);
        printf("input the name of tongxunzhe:");                 
        scanf("%s",s -> name);
        printf("input the sex of tongxunzhe:");
        scanf("%s",s -> sex);
		   printf("input the phone_number of tongxunzhe:");
        scanf("%s",s -> phone_number);
		   printf("input the address of tongxunzhe:");
        scanf("%s",s -> address);
        p -> next = s;       //将s结点连接到p结点的后面
        p = s;         // 让p指向s结点
    }
    printf("通讯录建立完毕！\n");
    return head;    //头指针返回主函数
}

 struct tongxunzhe *del(struct tongxunzhe *head)  //删除通讯者
{
        struct tongxunzhe *p,*q;
        int j, k = 1;
        if(!head)
        {
	         printf("memory error----");
	         exit(0);
         }

         char in_char[11];
         printf("输入你要删除的通讯者:");
         scanf("%s",in_char);

         p = head->next;

         while(p != NULL)
         {
	           if(strcmp(p->name,in_char) == 0)
	           {  
		             q = head;
		             j = 1;
		            while(j < k && q -> next != p) //找到要删除结点p的前驱
		            {
			              j++;
			              q = q -> next;                     
		             }
		             q -> next = p -> next; //删除p结点
                     printf("删除成功！\n");
		             return head;
                }
	            else
	           {
		       if(p -> next == NULL)
		       {
	                printf("抱歉，没有你要删除的通讯者!\n"); 
			          //直到最后一个还没有找到，说明没有此通讯者
			        break;
		       }
		       else
		       {
			        k++;
	                p = p -> next; //继续一个一个的往后找                             
			        continue;
		       }
	       }
       }
}

void query(struct tongxunzhe *head)           //查询通讯者
{
       struct tongxunzhe *p;
	   char in_char[11];                                    
	   printf("输入你要查询的通讯者:");
	   scanf("%s",in_char);
       p = head -> next;
       while(p != NULL)
       {
		   if(strcmp(p->name,in_char) == 0)
		   {
			      printf("地址:%s  姓名:%s  性别:%s  通讯号码:%s\n",p -> address, p -> name, p -> sex, p -> phone_number);
			  printf("查找成功\n");
		      break;
		    }
		   else
		  {
			     if(p -> next == NULL)
			     {
		             printf("抱歉,没有你要查找的通讯者！\n");                          
			           //直到最后一个还没有找到，说明没有此通讯者
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

struct tongxunzhe *add(struct tongxunzhe *head)       //添加通讯者
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
	        p -> next = s;       //将新增加的结点连接到已建好的链表
	        p = s;               //让p指向最后一个结点
	        printf("add success!\n");
	        return(head);
}

void display(struct tongxunzhe *head)     //显示通讯录
{
	          struct tongxunzhe *p;
	          p = head->next;
	          while(p != NULL)
	          {
		            printf("地址:%s  姓名:%s  性别:%s  通讯号码:%s\n",p -> address, p -> name, p -> sex, p -> phone_number);
		            p = p->next;
	          }
}

void save(struct tongxunzhe *head)      //保存通讯录
{
	         FILE *fp;
	         struct tongxunzhe *p;
	         if((fp = fopen("通讯录.txt","w+")) == NULL)           
				//打开名为"通讯录.txt"的文件夹,打开方式："wb"
	         {
		          printf("cannot open file!\n");
		          exit(0);
	          }

	          p = head->next ;
	          while(p != NULL)
	          {
		            fputs("地址：",fp);
		            fputs(p->address,fp);       //向指定的文件输出一个字符串
		            fputs("\n",fp);       //在指定文件夹里换行
		            fputs("姓名：",fp);
		            fputs(p->name,fp);                          
		            fputs("\n",fp); 
		            fputs("性别：",fp);
		            fputs(p->sex,fp);
		            fputs("\n",fp);
		            fputs("手机号码：",fp);
		            fputs(p->phone_number,fp);
		            fputs("\n",fp);
		            fputs("\n",fp);
		            p = p->next;
	         }
	         fclose(fp);
	         printf("save success!\n");
}




int main(){
	system("title joyang的通讯录系统");//设置cmd窗口标题
	system("mode con cols=80 lines=35");//窗口宽度高度
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

