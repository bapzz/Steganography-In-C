/* decryption of sizes */
void size_decryption(FILE *pf1, int *size_txt)
{
	int file_buff = 0, i;
	int ch, bit_msg;
	for (i = 0; i < 8; i++)
	{
		ch = fgetc(pf1);
		bit_msg = (ch & 1);
		if (bit_msg)
		{
			file_buff = (file_buff << 1) | 1;
		}
		else
		{
			file_buff = file_buff << 1;
		}
	}
	*size_txt = file_buff;
}

/* decryption of strings*/
void string_decryption(FILE *pf1,char *strng,int size)
{
	int file_buff=0, i, j=0, k=0;
	int ch, bit_msg;
	for (i = 0; i < (size * 8); i++)
	{
		j++;
		ch = fgetc(pf1);
		bit_msg = (ch & 1);
		if (bit_msg)
		{
			file_buff = (file_buff << 1) | 1;
		}
		else
		{
			file_buff = file_buff << 1;
		}

		if ( j == 8)
		{
			strng[k] =(char)file_buff; 
			j=0;
			k++;
			file_buff = 0;
		}
	}
	strng[k] = '\0';
}
/* decryption of secret message*/
void secret_decryption(int size_txt, FILE *pf1, FILE *pf2)
{
	int file_buff=0, i, j = 0, k = 0;
	int ch,bit_msg;
	char output[250] = {0};
	for (i = 0; i < (size_txt * 8); i++)
	{
		j++;
		ch = fgetc(pf1);
		bit_msg = (ch & 1);
		if (bit_msg)
		{
			file_buff = (file_buff << 1) | 1;
		}
		else
		{
			file_buff = file_buff << 1;
		}

		if ( j == 8)
		{
			putc(file_buff, pf2);
			output[k++] = file_buff;
			j=0;
			file_buff = 0;
		}
	}
	printf("\n*** Secret Text Is ==> %s\n\n", output);
}
int Decode(char *argv_2, char *argv_4)
{
	FILE *pf1, *pf2;
	
	int size, size1, size_txt;

	//opening Image File
	if((pf1 = fopen(argv_2, "r")) == NULL) 
	{
		printf("Could not open file %s.\nAborting\n", argv_2);
		return 1;
	}

	fseek(pf1,54 ,SEEK_SET);
	
	if((pf2 = fopen(argv_4, "w+")) == NULL) 
	{
		printf("Could not open file %s.\nAborting\n", argv_4);
		return 1;
	}

	//magic str
	char magic_strn[20], magic_strn1[20], strng[20];
	int j;

	size_decryption(pf1,&size);
	string_decryption(pf1,magic_strn,size);

	printf("\nEnter the  magic string : \t");
	for(j = 0;(magic_strn1[j] = getchar()) != '\n'; j++);
	magic_strn1[j]= '\0';

	int temp;
	temp = strcmp(magic_strn1, magic_strn);

	if(temp)
	{
		printf("\n\t*** Entered Wrong Magic String ***\n");
		return 0;
	}
	else
		printf("\n\t*** Magic String Accepted ***\n\n");

	//password
	char passwd[20], passwd_str[20];

	size_decryption(pf1,&size1);
	string_decryption(pf1,passwd_str,size1);

	printf("Enter The Password : \t");
	scanf("%s", passwd);

	temp = strcmp(passwd,passwd_str);

	if(temp)
	{
		printf("\n\t*** Entered Wrong Password ***\n");
		return 0;
	}
	else
		printf("\n\t*** Password Accepted ***\n");

	/*Secret Text */
	size_decryption(pf1, &size_txt);
	secret_decryption(size_txt, pf1, pf2);

	printf("*** The Secret Text Is Copied To ==> %s\n\n", argv_4);

	/* closeing files */
	fclose(pf1);

}
