#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2){
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    else{
        string x = argv[1];
        int size = strlen(x);

        for(int i=0;i<size;i++){
            if(!isalnum(x[i])){
                print("Usage: ./vigenere keyword\n");
                return 1;
            }
        }

        // I created an array to not to iterate over argv[1] again and again inside if conditional
        int arr[30];

        bool control = true;
      
      // index2 = to restrict the array and to stop while loop
      // letter = for iterating over argv[1]
        int index2 =0;
        int letter =0;
        while(control == true){
            if(index2 ==30){
                break;
            }
            if(letter==size){
                letter=0;
            }
            char ekleme = tolower(x[letter])-97;
            arr[index2] = (int)ekleme;
            
            index2++;
            letter++;
        }

        string plaintext = get_string("plaintext: ");
        int size2 = strlen(plaintext);

        printf("ciphertext: ");
        int index =0;
        for(int i=0;i<size2;i++){
            
            if(isupper(plaintext[i]) && isalnum(plaintext[i])){

                int key = arr[index];

                char result = (int)(plaintext[i] + key -65)%26 + 65;
                printf("%c",result);

                index++;
            }
            else if(islower(plaintext[i]) && isalnum(plaintext[i])){
                int key = arr[index];
            
                char result = (int)(plaintext[i] +key-97)%26 + 97;
                printf("%c",result);
               
                index++;
            }
            else{
                printf("%c",plaintext[i]);
            }
            
        }
        printf("\n");
    }
    return 0;
}
