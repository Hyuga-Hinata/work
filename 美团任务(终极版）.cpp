#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
void shu(int);         //�����ɫ 
void number1(int,int); //�������� 
int number2(int);   //��¼��ֵ 
int miss(void);   //�����ж� 
int main(void)
{
	int u;
	char input;
	srand((unsigned)time(NULL));
	
	printf("��������İ�������֤�Ƿ񰴼�������(q������֤)\n"); //�������鿪ʼ 
    while(scanf("%c",&input)==1)
    {
    	if(input!='q')
    	  printf("%c",input);
    	if(input=='q')
    	  {
		    printf("������ɣ�\n");
		    break;
		  }
		continue; 
	}
	                             //������� 
	do{
		
	  int a[52],b[52],c[52]; //aΪ������b�ж��ظ���cΪ��ɫ 
	  int i;//�����������ֵ 
	  
	
	  for(i=0;i<=51;i++)    //b[52]��ʼֵ 
	  {
		
		  b[i]=0;
		
	  }
	
	  for(i=0;i<=51;i++)   //���a[52]�Aֵ 
	  {
		  int f;
	      do
		  {
		      f=1;
			  a[i]=rand()%52+1;
			  b[a[i]]++;
			  if(b[a[i]]==2)   //��ֹa[52]�ظ� 
			  {
				  b[a[i]]=1;
				  f=0;
			  }
			  
		  }while(f==0);
		
	  }
	
       for(i=0;i<=51;i++)
       {
		   c[i]=(a[i]-1)/13+1;   //��ɫ 
		 
	   }
	 
	  

      printf("ף����Ϸ��죡");
      printf("���ڿ�ʼ��Ϸ(������y,n;q�˳�)\n");
    
      int m,n;   //�׷��ҷ�������ֵ 
	  int r1,r2; //���ҵ�ÿ�ε����� 
	  int w;     //����ɾ�� 
	  int s1,s2; //�����ж��Ƿ������ 
	  m=n=w=0;
        while(m<=21&&n<=21)
		{ 
           i=rand()%(52-w);
           if(m==0)
           printf("��ʼ�ַ��׷�����:\n");
           else
           {
       	    printf("��׷���ʼҪ�ƣ���yҪ�ƣ�n��Ҫ��\n");
       	    s1=miss();
	       }
	   
           if(m==0||s1==1)
	       {
       	    number1((a[i]-1)%13+1,c[i]);
		    r1=number2((a[i]-1)%13+1);
		    m+=r1;
		    w++;
		    for(;i<=(51-w);i++)  //ɾȥ������� 
	  	      {
	  			  a[i]=a[i+1];
	  			  c[i]=c[i+1];
	  		  }
	       }
	       
	       printf("�׷�������ֵ�ǣ�%d\n",m);
	       
	       if(m>21)   //��ֹ�׷����� 
	       {
	   	     break;
	       } 
		   
		    
           i=rand()%(52-w);
           if(n==0)
           printf("��ʼ�ַ��ҷ�����:\n");
           else
           {
       	    printf("���ҷ���ʼҪ�ƣ���yҪ�ƣ�n��Ҫ��\n");
       	    s2=miss();
	       } 
	   
           if(n==0||s2==1)
	       {
       	    number1((a[i]-1)%13+1,c[i]);
		    r2=number2((a[i]-1)%13+1);
		    n+=r2;
		    w++;
		    for(;i<=(51-w);i++)  //ɾȥ������� 
	  	      {
	  			  a[i]=a[i+1];
	  			  c[i]=c[i+1];
	  		  }
	       }
	       
	       printf("�ҷ�������ֵ�ǣ�%d\n",n);
	   
	       if(s1==2&&s2==2)  //����n�˳� 
	        {
	    	  puts("˫����ûҪ��,��ʼ�ȷ֣�");
			  s1=0;
			  s2=0; 
			  break;
		    } 
	    }
	  //��ʼ�жϽ�� 
	  if(m>21)
	   printf("�ױ��ƣ��һ�ʤ����ϲ��\n"); 
	  if(n>21)
	   printf("�ұ��ƣ��׻�ʤ����ϲ��\n");
	  if(m<=21&&n<=21)
	    {
	  	  if(m==n)
	   	  printf("push!ƽ�֣�\n");
	  	  if(m>n)
	  	  printf("�׻�ʤ����ϲ��\n");
	  	  if(m<n)
	  	  printf("�һ�ʤ����ϲ��\n");
	    }
	   
	  printf("�㻹������һ���𣿣�y������n�˳�):\n"); 
	  u=miss();
	   
    }while(u==1); 
	  printf("��Ϸ������лл����\n");

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
           	printf("�������˶����ĸ�����������룺\n");
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
		      printf("���������ĸ��������������\n");
		      continue; 
	        }
		   }
		   
	    }while(ch[0]!='q'||ch[1]!='\0');
	return  w;
}


void shu(int m)
{
	switch(m){
		case 1:printf("����");
		break;
		case 2:printf("����");
		break;
		case 3:printf("÷��");
		break;
		case 4:printf("�췽");
		break; 
	}
	return ;
}

