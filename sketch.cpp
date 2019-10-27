#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
//#include <unistd.h>
#include<Windows.h>


using namespace std;


int main(){
	
	//g20 countries down bellow
	
	string names[19]={"Australia","Canada","Saudi arabia","United States","India","Russia","South Africa","Turkey","Argentina","Brazil","Mexico","France","Germany","Italy","UK","China","Indonesia","Japan","South Korea"};
  
  string name;
  string country;
  int pos1,pos2;
  
    double wfoughts[19]={13,20,51,121,107,171,15,19,34,63,43,168,27,33,158,32,90,38,6};
  
    double won[19]={8,17,30,95,67,110,7,12,17,59,34,109,14,24,110,13,67,22,4}; 
  cout<<"Hello user, my name is WS1, tell me your name: ";

  getline(cin,name);

  cout<<"Welcome "<<name<<", This is the first version of the G20 War simulator, our goal is to calculate the odds of a country winning a war based in the information the other one has, in this first version we are only using the G20 countries, excluding the EU"<<endl<<endl;

cout<<"Take a look at the G20 countries: "<<endl<<endl;

  //for(int i=0;i<19;i++){
    //cout<<names[i]<<" Fought = "<<wfoughts[i]<<" Won = "<<won[i]<<endl;
    //Sleep(200);
 // } 
  
  
  for(int i=0;i<19;i++){
    cout<<names[i]<<endl;
    Sleep(6);
 }
  
  cout<<"Choose the first country: ";
  getline(cin,country);
  
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos1=i;
	  }
  }
  
  cout<<country<<" Fought "<<wfoughts[pos1]<<" wars and won "<<won[pos1]<<endl;
  
  cout<<"Choose the second country(the one you are supposed to comparate): ";
  
    getline(cin,country);
  
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos2=i;
	  }
  }
  
  cout<<country<<" Fought "<<wfoughts[pos2]<<" wars and won "<<won[pos2]<<endl;
  
  //calculating the odds
  
  double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  
  cout<<" The odds of "<<names[pos1]<<" winning a war, when compared to the odds of "<<names[pos2]<<" winning it, are ";
  
  if(round(oddsratio)<2&&round(oddsratio)>=1){
  	cout<<"almost the same";
  }else if(round(oddsratio)<1){
  	
  	cout<<setprecision(2)<<oddsratio<<" times worse";
  
  	
  }else{
  	
  	cout<<fixed<<setprecision(2)<<oddsratio<<" times superior";
  }
  
  //confidence interval and significance
  //ci = exp(log(or) ± Zl/2­*v1/a + 1/b + 1/c + 1/d), Z is the critical value, and it's supposed to be 1,96, cause we are calculating for a 95% confidence interval
  //or is the odds ratio
  //a is supposed the number of winnings by the 1nd country
  //b is supposed to be the number of it's losses
  //c is supposed to be the number of wars won by the 2nd country
  //d is supposed to be the number of losses by the 2nd
  
  double cisup=exp(log(oddsratio)+(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));
    double cinf=exp(log(oddsratio)-(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));
    
    cout<<endl;
    cout<<"It's confidence interval is given by the range of:"<<endl;
    cout<<fixed<<setprecision(2)<<"CI :("<<cinf<<" - "<<cisup<<")"<<endl;

  
  
  
  
  return 0;
  
}
