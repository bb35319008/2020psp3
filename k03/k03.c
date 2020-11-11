#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int i, text_len, key_len, n, cn, x;

    for(i=0; text[i] != '\0'; i++){
        text_len = i;
    }

    for(i=0; key[i] != '\0'; i++){
        key_len = i;
    }

    for(i=0; i <= text_len - key_len; i++){
        for(n=0; n <= key_len; n++){
            cn = i + x;
            if(text[cn] == key[n]){
                x++;
                if(n == key_len){
                    goto END;
                }
            }else{
                break;
            }
        }
    }

    return NULL;

    END:
    return &text[i+1];
}    

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int i, text_len, key_len, table[256], n, cn, index, x, z;

    for(i=0; text[i] != '\0'; i++){
        text_len = i;
    }

    for(i=0; key[i] != '\0'; i++){
        key_len = i;
    }

    for(i=0; i <= 255; i++){
        table[i] = key_len + 1;
    }

    for(i=0; key[i] != '\0'; i++){
        table[(unsigned char)key[i]] = key_len - i;
    }

    for(i=key_len; i <= text_len; i = i + table[index]){
        for(cn=i; cn >= cn - key_len; cn--){
            n = key_len - z;
            if(text[cn] == key[n]){
                z++;
                if(z == key_len + 1){
                    goto END;
                }
            }else{
                z = 0;
                x = 0;
                while(n - x >= 0){
                    if(text[cn] == key[n-x]){
                        index = table[(unsigned char)key[n-x]];
                        goto SKIP;
                    }
                    x++;
                }

                index = table[0];
                break;

                SKIP:
                    break;
            }
        }
    }

    return NULL;

    END:
    return &text[i - key_len];
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}