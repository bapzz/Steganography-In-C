#include "Stegano_header.h"

int main(int argc,char *argv[])
{
    int i;
    char *argv_2,*argv_3,*argv_4;

    switch(argc)
    {
			//Comparing For 
	case 8 :	if(!strcmp(argv[1],"-E"))
			{
			    for (i = 2; i < 8; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];

				if (!strcmp(argv[i],"-s"))
				    argv_3 = argv[i+1];

				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    
			    Encoding(argv_2, argv_3, argv_4);
			    break;
			}

	case 6 :	if(!strcmp(argv[1], "-D"))
			{
			    for (i = 2; i < 6; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];
				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    

			    Decode(argv_2, argv_4);
			    break;
			}

	default : 
		printf("\t*** !! Error !! ERROR !! Error !!***\n\n");
		printf("*** EXECUTION ==> ");
		printf("\n\t\t*** ENCODING *** ==> \t./a.out -E -i <input.bmp> -s <secret.txt> -o <output.bmp>\n\n");
		printf("\t\t*** DECODING *** ==> \t./a.out -D -i <output.bmp> -o <output_text.txt>\n\n");
		printf("\t\tFOR MORE DETAILS ===> **README**\n");

    }	
    return 0;
}

