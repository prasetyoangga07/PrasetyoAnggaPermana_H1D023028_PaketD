#include <stdio.h>
typedef struct {
    int nim;
    float ip;
} KHS;

void printKHS(KHS *p) {
    printf("NIM: %d\n", p->nim);
    printf("IP: %.2f\n", p->ip);
}

int main() {
    KHS p;
    p.nim = 24052;
    p.ip = 3.85;
    printf("sebelum IP diperbarui:\n");
    printKHS(&p);
    printf("\n");
    p.ip = 4.00;
    printf("setelah IP diperbarui:\n");
    printKHS(&p);
    return 0;
}
