#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
//#include <unistd.h>
#include<Windows.h>


using namespace std;

double odds(double won[],double wfoughts[],int pos1,int pos2){
	double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  
  return oddsratio;
}//function to calculate the odds ratio

  //confidence interval and significance
  
  //ci = exp(log(or) ± Zl/2­*v1/a + 1/b + 1/c + 1/d), Z is the critical value, and it's supposed to be 1,96, cause we are calculating for a 95% confidence interval
  //or is the odds ratio
  //a is supposed the number of winnings by the 1nd country
  //b is supposed to be the number of it's losses
  //c is supposed to be the number of wars won by the 2nd country
  //d is supposed to be the number of losses by the 2nd
double cinsup(double won[],double wfoughts[],int pos1,int pos2){
	
	double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  
    double cisup=exp(log(oddsratio)+(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//superior
return cisup;
}
double cinf(double won[],double wfoughts[],int pos1,int pos2){
	
	double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  
      double cinf=exp(log(oddsratio)-(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//inferior

return cinf;
}


//building some recursive algorithms 

int search(int i,string country,string names[],int size){
    	
		if(i<size){
		
		if(names[i]!=country){
    		return search(i + 1,country,names,size);
			
			
			
			}else if(names[i]==country){
				return i;
			
			
		}
		
		}else{
			return 19;
		}
	}//recursive search


int recursiveSleep(int i,int size){
	if(i<size){
		
		Sleep(i);
		return recursiveSleep(i+1,size);
	}
}

int recursivePrint(int size,int i, string names[]){
 	if(i<size){
 		cout<<names[i]<<endl;
 		Sleep(200);
 		return recursivePrint(size,i+1,names);
	 }
 }

int main(){
	int freq=0;
	//g20 countries down bellow
	cout<<"Choose your language/Escolha seu idioma"<<endl;
	cout<<"Press 0 for english/Aperte um numero diferente de 0 para portugues"<<endl;
	int language;
	
	cin>>language;
	cin.ignore();
	string names[19]={"Australia","Canada","Saudi Arabia","United States","India","Russia","South Africa","Turkey","Argentina","Brazil","Mexico","France","Germany","Italy","Uk","China","Indonesia","Japan","South Korea"};
	string namesbr[19]={"Australia","Canada","Arabia Saudita","Estados Unidos","India","Russia","Africa Do Sul","Turquia","Argentina","Brasil","Mexico","Franca","Alemanha","Italia","Reino Unido","China","Indonesia","Japao","Coreia Do Sul"};

  string name;
  string country;
  int pos1,pos2;
  
    double wfoughts[19]={13,20,51,121,107,171,15,19,34,63,43,168,27,33,158,32,90,38,6};
  
    double won[19]={8,17,30,95,67,110,7,12,17,59,34,109,14,24,110,13,67,22,4}; 
  if(language==0){
  
  while(1){
  if(freq==0){
  
  cout<<"Hello user, my name is WS1, tell me your name: ";

  getline(cin,name);
  
  name[0]=toupper(name[0]);
  
  int tamnam=name.size();
  
  for(int i=0;i<tamnam;i++){
  	
  	if(name[i]==' '){
  		name[i+1]=toupper(name[i+1]);
	  }
  	
  }//all the first letters of the names and surnames to upper case

  cout<<"Welcome "<<name<<", This is the first version of the G20 War simulator, our goal is to calculate the odds of a country winning a war based in the information the other one has, in this first version we are only using the G20 countries, excluding the EU"<<endl<<endl;
}

cout<<"Take a look at the G20 countries: "<<endl<<endl;

  
  recursivePrint(19,0,names);
  
  int tamc;
  pos1=19;
  while(pos1==19){
   cout<<"Choose the first country: ";

  getline(cin,country);
  
   tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
  pos1=search(0,country,names,19);
  if(pos1==19){
  	cout<<endl;
  	cout<<country<<" Is not available in our database, please select one of the following:"<<endl<<endl;
  	  recursivePrint(19,0,names);
  	  
  }
}
  cout<<country<<" Fought "<<fixed<<setprecision(0)<<wfoughts[pos1]<<" wars and won "<<fixed<<setprecision(0)<<won[pos1]<<endl<<endl;
  
  
     pos2=19;
  while(pos2==19){
  	  cout<<"Choose the second country(the one you are supposed to comparate): ";

  
  getline(cin,country);
  
   tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
  pos2=search(0,country,names,19);
  if(pos2==19){
  	cout<<endl;
  	cout<<country<<" Is not available in our database, please select one of the following:"<<endl<<endl;
  	  recursivePrint(19,0,names);
  }
}
  cout<<country<<" Fought "<<fixed<<setprecision(0)<<wfoughts[pos2]<<" wars and won "<<fixed<<setprecision(0)<<won[pos2]<<endl;
  
  //calculating the odds
  
  
  cout<<endl;
  cout<<" The odds of "<<names[pos1]<<" winning a war, when compared to the odds of "<<names[pos2]<<" winning it, are ";
  
  if(round(odds(won,wfoughts,pos1,pos2))<2&&round(odds(won,wfoughts,pos1,pos2))>=1){
  	cout<<"almost the same";
  }else if(round(odds(won,wfoughts,pos1,pos2))<1){
  	
  	cout<<setprecision(2)<<odds(won,wfoughts,pos1,pos2)<<" times worse";
  
  	
  }else{
  	
  	cout<<fixed<<setprecision(2)<<odds(won,wfoughts,pos1,pos2)<<" times superior";
  	
  }
  cout<<endl;
  
    
    cout<<endl<<endl;
    cout<<"The confidence interval for this measure is given by the range of:"<<endl;
    
    cout<<fixed<<setprecision(2)<<"CI :("<<cinf(won,wfoughts,pos1,pos2)<<" - "<<cinsup(won,wfoughts,pos1,pos2)<<")"<<endl<<endl;


if(cinf(won,wfoughts,pos1,pos2)>0&&cinf(won,wfoughts,pos1,pos2)<=1&&cinsup(won,wfoughts,pos1,pos2)>=1){
	cout<<"But these results have no significance which means you may be being tricked"<<endl;
}
  
  cout<<"Would you like to continue?"<<endl;
  
  cout<<"Yes or No? Please insert (no) or (No) if you desire to turn off the program, otherwhise the program will keep going :D R = ";
  
  string opt;
  
  cin>>opt;
  cin.ignore();
  
  if(opt=="no"||opt=="No"){
  	cout<<"Well, it was nice to meet you "<<name<<endl;
  	recursiveSleep(0,20);
  	cout<<"See you soon!"<<endl;
  	  	recursiveSleep(0,20);

  	cout<<"I hope..."<<endl;
  	  	recursiveSleep(0,20);

  	cout<<":D"<<endl;
  
  return 0;
  
  }
  freq++;
}
}else{
	
	 while(1){
  if(freq==0){
  
  cout<<"Ola usuario,meu nome e WS1, me conte seu nome: ";

  getline(cin,name);
  
  name[0]=toupper(name[0]);
  
  int tamnam=name.size();
  
  for(int i=0;i<tamnam;i++){
  	
  	if(name[i]==' '){
  		name[i+1]=toupper(name[i+1]);
	  }
  	
  }//all the first letters of the names and surnames to upper case

cout<<"Bem vindo "<<name<<", esta e a primeira versao do simulador de guerra do G20, nosso objetivo e calcular as chances de um pais vencer uma guerra com base nas informacoes que o outro possui, nesta primeira versao estamos usando apenas os paises do G20, excluindo a UE."<< endl << endl;
}
cout<<"De uma olhada nos paises do G20: "<<endl<<endl;

  
    recursivePrint(19,0,namesbr);


  int tamc;
  
    

       pos1=19;
  while(pos1==19){
  cout<<"Escolha o primeiro pais: ";

  
  getline(cin,country);
  
   tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
pos1=search(0,country,namesbr,19);

  if(pos1==19){
  	cout<<endl;
  	cout<<country<<" Nao esta disponivel na nossa base dados, por favor selecione um dos seguintes:"<<endl<<endl;
  	  recursivePrint(19,0,namesbr);
  }
}
  
  cout<<country<<" Lutou "<<fixed<<setprecision(0)<<wfoughts[pos1]<<" guerras e ganhou "<<fixed<<setprecision(0)<<won[pos1]<<endl<<endl;
  
  
    
       pos2=19;
  while(pos2==19){
  cout<<"Escolha o segundo pais(aquele que usara para como comparacao): ";

  
  getline(cin,country);
  
   tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
pos2=search(0,country,namesbr,19);

  if(pos2==19){
  	cout<<endl;
  	cout<<country<<" Nao esta disponivel na nossa base dados, por favor selecione um dos seguintes:"<<endl<<endl;
  	  recursivePrint(19,0,namesbr);
  }
}

  
  cout<<country<<" Lutou "<<fixed<<setprecision(0)<<wfoughts[pos2]<<" guerras e ganhou "<<fixed<<setprecision(0)<<won[pos2]<<endl;
  
  //calculating the odds
  

  cout<<endl;
  cout<<" As chances de "<<namesbr[pos1]<<" Ganhar uma guerra quando comparado com as de "<<namesbr[pos2]<<" ganhar, sao ";
  
  if(round(odds(won,wfoughts,pos1,pos2))<2&&round(odds(won,wfoughts,pos1,pos2))>=1){
  	cout<<"quase a mesma";
  }else if(round(odds(won,wfoughts,pos1,pos2))<1){
  	
  	cout<<setprecision(2)<<odds(won,wfoughts,pos1,pos2)<<" vezes menor";
  
  	
  }else{
  	
  	cout<<fixed<<setprecision(2)<<odds(won,wfoughts,pos1,pos2)<<" vezes maior";
  	
  }
  cout<<endl;

    
    cout<<endl<<endl;
    cout<<"O intervalo de confianca e dado por:"<<endl;
    
    cout<<fixed<<setprecision(2)<<"CI :("<<cinf(won,wfoughts,pos1,pos2)<<" - "<<cinsup(won,wfoughts,pos1,pos2)<<")"<<endl<<endl;


if(cinf(won,wfoughts,pos1,pos2)>0&&cinf(won,wfoughts,pos1,pos2)<=1&&cinsup(won,wfoughts,pos1,pos2)>=1){
	cout<<"Mas esses resultados nao tem significancia, portanto pode estar sendo enganado"<<endl;
}
  
  cout<<"Quer continuar?"<<endl;
  
  cout<<"Sim ou Nao? Por favor, escreva (nao) ou (Nao) caso deseje sair, caso contrario o programa vai rodar mais uma vez :D R = ";
  
  string opt;
  
  cin>>opt;
  cin.ignore();
  
  if(opt=="nao"||opt=="Nao"){
  	cout<<"Foi bom te conhecer! "<<name<<endl;
  	recursiveSleep(0,20);
  	cout<<"Te vejo em breve!"<<endl;
  	  	recursiveSleep(0,20);

  	cout<<"Eu espero..."<<endl;
  	  	recursiveSleep(0,20);

  	cout<<":D"<<endl;
  
  return 0;
  
  }
  freq++;
}
	
}


  return 0;
}
