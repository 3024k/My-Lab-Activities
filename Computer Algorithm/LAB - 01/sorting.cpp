#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    FILE *fp;  // File declaration
    int n,r1,r2,choose,test;
    double t1,t2,t3,t4,t5,t6;
    cout<<"\nHow many tests ? ";    // Prompt for no.of data test
    cin>>test;
    cout<<"\nRandom numbers ranging from _ to _ ";  //Prompt for range of random numbers
    cin>>r1>>r2;
    fp=fopen("D:\\lab_1.txt","w+");  //Opening file in 'D' Drive
    choose=1;
    while(choose<=test){
    cout<<"\nHow many numbers do you want to sort? ";//Prompt for the no. of data in each test
    cin>>n;
    int NUM[n],a[n],b[n],i,p,t,j,value,min;
    srand(time(0));
    fprintf(fp,"\nGenerated Random Numbers are:\n\n");
    for(i=0;i<n;i++){
        NUM[i]=(r1+rand()%(r2-r1));
        fprintf(fp,"%d\t",NUM[i]);
        a[i]=NUM[i];
        b[i]=NUM[i];
    }
    fprintf(fp,"\n");
    //Bubble sort and recording the start time
    t1=clock();
    for(i=0;i<n;i++){
        for(p=0;p<n-i;p++){
            if(NUM[p]>NUM[p+1]){
                t=NUM[p];
                NUM[p]=NUM[p+1];
                NUM[p+1]=t;
            }
        }
    }
    t2=clock();//recording the end time
    fprintf(fp,"\nAfter sorting by Bubble sort:\n\n");
    for(i=0;i<n;i++){
        fprintf(fp,"%d\t",NUM[i]);
    }
    fprintf(fp,"\n");
    //Selection sort and recording the start time
    t3=clock();
    for(i=0;i<=n-2;i++){
        min=i;
        for(j=i+1;j<=n-1;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(i!=min){
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }

    }
    t4=clock();//recording the end time
    fprintf(fp,"\nAfter sorting by Selection sort:\n");
    for(i=0;i<n;i++){
        fprintf(fp,"%d\t",a[i]);
    }
    fprintf(fp,"\n");
    //Insertion sort and recording the start time
    t5=clock();
    for(i=1;i<n;i++){
        value=b[i];
        int j=i;
        while(j>0&&b[j-1]>=value){
            b[j]=b[j-1];
            --j;
        }
        b[j]=value;
    }
    t6=clock();//recording the end time
    fprintf(fp,"\nAfter sorting by Insertion sort:\n");
    for(i=0;i<n;i++){
        fprintf(fp,"%d\t",b[i]);
    }
    fprintf(fp,"\n");

    cout<<"\n\nNo. of data\tBubble Sort\tSelection Sort\tInsertion Sort\n\n";
    cout<<n<<"\t\t"<<difftime(t2,t1)/CLOCKS_PER_SEC<<"\t\t"<<
    difftime(t4,t3)/CLOCKS_PER_SEC<<"\t\t"<<difftime(t6,t5)/CLOCKS_PER_SEC<<"\n\n";
    choose++;
    }//end of while
}//end of main
