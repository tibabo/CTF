#include <cstdint>
#include <sys/mman.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <csignal>

struct context
{
  uint64_t uVar1;
  uint16_t *local_98;
  uint16_t *arg7;
  uint64_t arg9;
  uint64_t arg11;
  uint64_t arg13;
  uint64_t arg15;
  uint64_t arg17;
  uint64_t arg19;
  uint64_t arg21;
  uint64_t arg23 [2];
  uint16_t *local_40;
};

unsigned char * M;
char DAT_0011116a = 0;

char s[] = {'d','l','r','u'};

char start[] = "{0x25, 0x31, 0x24, 0x30, 0x30, 0x30, 0x33, 0x38, 0x73, 0x25, 0x33, 0x24}";

context trueMain(char *, int, int, context c);

char buff[0x40000000];

char * varToName(int i)
{
  switch (i)
  {
    case 24:
          {
            int i=0;
            i++;
            return "*uVar1";
          }
    case 23: return "arg23";
    case 22: return "arg23";
    case 21: return "arg21";
    case 20: return "arg21";
    case 19: return "arg19";
    case 18: return "arg19";
    case 17: return "arg17";
    case 16: return "arg17";
    case 15: return "arg15";
    case 14: return "arg15";
    case 13: return "arg13";
    case 12: return "arg13";
    case 11: return "arg11";
    case 10: return "arg11";
    case 9: return "arg9";
    case 8: return "arg9";
    case 7: return "arg7";
    case 6: return "*arg7";
    case 5: return "*arg7";
    default : 
    {
      int j=0;
      j++;
    }
  }
  return "";
}

int main(void)
{
  FILE * f = fopen("../sprint", "rb");
	fseek(f, 0, SEEK_END);
	size_t binsize = ftell(f);
	rewind(f);

	unsigned char * bin = (unsigned char*)malloc(binsize);
	fread(bin, 1, binsize, f);
	fclose(f);
  M = bin + 0x2020;
  // for(int i = 0; i < binsize -12; i++)
  // {
  //   if(strncmp((const char *)(bin + i),start,12) == 0)
  //   {
  //       //printf(" i = %d", i);
  //       //M = bin + 0x2020;
  //       break;

  //   }
  // }

  char pass[256];
    // char pass2[255];
  memset(pass, 'r', 254);
  pass[254] = 0;
    // memset(pass2, 0, 255);


  int PC = 0x4000000;
  char trucnul = 1;
  int len = 1;
  int index = 0;
  int i = 0;
  while(index < 5166)
  {
    
    sscanf((char *)M+index, "%s",buff);
    len = strlen(buff);
    if(len) { 
      //printf("%s\n",buff);
      printf("P%d: ", index);
      index += len + 1;
      i++;
      int next;
      int delta;
      int move;
      int varIndex;
      int n = sscanf(buff, "%%1$%ds%%3$hn%%1$%ds%n",&next,&delta,&move);
      char * start = buff;

      if(n == 2)
      {

        start += move;
      }
      else
      {
        n = sscanf(start, "%%1$%ds%%3$hn%n",&next,&move);
        if(n == 1)
        {
          start += move;
        }
      }

      short constant;
      int varIndexDest;
      int varIndex2;
      // varx = varz + vary
      n = sscanf(start, "%%1$*%d$s%%1$*%d$s%%%d$hn%n",&varIndex2,&varIndex,&varIndexDest,&move);
      if(n == 3)
      {
        printf("%s = %s + %s; ", varToName(varIndexDest), varToName(varIndex2), varToName(varIndex));
        start += move;
      }

      // varx = constant + vary
      n = sscanf(start, "%%1$%hds%%1$*%d$s%%%d$hn%n",&constant,&varIndex,&varIndexDest,&move);
      if(n == 3)
      {
        printf("%s = %#hx + %s; ", varToName(varIndexDest), constant, varToName(varIndex));
        start += move;
      }
      // varx = vary + constant
      n = sscanf(start, "%%1$*%d$s%%1$%hds%%%d$hn%n", &varIndex, &constant, &varIndexDest, &move);
      if(n == 3)
      {
        printf("%s = %s + %hd; ", varToName(varIndexDest), varToName(varIndex), constant);
        start += move;
      }

      // varx = vary
      n = sscanf(start, "%%1$*%d$s%%%d$hn%n", &varIndex, &varIndexDest, &move);
      if(n == 2)
      {
        printf("%s = %s; ", varToName(varIndexDest), varToName(varIndex));
        start += move;
      }

      // var = constant
      n = sscanf(start, "%%1$%hds%%%d$hn%n",&constant,&varIndex,&move);
      if(n == 2)
      {
        printf("%s = %#hx; ", varToName(varIndex), constant);
        start += move;
      }
    
      // if(var) PC = x else PC = Y
                        
      n = sscanf(start, "%%%d$c%%1$%ds%%2$c%%4$s%%1$%ds%%3$hn%n",
      &varIndex, &delta, &next, &move);
      if(n == 3)
      {
        printf("if( %s ) goto P%hd; \n", varToName(varIndex), delta*2 + next + 3);
        start += move;
      }
      else
      {
        if(next != index)
          printf("goto P%d;\n",next);
        else
          printf("\n");
          
      }
      
    
    }
  }
  printf("%d\n",i);
  context c;
  c.local_40 = (uint16_t *)mmap((void *)0x4000000,0x4000000,3,0x22,-1,0);
  memcpy(c.local_40,M,0xf134);
  c.arg9 = 0;
  c.arg11 = 0;
  c.arg13 = 0;
  c.arg15 = 0;
  c.arg17 = 0;
  c.arg19 = 0;
  c.arg21 = 0;
  c.arg23[0] = 0;
  c.local_98 = c.local_40;
  c.arg7 = c.local_40;

  c.uVar1 = 0x101270;
  sprintf((char*)(c.local_40 + 0x7000),"%s",pass);
  c = trueMain(pass, 0, 1334, c);

  for(int y = 0; y < 0x10; y++)
  {
    for(int x = 0; x < 0x10; x++)
    {
      unsigned char value = *( (unsigned char*)0x400f000 + y*0x10 + x);
      if (*( (char*)0x4007000 + value*2))
      {
        printf("#");
      }
      else
      {
        bool found = false;
        unsigned char pos = y*0x10 + x;
        for (char z = 0; z < 9; z++)
        {
          unsigned char sum = *((unsigned char*)0x400f103 + z) + pos;
          if(sum == 0)
          {
            found = true;
            printf("%d",z);
          }
        }
        if(!found)
          printf(" ");
      }
    }
    printf("\n");
  }

  const char *p ="ddrrrrrrddrrrrrrrrddll"
                  "rruullllllllddddllllllddddrrrrrrrruurrddrrddrr"
                  "lluulluullddlllllllluuuurrrrrruuuuuulllllldd"
                  "uurrrrrrddddddllllllddddrrrrrruu"
                  "ddlllllluuuuuurruu"
                  "ddllddrrrrrruuuurrrrrruurr"
                  "llddllllllddddllllllddddrrddll"
                  "rruulluuuurrrrrruull"
                  "rruurruuuurrrrrr";
  int l = strlen(p);
  strncpy(pass,p,l);
  sprintf((char*)(c.local_40 + 0x7000),"%s",pass);
  c = trueMain(pass, 1334, 65535, c);

  {
    for(int index = 0; index < 254; index++)
    {
      int i = 0;
      char a = s[i];
      while(1)
      {
          pass[index] = a;
          sprintf((char*)(c.local_40 + 0x7000),"%s",pass);
          context ret = trueMain(pass, 1334, 3414, c);
          if(ret.arg9 <= index && ret.arg23[0])
          {
            i++;
            if(i>= sizeof(s))
              break;
            a = s[i];
          }
          else
          {
            index = ret.arg9-1;
            i=0;
            break;
          }
          
          

      }
    }
  }

  munmap((void *)0x4000000,0x4000000);
  return 0 ;
}



context trueMain(char* pass, int start, int stop, context c)
{  
  while (c.local_98 != c.local_40 + 0x7fff) {
  
    printf("%05d %s\n",c.local_98 - 0x2000000, c.local_98);
    
    sprintf((char *)0x6000000,(char *)c.local_98,&DAT_0011116a,0,&c.local_98,0x6000000,(uint32_t)*c.arg7,
            c.arg7,&c.arg7,c.arg9,&c.arg9,c.arg11,&c.arg11,c.arg13,&c.arg13,c.arg15,
            &c.arg15,c.arg17,&c.arg17,c.arg19,&c.arg19,c.arg21,&c.arg21,c.arg23[0],c.arg23,
            c.uVar1);
    if((char*)c.local_98 == (((char*)c.local_40) + 3286))
    {
      int i = 0;
      i++;
    }
    if((char*)c.local_98 == (((char*)c.local_40) + stop))
    {
      goto exit;
    }

  }
  if (c.local_40[0x7400] != 0) {
    printf("Flag: %s\n",(char *)(c.local_40 + 0x7400));
  }
exit:

  return c;
}

