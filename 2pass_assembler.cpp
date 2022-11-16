/*Bhaiyasaheb chaudhari*/

#include<iostream>
#include<string.h>
using namespace std;

void InputSymbol(string sym[2][3])
{
	cout<<"\nEnter Symbol table:\t";
	for(int i=0; i<2; i++)
	{
		cout<<"\nEnter row:"<<i+1;
		for(int j=0; j<3; j++)
		{
			cin>>sym[i][j];
		}	
	}
}

void InputLiteral(string lit[2][3])
{
	cout<<"\nEnter Literal table:\t";
	for(int i=0; i<2; i++)
	{
		cout<<"\nEnter row:"<<i+1;
		for(int j=0; j<3; j++)
		{
			cin>>lit[i][j];
		}	
	}
}

void Display(string sym[2][3], string lit[2][3])
{
	cout<<"\n------------------------------------------------------------";
	cout<<"\n Symbol table:\t";
	cout<<"\n------------------------------------------------------------";
	cout<<"\nIndex\tSymbol\tAddress";
	cout<<"\n------------------------------------------------------------\n";
	for(int i=0; i<2; i++)
	{
		
		for(int j=0; j<3; j++)
		{
			cout<<sym[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	cout<<"\n------------------------------------------------------------";
	cout<<"\n Literal table:\t";
	cout<<"\n------------------------------------------------------------";
	cout<<"\nIndex\titeral\tAddress";
	cout<<"\n------------------------------------------------------------\n";
	for(int i=0; i<2; i++)
	{
		
		for(int j=0; j<3; j++)
		{
			cout<<lit[i][j]<<"\t";
		}	
		cout<<endl;
	}
}

void PrintLiteral(string lit[2][3])
{
	for(int i=0; i<2; i++)
	{
		
		cout<<"(DL,02)"<<" "<<"(c,"<<lit[i][1]<<")"<<endl;
	}
}

void PrintLiteralIndex(string lit[2][3], string lit_val)
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(lit[i][j]==lit_val)
			{
				cout<<"(L,"<<lit[i][0]<<")";
			}
		}
	}
}

void PrintSymbolIndex(string sym[2][3], string sym_val)
{
	int cons=0;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(sym[i][j]==sym_val)
			{
				cout<<"(s,"<<sym[i][0]<<")";
				cons=1;
			}
		}
		
		
	}
	if(cons==0)
		{
			cout<<"(c,"<<sym_val<<")";
		}
}

void Generate_intermediate_code(string mot[8][3], string sym[2][3], string lit[2][3], string inst[8][5])
{
	int i, j;
	i=0;
	while(i<8)
	{
		j=0;
		if(inst[i][j]=="origin")
		{
			cout<<"(AD,03)"<<endl;
			i++;
		}
		else if(inst[i][j]=="ltorg")
		{
			cout<<"(AD,04)"<<endl;
			PrintLiteral(lit);
			i++;
		}
		else
		{
			
			while(j<5 && inst[i][j]!="origin" && inst[i][j]!="ltorg")
			{
				int m=0;
				while(m<8)
				{
					if(inst[i][j]==mot[m][0])
					{
						cout<<"("<<mot[m][1]<<","<<mot[m][2]<<")";
						j++;
						m=0;
						
					}
					else
					{
						m++;
					}
					
				}
				
				if(inst[i][j]=="2" || inst[i][j]=="1")
				{
					string lit_val=inst[i][j];
					PrintLiteralIndex(lit, lit_val);
					j++;
				}
				else if(inst[i][j]==" " || inst[i][j]=="+" || inst[i][j]=="," || inst[i][j]==",=") 
				{
					j++;
					continue;
				}
				else
				{
					string sym_val=inst[i][j];
					PrintSymbolIndex(sym, sym_val);
					j++;
				}
			}
			i++;
			cout<<endl;
		}
		
		
	}
}

void MOT(string sym[2][3], string lit[2][3], string inst[8][5])
{
	string mot[8][3]={
				"start","AD","01",
				"mover","IS","04",
				"breg","RG","02",
				"areg","RG","01",
				"add","IS","01",
				"origin","AD","04",
				"ltorg","AD","03",
				"dc","DL","02",
				
	
	};
	
	Generate_intermediate_code(mot, sym, lit, inst);
}

int main()
{
	string sym[2][3];
	string lit[2][3];
	string inst[8][5]={
				"start","100"," "," "," ",
				"mover","breg",",=","2"," ",
				"loop","mover","areg",",","n",
				"add","breg",",=","1"," ",
				"origin","loop","+","5"," ",
				"ltorg"," "," "," "," ",
				"n","dc","5"," "," ",
				"end"," "," "," "," ",
	
	};
	
	
	InputSymbol(sym);
	InputLiteral(lit);
	Display(sym, lit);
	MOT(sym, lit, inst);
	
	
}
