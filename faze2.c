# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/******* We Should Define a structure for data part of the MIDI file *******/
typedef struct 
{
    unsigned int format;
    unsigned int track;
    unsigned int division;
}header_data;
/******* this structure is the header chunk of the MIDI file *******/
typedef struct 
{
   unsigned char type [4];
   unsigned int length;
   header_data data;
}header_chunk;

/******* this function is to convert the readed format of little-endian systems which are different in
         reading bytes into big-endian format to display in the order which is needed!   *******/
int change_endian (int x); 

int main()
{
    header_chunk chunk;
    FILE *infile = fopen ("Movie_Themes_-_Addicted_To_Love.mid","rb"); /******* reading bytes if MIDI file in the project folder *******/

    int array_home; /******* the counter which is used in the loop for type of MIDI file string *******/\
    /******* 3 temperary valuables for reading data of MIDI file and then cobverting into int to display *******/
    int counter;
    /******* these 2-home charachters are for reading only 2 bytes for each part of DARA which is 2 bytes, but for print them
we should convert into integer numbers because if we don't do that, the program prints its ascii code instead of the number! *******/
    unsigned char temp1[2];
    unsigned char temp2[2];
    unsigned char temp3[2];
    fread (chunk.type, sizeof(chunk.type) , 1 , infile);
    if (strstr (chunk.type , "MThd") == NULL) {
         printf ("WARNING : YOUR MIDI FILLE IS NOT SUPPORTED!! \n");
         printf ("PLEASE UPLOAD 'MThd' MIDI FILE!");
    }
    else 
    {
    printf ("----------------------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\t **HEADER CHUNK**\n");
    printf ("----------------------------------------------------------------------------------------------------\n");
    /******* read and show the type of MIDI file *******/

    printf ("TYPE OF TOUR MIDI FILE == ");
    for ( array_home=0 ; array_home<4 ; array_home ++ ) printf("%c",chunk.type[array_home]); 
    printf("\n");
    }
    /******* read and show the length of MIDI file *******/
    fread (&chunk.length, 4, 1 , infile);
    printf ("lENGTH OF TOUR MIDI FILE == ");
    chunk.length = change_endian(chunk.length);
    printf("%d\n",chunk.length);

    /******* read and show the format of MIDI file *******/
    fread (temp1, sizeof(temp1), 1 , infile);
    printf ("FORMAT OF THE DATA PART OF YOUR MIDI FILE == ");
    chunk.data.format = temp1[1] | temp1[0] <<8;
    printf ("%d\n", chunk.data.format);

    /******* read and show the track of MIDI file *******/
    fread (temp2, sizeof(temp2), 1 , infile);
    printf ("TRACK OF THE DATA PART OF YOUR MIDI FILE == ");

    /******* read and show the track of MIDI file *******/
    chunk.data.track = temp2[1] | temp2[0] <<8;
    printf ("%d\n", chunk.data.track);

    fread (temp3, sizeof(temp3), 1 , infile);
    printf ("DIVISION OF THE DATA PART OF YOUR MIDI FILE == ");

    chunk.data.division = temp3[1] | temp3[0] <<8;
    printf ("%d\n", chunk.data.division);
    printf ("----------------------------------------------------------------------------------------------------\n");

    

    
    /******* close the file *******/
    fclose (infile);
    return 0;
}

/******* this function is to convert the readed format of little-endian systems which are different in
         reading bytes into big-endian format to display in the order which is needed!   *******/
int change_endian (int x)
{
    return ( ( x >> 24 ) | (( x << 8) & 0x00ff0000 )| ((x >> 8) & 0x0000ff00) | ( x << 24) ) ;
   
}

