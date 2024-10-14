#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>

int genjam (char a[]) //extend it for all the functions
 {
    for(int p=0; p<strlen(a); p++) {
        if(a[p] == 'a'|| a[p] == 's'||a[p] == 'c'||a[p] == 't'||a[p] == 'S'||a[p] == 'C'||a[p] == 'T'||a[p] == 'r'||a[p] == 'R'||
        a[p] == 'd'||a[p] == 'L'||a[p] == 'l'||a[p] == 'b') return 1;
    }
}

char genjamtype (char a[]) //extend it for all the functions
 {
    for(int p=0; p<strlen(a); p++) {
        if(a[p] == 'a') return 'a';
         if(a[p] == 's') return 's';
          if(a[p] == 'c') return 'c';
           if(a[p] == 't') return 't';
            if(a[p] == 'S') return 'S';
             if(a[p] == 'C') return 'C';
              if(a[p] == 'T') return 'T';
               if(a[p] == 'r') return 'r';
                if(a[p] == 'R') return 'R';
                 if(a[p] == 'd') return 'd';
                  if(a[p] == 'L') return 'L'; 
                  if(a[p] == 'l') return 'l'; 
                  if(a[p] == 'b') return 'b';
                  if(a[p] == 'e') return 'e';

    }
}

double genjamvalue (char a[]) {
    int p=0;
    while  ((a[p]>='0' && a[p] <='9') || a[p] =='.' || a[p] == '-') {
        p++;
    }
char b[100];
    for(int q=0; q<p; q++) {
        b[q] = a[q];
    }

    double genjam_value;
     sscanf(b, "%lf", &genjam_value);
     
     return genjam_value;
}

double genjameval (double genjam_value, char genjamtype)
{
    switch (genjamtype)  {
        
        case 'a' :
        return pow(genjam_value,2);
        case 'b' :
        return pow(genjam_value,3);
        case 'd' :
        return (1/genjam_value);
        case 'l' : 
        return log10(genjam_value);
        case 'L' : 
        return log(genjam_value);
         case 'R' : 
        return sqrt(genjam_value);
        case 'r' : 
        return cbrt(genjam_value);
        case 's' :
        { 
        genjam_value = genjam_value* (3.1416/180);
        return sin(genjam_value);
        }
        case 'c' :
         { 
        genjam_value = genjam_value* (3.1416/180);
        return cos(genjam_value);
        }
       
        case 't' :
         { 
        genjam_value = genjam_value* (3.1416/180);
        return tan(genjam_value);
        }
        case 'S' :
         { 
        genjam_value = asin(genjam_value);
        return genjam_value * (180/3.1416);
        }
        case 'C' :
         { 
         genjam_value = acos(genjam_value);
        return genjam_value * (180/3.1416);
        }
        case 'T' :
         { 
         genjam_value = atan(genjam_value);
        return genjam_value * (180/3.1416);
        }   
        case 'e': {
        return pow(2.71828,genjam_value);
        }
    }
}