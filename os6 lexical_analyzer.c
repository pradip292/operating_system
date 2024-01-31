#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
int main() 
{ 
		FILE *input, *output; 
		int l=1; 
		int t=0; 
		int j=0; 
		int i,flag; 
		char ch,str[20]; 
		input = fopen("yash.txt","r"); //take the input for reading
		output = fopen("musmade.txt","w"); //display the output for writing
		char keyword[30][30] = {"int","main","if","else","do","while"}; 
		fprintf(output,"Line no. \t Token no. \t\t Token \t\t\t Output\n\n"); 
			while(!feof(input)) 
			{ 
			i=0;   // Initialize the index for the current token
			flag=0;   // Reset the flag
			ch=fgetc(input); // Read a character from the input file
					if( ch=='+' || ch== '-' || ch=='*' || ch=='/' ) 
						{ 
						fprintf(output,"%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch); 
						t++; 
						} 
					else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || 
					ch=='@' || ch=='!' || 
					ch=='%') 
						{ 
						fprintf(output,"%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch); 
						t++; 
						} 
					 
			
				else if(isdigit(ch)) 
					{ 
					fprintf(output,"%7d\t\t %7d\t\t Constant \t\t %7c\n",l,t,ch); 
					t++; 
					} 
				else if(isalpha(ch)) 
				{ 
					str[i]=ch; // Store the first character of an identifier or keyword
					i++; 
					ch=fgetc(input);  // Read the next character
						while(isalnum(ch) && ch!=' ') 
							{ 
							str[i]=ch; // Store subsequent characters
							i++; 
							ch=fgetc(input); 
							} 
					str[i]='\0';   // Null-terminate the string
					for(j=0;j<=30;j++) 
						{ 
							if(strcmp(str,keyword[j])==0) 
								{ 
								flag=1;   // Set the flag if the token is a keyword
								break; 
								} 
						} 
							if(flag==1) 
							{ 
							fprintf(output,"%7d\t\t %7d\t\t Keyword\t %7s\n",l,t,str); 
							t++;  // Increment the token number
							} 
						else 
							{ 
							fprintf(output,"%7d\t\t %7d\t\t Identifier\t %7s\n",l,t,str); 
							t++; 
							} 
				 
				} 
				else if(ch=='\n') 
					{ 
					l++; 
					} 
			} 
		fclose(input); //close the input file
		fclose(output); //close the output file
		return 0; 
}
