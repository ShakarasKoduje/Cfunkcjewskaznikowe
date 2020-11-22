#include<stdio.h>
#include<string.h>



int my_int_foo(int x, int y){

    printf("X from my int foo:%d\n", x);
    printf("Y from my int foo:%d\n", y);
    return 0;
}
int my_int_foo2(int x, int y){

    printf("X from my int foo2:%d\n", x);
    printf("Y from my int foo2:%d\n", y);
}
int my_int_foo3(int *x, int *y){
    int a = *x;
    int b = *y;
    *x = a*3;
    *y = b*4;
    printf("X from my int foo3:%d\n", a);
    printf("Y from my int foo3:%d\n", b);
    return 0;
}
void my_int_foo4(){

    printf("X from my int foo4:%d\n");
    printf("Y from my int foo4:%d\n");
}
void my_int_foo5(){

    printf("X from my int foo5:%d\n");
    printf("Y from my int foo5:%d\n");
}
typedef struct taka_t taka_t; // wczesniej trzeba w ten sposob zadeklarowac typ struktury, bez tego nie bedzie mozna sie wewnatrz struktury odwolywac do niej jako typu,
//ani w funkcjach typu taka_foo4 ktora za argumenty przyjmuje wlasnie struktury
struct taka_t{


    char *name;
    int x;
    int y;
    int *w;
    int *z;
    int (*taka_foo)(int,int); // funkcja wskaznikowa moze byc polem w Strukturze
    int (*taka_foo2)(int*,int*); // funkcja wskaznikowa moze byc polem w Strukturze, przyjmuje wskazniki
    int (*taka_foo3)(int *atak_self, int *obrana_target, int *zywotnosc_target);
    void (*taka_foo4)(const taka_t t1, const taka_t t12); // teraz mozna do funkcji wrzucic jako argumenty struktury


    //pary zmienna, wskaznik dla cech
    int atak;
    int *patak;

    int pancerz;
    int *ppancerz;

    int zywotnosc;
    int *pzywotnosc;

};

int zaatakuj(int *a , int  *p, int *z){
    int obrazenia = *a - *p;
    int zywotnosc = *z - obrazenia;
    printf("Obrazenia wynosza: %d\n", obrazenia);
    printf("Zywotnosc wynosi: %d\n", zywotnosc);
    if(zywotnosc<=0) printf("TRUP!\n");
    *z = zywotnosc;
    return 0;
    }

//funkcja przyjmujaca za argumenty strukture
void zaatakuj2(const taka_t self, const taka_t target){
    printf("%s zaatakowal z impetem %s...", self.name, target.name);
    printf("JEB!\n");
    int obrazenia = *self.patak - *target.ppancerz;
    int zywotnosc = *target.pzywotnosc - obrazenia;   
    *target.pzywotnosc = zywotnosc; 
    printf("Obrazenia wynosza: %d\n", obrazenia);
    printf("Pancerz obroncy wynosi:: %d\n", *target.ppancerz);
    printf("Zywotnosc obroncy wynosi: %d\n", *target.pzywotnosc);
    if(*target.pzywotnosc<=0) printf("TRUP!\n");

}

int main(){

    taka_t t; t.name = "Albrecht I";
    taka_t t1; t1.name = "Tycjusz Krwawy";
    t.x = 8; t.w = &t.x; t.y = 10; t.z = &t.y;
    t1.x = 8; t1.w = &t1.x; t1.y = 10; t1.z = &t1.y;
    t.taka_foo = &my_int_foo; // przypisanie funkcji do pola struktury (w tym przypadku funkcji wskaznikowej)
    //(*t.taka_foo)(t.x,t.y); //wywolanie funkcji wskaznikowej z wlasnymi parametrami przez strukture
    //mozliwe, ze bedzie tu mozliwe zmienianie parametrow poprzez wskazniki
    //t.taka_foo2 = &my_int_foo3; // ten przykład udawadnia powyższą tezę.
    //(*t.taka_foo2)(t.w,t.z);
    //t.taka_foo3 = &zaatakuj;

    t.atak = 9; t.pancerz = 2; t.zywotnosc = 11;
    t.patak = &t.atak; t.ppancerz = &t.pancerz; t.pzywotnosc = &t.zywotnosc;
    t1.atak = 6; t1.pancerz = 6; t1.zywotnosc = 12;
    t1.patak = &t1.atak; t1.ppancerz = &t1.pancerz; t1.pzywotnosc = &t1.zywotnosc;
/*
    int atak = 9, pancerz = 2, zywotnosc = 11;
    t.atak = &atak; t.pancerz = &pancerz; t.zywotnosc = &zywotnosc;

*/
       
    //(*t.taka_foo3)(t.atak,t.pancerz, t.zywotnosc);
    //(*t.taka_foo3)(t.atak,t.pancerz, t.zywotnosc);
    t.taka_foo4 = &zaatakuj2; // przypisanie funkcji zaatakuj2(const taka_t t1, const taka_t t2) do funkcji wskaznikowej struktury.
    (*t.taka_foo4)(t, t1);    //wyolanie funkcji
    (*t.taka_foo4)(t1, t);
    (*t.taka_foo4)(t, t1);
    (*t.taka_foo4)(t1, t);

    printf("TAKA SYTUACJA: %d || %d\n", *t.w, *t.z);
    printf("{%s}|| Atak  %d || Pancerz: %d ||\n", t.name, *t.patak, *t.ppancerz);
    printf("{%s}|| Atak  %d || Pancerz: %d ||\n", t1.name, *t1.patak, *t1.ppancerz);
        /*    
    //void (*funckje[3])(int , int ) = {&my_int_foo, &my_int_foo2, &my_int_foo3}; 
    int (*funkcje[2])(int,int); //={my_int_foo, my_int_foo}
    int (*foo)(int,int);
    foo = &my_int_foo;    
    funkcje[0] = foo;
    foo = &my_int_foo2;   
    funkcje[1] = foo;     
    (*funkcje[0])(7,9);
    (*funkcje[0])(111,2312321);
    //(*foo)(90, 100);
    //(foo)(398, 900);

    for(int i = 0, j = 10, k = 100; i<2;i++, j*=7, k-=5){
        (*funkcje[i])(j,k);
    }

*/

    return 0;
}
