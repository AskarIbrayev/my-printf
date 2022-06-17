#include <stdio.h>
#include <string.h>
#include <stdarg.h>
//#include <unistd.h>

void int2str(int param_1, int param_2){
    char rev_d2s[15], d2s[15];  
    int i = 0, end = 0, sign = 0;
    if (param_1 < 0){       
        sign = param_1;
        param_1 = -param_1;
    }  
    while (param_1 > 0){  
        if (param_1%param_2 < 10) rev_d2s[i] = param_1%param_2 + '0';
        else rev_d2s[i] = param_1%param_2 - 10 + 'a';
        param_1 /= param_2;
        i++;
    }
    if (sign < 0) rev_d2s[i] = '-';
    else i--;
    while (i >= 0){       
        d2s[end] = rev_d2s[i];
        i--;
        end++;
    }
    d2s[end] = '\0';
    fputs(d2s,stdout);
}
/*
void octal2str(int param_1){
    char rev_o2s[15], o2s[15];  
    int i = 0, end = 0;
    while (param_1 > 0){    
        rev_o2s[i] = param_1%8 + '0';
        param_1 /= 8;
        i++;
    }

    i--;
    while (i >= 0){         
        o2s[end] = rev_o2s[i];
        i--;
        end++;
    }
    o2s[end] = '\0';
    fputs(o2s,stdout);
}

void hex2str(int param_1){
    char rev_h2s[15], h2s[15];  
    int i = 0, end = 0;
    while (param_1 > 0){    
        if (param_1%16 < 10) rev_h2s[i] = param_1%16 + '0';
        else rev_h2s[i] = param_1%16 - 10 + 'a';
        param_1 /= 16;
        i++;
    }
    i--;
    while (i >= 0){        
        h2s[end] = rev_h2s[i];
        i--;
        end++;
    }
    h2s[end] = '\0';
    fputs(h2s,stdout);
}
*/

int my_printf(char *fmt, ...)
{
    va_list ap;
    int d,o,u,x,base;
    char c, *s;
    va_start(ap, fmt);
    while (*fmt){
        if (*fmt++ == '%'){            
            switch (*fmt++) {
                case 'd':
                    d = va_arg(ap, int);
                    base = 10;
                    int2str(d,base);                    
                    break;
                case 'o':
                    o = va_arg(ap, int);
                    base = 8;
                    int2str(o,base);  
                    break;
                case 'u':
                    u = va_arg(ap, int);
                    base = 10;
                    int2str(u,base);  
                    break;
                case 'x':
                    x = va_arg(ap, int);
                    base = 16;
                    int2str(x,base); 
                    break;
                case 'c':
                    c = (char) va_arg(ap, int);
                    putchar(c);
                    break;
                case 's':
                    s = va_arg(ap, char *);                   
                    fputs(s, stdout);
                    break;                
            }
        } else putchar(*(fmt-1));
    }
    va_end(ap);
    return 0;
}

int main(){
    int sign_decimal = -12345;
    int unsign_octal = 12345;
    int unsign_decimal = 12345;
    int unsign_hexadec = 32112345;
    char* name = "Askar";
    char first_letter = 'I';

    my_printf("This is signed decimal %d\n",sign_decimal);
  //  printf("PRINTF VERSION: This is signed decimal %d\n",sign_decimal);
     my_printf("This is unsigned octal %o\n",unsign_octal);   
    printf("PRINTF VERSION:This is unsigned octal %o\n",unsign_octal);
    my_printf("This is unsigned decimal %u\n",unsign_decimal);
  //  printf("PRINTF VERSION:This is unsigned decimal %u\n",unsign_decimal);
     my_printf("This is unsigned hexadecimal %x\n",unsign_hexadec);
    printf("PRINTF VERSION:This is unsigned hexadecimal %x\n",unsign_hexadec);
    my_printf("My name is %s. My surname starts with %c.\n",name,first_letter);  
  //  printf("PRINTF VERSION: My name is %s. My surname starts with %c.\n",name,first_letter);
}
