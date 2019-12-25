#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int getline1(char s[]){
    
   fgets(s, LINE, stdin); 
   int length=strlen(s)-1;
   return length;
    
}
int getword(char w[]){
    
    scanf("%s",w);
    int length=strlen(w);
    return length;
    
}


int substring(char *str, char *str2)
{
  int matches = 0;
  int subStrringSize = 0;
  // If there are as many matches as there are characters in sub, then a substring exists.
  while (*str2 != '\0') {
    subStrringSize++;
    str2++;
  }
  str2 = str2 - subStrringSize;  // Reset pointer place

  while (*str != '\0') 
  {
    while (*str2 == *str && *str2 != '\0')
    {
      matches++;
      str2++;
      str++;
    }
    
    if (matches == subStrringSize) {return 1;}
    if(*str2 != *str){
        str2 = str2 - matches;
        matches = 0;  // Reset counter to 0 whenever a difference is found.    
    }
    str++;
  }
  return 0;
}

int similar (char *s, char *t, int n){
    
    int count=0,count2=0;
    while(*s != '\0'){
        count++;
        s++;
    }
    while(*t !='\0'){
        count2++;
        t++;
    }
    if(count<count2)
        return 0;

    s = s - count;
    t = t - count2;
    int unmatches = 0;
    int matches = 0;
    int subStrringSize = 0;
        
    // If there are as many matches as there are characters in sub, then a substring exists.
    while (*t != '\0') {
        subStrringSize++;
        t++;
    }

    t = t - subStrringSize;  // Reset pointer place
    
    while (*s != '\0' && *t != '\0' ) {
            if(*t == *s){
                //printf("its a match \n");
                matches++;
                t++;
                s++;
            }
            if(*t != *s){
                //printf("does not much %c =! %c \n",*t,*s);
                unmatches++;
                s++;
            }
    }
    if(unmatches != n)
        return 0;
    else return 1;
  }
  void print_lines(char *str){
    char *buffer = NULL;
    size_t size = 0;
    /// Open your_file in read-only mode
    FILE *fp = fopen("find_input.txt", "r");

    // Get the buffer size
    fseek(fp, 0, SEEK_END); // Go to end of file
    size = ftell(fp); // How many bytes did we pass ?

    // Set position of stream to the beginning
    rewind(fp);

    // Allocate the buffer (no need to initialize it with calloc)
    buffer = malloc((size + 1) * sizeof(*buffer)); // size + 1 byte for the \0

    // Read the file into the buffer
    fread(buffer, size, 1, fp); // Read 1 chunk of size bytes from fp into buffer

    // NULL-terminate the buffer
    buffer[size] = '\0';

    // Print it
    //printf("%s\n", buffer);
    
    // separe lines and check for the substring
    int i=0,j=0,n=0;
    //int line_numbers[LINE];
    char p=buffer[i];
    char line[LINE];
    while(buffer[i] != '\0'){
        while(p != '\n' && p != '\0'){
            line[n]=p;
            // i = runs on the file string
            i++;
            n++;
            p=buffer[i];
        }
        line[n]='\0';
        n=0;
        //line_checked = keep track which line its now
        //line_checked++;
        if(substring(line,str)==1){
            printf("%s\n",line);
            // line_numbers = save in array which lines have substring we search
            // j= keep track how many elements in line_numbers
            //line_numbers[j]=line_checked;
            j++;
        }
        i++;
        p=buffer[i];
    }
    j--;
    
    //while (j>-1){
    //    printf("The String : %s appear in line: %d  \n",str,line_numbers[j]);
    //   j--;
    //}
  }
  
 void print_similar_words(char * str){
    char *buffer = NULL;
    size_t size = 0;
    /// Open your_file in read-only mode
    FILE *fp = fopen("find_input.txt", "r");

    // Get the buffer size
    fseek(fp, 0, SEEK_END); // Go to end of file
    size = ftell(fp); // How many bytes did we pass ?

    // Set position of stream to the beginning
    rewind(fp);

    // Allocate the buffer (no need to initialize it with calloc)
    buffer = malloc((size + 1) * sizeof(*buffer)); // size + 1 byte for the \0

    // Read the file into the buffer
    fread(buffer, size, 1, fp); // Read 1 chunk of size bytes from fp into buffer

    // NULL-terminate the buffer
    buffer[size] = '\0';

    // Print it
    //printf("%s\n", buffer);
    
    int i=0,j=0,n=0,count=0;;
    //int line_numbers[LINE];
    char p=buffer[i];
    char line[LINE];
    char word[WORD+1]; // +1 for '\0'
    // prints the word we looking for since its the first word always.
    printf(" %s\n",str);
    while(buffer[i] != '\0'){
        
         while(p != '\n' && p != '\0'){
            line[n]=p;
            // i = runs on the file string
            i++;
            n++;
            p=buffer[i];
         }
         line[n]='\0';
         
        while(line[j] != '\0')
        {
            while(line[j] != ' ' && line[j] != '\0')
            {
                word[count]=line[j];
                count++;
                j++;
            }
            
            word[count]='\0';
            if(similar(word,str,1)){
                printf(" %s\n",word);
            }
            count=0;
            j++;
            
        }
        i++;
        p=buffer[i];
        n=0;
        j=0;
        
    }
     
 }
    

int main(){
    
    char *buffer = NULL;
    size_t size = 0;
    /// Open your_file in read-only mode
    FILE *fp = fopen("find_input.txt", "r");

    // Get the buffer size
    fseek(fp, 0, SEEK_END); // Go to end of file
    size = ftell(fp); // How many bytes did we pass ?

    // Set position of stream to the beginning
    rewind(fp);

    // Allocate the buffer (no need to initialize it with calloc)
    buffer = malloc((size + 1) * sizeof(*buffer)); // size + 1 byte for the \0

    // Read the file into the buffer
    fread(buffer, size, 1, fp); // Read 1 chunk of size bytes from fp into buffer

    // NULL-terminate the buffer
    buffer[size] = '\0';
    
    
    int i=0,count=0;
    char word[WORD];
    while(buffer[i] != ' ')
    {
        word[count]=buffer[i];
        count++;
        i++;
    }
    if(buffer[i+1] == 'a'){
        print_lines(word);
    }
    if(buffer[i+1] == 'b'){
        print_similar_words(word);
    }
    
    
    return 0;
}
