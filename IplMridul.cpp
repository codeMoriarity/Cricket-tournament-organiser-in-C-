#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
class Database
{
	
		char Name[20];
		int matches,runs,centur,halfcentur,sixes,fours,wick,b4;
		double avg,econ;
	public:	
		void read_batsmans_data()
		{
			cout<<"\nName: ";
			cin.ignore();
			gets(Name);
			string str=Name;
			transform(str.begin(),str.end(),str.begin(),::tolower);
					fstream F;
					str=str+",";
					F.open("Batsmanlist.txt",ios::out|ios::binary|ios::app);
					int i=0;
					for(std::string::iterator it=str.begin();it!=str.end();++it)
					{
						char ch=str.at(i);
						F.put(ch);
						i++;						
					}
					F.close();
			cout<<"\nMatches: ";
			cin>>matches; 
			cout<<"\nRuns: ";
			cin>>runs;
			cout<<"\nCenturies: ";
			cin>>centur;
			cout<<"\nHalf Centuries: ";
			cin>>halfcentur;
			cout<<"\nSixes: ";
			cin>>sixes;
			cout<<"\nFours: ";
			cin>>fours;
			cout<<"\nAverage: ";
			cin>>avg;
		}
		void read_bowlers_data()
		{
			cout<<"Name: ";
			cin.ignore();
			gets(Name);
			string str=Name;
			transform(str.begin(),str.end(),str.begin(),::tolower);
					fstream F;
					str=str+",";
					F.open("Bowlerlist.txt",ios::out|ios::binary|ios::app);
					int i=0;
					for(std::string::iterator it=str.begin();it!=str.end();++it)
					{
						char ch=str.at(i);
						F.put(ch);
						i++;						
					}
					F.close();
			cout<<"\nMatches: ";
			cin>>matches;
			cout<<"\nWickets: ";
			cin>>wick;
			cout<<"\nEconomy(enter as a decimalnumber): ";
			cin>>econ;
			cout<<"\n4-wicket haul: ";
			cin>>b4;
		}
		void show_batsmandata()
		{
			cout<<"\nName: "<<Name; 
			cout<<"\nMatches: "<<matches; 
			cout<<"\nRuns: "<<runs;
			cout<<"\nCenturies: "<<centur;
			cout<<"\nHalf Centuries: "<<halfcentur;
			cout<<"\nSixes: "<<sixes;
			cout<<"\nFours: "<<fours;
			cout<<"\nAverage: "<<avg;
		}
		void show_bowlerdata()
		{
			cout<<"\nName: "<<Name; 
			cout<<"\nMatches: "<<matches;
			cout<<"\nWickets: "<<wick; 
			cout<<"\nEconomy: "<<econ;
			cout<<"\n4-Wicket haul: "<<b4;
		}
		
};
int main()
{
	fstream FILE;
	int ch;
    cout<<"\n********************************************************************";
    cout<<"\n###################--@--Indian Priemere League--@--#################";
    cout<<"\n********************************************************************";
    cout<<"\n####################-@-Designed By Mridul Mishra-@-#################";
    cout<<"\nPress 1 to Enter our Database: ";
    cout<<"\nPress 2 to Generate the Match Schedule for eight teams: ";
    cout<<"\nPress 3 to Predict the chances of a player for next IPL: ";
    cout<<"\nChoice: ";
    cin>>ch;
    switch (ch)
    {
    case 1://to access to the database
    {
    	system("cls");
    int cd;
    cout<<"\n********************************************************************";
    cout<<"\n##############--@--Welcome to the Players database--@--#############";
    cout<<"\n********************************************************************";
    cout<<"\n*****************Enter 1 to edit Batsman database*******************"; 
    cout<<"\n********************************************************************";
    cout<<"\n*****************Enter 2 to edit Bowlers Database***********";
    cout<<"\n********************************************************************";
    cout<<"\n************Enter 3 to search for statistics of a player************"<<endl;
	cout<<"\n********************************************************************";
	cout<<"\nChoice: ";
	cin>>cd;
    switch (cd)
    {
    	case 1://to edit  the batsman's database  
    	{
    		system("cls");
			int n=5, i=0;
    		Database BT[150];
    		FILE.open("Batsman.txt",ios::out|ios::app|ios::binary);
    		cout<<"\n********************************************************************";
    		cout<<"\n>>>>>>>>>--Enter the Batsman's details as per requirement--<<<<<<<<<";
    		cout<<"\n********************************************************************";
    		while(n!=0)
    		{
    			BT[i].read_batsmans_data();
                FILE.write((char *)&BT[i],sizeof(BT[i]));
                i++;
                cout<<"\nEnter 0 to terminate/Enter 1 to continue: ";
                cin>>n;
                system("cls");
			}
    		cout<<"Thank You for updating our database";
    		break;
    	}
    	case 2://to edit bowler's database
    	{
    		system("cls");
			int n=5, i=0;
    		Database BO[150];
    		FILE.open("Bowler.txt",ios::out|ios::app|ios::binary);
    		cout<<"\n********************************************************************";
    		cout<<"\n>>>>>>>>>--Enter the Bowler's details as per requirement--<<<<<<<<<<";
    		cout<<"\n********************************************************************"<<endl;
    		while(n!=0)
    		{
    			BO[i].read_bowlers_data();
                FILE.write((char *)&BO[i],sizeof(BO[i]));
                i++;
                cout<<"\nEnter 0 to terminate/Enter 1 to continue: ";
                cin>>n;
                system("cls");
			}
    		cout<<"Thank You for updating our database";
    		break;
    	}
		case 3://to search for a given player
		{
				system("cls");
				Database d;
				int cs;
				string name;	
				cout<<"\nEnter the player's name: ";
				cin.ignore();
				getline(cin,name);
				cout<<"\nEnter 1 to search for the batting stats and Enter 2 to search for the bowling stats: ";
				cin>>cs;
				switch (cs)
				{
			case 1://to search for a batsman
			{
				system("cls");
				fstream ob1;
				char ch;
				string nam="";
				int  count=0;
				ob1.open("Batsmanlist.txt",ios::in);
				while(ob1)
				{
				ch=ob1.get();
				if(ch!=',')
				{
					nam=nam+ch;	
				}
				else
				{
					count++;
					if(name==nam)
					{
						break;	
				    }
				    nam="";
				   
				}
				}
	            ob1.close();
	            system("cls");
	            cout<<count;
				fstream FILE;
				FILE.open("Batsman.txt",ios::in|ios::binary);
				FILE.seekg((sizeof(d)*(count-1)),ios::cur);	
				FILE.read((char*)&d,sizeof(d));
				d.show_batsmandata();
				FILE.close();
				break;
			}
			case 2://to search for a bowler
			{
				system("cls");
				fstream ob1;
				char ch;
				string nam="";
				int  count=0;
				ob1.open("Bowlerlist.txt",ios::in);
				while(ob1)
				{
				ch=ob1.get();
				if(ch!=',')
				{
					nam=nam+ch;	
				}
				else
				{
					count++;
					if(name==nam)
					{
						break;	
				    }
				    nam="";
				}
				}
	            ob1.close();
	            system("cls");
	            cout<<count;
				fstream FILE;
				FILE.open("Bowler.txt",ios::in|ios::binary);
				FILE.seekg((sizeof(d)*(count-1)),ios::cur);	
				FILE.read((char*)&d,sizeof(d));
				d.show_bowlerdata();
				FILE.close();
				break;
			}
			default:
				cout<<"You have entered the wrong choice. You must select between bowling ang batting statistics. Please reinitiate the program.Thank You! ";
			}
			break;
		}
    		
    	default:
    	{
    		cout<<"SORRY! You have entered a wrong choice. Please reintialise the program";
		}
	}
	break;
	}
	case 2://to generate random match schedule
	{
		system("cls");
        string team[8];
        cout<<"\nEnter eight team names(Enter short names::as CSK for Chennai Super kings): "<<endl;
        cin.ignore();
        for(int i=0;i<=7;i++)
        {
			getline(cin,team[i]);
		}
		system("cls");
		cout<<"\n*********************";
		cout<<"\n***Match schedule:***";
		int a=-3,b=-2,c=-1,d=0;
		for(int k=1;k<=2;k++)
		{
			int n=1;
        while(n!=8)
        {
            cout<<"\nMatch "<<(a+=4)<<": "<<team[0]<<" vs "<<team[4];
            cout<<"\nMatch "<<(b+=4)<<": "<<team[1]<<" vs "<<team[5];
            cout<<"\nMatch "<<(c+=4)<<": "<<team[2]<<" vs "<<team[6];
            cout<<"\nMatch "<<(d+=4)<<": "<<team[3]<<" vs "<<team[7];
            string temp=team[7];
            for(int i=7;i>=2;i--)
            {
                team[i]=team[i-1];
            }
            team[1]=temp;
            n++;
		}
		}
		cout<<"\nMatch 57: Qualifier I";
		cout<<"\nMatch 58: Eliminator ";
		cout<<"\nMatch 59; Qualifier II";
		cout<<"\n***The Grand Finale***";
		cout<<"\n**********************";
		break;
	}
	case 3:
	{
		system("cls");
		cout<<"\nLet's predict someone's future for next IPL: ";
		cout<<"\nPress 1 for a Batsman, 2 for Bowler and 3 for a All-rounder: ";
		cout<<"\nChoice: ";
		cin>>ch;
		switch (ch)
		{
			case 1:
				{
					system("cls");
					string name;double strate;
					cout<<"\nEnter the Player's name: ";
					cin.ignore();
					getline(cin,name);
					cout<<"\nEnter the strike rate of the batsman: ";
					cin>>strate;
					system("cls");
					if(strate>=130.00)
					{
						cout<<"\n"<<name<<" is eligible to play as a batsman in the next IPL.";
					}
					else
					{
						cout<<"\n"<<name<<" is not eligible to play in the next IPL. Better Luck next Time.";
					}
					cout<<"Thank you for using our service :)";
					break;
				}
			case 2:
				{
					system("cls");
					string name;double econ;
					cout<<"\nEnter the Player's name: ";
					cin.ignore();
					getline(cin,name);
					cout<<"\nEnter the economy of the bowler: ";
					cin>>econ;
					system("cls");
					if(econ>=8.00)
					{
						cout<<"\n"<<name<<" is eligible to play as a bowler in the next IPL.";
					}
					else
					{
						cout<<"\n"<<name<<" is not eligible to play in the next IPL. Better Luck next Time.";
					}
					cout<<"Thank you for using our service :)";
					break;					
				}
			case 3:
				{
					system("cls");
					string name;double econ,strate;
					cout<<"\nEnter the Player's name: ";
					cin.ignore();
					getline(cin,name);
					cout<<"\nEnter the strike rate in batting: ";
					cin>>strate;
					cout<<"\nEnter the economy in bowling: ";
					cin>>econ;
					system("cls");
					if(strate>=110.00 && econ<=10.00)
					{
						cout<<"\n"<<name<<" is eligible to play as an all-rounder in the next IPL.";
					}
					else
					{
						cout<<"\n"<<name<<" is not eligible to play in the next IPL. Better Luck next Time.";
					}
					cout<<"\nThank you for using our service :)";
					break;					
				}
			default:
				{
					system("cls");
					cout<<"\n There is no fourth option other than batsman, bowler and an allrounder to play for. If there will be, you can try again later :(";
					cout<<"\n Thank you for using our service :)";
				}					
		}
		break;			
	}
	default:
	{
		cout<<"You have entered a wrong choice. Please reinitialise the program";
	}
	}
	return 0;
}

