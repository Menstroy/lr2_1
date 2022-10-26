#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

struct cpu {
    int cpu_price;
    int cpu_core;
    char *cpu_name;
};

struct gpu {
    int gpu_price;
    int gpu_year;
    char *gpu_name;
};

struct motherboard {
    int mb_price;
    int mb_year;
    char *mb_name;
};

struct ram {
    int ram_price;
    int ram_volume;
    char *ram_name;
};

struct hdd {
    int hdd_price;
    int hdd_volume;
    char *hdd_name;
};

struct pc {
    struct cpu cpu_get;
    struct gpu gpu_get;
    struct motherboard mb_get;
    struct ram ram_get;
    struct hdd hdd_get;
};

void init(struct pc *p){
    p->cpu_get.cpu_price = 0;
    p->cpu_get.cpu_core = 0;
    p->cpu_get.cpu_name = (char*)calloc(30, (sizeof(char)));

    p->gpu_get.gpu_price = 0;
    p->gpu_get.gpu_year = 0;
    p->gpu_get.gpu_name = (char*)calloc(30, (sizeof(char)));

    p->mb_get.mb_price = 0;
    p->mb_get.mb_year = 0;
    p->mb_get.mb_name = (char*)calloc(30, (sizeof(char)));

    p->ram_get.ram_price = 0;
    p->ram_get.ram_volume = 0;
    p->ram_get.ram_name = (char*)calloc(30, (sizeof(char)));

    p->hdd_get.hdd_price = 0;
    p->hdd_get.hdd_volume = 0;
    p->hdd_get.hdd_name = (char*)calloc(30, (sizeof(char)));
}

void input(struct pc *p){
    printf("*ПРОЦЕССОР*\n\nВведите название:");
    scanf("%s", p->cpu_get.cpu_name);
    printf("\nВведите количество ядер:");
    scanf("%d", &p->cpu_get.cpu_core);
    printf("\nВведите стоимость:");
    scanf("%d", &p->cpu_get.cpu_price);

    printf("*ВИДЕОКАРТА*\n\nВведите название:");
    scanf("%s", p->gpu_get.gpu_name);
    printf("\nВведите год выпуска:");
    scanf("%d", &p->gpu_get.gpu_year);
    printf("\nВведите стоимость:");
    scanf("%d", &p->gpu_get.gpu_price);

    printf("*МАТЕРИНСКАЯ ПЛАТА*\n\nВведите название:");
    scanf("%s", p->mb_get.mb_name);
    printf("\nВведите год выпуска:");
    scanf("%d", &p->mb_get.mb_year);
    printf("\nВведите стоимость:");
    scanf("%d", &p->mb_get.mb_price);

    printf("*ОПЕРАТИВНАЯ ПАМЯТЬ*\n\nВведите название:");
    scanf("%s", p->ram_get.ram_name);
    printf("\nВведите объем(в ГБ):");
    scanf("%d", &p->ram_get.ram_volume);
    printf("\nВведите стоимость:");
    scanf("%d", &p->ram_get.ram_price);

    printf("*ЖЕСТКИЙ ДИСК*\n\nВведите название:");
    scanf("%s", p->hdd_get.hdd_name);
    printf("\nВведите объем(в ГБ):");
    scanf("%d", &p->hdd_get.hdd_volume);
    printf("\nВведите стоимость:");
    scanf("%d", &p->hdd_get.hdd_price);
}
void proverka(struct pc *p){
    if(p->cpu_get.cpu_price > p->gpu_get.gpu_price){
        printf("видеокарта не оптимальна подобрана под процессор, рекомендуем выбрать подороже видеокарту или более бюджетный процессор");
        int a;
        printf("вы будете менять видеокарту или процессор?\n 1-карту,0-процессор\n");
        scanf("%d",&a);
        if(a==1){
            printf("*ВИДЕОКАРТА*\n\nВведите название:");
            scanf("%s", p->gpu_get.gpu_name);
            printf("\nВведите год выпуска:");
            scanf("%d", &p->gpu_get.gpu_year);
            printf("\nВведите стоимость:");
            scanf("%d", &p->gpu_get.gpu_price);
        }
        else{
            printf("*ПРОЦЕССОР*\n\nВведите название:");
            scanf("%s", p->cpu_get.cpu_name);
            printf("\nВведите количество ядер:");
            scanf("%d", &p->cpu_get.cpu_core);
            printf("\nВведите стоимость:");
            scanf("%d", &p->cpu_get.cpu_price);
        }
    }
}
void config(struct pc *p) {
    int sum;
    puts("*ВАША СБОРКА*:");
    if (p->cpu_get.cpu_price)
        printf("процессор - %s; количество ядер - %d; цена - %d руб.\n", p->cpu_get.cpu_name, p->cpu_get.cpu_core, p->cpu_get.cpu_price);
    if (p->gpu_get.gpu_price)
        printf("видеокарта - %s; год выпуска - %d; цена - %d руб.\n", p->gpu_get.gpu_name, p->gpu_get.gpu_year, p->gpu_get.gpu_price);
    if (p->mb_get.mb_price)
        printf("материнская плата - %s; год выпуска - %d; цена - %d руб.\n", p->gpu_get.gpu_name, p->gpu_get.gpu_year, p->gpu_get.gpu_price);
    if (p->ram_get.ram_price)
        printf("оперативная память - %s; объем - %d; цена - %d руб.\n", p->ram_get.ram_name, p->ram_get.ram_volume, p->ram_get.ram_price);
    if (p->hdd_get.hdd_price)
        printf("жесткий диск - %s; объем - %d; цена - %d руб.\n", p->hdd_get.hdd_name, p->hdd_get.hdd_volume, p->hdd_get.hdd_price);
}
void result(struct pc *p){
    int sum;
    sum = p->cpu_get.cpu_price + p->gpu_get.gpu_price + p->gpu_get.gpu_price + p->ram_get.ram_price + p->hdd_get.hdd_price;
    printf("Итог: %d\n", sum);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    struct pc cfg;
    init(&cfg);
    input(&cfg);
    proverka(&cfg);
    config(&cfg);
    result(&cfg);
}

