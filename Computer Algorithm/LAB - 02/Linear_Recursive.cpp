#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std;

int N,i,key,r1,r2,count,test,choice,DATA[50000],ans;
bool flag;
double t1,t2;
int linearSearch(int num,int position)
{
    count++;
    if(num==DATA[position])
    {
        return position+1;
    }
    else
    {
        position++;
        return linearSearch(num,position);
    }

    return count;

}

int main()
{
    FILE *fp;
    fp = fopen("D:\\linearRecursive.txt","w+");

    cout<<"\nHow many tests ?:> ";    // Prompt for no.of data test
    cin>>test;
    cout<<"\nRandom numbers ranging from _ to _:> ";  //Prompt for range of random numbers
    cin>>r1>>r2;
    choice = 1;
    while(choice<=test){
        cout<<"\nHow many data on test no."<<choice<<" :> ";

        cin>>N;
        //int DATA[N];
        srand(time(0));
        fprintf(fp,"\nGenerated Random Numbers are on test - %d:\n\n",choice);
        for(i=0;i<N;i++){
            DATA[i]=(r1+rand()%(r2-r1));
            fprintf(fp,"%d\t",DATA[i]);
        }
        fprintf(fp,"\n");
        cout<<"\nEnter the number which is to be searched:> ";
        cin>>key;
        count = 0;
        t1=clock();
        ans=linearSearch(key,0);
        t2= clock();
        if(ans<=N){
            cout<<endl<<key<<" is found at the position "<<ans<<"(position starts at 1)"<<endl;
           // printf("Number %d found,position is %d ,Time complexity is %d",srch,ans,count);
        }
        else{
            cout<<endl<<key<<" is not found in the list\n";
        }
        double time = difftime(t2,t1)/CLOCKS_PER_SEC;
        if(time==0){
            time = (double)(count*.000001);
        }
        cout<<"\nStep = "<<count<<endl;
        cout<<"\nNUM_of_DATA\tRequired Time\n\n";
        cout<<N<<"\t\t"<<time<<endl;
        choice++;
    }
}
