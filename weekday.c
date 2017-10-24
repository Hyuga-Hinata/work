//输入日期算星期几 
#include<stdio.h>
#include<ctype.h>
void Day(void);
void Month(void);
void Year(void);
void Input(void);   //输入部分 
void Output1(void); //输出部分（year>=2017) 
void Output2(void); //输出部分（year<2017)
void result1(void); //结果部分（year>=2017)
void result2(void); //结果部分（year<2017)
int tot=0,day,month,year;  //静态全局变量，方便管理 

int main(void)
{
	char q1[2];
    do
	{
		Input();
    	Output1();
   		Output2();
    	result1();
    	result2();
        printf("\nOnly enter \'q\' to quit:\n");
        do{
    	     scanf("%s",&q1);
    	     if(q1[1]!='\0')
    	       q1[1]='\0';
	      }while(isspace(q1[0]));
    }while(q1!='q');

    printf("Bye!");
    
    return 0;
}

void Input(void)
{
	printf("Please input year(>0):\n");
	Year();

	printf("Please input moth (1-12):\n");
    Month();
	  
	printf("Please input day (1-31):\n");
    Day();
    return ;
}

void Output1(void)
{
	int i;
	if(year>=2017)
	{
		for(i=2017;i<year;i++)
		    {
		    	if(i%4!=0||(i%100==0&&i%400!=0))
		    	tot+=365;
		    	if((i%4==0&&i%100!=0)||i%400==0)
		    	tot+=366;
			}
		for(i=2;i<=month;i++)
		{
			if(i==2)
			   tot+=31;
			if((i%4!=0||(i%100==0&&i%400!=0))&&i==3)
			   tot+=28;
			if(i==3&&((i%4==0&&i%100!=0)||i%400==0))
			   tot+=29;
			if(i>3&&i<=8)
			{
				if(i%2==0)
				 tot+=31;
				if(i%2==1)
				 tot+=30;
			}
			if(i>8)
			{
				if(i%2==0)
				 tot+=30;
				if(i%2==1)
				 tot+=31;
			}
		}
		tot+=day;	      
	}
	return ;
} 

void Output2(void)
{
	int i;
	if(year<2017)
	{
		for(i=2017;i>year;i--)
		    {
		    	if((i-1)%4!=0||((i-1)%100==0&&(i-1)%400!=0))
		    	tot+=365;
		    	if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0)
		    	tot+=366;
			}
		for(i=2;i<=month;i++)
		{
			if(i==2)
			   tot-=31;
			if(((i-1)%4!=0||((i-1)%100==0&&(i-1)%400!=0))&&i==3)
			   tot-=28;
			if(i==3&&(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0))
			   tot-=29;
			if(i>3&&i<=8)
			{
				if(i%2==0)
				 tot-=31;
				if(i%2==1)
				 tot-=30;
			}
			if(i>8)
			{
				if(i%2==0)
				 tot-=30;
				if(i%2==1)
				 tot-=31;
			}
		}
		tot=(tot-=day)+1;	      
	}
	return ;
} 

void Month(void)
{
	while(scanf("%d",&month)==1)  
	   {
        if(month<=12&&month>=1)
	        {
	        	break;
		    }
		printf("Your answer is false.Please input again.\n");
	  }
    return ;
}

void Day(void)
{
	while(scanf("%d",&day)==1)
	{
		int n=0;
      if(day>31||day<1)
	        {
	        	printf("Your answer is false.Please input again.\n");
	        	n=1;
			}	  
	  if(month==2&&(year%4!=0||(year%100==0&&year%400!=0)))
	    {
	    	if(day>28)
		    {
		  	  printf("Febrary doesn't have %d.Please input again.\n",day); 
		  	  n=1;
			}
		}
	  if(month==2&&((year%4==0&&year%100!=0)||year%400==0))
	    {
	    	if(day>29)
		    {
		  	  printf("Febrary doesn't have %d.Please input again.\n",day); 
		  	  n=1;
			}
		}  
	  if(month<=7&&month>2)
	  {
	  	if(month%2==0)
        {
        	if(day==31)
        	  {
        	  	printf("%d month doesn't have %d.Please input again.\n",month,day);
        	  	n=1;
			  }
		}
	  }
	  if(month<=12&&month>=8)
	  {
	  	if(month%2==1)
	    {
	    	if(day==31)
	    	  {
	    	  	printf("%d month doesn't have %d.Please input again.\n",month,day);
	    	  	n=1;
			  }
		}
	  }
	  if(n==0)
	   break;
	  }
	  return ;
}

void Year(void)
{
	while(scanf("%d",&year)==1)
	{
		if(year>0)
		break;
		printf("Please input again!\n");
	}
	return ;
}

void result1(void)
{
	if(year>=2017)
    {
    	printf("%d-%d-%d is ",year,month,day);
		switch(tot%7){
			case 1: printf("Sunday.");
			break;
			case 2: printf("Monday.");
			break;
			case 3: printf("Tuesday.");
			break;
			case 4: printf("Wednesday.");
			break;
			case 5: printf("Thursday.");
			break;
			case 6: printf("Friday.");
			break;
			case 0: printf("Saturday.");
			break;
		} 
	}
	return ;
}

void result2(void)
{
	if(year<2017)
    {
    	printf("%d-%d-%d is ",year,month,day);
		switch(tot%7){
			case 0: printf("Sunday.");
			break;
			case 6: printf("Monday.");
			break;
			case 5: printf("Tuesday.");
			break;
			case 4: printf("Wednesday.");
			break;
			case 3: printf("Thursday.");
			break;
			case 2: printf("Friday.");
			break;
			case 1: printf("Saturday.");
			break;
		} 
	}
	return ;
}


