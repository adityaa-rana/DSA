#include<stdio.h>
#include<string.h>
void rev(char s[]){
    int len=strlen(s);
    int i=0;
    int j=len-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}
void removeSpaces(char str[]) {
    int i = 0, j = 0;
    
    // Loop through the string
    while (str[i] != '\0') {
        // If the current character is not a space, copy it to the new position
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    // Null terminate the modified string
    str[j] = '\0';
}
int main(){
    char add[]="as es dw fs d fd ";
    removeSpaces(add);
    printf("%s",add);
    return 0;
}