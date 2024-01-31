//Disk Scheduling CODE 8
//FIFO
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
 int i, n, req[50], mov=0, cp;
 printf("Enter the current position\n");
 scanf("%d", &cp);
 printf("Enter the number of requests\n");
 scanf("%d", &n);
 printf("Enter the request order\n");
 for(i=0; i<n; i++) {
 scanf("%d", &req[i]);
 }
 mov = mov + abs(cp - req[0]);
 printf("%d -> %d", cp, req[0]);
 for(i=1; i<n; i++) {
 mov = mov + abs(req[i] - req[i-1]);
 printf(" -> %d", req[i]);
 }
 printf("\nTotal head movement = %d\n", mov);
 return 0;
}
//SSTF
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
 int i, n, k, req[50], mov=0, cp, index[50], min, a[50], j=0, mini, cp1;
 printf("Enter the current position\n");
 scanf("%d", &cp);
 cp1 = cp;
 printf("Enter the number of requests\n");
 scanf("%d", &n);
 printf("Enter the request order\n");
 for(i=0; i<n; i++) {
 scanf("%d", &req[i]);
 }
 for(k=0; k<n; k++) {
 for(i=0; i<n; i++) {
 index[i] = abs(cp - req[i]);
 }
 min = index[0];
 mini = 0;
 for(i=1; i<n; i++) {
 if(min > index[i]) {
 min = index[i];
 mini = i;
 }
 }
 a[j] = req[mini];
 j++;
 cp = req[mini];
 req[mini] = 999;
 }
 printf("Sequence is : ");
 printf("%d", cp1);
 mov = mov + abs(cp1 - a[0]);
 printf(" -> %d", a[0]);
 for(i=1; i<n; i++) {
 mov = mov + abs(a[i] - a[i-1]);
 printf(" -> %d", a[i]);
 }
 printf("\nTotal head movement = %d\n", mov);
 return 0;
}