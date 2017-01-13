# Steganography
Image Steganography In C.

Steganography Is The Process To Hide Text Files In A Image Without Altering The Original Image.
The Text Is Hidden In .BMP Image Files.

FOR EXECUTION OF THE PROGRAM , FOLLOW THE STEPS :-

~$ gcc Steganography.c

After Compiling The GCC will Create A Output File i.e "a.out".

*** ENCODING ***

~$ ./a.out -E -i input_image.bmp -s secret_text.txt -o output_image.bmp

*** DECODING ***

~$ ./a.out -D -i output.bmp -o text_output.txt

// text_output.txt Is To Store The Secret Text Present In Image.

*** INDEX ***

	-E = ENCODING
	-D = DECODING
	-i = Input Source BMP Image / Output Image
	-s = Secret Text File
	-o = Output BMP Image / Output Text File
  
  ************ THANK YOU *****************
  
  # Biswajeet Sahoo.
