#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class worker {
    private:
        int n;
        //int existance;
        int startT;
        int endT;
        int* payment;
        int* start;
        int* end;
        int** paymentB;
        string** workerB;
    public:
        worker(int n,int startT,int endT, int* payment, int* start,int* end){
            this->n=n;
            //existance=true;
            this->startT=startT;
            this->endT=endT;
            this->start=new int[n];
            this->end=new int[n];
            this->payment=new int[n];
            paymentB = new int*[1000];
                for(int i = 0; i <1000; i++)
                paymentB[i] = new int[1000];
            workerB = new string*[1000];
                for(int i = 0; i<1000; i++)
                workerB[i] = new string[1000];
            for(int i=0;i<1000;i++){
                for(int j=0;j<1000;j++){
                    paymentB[i][j]=9999999;
                    workerB[i][j]="/0";
                }
            }
            for(int i=0;i<=n;i++){
                this->start[i]=start[i];
                this->end[i]=end[i];
                this->payment[i]=payment[i];
            }

        }
        void solve(){
            int paymentT=0;
            int start_temp=0,end_temp=0,time=0;
            for(int i=0;i<n;i++)
            {

                start_temp=start[i];
                end_temp=end[i];
                time=end_temp-start_temp;
                while(start_temp<end_temp)
                {
                    if(payment[i]<paymentB[start_temp][start_temp+1])
                    {
                        paymentB[start_temp][start_temp+1]=payment[i];
                        stringstream ss;
                        ss << i;
                        string s;
                        ss >> s;
                        workerB[start_temp][start_temp+1]=s;
                        //cout<<workerB[start_temp][start_temp+1];
                    }
                    start_temp++;
                }
                time*=payment[i];
                //cout<<paymentB[start_temp][end_temp]<<""<<time<<endl;
                if(time<paymentB[start_temp][end_temp]){
                    paymentB[start_temp][end_temp]=time;
                    stringstream ss;
                    ss << i;
                    string s;
                    ss >> s;
                    workerB[start_temp][end_temp]=s;
                }
            }

            for(int k=startT+1;k<=endT;k++)
            {
                for(int i=startT;i<endT;i++){
                    for(int j=startT+2;j<=endT;j++){
                        if(paymentB[i][k]+paymentB[k][j]<paymentB[i][j])
                        {
                        paymentB[i][j]=paymentB[i][k]+paymentB[k][j];
                        workerB[i][j]=workerB[i][k]+"/"+workerB[k][j];
                        }


                    }
                }
            }
            paymentT =paymentB[startT][endT];


            cout<<"payment is :"<<paymentT<<endl;
            cout<<"workers are :"<<workerB[startT][endT]<<endl;

        }
};
int main(){
    int n;
    int startT;
    int endT;
    int* payment;
    int* start;
    int* end;
    start=new int[n];
    end=new int[n];
    payment=new int[n];

    cout<<"Enter starting time: "<<endl;
    cin>>startT;
    cout<<"Enter finishing time: "<<endl;
    cin>>endT;
    cout<<"Enter number of workers: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      cout<<"enter start & end time & payment per hour of worker number "<<i<<endl;
      cin>>start[i];
      cin>>end[i];
      cin>>payment[i];
    }
    worker workers(n,startT,endT,payment,start,end);
    workers.solve();
    delete end;
    delete start;
    delete payment;
}
