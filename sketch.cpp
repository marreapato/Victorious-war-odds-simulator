#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
//#include <unistd.h>
#include<Windows.h>


using namespace std;
//building some recursive algorithms 
	
/*string funame(string v[],int i,int tam){
	
	if(i<tam){
		
		cout<<funame(v,i+1,tam)<<endl;
				return funame(v,i+1,tam);

	}
}*/

/*int find(int v[],int tam,int i, int pos){
	
	if(i<tam){
		return find(v,tam,i+1,pos);
		
	}else if(i==pos){
		cout<<v[i];
		
	}
	
	
}*/
int main(){
	int freq=0;
	//g20 countries down bellow
	cout<<"Choose your language/Escolha seu idioma"<<endl;
	cout<<"Press 0 for english/Aperte 1 para portugues"<<endl;
	int language;
	
	cin>>language;
	cin.ignore();
	string names[19]={"Australia","Canada","Saudi Arabia","United States","India","Russia","South Africa","Turkey","Argentina","Brazil","Mexico","France","Germany","Italy","Uk","China","Indonesia","Japan","South Korea"};

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

//funame(names,0,19);

  //for(int i=0;i<19;i++){
    //cout<<names[i]<<" Fought = "<<wfoughts[i]<<" Won = "<<won[i]<<endl;
    //Sleep(200);
 // } 
  
  
  for(int i=0;i<19;i++){
    cout<<names[i]<<endl;
    Sleep(600);
 }
  
  cout<<"Choose the first country: ";
  getline(cin,country);
  
  int tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos1=i;
	  }
  }
  
  cout<<country<<" Fought "<<fixed<<setprecision(0)<<wfoughts[pos1]<<" wars and won "<<fixed<<setprecision(0)<<won[pos1]<<endl;
  
  cout<<"Choose the second country(the one you are supposed to comparate): ";
  
    getline(cin,country);
  
  tamc=country.size();
  
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos2=i;
	  }
  }
  
  cout<<country<<" Fought "<<fixed<<setprecision(0)<<wfoughts[pos2]<<" wars and won "<<fixed<<setprecision(0)<<won[pos2]<<endl;
  
  //calculating the odds
  
  double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  cout<<endl;
  cout<<" The odds of "<<names[pos1]<<" winning a war, when compared to the odds of "<<names[pos2]<<" winning it, are ";
  
  if(round(oddsratio)<2&&round(oddsratio)>=1){
  	cout<<"almost the same";
  }else if(round(oddsratio)<1){
  	
  	cout<<setprecision(2)<<oddsratio<<" times worse";
  
  	
  }else{
  	
  	cout<<fixed<<setprecision(2)<<oddsratio<<" times superior";
  	
  }
  cout<<endl;
  //confidence interval and significance
  
  //ci = exp(log(or) ± Zl/2­*v1/a + 1/b + 1/c + 1/d), Z is the critical value, and it's supposed to be 1,96, cause we are calculating for a 95% confidence interval
  //or is the odds ratio
  //a is supposed the number of winnings by the 1nd country
  //b is supposed to be the number of it's losses
  //c is supposed to be the number of wars won by the 2nd country
  //d is supposed to be the number of losses by the 2nd
  
  double cisup=exp(log(oddsratio)+(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//superior
    double cinf=exp(log(oddsratio)-(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//inferior
    
    cout<<endl<<endl;
    cout<<"The confidence interval for this measure is given by the range of:"<<endl;
    
    cout<<fixed<<setprecision(2)<<"CI :("<<cinf<<" - "<<cisup<<")"<<endl<<endl;


if(cinf>0&&cinf<=1&&cisup>=1){
	cout<<"But these results have no significance which means you may be being tricked"<<endl;
}
  
  cout<<"Would you like to continue?"<<endl;
  
  cout<<"Yes or No? R = ";
  
  string opt;
  
  cin>>opt;
  cin.ignore();
  
  if(opt=="no"||opt=="No"){
  	cout<<"Well, it was nice to meet you "<<name<<endl;
  	Sleep(600);
  	cout<<"See you soon!"<<endl;
  	  	Sleep(600);

  	cout<<"I hope..."<<endl;
  	  	Sleep(600);

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

cout<<"Bem vindo "<<name<<", esta e a primeira versao do simulador de guerra do G20, nosso objetivo e calcular as chances de um pais vencer uma guerra com base nas informacoes que o outro possui, nesta primeira versao estamos usando apenas os países do G20, excluindo a UE."<< endl << endl;
}
cout<<"De uma olhada nos paises do G20: "<<endl<<endl;

//funame(names,0,19);

  //for(int i=0;i<19;i++){
    //cout<<names[i]<<" Fought = "<<wfoughts[i]<<" Won = "<<won[i]<<endl;
    //Sleep(200);
 // } 
  
  
  for(int i=0;i<19;i++){
    cout<<names[i]<<endl;
    Sleep(600);
 }
  
  cout<<"Escolha o primeiro pais: ";
  getline(cin,country);
  
  int tamc=country.size();
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos1=i;
	  }
  }
  
  
  cout<<country<<" Lutou "<<fixed<<setprecision(0)<<wfoughts[pos1]<<" guerras e ganhou "<<fixed<<setprecision(0)<<won[pos1]<<endl;
  
  cout<<"Escolha o segundo pais(aquele que usara para como comparacao): ";
  
    getline(cin,country);
  
  tamc=country.size();
  
  country[0]=toupper(country[0]);
  for(int i=0;i<tamc;i++){
  	if(country[i]==' '){
  		country[i+1]=toupper(country[i+1]);
	  }
  }
  for(int i=0;i<19;i++){
  	if(names[i]==country){
  		pos2=i;
	  }
  }
  
  cout<<country<<" Lutou "<<fixed<<setprecision(0)<<wfoughts[pos2]<<" guerras e ganhou "<<fixed<<setprecision(0)<<won[pos2]<<endl;
  
  //calculating the odds
  
  double odds1=(won[pos1]/(wfoughts[pos1]-won[pos1]));
  
  double odds2=(won[pos2]/(wfoughts[pos2]-won[pos2]));
  
  double oddsratio=odds1/odds2;
  cout<<endl;
  cout<<" As chances de "<<names[pos1]<<" Ganhar uma guerra quando comparado com as de "<<names[pos2]<<" ganhar, sao ";
  
  if(round(oddsratio)<2&&round(oddsratio)>=1){
  	cout<<"quase a mesma";
  }else if(round(oddsratio)<1){
  	
  	cout<<setprecision(2)<<oddsratio<<" vezes menor";
  
  	
  }else{
  	
  	cout<<fixed<<setprecision(2)<<oddsratio<<" vezes maior";
  	
  }
  cout<<endl;
  //confidence interval and significance
  
  //ci = exp(log(or) ± Zl/2­*v1/a + 1/b + 1/c + 1/d), Z is the critical value, and it's supposed to be 1,96, cause we are calculating for a 95% confidence interval
  //or is the odds ratio
  //a is supposed the number of winnings by the 1nd country
  //b is supposed to be the number of it's losses
  //c is supposed to be the number of wars won by the 2nd country
  //d is supposed to be the number of losses by the 2nd
  
  double cisup=exp(log(oddsratio)+(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//superior
    double cinf=exp(log(oddsratio)-(1.96*(sqrt((1/won[pos1])+(1/wfoughts[pos1])+(1/won[pos2])+(1/wfoughts[pos2])))));//inferior
    
    cout<<endl<<endl;
    cout<<"O intervalo de confianca e dado por:"<<endl;
    
    cout<<fixed<<setprecision(2)<<"CI :("<<cinf<<" - "<<cisup<<")"<<endl<<endl;


if(cinf>0&&cinf<=1&&cisup>=1){
	cout<<"Mas esses resultados nao tem significancia, portanto pode estar sendo enganado"<<endl;
}
  
  cout<<"Quer continuar?"<<endl;
  
  cout<<"Sim ou Nao? R = ";
  
  string opt;
  
  cin>>opt;
  cin.ignore();
  
  if(opt=="nao"||opt=="Nao"){
  	cout<<"Foi bom te conhecer! "<<name<<endl;
  	Sleep(600);
  	cout<<"Te vejo em breve!"<<endl;
  	  	Sleep(600);

  	cout<<"Eu espero..."<<endl;
  	  	Sleep(600);

  	cout<<":D"<<endl;
  
  return 0;
  
  }
  freq++;
}
	
}


  return 0;
}
