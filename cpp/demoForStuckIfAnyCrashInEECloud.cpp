#include <string.h>
#include <stdio.h>
#include <stdexcept>

int main()
{
   printf("entry main() \r\n");
   char s[] = "Golden Global   View  disk           desk";
   const char *d = " ";
   char *p;
   char* t[10];
   memset(t, 0, sizeof(t[0][0])*10*100); //do not why stuck if some segment fault happen.
   p = strtok(s,d);
   int i =0 ;

   while(p)
   {
      //printf("%s\n",p);
      try {
      //printf("%s\n", t[i]);
      if (0 > snprintf(t[i],sizeof(p), "%s",p)) {
          printf("wrong snprintf\n");
      }
      printf("t[%d]:%s \r\t",i,t[i]);
      } catch (std::exception& e) {
          printf("%s\n", e.what());
      }
      i++ ;
      p=strtok(NULL,d);
                                                                                            }

      return 0;
}