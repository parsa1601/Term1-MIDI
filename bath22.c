# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include"beep.h"
# include"notes_freq.h"
# include <math.h>
# define ALWAYS 1
# define TEMPOEVENT 16
# define NOTTEMPO 15
# define CLEAN     printf("\033[H\033[J")
# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"


void frequency_convert (int octave, int note_group , char * pointer);
float findfreq (char note_type[5]); 
note_inf notes[110]; /******* protype of arrays of structures which is in our header library (notes_freq) *******/

int delta_make (FILE * my_file);

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

typedef struct 
{
    unsigned char tr_header [4];
    unsigned int tr_length;
}track_information;


/******* this function is to convert the readed format of little-endian systems which are different in
         reading bytes into big-endian format to display in the order which is needed!   *******/
int change_endian (int x); 

int main()
{
    NOTES_FREQ(notes); /******* the function which is in our header library (notes_freq) *******/
    header_chunk chunk;
    track_information track;
    FILE *infile = fopen ("bach22.mid","rb"); /******* reading bytes if MIDI file in the project folder *******/
////////////////////////////forelise//break//sugarplum//bach22//00
    if (infile==NULL) { // to check if input file is opened properly or not
		printf("Sorry, input file not found");
		exit(1); // terminates the program
		}
    int array_home; /******* the counter which is used in the loop for type of MIDI file string *******/
    /******* 3 temperary valuables for reading data of MIDI file and then cobverting into int to display *******/
    /******* these 2-home charachters are for reading only 2 bytes for each part of DARA which is 2 bytes, but for print them
we should convert into integer numbers because if we don't do that, the program prints its ascii code instead of the number! *******/
    unsigned char temp1[2];
    unsigned char temp2[2];
    unsigned char temp3[2];
    fread (chunk.type, sizeof(chunk.type) , 1 , infile);
        printf("%s", RED);
    if (strstr (chunk.type , "MThd") == NULL) {
         printf ("WARNING : YOUR MIDI FILLE IS NOT SUPPORTED!! \n");
         printf ("PLEASE UPLOAD 'MThd' MIDI FILE!");
    }
    else 
    {
    	 printf("%s", NRM);
    printf ("----------------------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\t **HEADER CHUNK**\n");
    printf ("----------------------------------------------------------------------------------------------------\n");
    /******* read and show the type of MIDI file *******/
    	printf("%s", RED);
    printf ("TYPE OF YOUR MIDI FILE == ");
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
    if (chunk.data.format == 2) {
    							printf("%s", WHT);
                                printf("TASK FAILD SUCCESSFULY :D\nYOUR MIDI FILE  IS TYPE 2\n");
                                exit(0);
                                }
                            printf("%s", YEL);
    fread (track.tr_header,sizeof(track.tr_header), 1, infile);
    printf ("TYPE OF TOUR MIDI TRACK == ");
    for ( array_home=0 ; array_home<4 ; array_home ++ ) printf("%c",track.tr_header[array_home]); 
    printf("\n");

    fread (&track.tr_length, 4, 1 , infile);
    printf ("BYTE-COUNT(LENGTH) OF YOUR HOLE TRACK == ");
    track.tr_length = change_endian(track.tr_length);
    printf("%d\n",track.tr_length);
    int count=0;
    int i,j; /******* size of array counters for print *******/
    unsigned char event[4]; /******* an array for getting bytes and checking its event *******/
    unsigned char tempo[4]; /******* temperary valuables *******/
    unsigned char velocity; /******* valuable for velocit of notes *******/
    unsigned char tempoo_check[2]; /******* valuable for tempo (FF 51) *******/
    int event_beep; /******* valuable for chack event is note on or note off *******/
    int frequency; /******* valuable for decimal form of frequency *******/
    char note_comp[4]; /******* frequency valuable which should be compare like first phase *******/
    int note_group,octave;
    /////int octave;
    ////int time;
    int temp5,time,duration;
    float final_freq; 
    int tempo_dec;
    int tempo1,tempo2;
    int flag = 0;
    int shape_form=0;
    ///int duration;
    char *pointer = (char *) malloc (4*sizeof(char));
    while (ALWAYS)
    {
                time = delta_make(infile); /******* recieve and conveting delta time ito decimal *******/
                /******* getting events, cast into decimal and check  *******/
                event[0] = fgetc(infile); 
                event_beep = event[0];
                event[1] = fgetc(infile);
                int event_beep2 = event [1];
                /******* check for tempo evetn, this part is hard to explain :/  *******/
                if (event_beep == 255 || event_beep2 == 255)  {
                    fseek ( infile , -1 , SEEK_CUR);
                    fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);

                    if (tempoo_check[1] == 81 || tempoo_check[0] == 81)  {
                        if (tempoo_check[0] == 81) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                               printf("%s", MAG);
                    printf ("TEMPO EVENT\n");
                    for ( j = 0; j <=1 ; j++)
                    {
                        printf ("%x\n" , tempoo_check[j]);
                    }
                    tempo1 = tempoo_check[1];
                    printf ("EVET KEY %d\n", tempo1);
                    flag = TEMPOEVENT;}

                    if (tempoo_check[1] == 47 || tempoo_check[0] == 47){
                        if (tempoo_check[0] == 47) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                    unsigned char finish = fgetc (infile);
                    for ( j = 0; j <=1 ; j++)
                    {
                        printf ("%x\n" , tempoo_check[j]);
                    }                    
                    printf("%x\nTRACK FINISHED!\n",finish);
                    exit(0);
                    }

                    if (tempoo_check[1] == 1 || tempoo_check[0] == 1){
                        if (tempoo_check[0] == 1) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("TEXT EVENT\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 2 || tempoo_check[0] == 2){
                        if (tempoo_check[0] == 2) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                           printf("%s", GRN);
                    printf("COPYWRITE NOTICE\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 3 || tempoo_check[0] == 3){
                        if (tempoo_check[0] == 3) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("TRACK NAME\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 4 || tempoo_check[0] == 4){
                        if (tempoo_check[0] == 4) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("INSTRUMENT NAME\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 5 || tempoo_check[0] == 5){
                        if (tempoo_check[0] == 5) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("LYRIC\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 6 || tempoo_check[0] == 6){
                        if (tempoo_check[0] == 6) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("MARKER\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }

                    if (tempoo_check[1] == 7 || tempoo_check[0] == 7){
                        if (tempoo_check[0] == 7) {fseek ( infile , -3 , SEEK_CUR);
                                                   fread (tempoo_check , sizeof(tempoo_check) , 1 , infile);
                                                   }
                                            printf("%s", GRN);
                    printf("CUE POINT\n");
                    unsigned char text = fgetc (infile);
                    unsigned char print_text;
                    text = (int) text;
                    for ( j = 0; j <=text ; j++)
                    {
                    	print_text = fgetc(infile);
                        printf ("%c" , print_text);
                    }                    
                    printf("\n");
                    }


                    }


                /******* printing tempo  *******/
                if (flag == TEMPOEVENT && flag != 15)
                {
                    tempo[0] = fgetc(infile);
                    tempo[1] = fgetc(infile);
                    tempo[2] = fgetc(infile);
                    tempo_dec =  tempo[0] << 16 | tempo[1] << 8 | tempo[2];
                    						printf("%s", WHT);
                    printf ("tempo in dec  %d\n",tempo_dec);
                    printf ("tempo  %x\t",tempo[0]);
                    printf ("tempo  %x\t",tempo[1]);
                    printf ("tempo  %x\n",tempo[2]);
                    flag = NOTTEMPO;
                }
                /******* note on note off event  *******/
                if (event_beep >=128 && event_beep <=159)
                {
                						printf("%s", BLU);
                printf ("time in dec%d\n", time);
                /******* calculating the duraton which will be passed to beep function  *******/
				temp5 = 10000 * chunk.data.division;
                duration = temp5 * time / tempo_dec;

                if (duration < 0) duration*=-1;
                						printf("%s", CYN);
                printf("eve%x\n",event_beep);
                						printf("%s", GRN);
                frequency = event[1];
                /*******  converting decimal form of frequnecy into note, based on midi note table *******/
                note_group = frequency % 12;
                octave = ( frequency / 12 ) + 48;
                frequency_convert(octave , note_group , pointer);
                puts (pointer);

                velocity = fgetc(infile);
                /******* the following function checks and returns the frequency of each character *******/
                final_freq = findfreq(pointer);
                         	   			printf("%s", YEL);                			
                printf ("duration %d\n\n", duration);
                final_freq+=20;
                beep (final_freq , duration/7 );
                shape_form++;
                						printf("%s", GRN);
                if (shape_form % 6 == 0) printf("\n");
                if (shape_form % 6 == 1) {printf("%s", YEL); printf("    ^      ^\n"); printf("%s", GRN); printf("    #      #\n");}
                if (shape_form % 6 == 2) {printf("%s", YEL); printf("    ^      ^\n"); printf("%s", GRN); printf("    #      #\n"); printf("%s", YEL); printf("      *****\n");} 
                if (shape_form % 6 == 3) {printf("%s", YEL); printf("    ^      ^\n"); printf("%s", GRN); printf("    #      #\n"); printf("%s", YEL); printf("      **********\n");}  
                if (shape_form % 6 == 4) {printf("%s", YEL); printf("    ^      ^\n"); printf("%s", GRN); printf("    #      #\n"); printf("%s", YEL); printf("      **********\n"); printf("%s", RED); printf("     _______/\n");}
                if (shape_form % 6 == 5) {printf("%s", YEL); printf("    ^      ^\n"); printf("%s", GRN); printf("    #      #\n"); printf("%s", YEL); printf("      **********\n"); printf("%s", RED); printf("     _______/\n"); printf("    /\n");} 
                }
    }
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

/******* this function gets and converts deltatime into decimal *******/
int delta_make (FILE * my_file)
{
    unsigned int value;
    unsigned char c;

    if ( (value = getc(my_file)) & 0x80)
    {
        value &= 0x7f;
        do
        {
            value = (value << 7) + ((c = getc(my_file)) & 0x7f);
        } while (c & 0x80);    
    }

    return (value);
}
/******* the following function checks and returns the frequency of each character *******/
float findfreq(char string[5])
{
    int i;
    for (i=0;i<=108;i++)
        {
            if (strcmp(notes[i].name , string)== 0) return notes[i].freq;
        }
}

void frequency_convert (int octave, int note_group , char * pointer)
	{
		char note_comp[4];

		                 if (note_group == 0)  
                                {
                                    note_comp[0] = 'C';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 1)  
                                {
                                    note_comp[0] = 'C';
                                    note_comp[1] = '#';
                                    note_comp[2] = octave;
                                    note_comp[3] = '\0';
                                }
                    else if (note_group == 2)  
                                {
                                    note_comp[0] = 'D';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 3)  
                                {
                                    note_comp[0] = 'D';
                                    note_comp[1] = '#';
                                    note_comp[2] = octave;
                                    note_comp[3] = '\0';
                                }
                    else if (note_group == 4)  
                                {
                                    note_comp[0] = 'E';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 5)  
                                {
                                    note_comp[0] = 'F';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 6)  
                                {
                                    note_comp[0] = 'F';
                                    note_comp[1] = '#';
                                    note_comp[2] = octave;
                                    note_comp[3] = '\0';
                                }
                    else if (note_group == 7)  
                                {
                                    note_comp[0] = 'G';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 8)  
                                {
                                    note_comp[0] = 'G';
                                    note_comp[1] = '#';
                                    note_comp[2] = octave;
                                    note_comp[3] = '\0';
                                }
                    else if (note_group == 9)  
                                {
                                    note_comp[0] = 'A';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }
                    else if (note_group == 10)  
                                {
                                    note_comp[0] = 'A';
                                    note_comp[1] = '#';
                                    note_comp[2] = octave;
                                    note_comp[3] = '\0';                               
                                }
                    else if (note_group == 11)  
                                {
                                    note_comp[0] = 'B';
                                    note_comp[1] = octave;
                                    note_comp[2] = '\0';
                                }	

            strcpy(pointer , note_comp);
	}

