// input the sky is blue

// output blue is sky the

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* reverse_words(char *input)
{
    char *output = (char*)malloc(sizeof(input));

    int j = 0;

    int o_count = 0;
    for(int i = strlen(input) - 1; i >= 0; i--)
    {
        if (input[i] == ' ')
        {
            
            strncpy(output + o_count, input + i + 1, j);
            o_count += j;
            j = 0;
        }
        j++;
    }

    return output;

}


int main() {

    char input[] = {"the sky is blue"};


    char *output = reverse_words(input);


    printf("%s\n",output);
    


    return 0;
}