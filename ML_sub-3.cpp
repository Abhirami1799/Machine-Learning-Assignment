#include<bits/stdc++.h>
#include "matplotlibcpp.h"
#include<sstream>

#define PI 3.1416
#define watch(m) cout<<m<<"\n";
int Size_arr[] = {10,100,1000,10000};
int index_size = 0;
using namespace std;
namespace plt= matplotlibcpp;

void displayvector(vector <double>);

double generator(float x)
{
  int rand();
  float m=(float)(rand()%Size_arr[index_size]);
  double y=sin(2*PI*x);
  double p=(1/(0.3*sqrt(2*PI)))*exp(-pow(m-0.5,2.0)/0.18);   //probability density function with mean=0.5 and S.D.=0.3
  return(y+=p);
}

void f1()
{
  default_random_engine generator;
  normal_distribution <double> variable(0.5,0.3);
  vector <double> v;
  for(int i=0; i<10;i++)
    { v.push_back(variable(generator));
  v[i]+=sin(2*PI*i/10);
    }
  for(int i=0; i<10; i++)
    cout<<v[i]<<endl;
    }

double hypothesis(vector <double> para, double x)
{
  int n=para.size();
  double h = 0;
  for(int i=0; i<n; ++i)
    h+=para[i]*pow(x,i);
  return(h);
}

double mse_cost(vector <double> para, vector <double> trainx, vector <double> trainy)
{
  double J=0;
  int m=trainx.size();
  for(int i=0; i<m; ++i)
    J+=pow(hypothesis(para,trainx[i])-trainy[i],2)/(2*m);
  return(J);
}

double cost(vector <double> para, vector <double> trainx, vector <double> trainy)
{
  double J=0;
  int m=trainx.size();
  for(int i=0; i<m; ++i)
    J+=pow(hypothesis(para,trainx[i])-trainy[i],4)/(2*m);
  return(J);
}

double differential(vector <double> para, int j, vector <double> trainx, vector <double> trainy)
{
  double D=0;
  int m=trainx.size();
  for(int i=0; i<m; ++i)
    D+=(hypothesis(para, trainx[i])-trainy[i])*pow(trainx[i],j)/m;
  return(D);
}

void learn_para(vector <double> &para, vector <double> trainx, vector <double> trainy, double lp)
{
  vector <double> temp;
  
  int n=para.size(), i;
  double t ;
  for(i=0; i<n; ++i)//i is the ith parameter
  {
    t=differential(para, i, trainx, trainy);
    temp.push_back(para[i]-lp*t);
  }
  
  for(i=0; i<n; ++i)
   para[i]=temp[i];
}

void find_target(int n, vector <double> &para, vector <double> trainx, vector <double> trainy, double lp)
{
  double J=0, J1=0;
  int i;
  para.clear();
  
  for(i=0; i<=n; ++i)
    para.push_back(100*(rand()%Size_arr[index_size])/Size_arr[index_size]);
  
  learn_para(para, trainx, trainy, lp);
  
  J=cost(para, trainx, trainy);
  
  while(1)
    {
      learn_para(para, trainx, trainy, lp);
      
      J1=cost(para, trainx, trainy);
      
      if(abs(J-J1)*1000<1.0) break;
      
      J=J1;
    }
}

/*void displayvector(vector <double> T)
{
  for(int i=0; i<T.size(); i++) cout << T[i] << " " ;
  cout << endl ;
}
*/


  
double pseudo_main()
{
  int j=0,p;
  vector <double> x,x1,x2;
  vector <double> y,y1,y2;
  //vector<float>::iterator q;
  vector <int> k;
  for(int i=0;i<Size_arr[index_size];++i)
    {
       x.push_back(((double)i)/Size_arr[index_size]);
       y.push_back(generator(x[i]));
    }
int sx=x.size(), sy=y.size();
/*for(int q=0;q<sx;++q)
  cout<<x[q]<<" "<<y[q]<<endl;*/
  // f1();

//training set-(x1,y1)
 
 srand(time(NULL));
     k.push_back(rand()%Size_arr[index_size]);
     x1.push_back(x[k[0]]);
     y1.push_back(y[k[0]]);
     for(int i=1;i<sx*0.8;++i)
       {
	  while(1)
	    {
	      p=rand()%Size_arr[index_size];
	      for(j=0;j<k.size();j++)
		if(k[j]==p)
		  break;
	      if(j<k.size())
		continue;
	      else
		{ k.push_back(p);
		  break;}
	    }
	  x1.push_back(x[p]);
	  y1.push_back(y[p]);
       }

 //test set-(x2,y2)

 for(int i=0; i<sx; ++i)
   {
     int c=0;
     for(j=0;j<k.size();++j)
       if(i==k[j])
	 c++;
     if(c!=0)
       continue;
     else
       { x2.push_back(x[i]);
	 y2.push_back(y[i]);
       }
       }
 /*cout<<endl;
 cout<<"Training set\n";
 for(j=0;j<x1.size();++j)
   cout<<x1[j]<<" "<<y1[j]<<" \n";
 cout<<endl;
 cout<<"Test set\n";
 for(j=0;j<x2.size();++j)
 cout<<x2[j]<<" "<<y2[j]<<" \n";*/
 

 //Learning target function
 
 vector <double> para, h;
 vector <double> test_error, train_error;
 double min_error;
 int u=1;

//Displaying test errors for different degree curves



//**********************************************************************************************************************************************
//Question-2
//**********************************************************************************************************************************************


//Plotting y vs x (synthesized data set)

 plt::plot(x,y);
 stringstream st;
 st<<Size_arr[index_size];
 plt::title("Synthesized data set for size: " + st.str());
 plt::show();

vector< double > error;

//Plotting hypotheses against x

 for(j=1; j<10; ++j)//j is degree of hypothesis
   {
     para.clear();
     find_target(j, para, x1, y1, 0.05);
     test_error.push_back(cost(para, x2, y2));
     train_error.push_back(cost(para, x1, y1));
     error.push_back(cost(para, x, y));
     h.clear();
     cout<<"-----degree is-----"<<j<<endl;
     for(int g=0; g<sx; ++g)
       {
	 h.push_back(hypothesis(para, x[g]));
   }
     plt::plot(x,h);
     stringstream ss,st;
     ss<<j;
     st<<Size_arr[index_size];
     plt::title("Hypothesis for degree "+ss.str() + ", data size " + st.str());
     plt::show();
   //   int flag = 0;
   //   int dummy;
   //    cout<<"\nClose the current window and enter 1 for the next plot"<<endl;
   //    while(!flag)//waiting for button press to switch to next iteration
   //    {
	  // cin>>dummy;
	  // if(dummy == 1)
	  //   {
	  //   flag = 1;
	  //   break;
	  //   }
   //     }
   }
   cout<<"\nTest errors for different degrees of polynomials\n";
 for(j=0;j<test_error.size();++j)
   cout<<test_error[j]<<" for degree "<<j+1<<endl;
 
//Finding degree with minimum test error
 min_error=error[0];
u=1;
 for(j=1; j<error.size(); ++j)
   if(error[j]*100<min_error*100)
     {u=j+1;
      min_error=error[j];
      }
 cout<<"\n\nDegree that fits the data best:"<<u<<"\n\n";

vector <int> degree;
for(j=1;j<10;++j)
degree.push_back(j);
plt::plot(degree, test_error,"bo");
plt::plot(degree, train_error,"ro");
plt::title("Test_error in blue & Train_error in red for data size " + st.str());
plt::show();

vector <double> rmse;

double learn_arr[] = {0.025, 0.05, 0.1, 0.2,0.5};
for(j = 0; j < 5; j++)
{
    para.clear();
    find_target(u,para, x1,y1, learn_arr[j]);
    rmse.push_back(sqrt(mse_cost(para,x2,y2)));
    cout<<"\nRMSE for different learning parameters\n";
    cout<<"Learning parameters:"<<learn_arr[j]<<"____ RMSE:"<<rmse[j]<<endl;

}

plt::plot(learn_arr,rmse,"go");
plt::title("RMSE vs Learning Parameters for data size "+ st.str());
plt::show();
return(rmse[1]);
}

int main()
{
  int j=0;
  vector <int> Size_vec;
  cout<<"Different dataset sizes available are:\n";
  for(j=0;j<4;++j)
  {
    Size_vec.push_back(Size_arr[j]);
    cout<<Size_arr[j]<<"\t";
  }
   vector <double> error_size;
  for(j=0; j<4; ++j)
  {
    cout<<"\n\nSolving for data size: "<<Size_arr[j]<<endl;
    index_size=j;
    error_size.push_back(pseudo_main());
  }
  //long int fig = plt::figure()
  plt::plot(Size_vec,error_size);
  plt::title("Learning curve vs Size");
  plt::show();
return(0);

}
  
  
