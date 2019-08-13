//Program by Christina Ochsner
//PS#: 1166214
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <cctype>
#include <string>
#include <string.h>
#include <iomanip>
#include <bits/stdc++.h> 

using namespace std;

struct Node
{
	int id;
	char* first;
	char* last;
	char* dob;
	int years;
	int salary;
	char* pos;

	struct Node *next=NULL;
	struct Node *prev=NULL;
};
void deletes(struct Node **head, int key)
{
	struct Node* temp = *head;
	struct Node* prev = 0;

	if (temp != NULL && temp->id == key)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->id != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;

	prev->next = temp->next;

	free(temp);
}
void deleteEnd(struct Node **head)
{
	struct Node *temp = *head;
	if (temp == NULL)
		return;

	if (temp->next==NULL)
	{
		*head = NULL;
		free(temp);
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);

}
void deleteNode(struct Node **head, int index)
{
	if (*head == NULL)
		return;

	struct Node* temp = *head;

	if (index==0)
	{
		*head = temp->next;  
		free(temp); 
		temp = *head;
		return;
	}

	for (int i = 0; temp != NULL && i<index; i++)
		temp = temp->next;
	if (temp == NULL)
		return;

	if (temp->next != NULL)
	{
		temp->next->prev = temp->prev;
	}

	temp->prev->next = temp->next;

	free(temp);
	
}
void addAtEnd(struct Node** head, int id, char* first, char* last, char* dob, int years, int salary, char* pos)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *lastNode = *head;
	struct Node *current = *head;
	node->id = id;
	node->first = first;
	node->last = last;
	node->dob = dob;
	node->years = years;
	node->salary = salary;
	node->pos = pos;
	node->salary = salary;
	node->next = NULL;



	if (*head == NULL)
	{
		*head = node;
		return;
	}

	while (current != NULL)
	{
		if (current->id == node->id)
		{
			return;
		}
		current = current->next;
		
		if(lastNode->next!=NULL)
		{
			lastNode = lastNode->next;
		}
	}
	node->prev = lastNode;
	lastNode->next = node;

	return;
}
void addAtStart(struct Node **head, int id, char* first, char* last, char* dob, int years, int salary, char* pos)
{
	struct Node *node = new Node;
	node->id = id;
	node->first = first;
	node->last = last;
	node->dob = dob;
	node->years = years;
	node->salary = salary;
	node->pos = pos;

	node->next = *head;
	
	/*struct Node *current = *head;
	while (current != NULL)
	{
		if (current->id == node->id)
		{
			return;
		}
		current = current->next;
	}*/
	if (node->next != NULL)
	{
		node->next->prev = node;
	}
	node->prev = NULL;
	*head = node;

}

void addAfter(struct Node **head, int id, char* first, char* last, char* dob, int years, int salary, char* pos, int index)
{
	struct Node *node = new Node;
	node->id = id;
	node->first = first;
	node->last = last;
	node->dob = dob;
	node->years = years;
	node->salary = salary;
	node->pos = pos;

	struct Node *temp = *head;
	
	struct Node *current = *head;
	while (current != NULL)
	{
		if (current->id == node->id)
		{
			return;
		}
		current = current->next;
	}
	
	if (head == NULL)
	{
		return;
	}

	for (int i = 0; i < index && temp!=NULL; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return;
	}
	if (temp->next != NULL)
	{
		node->next = temp->next;
		temp->next->prev = node;
	}
	else
	{
		node->next = NULL;
	}

	node->prev = temp;
	temp->next = node;
	temp = node;
	
}
void addBefore(struct Node **head, int id, char* first, char* last, char* dob, int years, int salary, char* pos, int index)
{
	struct Node *node = new Node;
	node->id = id;
	node->first = first;
	node->last = last;
	node->dob = dob;
	node->years = years;
	node->salary = salary;
	node->pos = pos;

	struct Node *temp = *head;
	
	struct Node *current = *head;
	while (current != NULL)
	{
		if (current->id == node->id)
		{
			return;
		}
		current = current->next;
	}
	
	if (head == NULL)
	{
		return;
	}
	if (index == 0)
	{
		node->next = *head;
		node->prev = NULL;
		node->next->prev = node;
		*head = node;
		return;
	}

	for (int i = 0; i < index && temp != NULL; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return;
	}
	node->next = temp;
	node->prev = temp->prev;
	if (temp->prev != NULL)
	{
		temp->prev->next = node;
		temp->prev = node;
	}
	temp = node;
}
void swap(Node *i, Node *j)
{
	struct Node *temp = new Node;

	temp->id = i->id;
	temp->first = i->first;
	temp->last = i->last;
	temp->dob = i->dob;
	temp->years = i->years;
	temp->salary = i->salary;
	temp->pos = i->pos;

	i->id = j->id;
	i->first = j->first;
	i->last = j->last;
	i->dob = j->dob;
	i->years = j->years;
	i->salary = j->salary;
	i->pos = j->pos;

	j->id = temp->id;
	j->first = temp->first;
	j->last = temp->last;
	j->dob = temp->dob;
	j->years = temp->years;
	j->salary = temp->salary;
	j->pos = temp->pos;

}
int compareString(char* s, char* s2)
{
	char news[25];
	char news2[25];
	bool underscore = false;
	bool underscore2 = false;
	int i = 0;
	while (s[i] != '\0')
	{
		news[i] = tolower(s[i]);
		if (s[i] == '_')
		{
			underscore = true;
		}
		i++;
	}
	news[i] = '\0';
	i = 0;
	while (s2[i] != '\0')
	{
		news2[i] = tolower(s2[i]);
		if (s2[i] == '_')
		{
			underscore2 = true;
		}
		i++;
	}
	news2[i] = '\0';
	char *news3 = news;
	if (underscore)
	{
		news3 = strtok(news, "_");
		int l = 0;
		char *chArr[40];
		while (news3 != NULL)
		{
			chArr[l] = news3;
			news3 = strtok(NULL, "_");
			l++;
		}
		int m = 0;
		while (m + 1 < l)
		{
			news3 = strcat(chArr[m], chArr[m + 1]);
			m++;
		}
	}
	char *news4 = news2;
	if (underscore2)
	{
		news4 = strtok(news2, "_");
		int l = 0;
		char *chArr[40];
		while (news4 != NULL)
		{
			chArr[l] = news4;
			news4 = strtok(NULL, "_");
			l++;
		}
		int m = 0;
		while (m + 1 < l)
		{
			news4 = strcat(chArr[m], chArr[m + 1]);
			m++;
		}
	}
	bool equals = false;
	bool str = false;
	int length;
	if (strlen(news3) > strlen(news4))
	{
		length = strlen(news4);
		str = true;
	}
	else if (strlen(news3) < strlen(news4))
	{
		length = strlen(news3);
	}
	else
	{
		length = strlen(news3);
		equals = true;
	}
	if (strncmp(news3, news4, length) == 0)
	{
		if (equals)
		{
			return 0;
		}
		else
		{
			if (str)
			{
				return 1;

			}
			else
			{
				return -1;
			}
		}
	}
	else if (strncmp(news3, news4, length) > 0)
	{
		return 1;
	}
	else if (strncmp(news3, news4, length) < 0)
	{
		return -1;
	}
}
template <class T>
T compareNum(T num1, T num2)
{
	if (num1 < num2)
	{
		return -1;
	}
	else if (num1 == num2)
	{

		return 0;
	}
	else
	{
		return 1;
	}
}
int compare(char type, Node *j, Node *h)
{
	int result;
	char * jDate= new char[25];
	char * hDate= new char[25];
	switch(type)
	{
		case 'D':
			for(int i=0; i<4;i++)
			{
				jDate[i]=j->dob[6+i];
				hDate[i]=h->dob[6+i];
			}
			jDate[4]=j->dob[0];
			jDate[5]=j->dob[1];
			jDate[6]=j->dob[3];
			jDate[7]=j->dob[4];
			jDate[8]='\0';
			
			hDate[4]=h->dob[0];
			hDate[5]=h->dob[1];
			hDate[6]=h->dob[3];
			hDate[7]=h->dob[4];
			hDate[8]='\0';
			
			result=compareString(jDate, hDate);
		break;
		case 'f':
			result=compareString(j->first, h->first);
		break;
		case 'l':
			result=compareString(j->last, h->last);
		break;
		case 's':
			result=compareNum(j->salary, h->salary);
		break;
		case 'p':
			result=compareString(j->pos, h->pos);
		break;
		case 'y':
			result=compareNum(j->years, h->years);
		break;
		case 'i':
			result=compareNum(j->id, h->id);
		break;
		default:
			//cout<<"Invalid type."<<endl;
			return 0;
		break;
	}

	return result;
}
Node* partition(Node *l, Node *h, char type [], int n)
{
	Node *i=l;
	
	int result;
	bool equal;
	
	for (Node *j = l; j != h; j = j->next)
	{
		equal = true;
		result=compare(type[n], j, h);
		if(result<1)
		{
			/*int count=n-1;
			
			while(count>=0)
			{
				result=compare(type[count], i, j);
				result=compare(type[count], i, j);
				if(result!=0)
				{
					equal=false;
				}
				count--;
			}*/
			
			if(equal)
			{
				
				swap(i, j);
				i = (i == NULL) ? l : i->next;
			}
			
			
		}
	}
	
	equal = true;
	/*int count=n-1;
	
	while(count>=0)
	{
		result=compare(type[count], i, h);
		if(result!=0)
		{
			equal=false;
		}
		count--;
	}*/
	if(equal)
	{
		swap(i, h);
	}
	
	return i;
}

void _quickSort(struct Node* l, struct Node *h, char type[], int n)
{
	if (h != NULL && l != h && l != h->next)
	{
			struct Node *p = partition(l, h, type, n);
			_quickSort(l, p->prev, type, n);
			_quickSort(p->next, h, type, n);
	}
}

void quickSort(struct Node **head, char type[], int n)
{
	struct Node *h = *head;
	while (h->next != NULL)
	{
		h = h->next;
	}
	_quickSort(*head, h, type, n);
}

void print(struct Node *node, ofstream& file3)
{
	while (node != NULL)
	{
		//cout << setfill('0') << setw(5) << node->id << " " << node->first << " " << node->last << " " << node->dob << " " << node->years << " " << node->salary << " " << node->pos << endl;
		file3 << setfill('0') << setw(5) << node->id << " " << node->first << " " << node->last << " " << node->dob << " " << node->years << " " << node->salary << " " << node->pos << endl;
		node = node->next;
	}
}

string *cmds(ifstream &cmd, int &num)
{
	string *lines=new string[1000];
	string line;
	
	while(getline(cmd, line))
	{
		lines[num]=line;
		num++;
	}
	
	return lines;
}

int main(int argc, char *argv[])
{
	
	//Declare and/or initialize variables to be used in program.

	char input[25];
	char commands[25];
	char output[25];
	char types;
	int i=0;
	int y=1;
	int o;
	
	//Parse command line to retrieve and store file names.
	while(argv[y][i]!='\0')
	{
		switch(argv[y][i])
		{
			case '=':
			{
				i++;
				o=0;
				while(argv[y][i]!='\0'&&argv[y][i]!=';'&&argv[y][i]!=' ')
				{
					switch(types)
					{
						case 'i':
						{
							input[o]=argv[y][i];
							if(argv[y][i+1]=='\0'||argv[y][i+1]==';')
							{
								input[o+1]='\0';
							}
						}
						break;
						
						case 'c':
						{
							commands[o]=argv[y][i];
							if(argv[y][i+1]=='\0'||argv[y][i+1]==';')
							{
								commands[o+1]='\0';
							}
						}
						break;
						
						case 'o':
						{
							output[o]=argv[y][i];
							if(argv[y][i+1]=='\0'||argv[y][i+1]==';')
							{
								output[o+1]='\0';
							}
						}
						break;
					}
					o++;
					i++;
				}
				if((argv[y][i]=='\0'||argv[y][i]==';')&&argc>2&&y<3)
				{
						i=0;
						y++;
				}
			}
			break;
			
			case 'i':
			{
				types='i';
				i++;
			}
			break;
			
			case 'c':
			{
				types='c';
				i++;
			}
			break;
			
			case 'o':
			{
				if(argv[y][i+1]=='u')
				{
					types='o';
				}
				i++;
			}
			break;
			
			default:
			{
				i++;
			}
			break;
		}

	}
	
	//Declare and open input/output files
	ifstream file;
	ifstream file2;
	ofstream file3;

	file.open(input);
	file2.open(commands);
	file3.open(output);

	string str;
	struct Node* head = NULL;

	if (file.is_open() && file2.is_open())
	{
		while (getline(file, str))
		{		
			stringstream ss(str);
			int id;
			char *first=new char[25];
			char *last=new char[25];
			int years;
			int salary;
			char *pos=new char[25];
			char *dob=new char[25];
			string date;
			string month;
			string day;
			string yr;

			ss >> id;
			ss >> first;
			ss >> last;
			ss >> month;
			ss >> day;
			ss >> yr;
			date = month+' ' + day + ' '+yr;

			int i = 0;
			while (i < date.length())
			{
				dob[i] = date[i];
				i++;
			}
			dob[i] = '\0';
			ss >> years;
			ss >> salary;
			ss >> pos;

			addAtEnd(&head, id, first, last, dob, years, salary, pos);
		}
	}
	else
	{
		//cout<<"Error opening files..."<<endl;
	}

	file.close();

	string command;
	int index;
	char type[500];
	int n=0;
	
	int count=0;
	int num=0;
	string* lines = cmds(file2, num);

	while (count < num)
	{
		stringstream ss(lines[count]);
		ss >> command;

		count++;

		if (command == "sort")
		{
			ss >> command;
			type[n]=command[0];
			
			quickSort(&head, type, n);
			
			n++;
		}
		else if (command == "add")
		{
			ss >> command;
			
			int id;
			int years;
			int salary;
			string date;
			string month;
			string day;
			string yr;
			char *first;
			char *last;
			char *pos;
			char *dob;

			if (command == "at")
			{
				ss >> command;
				
				if (command == "end")
				{	
					stringstream ss(lines[count]);
					string word;
					ss>>word;
					
					while(count < num && word != "add" && word != "delete" && word != "output" && word != "sort")
					{	
						stringstream ss(lines[count]);

						first = new char[25];
						last = new char[25];
						pos = new char[25];
						dob = new char[25];
						ss >> id;
						ss >> first;
						ss >> last;
						ss >> month;
						ss >> day;
						ss >> yr;
						date = month + ' ' + day + ' ' + yr;
						int i = 0;
						while (i < date.length())
						{
							dob[i] = date[i];
							i++;
						}
						dob[i] = '\0';
						ss >> years;
						ss >> salary;
						ss >> pos;
						
						addAtEnd(&head, id, first, last, dob, years, salary, pos);
						
						count++;

						stringstream ss2(lines[count]);
						ss2 >> word;
					}
				}
				else if (command == "beginning")
				{
					stringstream ss(lines[count]);
					string word;
					ss>>word;
					
					while(count < num && word != "add" && word != "delete" && word != "output" && word != "sort")
					{
						stringstream ss(lines[count]);

						first = new char[25];
						last = new char[25];
						pos = new char[25];
						dob = new char[25];
						
						ss >> id;
						ss >> first;
						ss >> last;
						ss >> month;
						ss >> day;
						ss >> yr;
						date = month + ' ' + day + ' ' + yr;
						int i = 0;
						while (i < date.length())
						{
							dob[i] = date[i];
							i++;
						}
						dob[i] = '\0';
						ss >> years;
						ss >> salary;
						ss >> pos;
						
						addAtStart(&head, id, first, last, dob, years, salary, pos);
						
						count++;

						stringstream ss2(lines[count]);
						ss2 >> word;
					}
				}
			}
			else if (command == "before")
			{
				ss >> index;
				
				stringstream ss(lines[count]);
				string word;
				ss>>word;
					
				while(count < num && word != "add" && word != "delete" && word != "output" && word != "sort")
				{
					stringstream ss(lines[count]);

					first = new char[25];
					last = new char[25];
					pos = new char[25];
					dob = new char[25];
					
					ss >> id;
					ss >> first;
					ss >> last;
					ss >> month;
					ss >> day;
					ss >> yr;
					date = month + ' ' + day + ' ' + yr;
					int i = 0;
					while (i < date.length())
					{
						dob[i] = date[i];
						i++;
					}
					dob[i] = '\0';
					ss >> years;
					ss >> salary;
					ss >> pos;
					
					addBefore(&head, id, first, last, dob, years, salary, pos, index);
					
					count++;

					stringstream ss2(lines[count]);
					ss2 >> word;
				}
			}
			else if (command == "after")
			{
				ss >> index;
				
				stringstream ss(lines[count]);
				string word;
				ss>>word;
					
				while(count < num && word != "add" && word != "delete" && word != "output" && word != "sort")
				{
					stringstream ss(lines[count]);

					first = new char[25];
					last = new char[25];
					pos = new char[25];
					dob = new char[25];
					
					ss >> id;
					ss >> first;
					ss >> last;
					ss >> month;
					ss >> day;
					ss >> yr;
					date = month + ' ' + day + ' ' + yr;
					int i = 0;
					while (i < date.length())
					{
						dob[i] = date[i];
						i++;
					}
					dob[i] = '\0';
					ss >> years;
					ss >> salary;
					ss >> pos;

					addAfter(&head, id, first, last, dob, years, salary, pos, index);
				
					count++;

					stringstream ss2(lines[count]);
					ss2 >> word;
				}
			}
		}
		else if (command == "delete")
		{
			char* commander = new char[100];
			ss >> commander;
			if (commander[0] == 'a')
			{
				ss >> command;
				if (command == "beginning")
				{
					deleteNode(&head, 0);
				}
				else if (command == "end")
				{
					deleteEnd(&head);
				}
			}
			else
			{
				int num = atoi(commander);
				ss >> command;

				if (command == "to")
				{
					ss >> index;
					for (int i = num; i <= index; i++)
					{
						deleteNode(&head, num);
					}
				}
				else
				{
					deletes(&head, num);
				}
			}
		}
		else if (command == "output")
		{
			file.open(input);
			string str2;
			while (getline(file, str2))
			{
				//cout << str2 << endl;
				file3 << str2 << endl;
			}
			file.close();
		}
		if(command!="output")
		{
			print(head, file3);
		}
		//cout<<endl;
		file3<<endl;
	}
	file2.close();
	file3.close();

	//system("pause");
	return 0;
}
