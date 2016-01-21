#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int time_to_end(int start_site, int num_sites) {
   int i=start_site; int t;
   for(t=0; i!=0 && i!=num_sites; ++t) {
      i += (rand()%2)*2-1;
   }
   return t;
}

float avg_time_to_end(int start_site, int num_sites, int trials) {
   float sum=0.0;
   int tri;
   for(tri=0; tri<trials; ++tri) {
      sum += time_to_end(start_site, num_sites);
   }
   return sum/trials;
}

void main() {
   int num_sites=100; int start_site;
   srand(time(NULL));
   for(start_site=1; start_site<num_sites; ++start_site) {
      float avg_time = avg_time_to_end(start_site, num_sites, 100);
      printf("%d\t%f\n", start_site, avg_time);
   }
}
