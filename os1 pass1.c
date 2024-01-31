#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct table 
{
	char mname[10];
	char mop[5];
}mot[10];
struct sym
{
	int srno;
	char sn[10];
	int saddr;
}SYMTAB[10];

struct lit
{
   int lrno;
   char ln[10];
   int laddr;
}LITTAB[10];

int main()
{
	
	FILE *fp;
	fp=fopen("src.alp","r");
	int n;
	int lc, sptr=1, isflag=0, lptr=1;
	int symfound=0;
	int litfound=0;
	int DLflag=0;
	char str[10], str1[10];
	int i;
	// MOT is Created and Init
	strcpy(mot[0].mname,"STOP");
	strcpy(mot[0].mop, "00");
	strcpy(mot[1].mname,"ADD");
	strcpy(mot[1].mop, "01");
	strcpy(mot[2].mname,"SUB");
	strcpy(mot[2].mop,"02");
	strcpy(mot[3].mname,"MULT");
	strcpy(mot[3].mop,"03");
	strcpy(mot[4].mname,"MOVEM");
	strcpy(mot[4].mop, "04");
	strcpy(mot[5].mname,"MOVER");
	strcpy(mot[5].mop, "05");
	
	
	if(fp==NULL)
	{
		printf("ERROR");
	}
	else
	{
		while(fscanf(fp,"%s",str)!=EOF)
		{
			isflag=0;
			symfound=0;
			litfound=0;
			DLflag=0;
			if(strcmp(str,"START")==0)
			{
				isflag=1;
				DLflag=1;
				printf("\n (AD 01)");
				fscanf(fp,"%s",str);
				lc=atoi(str);
				printf("  (C %d)",lc);
			}
			if(strcmp(str,"END")==0)
			{
				isflag=1;
				DLflag=1;
				printf("\n%d)(AD 02)",lc);
				for(i=1;i<lptr;i++)
				{
					printf("\n%d) Literal %s is procesed",lc,LITTAB[i].ln);
					LITTAB[i].laddr=lc;
					lc++;
				}
			}
			// iMPERATUIVE STATEMENT
			if(isflag==0)
			{
				
					for (i=0;i<10;i++)
					{
						if(strcmp(str,mot[i].mname)==0)
						{
							DLflag=1;	
								
							printf("\n %d (IS %s)", lc, mot[i].mop);
							lc++; // ONE IS conveterd into ONe MCCODE 
							// OPERAND 1
							
							fscanf(fp,"%s",str); 
							if(strcmp(str,"AREG")==0)
									printf("   (R, 1)");
							else if(strcmp(str,"BREG")==0)
					   		 printf("  (R, 2)");
					   	else if(strcmp(str,"CREG")==0)
					   		 printf("  (R, 3)");
							else if(strcmp(str,"DREG")==0)
							    printf("   (R,4)");
						
							// OPERND 2 can be LITREAL or SYMBOL
						
							fscanf(fp,"%s",str); 
			
							// search is it LIT or SYMBOL
							if(str[0]!='=')
							{
									// CHECK SYMBOL IS PRESNT OR NOT.....
								
								// IF NOT PRESENT THEN do entry in symbol table
								// CHeck the sybol PRESENT in ST or not
									
								// If found.....
								for(i=1;i<=sptr;i++)
								{
										if(strcmp(str,SYMTAB[i].sn)==0)
										{
													printf("   (S, %d)",i);		
													symfound=1;
													break;						
										}
								}
								if(symfound==0)
								{
									strcpy(SYMTAB[sptr].sn,str);
									SYMTAB[sptr].srno=sptr;
									printf("   (S, %d)",sptr);
									sptr++;
								}
						} //SYM work is over
						else if(str[0]=='=')
						{
					
						   for(i=1;i<=lptr;i++)
						   {
							     if(strcmp(str,LITTAB[i].ln)==0)
							     {
								       printf("   (L, %d)",i);
								       litfound=1;
								       break;
							     }
						   }
						   
						   if(litfound==0)
						   {
							     strcpy(LITTAB[lptr].ln,str);
							     LITTAB[lptr].lrno=lptr;
							     printf("   (L, %d)",lptr);
							     lptr++;
						   }
					   
					}
				}
			} // FOr loop of IS is closed
	}// IS code is over
					
							// code for DL statement............
					if(DLflag==0)
					{
						// Search whetaher that sym is present in ST 
						for(i=1;i<=sptr;i++)
						{
								if(strcmp(str,SYMTAB[i].sn)==0)
								{
									SYMTAB[i].saddr=lc;
									break;
								}
						
						}
						fscanf(fp,"%s",str);  // DC DS
						fscanf(fp,"%s",str1);  // COnst
						if(strcmp(str,"DC")==0)
						{
							printf("\n %d (DL 01) (C  %s)", lc, str1);
							lc++;



							
						}
						else if(strcmp(str,"DS")==0)
						{
							n=atoi(str1);
							lc=lc+n;
						}

					}
				 // DL COde ends here
		}
			
		
		
	}
	printf("\n----------------------------------------------");
	printf("\n \t SYMBOL TABLE ");
	printf("\n SRNO. \t SNAME \tSADDR");
	for(i=1;i<sptr;i++)
	{
		printf("\n %d \t %s \t%d",SYMTAB[i].srno,SYMTAB[i].sn,SYMTAB[i].saddr);
	
	}
		printf("\n----------------------------------------------");
	
	printf("\n \t LITERAL TABLE ");
	printf("\n LRNO. \t LNAME \tLADDR");
	for(i=1;i<lptr;i++)
	{
	  printf("\n %d \t %s \t%d",LITTAB[i].lrno,LITTAB[i].ln,LITTAB[i].laddr);
	
	}
	fclose(fp);

	return 0;
}
