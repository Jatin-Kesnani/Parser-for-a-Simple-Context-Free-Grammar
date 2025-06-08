

//		*************************************************
//		*												*
//		*												*
//		*		Jatin Kesnani				(K21-3204)	*
//		*												*
//		*												*
//		*************************************************


#include<bits/stdc++.h>
using namespace std;
int main(){
	string Input = "(a+a)*a";
	/*
		These are the sample inputs 
		that were generated from online calculator
		which are Correct Structure
		(1)  a
		(2)  (a)
		(3)  a+a
		(4)  a*a
		(5)  a*a+a
		(6)  ((a))
		(7)  (a)*a
		(8)  a+(a)
		(9)  a+a*a
		(10) (a+a)
		(11) (a*a)
		(12) (a)+a
		(13) a*(a)
		(14) a+a+a
		(15) a*a*a
		(16) a*a*(a)
		(17) a*a*a*a
		(18) a*(a*a)
		(19) a*a+a*a
		(20) a*(a)*a
	*/
	
	cout<<endl;
	cout<<"\t~~ Grammar ~~"<<endl;
	cout<<"\tE -> E + T | T"<<endl;
	cout<<"\tT -> T * F | F"<<endl;
	cout<<"\tF -> ( E ) | a"<<endl;
	
	cout<<"\n\tInput = "<<Input<<endl<<endl;
	
	string Output[100];
	
	int t = 0;
	int N = Input.length();
	int CountOpenBracket = 0, CountCloseBracket = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
	
	/*Checking Start and End Condition*/
	if(Input[0] == '+' || Input[0] == '*' || Input[N-1] == '+' || Input[N-1] == '*'){
		cout<<"\t~~~ Incorrect Structure ~~~"<<endl;
		exit(0);
	}
	/*Checking Double '+' and Double '*' Condition*/
	for(int i=0 ; i<N-1 ; i++){
		if(Input[i] == '+' && Input[i+1] == '+'){
			cout<<"\t~~~ Incorrect Structure ~~~"<<endl;
			exit(0);
		}
		if(Input[i] == '*' && Input[i+1] == '*'){
			cout<<"\t~~~ Incorrect Structure ~~~"<<endl;
			exit(0);
		}
	}
	/*Checking Open and Close Brackets*/
	for(int i=0 ; i<N ; i++){
		if(Input[i] == '('){
			CountOpenBracket++;
		}
		if(Input[i] == ')'){
			CountCloseBracket++;
		}
	}
	if(CountOpenBracket != CountCloseBracket){
		cout<<"\t~~~ Incorrect Structure ~~~"<<endl;
		exit(0);
	}
	
	/*Otherwise Correct Structure*/
	Output[t] = Input;
	while(Input != "E"){
		if(Input.find("a") != string::npos){
			for(int i=g ; i<Input.length() ; i++){
				if(Input[i] == 'a'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "F";
					for(int z=i+1 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("(E)") != string::npos){
			for(int i=c ; i<=Input.length()-3 ; i++){
				if(Input[i] == '(' && Input[i+1] == 'E' && Input[i+2] == ')'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "F";
					for(int z=i+3 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("(T)") != string::npos){
			for(int i=c ; i<=Input.length()-3 ; i++){
				if(Input[i] == '(' && Input[i+1] == 'T' && Input[i+2] == ')'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "E";
					for(int z=i+3 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("(F)") != string::npos){
			for(int i=c ; i<=Input.length()-3 ; i++){
				if(Input[i] == '(' && Input[i+1] == 'F' && Input[i+2] == ')'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "T";
					for(int z=i+3 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("T*F") != string::npos || Input.find("F*T") != string::npos){
			for(int i=b ; i<=Input.length()-3 ; i++){
				if((Input[i] == 'T' && Input[i+1] == '*' && Input[i+2] == 'F') || (Input[i] == 'F' && Input[i+1] == '*' && Input[i+2] == 'T')){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "T";
					for(int z=i+3 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("E+T") != string::npos || Input.find("T+E") != string::npos){
			for(int i=a ; i<=Input.length()-3 ; i++){
				if((Input[i] == 'E' && Input[i+1] == '+' && Input[i+2] == 'T') || (Input[i] == 'T' && Input[i+1] == '+' && Input[i+2] == 'E')){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "E";
					for(int z=i+3 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("E") != string::npos){
			for(int i=f ; i<Input.length() ; i++){
				if(Input[i] == 'E'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "F";
					for(int z=i+1 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("F") != string::npos){
			for(int i=e ; i<Input.length() ; i++){
				if(Input[i] == 'F'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "T";
					for(int z=i+1 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
		}
		else if(Input.find("T") != string::npos){
			for(int i=d ; i<Input.length() ; i++){
				if(Input[i] == 'T'){
					string temp = "";
					for(int z=0 ; z<i ; z++){
						temp += Input[z];
					}
					temp += "E";
					for(int z=i+1 ; z<Input.length() ; z++){
						temp += Input[z];
					}
					Input = temp;
					t++;
					Output[t] = Input;
					break;
				}
			}
			if(Input == "E"){
				break;
			}
		}
	}
	for(int i=t ; i>=0 ; i--){
		cout<<"\t"<<Output[i]<<endl;
	}
	cout<<"\n\t~~~ Correct Structure ~~~"<<endl;
}