# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "notes_freq.h"

int NOTES_FREQ(note_inf notes[])
{

    
    strcpy(notes[0].name ,"C0" );
    notes[0].freq= 16.35;

    strcpy(notes[1].name ,"C#0" );
    notes[1].freq= 17.32;

    strcpy(notes[2].name ,"D0" );
    notes[2].freq= 18.35;

    strcpy(notes[3].name ,"D#0") ;
    notes[3].freq= 19.45;

    strcpy(notes[4].name ,"E0" );
    notes[4].freq= 20.60;

    strcpy(notes[5].name ,"F0" );
    notes[5].freq= 21.83;

    strcpy(notes[6].name ,"F#0" );
    notes[6].freq= 23.12;

    strcpy(notes[7].name ,"G0"  );
    notes[7].freq= 24.50;

    strcpy(notes[8].name ,"G#0" );
    notes[8].freq= 16.35;

    strcpy(notes[9].name ,"A0" );
    notes[9].freq= 27.50;

    strcpy(notes[10].name , "A#0" );
    notes[10].freq = 29.14;

    strcpy(notes[11].name , "B0" );
    notes[11].freq = 30.87;

    strcpy(notes[12].name , "C1" );
    notes[12].freq = 32.70;

    strcpy(notes[13].name , "C#1" );
    notes[13].freq = 34.65;

    strcpy(notes[14].name , "D1" );
    notes[14].freq = 36.71;

    strcpy(notes[15].name , "D#1" );
    notes[15].freq = 38.89;

    strcpy(notes[16].name , "E1" );
    notes[16].freq = 41.20;

    strcpy(notes[17].name , "F1" );
    notes[17].freq = 43.62;

    strcpy(notes[18].name , "G1" );
    notes[18].freq = 49.00;

    strcpy(notes[19].name , "G#1" );
    notes[19].freq = 51.91;

    strcpy(notes[20].name , "A1" );
    notes[20].freq = 55.00;

    strcpy(notes[21].name , "A#1" );
    notes[21].freq = 58.27;

    strcpy(notes[22].name , "B1" );
    notes[22].freq = 61.74;

    strcpy(notes[23].name , "C2" );
    notes[23].freq = 65.41;

    strcpy(notes[24].name , "C#2" );
    notes[24].freq = 69.30;

    strcpy(notes[25].name , "D2" );
    notes[25].freq = 73.42;

    strcpy(notes[26].name , "D#2" );
    notes[26].freq = 77.48;

    strcpy(notes[27].name , "E2" );
    notes[27].freq = 82.41;

    strcpy(notes[28].name , "F2" );
    notes[28].freq = 87.31;

    strcpy(notes[29].name , "F#2" );
    notes[29].freq = 92.50;

    strcpy(notes[30].name , "G2" );
    notes[30].freq = 98.00;

    strcpy(notes[31].name , "G#2" );
    notes[31].freq = 103.83;

    strcpy(notes[32].name , "A2" );
    notes[32].freq = 110.00;

    strcpy(notes[33].name , "A#2" );
    notes[33].freq = 116.54;

    strcpy(notes[34].name , "B2" );
    notes[34].freq = 123.47;

    strcpy(notes[35].name , "C3" );
    notes[35].freq = 130.81;

    strcpy(notes[36].name , "C#3" );
    notes[36].freq = 138.59;

    strcpy(notes[37].name , "D3" );
    notes[37].freq = 146.83;

    strcpy(notes[38].name , "D#3" );
    notes[38].freq = 155.56;

    strcpy(notes[39].name , "E3" );
    notes[39].freq = 164.81;

    strcpy(notes[40].name , "F3" );
    notes[40].freq = 174.61;

    strcpy(notes[41].name , "F#3" );
    notes[41].freq = 185.00;

    strcpy(notes[42].name , "G3" );
    notes[42].freq = 196.00;

    strcpy(notes[43].name , "G#3" );
    notes[43].freq = 207.65;

    strcpy(notes[44].name , "A3" );
    notes[44].freq = 220.00;

    strcpy(notes[45].name , "A#3" );
    notes[45].freq = 233.08;

    strcpy(notes[46].name , "B3" );
    notes[46].freq = 246.94;

    strcpy(notes[47].name , "C4" );
    notes[47].freq = 261.63;

    strcpy(notes[48].name , "C#4" );
    notes[48].freq = 277.18;

    strcpy(notes[49].name , "D4" );
    notes[49].freq = 293.66;

    strcpy(notes[50].name , "D#4" );
    notes[50].freq = 311.13;

    strcpy(notes[51].name , "E4" );
    notes[51].freq = 329.63;

    strcpy(notes[52].name , "F4" );
    notes[52].freq = 349.23;

    strcpy(notes[53].name , "F#4" );
    notes[53].freq = 369.99;

    strcpy(notes[54].name , "G4" );
    notes[54].freq = 392.00;

    strcpy(notes[55].name , "G#4" );
    notes[55].freq = 415.30;

    strcpy(notes[56].name , "A4" );
    notes[56].freq = 440.00;

    strcpy(notes[57].name , "A#4" );
    notes[57].freq = 466.16;

    strcpy(notes[58].name , "B4" );
    notes[58].freq = 493.88;

    strcpy(notes[59].name , "C5" );
    notes[59].freq = 523.25;

    strcpy(notes[60].name , "C#5" );
    notes[60].freq = 554.37;

    strcpy(notes[61].name , "D5" );
    notes[61].freq = 587.33;

    strcpy(notes[62].name , "D#5" );
    notes[62].freq = 622.25;

    strcpy(notes[63].name , "E5" );
    notes[63].freq = 659.25;

    strcpy(notes[64].name , "F5" );
    notes[64].freq = 698.46;

    strcpy(notes[65].name , "F#5" );
    notes[65].freq = 739.99;

    strcpy(notes[66].name , "G5");
    notes[66].freq = 783.99;

    strcpy(notes[67].name , "G#5");
    notes[67].freq = 830.61;

    strcpy(notes[68].name , "A5" );
    notes[68].freq = 880.00;

    strcpy(notes[69].name , "A#5");
    notes[69].freq = 932.33;

    strcpy(notes[70].name , "B5");
    notes[70].freq = 987.77;

    strcpy(notes[71].name , "C6");
    notes[71].freq = 1046.50;

    strcpy(notes[72].name , "C#6");
    notes[72].freq = 1108.73;

    strcpy(notes[73].name , "D6");
    notes[73].freq = 1174.66;

    strcpy(notes[74].name , "D#6");
    notes[74].freq = 1244.51;

    strcpy(notes[75].name , "E6");
    notes[75].freq = 1318.51;

    strcpy(notes[76].name , "F6");
    notes[76].freq = 1396.91;

    strcpy(notes[77].name , "F#6");
    notes[77].freq = 1479.98;

    strcpy(notes[78].name , "G6");
    notes[78].freq = 1567.98;

    strcpy(notes[79].name , "G#6");
    notes[79].freq = 1661.22;

    strcpy(notes[80].name , "A6");
    notes[80].freq = 1760.00;

    strcpy(notes[81].name , "A#6");
    notes[81].freq = 1864.66;

    strcpy(notes[82].name , "B6");
    notes[82].freq = 1975.53;

    strcpy(notes[83].name , "C7");
    notes[83].freq = 2093.00;

    strcpy(notes[84].name , "C#7");
    notes[84].freq = 2217.46;

    strcpy(notes[85].name , "D7");
    notes[85].freq = 2349.32;

    strcpy(notes[86].name , "D#7");
    notes[86].freq = 2489.02;

    strcpy(notes[87].name , "E7");
    notes[87].freq = 2637.02;

    strcpy(notes[88].name , "F7");
    notes[88].freq = 2793.83;

    strcpy(notes[89].name , "F#7");
    notes[89].freq = 2959.96;

    strcpy(notes[90].name , "G7");
    notes[90].freq = 3135.96;

    strcpy(notes[91].name , "G#7");
    notes[91].freq = 3322.44;

    strcpy(notes[92].name , "A7");
    notes[92].freq = 3520.00;

    strcpy(notes[93].name , "A#7");
    notes[93].freq = 3729.31;

    strcpy(notes[94].name , "B7");
    notes[94].freq = 3951.07;

    strcpy(notes[95].name , "C8");
    notes[95].freq = 4186.01;

    strcpy(notes[96].name , "C#8");
    notes[96].freq = 4434.92;

    strcpy(notes[97].name , "D8");
    notes[97].freq = 4698.63;

    strcpy(notes[98].name , "D#8");
    notes[98].freq = 4978.03;

    strcpy(notes[99].name , "E8");
    notes[99].freq = 5274.04;

    strcpy(notes[100].name , "F8");
    notes[100].freq = 5587.65;

    strcpy(notes[101].name , "F#8");
    notes[101].freq = 5919.91;

    strcpy(notes[102].name , "G8");
    notes[102].freq = 6271.93;

    strcpy(notes[103].name , "G#8");
    notes[103].freq = 6644.88;

    strcpy(notes[104].name , "A8");
    notes[104].freq = 7040.00;

    strcpy(notes[105].name , "A#8");
    notes[105].freq = 7458.62;

    strcpy(notes[106].name , "B8");
    notes[106].freq = 7902.13;

    strcpy(notes[107].name , "F#1");
    notes[107].freq = 46.25;
}

