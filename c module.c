#include <stdio.h>
#include <string.h>
struct student{
    int studentId,studentPass,studentBookId,studentBookHold;
    char studentName[100];
}stu[100];
struct Book{
    int bookId,bookcount;
    char bookName[100],bookAuhtor[100],bookAvalibe[100];
}book[100];
struct viewIssued{
    int stuviewID,bookViewID,bookViewPrice;
    char bookViewName[100],bookViewAuthorName[100],stuviename[30];
}vie[100];
int i=0,k=0,j=0;
FILE *fp,*fp2;
void save()
{
	int y;
	fp=fopen("savedreport.txt","w+");
	fprintf(fp,"Book Id\t\tBook Name\t\tAuthor Name\t\tBook count\t\t\t\tBook Avaliblity\n");
    for(y=0;y<k;y++)
    {
        fprintf(fp,"%-7d\t\t%-16s\t%-18s\t%-17d\t%15s\n",book[y].bookId,book[y].bookName,book[y].bookAuhtor,book[y].bookcount,book[y].bookAvalibe);
    }
	fclose(fp);
	fp2=fopen("savedissuedreport.txt","w");
	fprintf(fp2,"Student Id\tStudent name\tBook Name\tAuthor Name\n");
    for(y=0;y<i;y++)
    {
       
       if(vie[y].stuviewID!=0)
       {
        fprintf(fp2,"%-10d\t%-15s\t%-14s\t%-11s\n",vie[y].stuviewID,vie[y].stuviename,vie[y].bookViewName,vie[y].bookViewAuthorName);   
       }
    }
    fclose(fp2);
}
void view()
{   int y;
    printf("\nBook Id\t\tBook Name\t\tAuthor Name\t\tBook count\t\tBook Avaliblity\n");
    for(y=0;y<k;y++)
    {
        printf("%-7d\t\t%-16s\t%-18s\t%-17d\t%15s\n",book[y].bookId,book[y].bookName,book[y].bookAuhtor,book[y].bookcount,book[y].bookAvalibe);
    }
}
void vieissuesfunc()                                               
{
   int y;
   printf("\nStudent Id\tStudent name\tBook Name\tAuthor Name\n");
   for(y=0;y<i;y++)
   {
       
       if(vie[y].stuviewID!=0)
       {
        printf("%-10d\t%-15s\t%-14s\t%-11s\n",vie[y].stuviewID,vie[y].stuviename,vie[y].bookViewName,vie[y].bookViewAuthorName);   
       }
   }
}
void adminLog()
{
    char adName[100];
    int adPass,choice,NOBook,n,i=0;
        printf("\nEnter admin name :");scanf("%s",adName);
        printf("Enter Admin Password :");scanf("%d",&adPass);
        
        
            if(strcmp("Resshmi",adName)==0&&adPass==1111)
            {
                while(1)
                {
                printf("\n\t1.Add\t\n\t2.View\t\n\t3.ViewIssued\t\n\t4.save\t\n\t5.Log out\n");
                printf("Enter You choice :");scanf("%d",&choice);
                if(choice==1)
                {   printf("No.of books should be added:");scanf("%d",&n);
                    for(i=1;i<=n;i++)
                    {
                        //printf("Enter Number Of Books :");scanf("%d",&NOBook);
                        printf("Enter Book Name :");scanf("%s",book[k].bookName);
                        printf("Enter Author Name :");scanf("%s",book[k].bookAuhtor);
                        printf("Enter Number Of Books :");scanf("%d",&book[k].bookcount);
//                      printf("Enter Book Price :");scanf("%d",&book[k].bookPrice);
                        strcpy(book[k].bookAvalibe,"Available");
                        book[k].bookId=k+2000;k++;
                        printf("\t\t\tBook Added Successfuly........\n");
                    }
                }
                else if(choice==2)
                {
                    view();
                }
                else if(choice==3)
                {
                    vieissuesfunc();
                }
                else if(choice==4)
                {
                    save();
                    printf("\t\t.....Report saved successfully.....\n");
                }
                else if(choice==5)
                {
                    break;
                }
                
            }
          
            }  else
              printf("Enter Correct Name Or Password\n");
    
    
}
void studentLog()
{
    int spass,sid,flag=0;
    char sname[200];
    int choice,stuChoice,lbookid,checkBookId;
    while(1)
    {
        printf("\n\n\t1.SignUp\n\t2.SignIn\n\t3.Exit\n\n");
        printf("Enter your choice :");scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Your Name :");scanf("%s",stu[i].studentName);
            printf("Enter Your Password (only numbers) :");scanf("%d",&stu[i].studentPass);
            stu[i].studentId=i+100;
            stu[i].studentBookId=-1;
            stu[i].studentBookHold=0;
            printf("Your Register Id :%d",stu[i].studentId);
            
            i++;
        }
        else if(choice==2)
        {
            printf("Enter Your Name :");scanf("%s",sname);
            printf("Enter Your Password (only numbers) :");scanf("%d",&spass);
            printf("Enter Your Id :");scanf("%d",&sid);
            for(j=0;j<i;j++)
            {
                if(strcasecmp(stu[j].studentName,sname)==0 && stu[j].studentPass==spass && stu[j].studentId==sid)
                {
                    //printf("%s %d %d\n",stu[j].studentName,stu[j].studentPass,stu[j].studentId);
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                while(1)
                {
                    printf("\n\t1.view\n\t2.lend\n\t3.return\n\t4.Exit\n");
                    printf("Enter Your choice:");scanf("%d",&stuChoice);
                    if(stuChoice==1)
                    {
                        view();
                    }
                    else if(stuChoice==2)
                    {
                        if(stu[j].studentBookId==-1&&stu[j].studentBookHold==0)
                        {
                        printf("Enter bookId :");scanf("%d",&lbookid);
                        // printf("%s %d %d %d\n",stu[j].studentName,stu[j].studentId,stu[j].studentBookId,stu[j].studentBookHold);
                        if(strcasecmp(book[lbookid-2000].bookAvalibe,"Available")==0)
                        {
                        stu[j].studentBookId=lbookid;
                        stu[j].studentBookHold=1;
                        book[lbookid-2000].bookcount-=1;
                        if(book[lbookid-2000].bookcount==0)	strcpy(book[lbookid-2000].bookAvalibe,"NotAvailable");
                        vie[j].stuviewID=stu[j].studentId;
                        strcpy(vie[j].stuviename,sname);
                        strcpy(vie[j].bookViewName,book[lbookid-2000].bookName);
                        strcpy(vie[j].bookViewAuthorName,book[lbookid-2000].bookAuhtor);
                        printf("Here is your book \"%s\" ....",book[lbookid-2000].bookName);
                        }
                        else
                          printf("Book Not Avalible\n");
                        // printf("%s %d %d %d\n",stu[j].studentName,stu[j].studentId,stu[j].studentBookId,stu[j].studentBookHold);
                        
                        }
                        else
                          printf("\t\tOops.! You can't lend book now... \n");
                        
                    }
                    else if(stuChoice==3)
                    {
                        if(stu[j].studentBookId!=-1&&stu[j].studentBookHold==1)
                        {
                            printf("Enter Your bookId:");scanf("%d",&checkBookId);
                           if(stu[j].studentBookId==checkBookId)
                           {
                               stu[j].studentBookId=-1;
                               //book[checkBookId-2000].bookcount+=1;
                        	   stu[j].studentBookHold=0;
                        	   book[checkBookId-2000].bookcount+=1;
                        	   if(book[checkBookId-2000].bookcount>0)
                               strcpy(book[checkBookId-2000].bookAvalibe,"Available");
                               printf("Thank You for returning  \"%s\" Book\n",book[checkBookId-2000].bookName);
                               vie[j].stuviewID=0;
                           }
                           else
                           {
                           	printf("wrong book id.!....\n");
						   }
                        }
                        else 
                          printf("You have nothing to return...\n");
                    }
                    else if(stuChoice==4)
                    {
                    	save();
                        break;
                    }
                }
                    
            }
            else
            {
                printf("Incorrect name/password/id.......");
            }
            
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            printf("Enter Correct Option");
        }
    }
}

int main()
{
    printf("\t\t\t\t RESSHMI LIBRARY \t\t\t\t\n");
    int choice;
    while(1)
    {
        printf("\n\t1.Admin\n\t2.Student\t\n\t3.Exit\n\n");
        printf("Enter your choice :");scanf("%d",&choice);
        if(choice==1)
            adminLog();
        else if(choice==2)
            studentLog();
            // break;
        else if(choice==3)
            break;
        else 
            printf("Enter Correct Option");
    }

    return 0;
}