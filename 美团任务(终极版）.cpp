#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
void shu(int);         //输出花色 
void number1(int,int); //输入牌数 
int number2(int);   //记录数值 
int miss(void);   //按键判断 
int main(void)
{
	int u;
	char input;
	srand((unsigned)time(NULL));
	
	printf("请输入你的按键来验证是否按键正常：(q结束验证)\n"); //按键检验开始 
    while(scanf("%c",&input)==1)
    {
    	if(input!='q')
    	  printf("%c",input);
    	if(input=='q')
    	  {
		    printf("检验完成！\n");
		    break;
		  }
		continue; 
	}
	                             //检验结束 
	do{
		
	  int a[52],b[52],c[52]; //a为排数，b判断重复，c为花色 
	  int i;//【】里面的数值 
	  
	
	  for(i=0;i<=51;i++)    //b[52]初始值 
	  {
		
		  b[i]=0;
		
	  }
	
	  for(i=0;i<=51;i++)   //随机a[52]旳值 
	  {
		  int f;
	      do
		  {
		      f=1;
			  a[i]=rand()%52+1;
			  b[a[i]]++;
			  if(b[a[i]]==2)   //防止a[52]重复 
			  {
				  b[a[i]]=1;
				  f=0;
			  }
			  
		  }while(f==0);
		
	  }
	
       for(i=0;i<=51;i++)
       {
		   c[i]=(a[i]-1)/13+1;   //花色 
		 
	   }
	 
	  

      printf("祝你游戏愉快！");
      printf("现在开始游戏(请输入y,n;q退出)\n");
    
      int m,n;   //甲方乙方的总数值 
	  int r1,r2; //甲乙的每次的牌数 
	  int w;     //用于删牌 
	  int s1,s2; //用于判断是否接受牌 
	  m=n=w=0;
        while(m<=21&&n<=21)
		{ 
           i=rand()%(52-w);
           if(m==0)
           printf("开始分发甲方的牌:\n");
           else
           {
       	    printf("请甲方开始要牌：（y要牌，n不要）\n");
       	    s1=miss();
	       }
	   
           if(m==0||s1==1)
	       {
       	    number1((a[i]-1)%13+1,c[i]);
		    r1=number2((a[i]-1)%13+1);
		    m+=r1;
		    w++;
		    for(;i<=(51-w);i++)  //删去打出的牌 
	  	      {
	  			  a[i]=a[i+1];
	  			  c[i]=c[i+1];
	  		  }
	       }
	       
	       printf("甲方的总数值是：%d\n",m);
	       
	       if(m>21)   //防止甲方爆牌 
	       {
	   	     break;
	       } 
		   
		    
           i=rand()%(52-w);
           if(n==0)
           printf("开始分发乙方的牌:\n");
           else
           {
       	    printf("请乙方开始要牌：（y要牌，n不要）\n");
       	    s2=miss();
	       } 
	   
           if(n==0||s2==1)
	       {
       	    number1((a[i]-1)%13+1,c[i]);
		    r2=number2((a[i]-1)%13+1);
		    n+=r2;
		    w++;
		    for(;i<=(51-w);i++)  //删去打出的牌 
	  	      {
	  			  a[i]=a[i+1];
	  			  c[i]=c[i+1];
	  		  }
	       }
	       
	       printf("乙方的总数值是：%d\n",n);
	   
	       if(s1==2&&s2==2)  //两个n退出 
	        {
	    	  puts("双方都没要牌,开始比分！");
			  s1=0;
			  s2=0; 
			  break;
		    } 
	    }
	  //开始判断结果 
	  if(m>21)
	   printf("甲爆牌！乙获胜！恭喜！\n"); 
	  if(n>21)
	   printf("乙爆牌！甲获胜！恭喜！\n");
	  if(m<=21&&n<=21)
	    {
	  	  if(m==n)
	   	  printf("push!平局！\n");
	  	  if(m>n)
	  	  printf("甲获胜！恭喜！\n");
	  	  if(m<n)
	  	  printf("乙获胜！恭喜！\n");
	    }
	   
	  printf("你还想再来一局吗？（y再来，n退出):\n"); 
	  u=miss();
	   
    }while(u==1); 
	  printf("游戏结束！谢谢参与\n");

	  return 0;
 }

void number1(int t,int r)
{
	shu(r);
	if(t==1)
	    printf("A\n"); 
    if(t<=10&&t>1)
      	printf("%d\n",t);
    if(t>10)
      {
	    switch(t)
		{
	    case 11:printf("J\n");
	    break;
	    case 12:printf("Q\n");
	    break;
	    case 13:printf("K\n");
	    break;
		}
	  }
    return ; 
}
	  
int number2(int t)
{
	int r;
	if(t==1)
	  	r=11;
	
    if(t<=10&&t>1)
      	r=t;
    
    if(t>10)
      	r=10;
    
	return r;
}

 
int miss(void)
{
	int w=0;
	char ch[2];
	do{
		  scanf("%s",ch);
          if(ch[1]!='\0')
           {
           	printf("你输入了多个字母，请重新输入：\n");
			continue; 
		   }  
		  if(ch[0]!='\n')
		  {
		    if(ch[0]=='q')
	          printf("Bye\n");
	         
	        if(ch[0]=='y')
	        {
	   	     printf("OK\n");
	   	     w=1;
	   	     ch[0]='q';
	        }
	        
	        if(ch[0]=='n')
	        {
	   	     printf("Not bad\n");
	   	     w=2;
	   	     ch[0]='q';
	        }
	        
	        	
	        if(ch[0]!='n'&&ch[0]!='y'&&ch[0]!='q')
	        {
		      printf("你输入的字母错误！请重新输入\n");
		      continue; 
	        }
		   }
		   
	    }while(ch[0]!='q'||ch[1]!='\0');
	return  w;
}


void shu(int m)
{
	switch(m){
		case 1:printf("黑桃");
		break;
		case 2:printf("红心");
		break;
		case 3:printf("梅花");
		break;
		case 4:printf("红方");
		break; 
	}
	return ;
}

