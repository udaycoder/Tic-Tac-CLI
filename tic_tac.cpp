#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void check(char a[3][3]);
void printarray(char a[3][3]);
void ai(char a[3][3]);

int main(){
	srand(time(0));
	cout<<"Welcome to the game of tic-tac-toe"<<endl;
	int c,i,j,t=0;
	cout<<"Game Modes"<<endl;
	cout<<"Enter 1 for Player 1 vs Player 2"<<endl;
	cout<<"Enter 2 for Player 1 vs Computer AI"<<endl;
	char m[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m[i][j]=' ';
		}
	}
	cin>>c;
	switch(c){
		case 1:
			int x,y;
			cout<<"Player 1's input is x"<<endl;
			cout<<"Player 2's input is o"<<endl;
			cout<<"Players need to input row and column position given both start with index 1 and max index is 3"<<endl;
			while(1){
				cout<<"Player 1's turn"<<endl;
				cout<<"Player 1 input row and column number seperated by space"<<endl;
				cin>>x>>y;
				x=x-1;
				y=y-1;
				m[x][y]='x';
				printarray(m);
				check(m);
				t++;
				if(t==9){
				cout<<"The game is a tie"<<endl;
				exit(0);
			}
				cout<<"Player 2's turn"<<endl;
				cout<<"Player 2 input row and column number seperated by space"<<endl;
				cin>>x>>y;
				x=x-1;
				y=y-1;
				m[x][y]='o';
				printarray(m);
				check(m);
				t++;
			}
			break;
		case 2:
			cout<<"Player 1's input is x"<<endl;
			cout<<"Player 2 i.e Computer's input is o"<<endl;
			cout<<"Player needs to input row and column position given both start with index 1 and max index is 3"<<endl;
			while(1){
				cout<<"Player 1's turn"<<endl;
				cout<<"Player 1 input row and column number seperated by space"<<endl;
				cin>>x>>y;
				x=x-1;
				y=y-1;
				m[x][y]='x';
				printarray(m);
				check(m);
				t++;
					if(t==9){
				cout<<"The game is a tie"<<endl;
				exit(0);
			    }
			    cout<<"Player 2 i.e Computer's turn"<<endl;
			    ai(m);
			    printarray(m);
			    check(m);
			    t++;

			}
		break;
		default:
			cout<<"Invalid Input"<<endl;
			break;
	}
	return 0;
}

void check(char a[3][3])
{
	int i,j,c=0,t=0,d=0,u=0,p1,p2;
	char ch,ch1,ch2,ch3;
	p1=1;
	p2=2;
	for(i=0;i<3;i++){
		c=0;
		t=0;
		ch=' ';
		ch1=' ';
		for(j=0;j<3;j++){
			if(j==0){
				c++;
				if(a[i][j]=='x')
				 ch='x';
				 if(a[i][j]=='o')
				 ch='o';
			}
			else{
				if(a[i][j]==ch && ch!=' ')
				c++;
			}
			if(j==0){
				t++;
				if(a[j][i]=='x')
				 ch1='x';
				 if(a[j][i]=='o')
				 ch1='o';
			}
			else{
				if(a[j][i]==ch1 && ch1!=' ')
				t++;
			}
			if(i==j){
				if(i==0){
					d++;
					if(a[i][j]=='x')
				 ch2='x';
				 if(a[i][j]=='o')
				 ch2='o';
				}
				else{
					if(a[i][j]==ch2 && ch2!=' ')
					d++;
				}
			}
			if((i+j)==2){
				if(i==0){
					u++;
						if(a[i][j]=='x')
				 ch3='x';
				 if(a[i][j]=='o')
				 ch3='o';
				}
				else{
					if(a[i][j]==ch3 && ch3!=' ')
					u++;
				}
			}

			if(c==3){
				cout<<endl;
			if(ch=='x')
			cout<<"The winner is player "<<p1<<endl;
			if(ch=='o')
			cout<<"The winner is player "<<p2<<endl;
			exit(0);
		    }
		    if(t==3){
		    	cout<<endl;
			if(ch1=='x')
			cout<<"The winner is player "<<p1<<endl;
			if(ch1=='o')
			cout<<"The winner is player "<<p2<<endl;
			exit(0);
		  }
		}

	}
	if(d==3){
		cout<<endl;
		if(ch2=='x')
			cout<<"The winner is player "<<p1<<endl;
			if(ch2=='o')
			cout<<"The winner is player "<<p2<<endl;
			exit(0);
	}
	if(u==3){
		cout<<endl;
		if(ch3=='x')
			cout<<"The winner is player  "<<p1<<endl;
			if(ch3=='o')
			cout<<"The winner is player "<<p2<<endl;
			exit(0);
	}

}

void printarray(char a[3][3])
{
	int i,j;
	cout<<"Matrix is: "<<endl;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(a[i][j]==' ')
			cout<<"- ";
			else
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void ai(char a[3][3]){
	int i,j,t=0,x,y;
	char *p,*q;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
				if(a[0][2]=='o'){
					if(a[2][0]=='o'){
						if(a[1][1]==' '){
					a[1][1]='o';
					return;
				}
			    }
			   }
			if(j==1){
				if(a[i][j]=='o'){
					p=&a[i][j];
					if(*(p-1)=='o'){
						if(*(p+1)==' '){
					*(p+1)='o';
					return;
				}
				   }
				   if(*(p+1)=='o'){
				   	if(*(p-1)==' '){
				   	*(p-1)='o';
				   	return;
				   }
				   }
				}
				if(a[j][i]=='o'){
					q=&a[j][i];
					if(*(q-3)=='o'){
					 if(*(q+3)==' '){
						*(q+3)='o';
						return;
					 }
					}
					if(*(q+3)=='o'){
						if(*(q-3)==' '){
						*(q-3)='o';
						return;
					}
					}
				}
				if(a[j][j]=='o'){
					q=&a[j][j];
					if(*(q-2)=='o'){
						if(*(q+2)==' '){
							*(q+2)='o';
							return;
						}
					}
					if(*(q+2)=='o'){
						if(*(q-2)==' '){
							*(q-2)='o';
							return;
						}
					}
					if(*(q-4)=='o'){
						if(*(q+4)==' '){
							*(q+4)='o';
							return;
						}
					}
					if(*(q+4)=='o'){
						if(*(q-4)==' '){
							*(q-4)='o';
							return;
						}
					}
				}
			}
			if(j==0){
				if(a[i][j]=='o'){
					p=&a[i][j];
					if(*(p+2)=='o'){
						if(*(p+1)==' '){
					*(p+1)='o';
					return;
				}
			    }
			     }
				if(a[j][i]=='o'){
					p=&a[j][i];
					if(*(p+6)=='o'){
						if(*(p+3)==' '){
					*(p+3)='o';
					return;
				}
			   }
		     }
				if(a[j][j]=='o'){
					p=&a[j][j];
					if(*(p+8)=='o'){
						if(*(p+4)==' '){
					*(p+4)='o';
					return;
				}
			    }
			   }
			   if(a[j][j]=='o'){
					p=&a[j][j];
					if(*(p+8)=='o'){
						if(*(p+4)==' '){
					*(p+4)='o';
					return;
				}
			    }
			   }
			}
			if(a[0][2]=='x'){
					if(a[2][0]=='x'){
						if(a[1][1]==' '){
					a[1][1]='o';
					return;
				}
			    }
			   }
			if(j==1){
				if(a[i][j]=='x'){
					p=&a[i][j];
					if(*(p-1)=='x'){
						if(*(p+1)==' '){
					*(p+1)='o';
					return;
				}
				   }
				   if(*(p+1)=='x'){
				   	if(*(p-1)==' '){
				   	*(p-1)='o';
				   	return;
				   }
				   }
				}
				if(a[j][i]=='x'){
					q=&a[j][i];
					if(*(q-3)=='x'){
					 if(*(q+3)==' '){
						*(q+3)='o';
						return;
					 }
					}
					if(*(q+3)=='x'){
						if(*(q-3)==' '){
						*(q-3)='o';
						return;
					}
					}
				}
				if(a[j][j]=='x'){
					q=&a[j][j];
					if(*(q-2)=='x'){
						if(*(q+2)==' '){
							*(q+2)='o';
							return;
						}
					}
					if(*(q+2)=='x'){
						if(*(q-2)==' '){
							*(q-2)='o';
							return;
						}
					}
					if(*(q-4)=='x'){
						if(*(q+4)==' '){
							*(q+4)='o';
							return;
						}
					}
					if(*(q+4)=='x'){
						if(*(q-4)==' '){
							*(q-4)='o';
							return;
						}
					}
				}
			}
			if(j==0){
				if(a[i][j]=='x'){
					p=&a[i][j];
					if(*(p+2)=='x'){
						if(*(p+1)==' '){
					*(p+1)='o';
					return;
				}
			    }
			     }
				if(a[j][i]=='x'){
					p=&a[j][i];
					if(*(p+6)=='x'){
						if(*(p+3)==' '){
					*(p+3)='o';
					return;
				}
			   }
		     }
				if(a[j][j]=='x'){
					p=&a[j][j];
					if(*(p+8)=='x'){
						if(*(p+4)==' '){
					*(p+4)='o';
					return;
				}
			    }
			   }
			   if(a[j][j]=='x'){
					p=&a[j][j];
					if(*(p+8)=='x'){
						if(*(p+4)==' '){
					*(p+4)='o';
					return;
				}
			    }
			   }
			}
		}
	}
	while(t==0){

		x=rand()%3;
		y=rand()%3;
		if(a[x][y]==' '){
			t=1;
			a[x][y]='o';
			return;
		}
		if(a[x][y]!=' ')
		continue;
	}
}
