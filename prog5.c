#include <stdio.h>
#include<stdlib.h>
struct process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int st;
    
};
int comparator(const void *p,const void *q)
{
    struct process *p1=(struct process*)p;
    
    struct process *p2=(struct process*)q;
    if(p1->at>=p2->at)
    return 1;
    else return -1;
}
int main()
{
  int n;
  printf("add no of processes\n");
  scanf("%d",&n);
 struct process p[n];
  for(int i=0;i<n;i++)
  {
      printf("enter %d process arrival time and burst time\n",i+1);
      scanf("%d%d",&p[i].at,&p[i].bt);
  }
  qsort(p,n,sizeof(struct process),comparator);
  p[0].ct=p[0].at+p[0].bt;
  p[0].tat=p[0].ct-p[0].at;
  p[0].wt=p[0].tat-p[0].bt;
  p[0].rt=p[0].ct-p[0].bt;
  int idle_time=0;
  float avg_tat=p[0].tat;
  float avg_wt=p[0].wt;
  float avg_rt=p[0].rt;
   int i=1;
   while(i<n)
   {
       if(p[i].at>=p[i-1].ct)
       {
            p[i].ct=p[i].at+p[i].bt;
       }
       else  p[i].ct=p[i-1].ct+p[i].bt;
       i++;
   }
    i=1;
  while(i<n)
  {
      
       p[i].tat=p[i].ct-p[i].at;
       p[i].wt=p[i].tat-p[i].bt;
       p[i].rt=p[i].ct-p[i].bt;
       avg_tat+=p[i].tat;
       avg_wt+=p[i].wt;
       avg_rt+=p[i].rt;
       if(p[i].at>p[i-1].at)
       {
           int temp=p[i].at-p[i-1].at;
           idle_time+=temp;
       }
       
       i++;
  }
  printf("printing process.........\n");
  printf("p_name  AT   BT   CT   TAT   WT   RT\n");
  for(int j=0;j<n;j++)
  {
      printf("   P%d    %d    %d    %d   %d    %d    %d\n",j+1,p[j].at,p[j].bt,p[j].ct,p[j].tat,p[j].wt,p[j].rt);
  }
  float length_cycle=p[n-1].ct;
  float cpu_utilization=(idle_time/length_cycle);
  cpu_utilization*=100;
  
  printf("averge turn around time of total process==> %f\n",avg_tat/n);
  printf("averge turn waiting time of total process==> %f\n",avg_wt/n);
  printf("averge response time of total process==> %f\n",avg_rt/n);
  printf("total cpu idle time==> %d\n",idle_time);
  printf("total cpu utilization==>%f\n",cpu_utilization);
  printf("throughput==> %f\n",n/(length_cycle));
  
  
      
  
  
}
